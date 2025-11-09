项目部分技术说明文档 25国庆
===========================

wxWidgets的wxTextCtrl的使用方法
---------------------------
1. 创建: 
.. code-block:: cpp
    :linenos:
    auto var = new wxTextCtrl(mypanel, wxID_ANY, wxT("mytext"));

2. 读取: 
.. code-block:: cpp 
    :linenos:
    auto rawa = var -> GetValue(); //此处rawa是wxString类型 
    auto rawb = rawa.ToStdString(); //此处rawb是std::string类型

lambda函数定义
---------------------------
1. 基本格式: 
.. code-block:: cpp 
    :linenos:
    auto lambdafunc = [/*捕获变量*/](/*传入参数*/){
        /*函数体*/
    };

2. 捕获变量可以 **使用=** 捕获所有变量: 
.. code-block:: cpp 
    :linenos:
    auto lambdafunc2 = [=](/*同上*/){
        /*同上*/
    };

stoi函数
---------------------------
1. 使用方法: 
.. code-block:: cpp 
    :linenos:
    int res = std::stoi(stringvar);

2. 注意事项: stoi **可能会抛出异常** ，建议 **在try-catch块使用**

wxWidgets的空wxCommandEvent
---------------------------
1. 定义位置: **var.hpp**
2. 名称: **EmptyEvent**

BigIntFile的Add函数
---------------------------
1. 模板: 
.. code-block:: cpp 
   :linenos:
   auto t = BigInt(Bank::BankStore.Read());
   t.Add(BigInt(5));
   Bank::BankStore.Write(t.toString());

PasswordFile的增加与减少
---------------------------
1. 增加: 
.. code-block:: cpp 
    :linenos:
    var.addnum(intv);

2. 减少: 
.. code-block:: cpp 
    :linenos:
    var.minusnum(intv); // 不检测
    var.canminus(intv); // 如果不足不减少返回false，反之减少并返回true 
    var.minusnum_if(intv); // 如果不足减少至0，反之正常减少

Rust的函数getrnd与getrnds的使用
---------------------------
1. **getrnd** 的使用
.. code-block:: cpp 
    :linenos: 
    int ans = getrnd(min_value, max_value + 1);//左闭右开

2. **getrnds** 的使用
.. code-block:: cpp 
    :linenos:
    int* ans = getrnds(min_value, max_value + 1, num);//左闭右开
    delete ans;//记得释放内存

