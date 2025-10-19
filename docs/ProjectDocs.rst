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

2. 捕获变量可以使用"="捕获所有变量: 
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

2. 注意事项: stoi可能会抛出异常，建议在try-catch块使用

wxWidgets的空wxCommandEvent
---------------------------
1. 定义位置: var.hpp
2. 名称: EmptyEvent

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
    var.minusnum(intv);

Rust的函数getrnd与getrnds的使用
---------------------------
1. getrnd的使用
.. code-block:: cpp 
    :linenos: 
    int ans = getrnd(min_value, max_value + 1);//左闭右开

2. getrnds的使用
.. code-block:: cpp 
    :linenos:
    int* ans = getrnds(min_value, max_value + 1, num);//左闭右开
    delete ans;//记得释放内存

ancient_shop_guwan的概率
---------------------------
1. 普通古玩：黄金5两
   概率：
   假货 55%
   玉佩 35%
   瓷器 10%
   碑刻 0%
2. 高级古玩：黄金10两
   概率：
   假货 35%
   玉佩 30% (x2)
   瓷器 25%
   碑刻 10%
3. 珍藏古玩：黄金30两
   概率：
   假货 15%
   玉佩 35% (x2)
   瓷器 25% (x2)
   碑刻 25%
4. 茶壶古玩：黄金20两
   概率：
   假货 50%
   茶壶 50%
5. 茶盏古玩：黄金30两
   概率：
   假货 50%
   茶盏 50% (x4)
6. 茶具古玩：黄金35两
   概率：
   假货 40%
   茶壶 35%
   茶盏 25% (x4)
7. 综合古玩：黄金50两
   概率：
   假货 10%
   玉佩 20% (x2)
   瓷器 15% (x2)
   碑刻 10%
   茶壶 25%
   茶盏 20% (x4)
8. 诚信古玩：黄金70两
   概率：
   玉佩 25% (x2)
   瓷器 20% (x2)
   碑刻 10%
   茶壶 25%
   茶盏 20% (x4)

MYLAST宏的用处
---------------------------
1. 用处: 
   整合MYBACK与MYUSE，
   使用MYLAST(function)相当于
   依次使用MYBACK(function,1)
   与MYUSE()
2. 注意事项: 
   现在多使用函数Simple::BackButton而非该宏

baoshi_choujiang1函数
---------------------------
1. 价格：5颗宝石
2. 概率：
   汉朝卡牌1*2：5%
   铜钱50枚：20%
   积分*50：25%
   仙币*30：50%

global.hpp使用方法
---------------------------
1. global.hpp提供全局变量
2. global.hpp的全局变量以static形式存储
3. 不要在不同源文件里访问同一个全局变量

