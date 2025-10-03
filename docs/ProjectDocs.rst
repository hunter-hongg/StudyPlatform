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
    auto rawa = var.GetValue(); //此处rawa是wxString类型 
    auto rawb = rawa.toStdString(); //此处rawb是std::string类型

lambda函数定义
---------------------------
1. 基本格式: 
.. code-block:: cpp 
    :linenos:
    auto lambdafunc = [/*捕获变量*/](/*传入参数*/){
        /*函数体*/
    };

2. 捕获变量可以使用"="捕获所有变量: 
.. code-block:: cpp 
    :linenos:
    auto lambdafunc2 = [=](/*同上*/){
        /*同上*/
    };

