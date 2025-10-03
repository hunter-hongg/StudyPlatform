项目部分技术说明文档 25国庆
===========================

wxTextCtrl的使用方法
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

