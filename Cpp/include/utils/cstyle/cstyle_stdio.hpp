// cstyle_stdio.hpp
#pragma once

#include <cstdio>      // FILE*, fopen, fclose, etc.
#include <memory>      // std::unique_ptr
#include <string>      // std::string
#include <system_error> // std::system_error
#include <cerrno>      // errno
#include <cstdarg>     // va_list (for formatted IO)
#include <vector>      // std::vector (for read_all)

namespace cstyle
{

//-------------------------------
// 错误处理（将 C 的 errno 转换为异常）
//-------------------------------
inline void throw_system_error(const char* msg)
{
    throw std::system_error(errno, std::generic_category(), msg);
}

//-------------------------------
// 文件句柄的 RAII 封装
//-------------------------------
class file
{
public:
    // 打开模式（模仿 C 的 fopen）
    enum class mode {
        read = 0,      // "r"
        write,         // "w"
        append,        // "a"
        read_update,   // "r+"
        write_update,  // "w+"
        append_update  // "a+"
    };

    // 构造函数（打开文件）
    explicit file(const std::string& path, mode m)
    {
        const char* mode_str = nullptr;
        switch (m) {
        case mode::read:
            mode_str = "r";
            break;
        case mode::write:
            mode_str = "w";
            break;
        case mode::append:
            mode_str = "a";
            break;
        case mode::read_update:
            mode_str = "r+";
            break;
        case mode::write_update:
            mode_str = "w+";
            break;
        case mode::append_update:
            mode_str = "a+";
            break;
        }

        handle_.reset(std::fopen(path.c_str(), mode_str));
        if (!handle_) {
            throw_system_error("Failed to open file");
        }
    }

    // 移动构造/赋值
    file(file&&) = default;
    file& operator=(file&&) = default;

    // 获取原始句柄（用于 C 接口交互）
    FILE* native_handle() const noexcept
    {
        return handle_.get();
    }

    // 读取/写入接口
    size_t read(void* buf, size_t size)
    {
        size_t ret = std::fread(buf, 1, size, handle_.get());
        if (std::ferror(handle_.get())) {
            throw_system_error("File read error");
        }
        return ret;
    }

    size_t write(const void* buf, size_t size)
    {
        size_t ret = std::fwrite(buf, 1, size, handle_.get());
        if (ret != size) {
            throw_system_error("File write error");
        }
        return ret;
    }

    // 读取整个文件（返回字节向量）
    std::vector<uint8_t> read_all()
    {
        std::vector<uint8_t> data;
        if (std::fseek(handle_.get(), 0, SEEK_END) != 0) {
            throw_system_error("Failed to seek file");
        }
        long size = std::ftell(handle_.get());
        if (size < 0) {
            throw_system_error("Failed to get file size");
        }
        std::rewind(handle_.get());

        data.resize(size);
        if (size > 0 && read(data.data(), size) != static_cast<size_t>(size)) {
            throw_system_error("Incomplete read");
        }
        return data;
    }

    // 格式化输出（类型安全的 printf）
    template <typename... Args>
    void printf(const char* fmt, Args... args)
    {
        if (std::fprintf(handle_.get(), fmt, args...) < 0) {
            throw_system_error("Failed to write formatted output");
        }
    }

private:
    struct file_deleter {
        void operator()(FILE* f) const noexcept
        {
            if (f) std::fclose(f);
        }
    };
    std::unique_ptr<FILE, file_deleter> handle_;
};

//-------------------------------
// 简化版文件操作（一次性接口）
//-------------------------------
inline std::string read_file_as_string(const std::string& path)
{
    file f(path, file::mode::read);
    auto data = f.read_all();
    return std::string(reinterpret_cast<const char*>(data.data()), data.size());
}

inline void write_file(const std::string& path, const std::string& content)
{
    file f(path, file::mode::write);
    f.write(content.data(), content.size());
}

} // namespace cstyle