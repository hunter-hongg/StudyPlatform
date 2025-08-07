#ifndef POLY_HXX
#define POLY_HXX

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

class poly
{
private:
    std::vector<double> coeffs;

    void trim()
    {
        while (!coeffs.empty() && coeffs.back() == 0.0) {
            coeffs.pop_back();
        }
    }

public:
    poly() = default;

    poly(std::initializer_list<double> init) : coeffs(init)
    {
        trim();
    }

    explicit poly(const std::vector<double>& coeffs) : coeffs(coeffs)
    {
        trim();
    }

    explicit poly(std::vector<double>&& coeffs) : coeffs(std::move(coeffs))
    {
        trim();
    }

    poly(const poly&) = default;
    poly(poly&&) = default;
    poly& operator=(const poly&) = default;
    poly& operator=(poly&&) = default;
    ~poly() = default;

    size_t degree() const
    {
        return coeffs.empty() ? 0 : coeffs.size() - 1;
    }

    double operator[](size_t power) const
    {
        return power < coeffs.size() ? coeffs[power] : 0.0;
    }

    void set_coeff(size_t power, double value)
    {
        if (power >= coeffs.size()) {
            if (value == 0.0) return;
            coeffs.resize(power + 1, 0.0);
        }
        coeffs[power] = value;
        trim();
    }

    poly operator+(const poly& other) const
    {
        size_t max_size = std::max(coeffs.size(), other.coeffs.size());
        std::vector<double> result(max_size, 0.0);

        for (size_t i = 0; i < max_size; ++i) {
            result[i] = (*this)[i] + other[i];
        }

        return poly(result);
    }

    poly operator-(const poly& other) const
    {
        size_t max_size = std::max(coeffs.size(), other.coeffs.size());
        std::vector<double> result(max_size, 0.0);

        for (size_t i = 0; i < max_size; ++i) {
            result[i] = (*this)[i] - other[i];
        }

        return poly(result);
    }

    poly operator*(const poly& other) const
    {
        if (coeffs.empty() || other.coeffs.empty()) {
            return poly();
        }

        size_t result_size = degree() + other.degree() + 1;
        std::vector<double> result(result_size, 0.0);

        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        return poly(result);
    }

    poly operator-() const
    {
        poly result = *this;
        for (auto& coeff : result.coeffs) {
            coeff = -coeff;
        }
        return result;
    }

    poly& operator+=(const poly& other)
    {
        *this = *this + other;
        return *this;
    }

    poly& operator-=(const poly& other)
    {
        *this = *this - other;
        return *this;
    }

    poly& operator*=(const poly& other)
    {
        *this = *this * other;
        return *this;
    }

    bool operator==(const poly& other) const
    {
        return coeffs == other.coeffs;
    }

    bool operator!=(const poly& other) const
    {
        return !(*this == other);
    }
};

#endif