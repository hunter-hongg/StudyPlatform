#include <headers.hpp>

void MyFrame::start()
{
    MYINIT();

    auto title = new wxStaticText(panel,wxID_ANY,wxString::FromUTF8("欢迎"+User+"来到学习平台"));
    title->SetFont(font30);
    vbox->Add(title,FLAG_CENTER);

    auto show = new wxButton(panel,wxID_ANY,
                             wxString(wxT("积分："))+JiFenReader.read_str()+NEWLINE+
                             wxT("积分等级：")+TOSTR(jifen::calculate_level(JiFenReader.read_int())));
    show->SetFont(font15);
    show->SetForegroundColour(MyBlue);
    vbox->Add(show,FLAG_CENTER);

    MYADDSPACER();

    MYBUTTON(button2,&MyFrame::mine,"我的主页");
    button2 -> SetFont(font19);
    MYBUTTON(button4,&MyFrame::xianbi_square,"神话传说");
    button4 -> SetFont(font19);
    MYBUTTON(button3,&MyFrame::calc_square,"计算广场");
    button3 -> SetFont(font19);
    MYBUTTON(button5,&MyFrame::ancient_square,"古代广场");
    button5 -> SetFont(font19);
    MYBUTTON(button6,&MyFrame::things_square,"物品领取");
    button6 -> SetFont(font19);

    MYADDSPACER();

    auto quitButton = new wxButton(panel,wxID_ANY,wxT("退出"));
    quitButton -> SetFont(font15);
    quitButton -> Bind(wxEVT_BUTTON,[](WXBTNEVT& evt) {
        (void)evt;
        exit(0);
    });
    vbox->Add(quitButton,FLAG_RIGHT);

    MYADDSPACER();

    MYUSE();
}

void MyFrame::mine(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("我的主页");
    MYSHOW(wxString(wxT("积分："))+JiFenReader.read_str()+NEWLINE+
           wxT("积分等级：")+TOSTR(jifen::calculate_level(JiFenReader.read_int())));

    MYBUTTON(button1,&MyFrame::all_thing_all,"所有物品");
    MYBUTTON(button2,&MyFrame::time_clock,"学习计时");
    MYBUTTON(button3,&MyFrame::lihe,"我的礼盒");
    
    MYADDSPACER();

    MYBACKTOMAIN();

    MYUSE();
}
void MyFrame::ancient_shop(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("普通店铺");

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1两白银\n10枚铜钱"));
    btn1->SetFont(font17);
    btn1->SetForegroundColour(MyRed);
    btn1->Bind(wxEVT_BUTTON,[this](WXBTNEVT& _) {
        if(!AncientVar::TongBiReader.high(10)) {
            MYMESSAGE("铜钱不足");
            return;
        }
        AncientVar::TongBiReader.minusnum(10);
        AncientVar::BaiYinReader.addnum(1);
        MYMESSAGE("购买成功");
    });
    grid->Add(btn1,FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("1两黄金\n10两白银"));
    btn2->SetFont(font17);
    btn2->SetForegroundColour(MyRed);
    btn2->Bind(wxEVT_BUTTON,[this](WXBTNEVT& _) {
        if(!AncientVar::BaiYinReader.high(10)) {
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::BaiYinReader.minusnum(10);
        AncientVar::HuangJinReader.addnum(1);
        MYMESSAGE("购买成功");
    });
    grid->Add(btn2,FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("100枚铜钱\n1两黄金"));
    btn3->SetFont(font17);
    btn3->SetForegroundColour(MyRed);
    btn3->Bind(wxEVT_BUTTON,[this](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.high(1)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(1);
        AncientVar::TongBiReader.addnum(100);
        MYMESSAGE("购买成功");
    });
    grid->Add(btn3,FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("佩剑1把\n100两黄金"));
    btn4->SetFont(font17);
    btn4->SetForegroundColour(MyRed);
    btn4->Bind(wxEVT_BUTTON,[this](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.high(100)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int ans = getrnd(0,7); // 左闭右开原则
        Ancient::Sword anss = static_cast<Ancient::Sword>(ans);
        AncientVar::Sword.Add(anss);
        AncientVar::HuangJinReader.minusnum(100);
        MYSTRMESSAGE(wxString("")+wxT("购买成功，恭喜获得")+wxString::FromUTF8(TOSTR(anss)));
    });
    grid->Add(btn4,FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("锦袍一件\n300两黄金"));
    btn5->SetFont(font17);
    btn5->SetForegroundColour(MyRed);
    btn5->Bind(wxEVT_BUTTON,[this](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.high(300)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int ans = getrnd(0,8); // 锦袍方面有银袍
        Ancient::Pao anss = static_cast<Ancient::Pao>(ans);
        AncientVar::Pao.Add(anss);
        AncientVar::HuangJinReader.minusnum(300);
        MYSTRMESSAGE(wxString("")+wxT("购买成功，恭喜获得")+wxString::FromUTF8(TOSTR(anss)));
    });
    grid->Add(btn5,FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("普通书籍*5\n50两白银"));
    btn6 -> SetFont(font17);
    btn6 -> SetForegroundColour(MyRed);
    btn6 -> Bind(wxEVT_BUTTON,[this](WXBTNEVT&) {
        if(!AncientVar::BaiYinReader.canminus(50)){
            MYMESSAGE("白银不足");
            return;
        }
        BookShelfFiles_WriteLevel1(BookShelf::Reader, 5);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("珍贵书籍*3\n75两白银"));
    btn7 -> SetFont(font17);
    btn7 -> SetForegroundColour(MyRed);
    btn7 -> Bind(wxEVT_BUTTON,[this](WXBTNEVT&) {
        if(!AncientVar::BaiYinReader.canminus(75)){
            MYMESSAGE("白银不足");
            return;
        }
        BookShelfFiles_WriteLevel2(BookShelf::Reader, 3);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("典藏书籍*2\n100两白银"));
    btn8 -> SetFont(font17);
    btn8 -> SetForegroundColour(MyRed);
    btn8 -> Bind(wxEVT_BUTTON,[this](WXBTNEVT&) {
        if(!AncientVar::BaiYinReader.canminus(100)){
            MYMESSAGE("白银不足");
            return;
        }
        BookShelfFiles_WriteLevel3(BookShelf::Reader, 2);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn8, FLAG_CENTER);

    vbox->Add(grid,FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_shopa,1);

    MYUSE();
}
void MyFrame::tsquare_free(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("免费领取");

    MYBUTTON(btn1,&MyFrame::tsquare_free_jifen,"免费积分");
    MYBUTTON(btn2,&MyFrame::tsqaure_free_xianbi,"免费仙币");
    MYBUTTON(btn3,&MyFrame::tsquare_free_tongqian,"免费铜钱");
    MYBUTTON(btn4,&MyFrame::tsquare_free_baoshi,"免费宝石");
    MYBUTTON(btn5,&MyFrame::tsquare_free_jinbi,"免费金币");

    MYADDSPACER();

    MYLAST(&MyFrame::things_square);
}
void MyFrame::ancient_square(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("古代广场");
    MYSHOW(wxString("")+
           wxT("铜钱：")+AncientVar::TongBiReader.read_str()+wxT("枚")+NEWLINE+
           wxT("白银：")+AncientVar::BaiYinReader.read_str()+wxT("两")+NEWLINE+
           wxT("黄金：")+AncientVar::HuangJinReader.read_str()+wxT("两")
          );

    MYBUTTON(btn1,&MyFrame::ancient_shopa,"古代店铺");
    MYBUTTON(btn3,&MyFrame::ancient_things,"我的物品");
    MYBUTTON(btn4,&MyFrame::ancient_wenguan,"我的官位");
    MYBUTTON(btn5,&MyFrame::ancient_juanzeng,"我的捐赠");

    MYADDSPACER();

    MYBACKTOMAIN();

    MYUSE();
}
void MyFrame::ancient_shop_baowu(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("宝物店铺");

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("明珠一颗\n500两黄金"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyOrange);
    btn1 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.high(500)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(500);
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct,AncientBaoWu_MingZhu,1);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn1,FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("玉雕1件\n800两黄金"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyOrange);
    btn2 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.high(800)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(800);
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct,AncientBaoWu_YuDiao,1);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn2,FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("玉璧1件\n1200两黄金"));
    btn3 -> SetFont(font17);
    btn3 -> SetForegroundColour(MyOrange);
    btn3 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.high(1200)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(1200);
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct,AncientBaoWu_YuBi,1);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn3,FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("绸缎2匹\n700两黄金"));
    btn6 -> SetFont(font17);
    btn6 -> SetForegroundColour(MyOrange);
    btn6 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.canminus(700)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct,AncientBaoWu_ChouDuan,2);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn6,FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("绸缎5匹\n1500两黄金"));
    btn4 -> SetFont(font17);
    btn4 -> SetForegroundColour(MyOrange);
    btn4 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.high(1500)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(1500);
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct,AncientBaoWu_ChouDuan,5);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn4,FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("玉盏1件\n1000两黄金"));
    btn5 -> SetFont(font17);
    btn5 -> SetForegroundColour(MyOrange);
    btn5 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.canminus(1000)) {
            MYMESSAGE("黄金不足");
            return;
        }
        YuZhan_Write(AncientVar::YuZhanReader,1);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn5,FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("玉壶1件\n1500两黄金"));
    btn7 -> SetFont(font17);
    btn7 -> SetForegroundColour(MyOrange);
    btn7 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.canminus(1500)) {
            MYMESSAGE("黄金不足");
            return;
        }
        BaoWuChaFiles_Add(AncientVar::BaoWuChaReader, AncientBaoWuCha_ChaHu, 1);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn7,FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("玉杯4件\n2000两黄金"));
    btn8 -> SetFont(font17);
    btn8 -> SetForegroundColour(MyOrange);
    btn8 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!AncientVar::HuangJinReader.canminus(2000)) {
            MYMESSAGE("黄金不足");
            return;
        }
        BaoWuChaFiles_Add(AncientVar::BaoWuChaReader, AncientBaoWuCha_ChaZhan, 4);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn8,FLAG_CENTER);

    vbox -> Add(grid,FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_shopa);
}
void MyFrame::ancient_things_baowu_maichu(WXBTNEVT&){
    MYINIT();

    AncientJinYinZhu_Get(AncientVar::JinYinZhuReader);
    AncientBaoWuResult_Get();
    int YuZhan = YuZhan_Get(AncientVar::YuZhanReader);
    AncientBaoWuCha_Get(AncientVar::BaoWuChaReader);

    MYTITLENS("宝物卖出");
    MYSHOW(wxString(wxT(""))+
        wxT("金珠：")+TOSTR(JinZhu)+wxT("颗\n")+
        wxT("银珠：")+TOSTR(YinZhu)+wxT("颗")
    );

    auto grid = new wxGridSizer(3,3,3,3);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1明珠\n10银珠"));
    btn1 -> SetForegroundColour(MyOrange);
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON, [MingZhu, this](WXBTNEVT& evt){
        if(MingZhu < 1){
            MYMESSAGE("明珠不足");
            return;
        }
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct, AncientBaoWu_MingZhu, -1);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_YinZhu, 10);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("1玉雕\n15银珠"));
    btn2 -> SetForegroundColour(MyOrange);
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON, [YuDiao, this](WXBTNEVT& evt){
        if(YuDiao < 1){
            MYMESSAGE("玉雕不足");
            return;
        }
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct, AncientBaoWu_YuDiao, -1);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_YinZhu, 15);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("1玉璧\n5金珠"));
    btn3 -> SetForegroundColour(MyOrange);
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON, [YuBi, this](WXBTNEVT& evt){
        if(YuBi < 1){
            MYMESSAGE("玉璧不足");
            return;
        }
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct, AncientBaoWu_YuBi, -1);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, 5);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("1绸缎\n1金珠"));
    btn4 -> SetForegroundColour(MyOrange);
    btn4 -> SetFont(font17);
    btn4 -> Bind(wxEVT_BUTTON, [ChouDuan, this](WXBTNEVT& evt){
        if(ChouDuan < 1){
            MYMESSAGE("绸缎不足");
            return;
        }
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct, AncientBaoWu_ChouDuan, -1);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, 1);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("5绸缎\n7金珠"));
    btn5 -> SetForegroundColour(MyOrange);
    btn5 -> SetFont(font17);
    btn5 -> Bind(wxEVT_BUTTON, [ChouDuan, this](WXBTNEVT& evt){
        if(ChouDuan < 5){
            MYMESSAGE("绸缎不足");
            return;
        }
        AncientBaoWuStruct_Write(AncientVar::BaoWuStruct, AncientBaoWu_ChouDuan, -5);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, 7);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("1玉盏\n4金珠"));
    btn6 -> SetForegroundColour(MyOrange);
    btn6 -> SetFont(font17);
    btn6 -> Bind(wxEVT_BUTTON, [YuZhan, this](WXBTNEVT& evt){
        if(YuZhan < 1){
            MYMESSAGE("玉盏不足");
            return;
        }
        YuZhan_Write(AncientVar::YuZhanReader, -1);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, 4);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("1玉壶\n7金珠"));
    btn7 -> SetForegroundColour(MyOrange);
    btn7 -> SetFont(font17);
    btn7 -> Bind(wxEVT_BUTTON, [ChaHu, this](WXBTNEVT& evt){
        if(ChaHu < 1){
            MYMESSAGE("玉壶不足");
            return;
        }
        BaoWuChaFiles_Add(AncientVar::BaoWuChaReader, AncientBaoWuCha_ChaHu, -1);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, 7);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("4玉杯\n9金珠"));
    btn8 -> SetForegroundColour(MyOrange);
    btn8 -> SetFont(font17);
    btn8 -> Bind(wxEVT_BUTTON, [ChaZhan, this](WXBTNEVT& evt){
        if(ChaZhan < 4){
            MYMESSAGE("玉杯不足");
            return;
        }
        BaoWuChaFiles_Add(AncientVar::BaoWuChaReader, AncientBaoWuCha_ChaZhan, -4);
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, 9);
        MYMESSAGE("卖出成功");
        this -> ancient_things_baowu_maichu(evt);
    });
    grid -> Add(btn8, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);
    
    MYADDSPACER();

    MYLAST(&MyFrame::ancient_things_baowu);
}
void MyFrame::ancient_things_baowu_show(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("宝物查看");

    AncientBaoWuResult_Get(); // 调用宏，获得MingZhu，YuDiao，YuBi，ChouDuan四个表示数量的变量
    auto YuZhan = YuZhan_Get(AncientVar::YuZhanReader);
    AncientBaoWuCha_Get(AncientVar::BaoWuChaReader);

    auto grid = new wxGridSizer(3,3,5,5);

    MYSHOWNSNCNBM(wxString(wxT("明珠："))+TOSTR(MingZhu)+wxT("颗"),btn1);
    btn1 -> SetForegroundColour(MyOrange);
    grid -> Add(btn1, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("玉雕："))+TOSTR(YuDiao)+wxT("件"),btn2);
    btn2 -> SetForegroundColour(MyOrange);
    grid -> Add(btn2, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("玉璧："))+TOSTR(YuBi)+wxT("块"),btn3);
    btn3 -> SetForegroundColour(MyOrange);
    grid -> Add(btn3, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("绸缎："))+TOSTR(ChouDuan)+wxT("匹"),btn4);
    btn4 -> SetForegroundColour(MyOrange);
    grid -> Add(btn4, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("玉盏："))+TOSTR(YuZhan)+wxT("件"),btn5);
    btn5 -> SetForegroundColour(MyOrange);
    grid -> Add(btn5, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("玉壶："))+TOSTR(ChaHu)+wxT("件"),btn6);
    btn6 -> SetForegroundColour(MyOrange);
    grid -> Add(btn6, FLAG_CENTER);

    grid -> AddSpacer(1); // 使最后一行居中

    MYSHOWNSNCNBM(wxString(wxT("玉杯："))+TOSTR(ChaZhan)+wxT("只"),btn7);
    btn7 -> SetForegroundColour(MyOrange);
    grid -> Add(btn7, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_things_baowu);
}
void MyFrame::tsquare_jinbi_tongqian(WXBTNEVT&){
    MYINIT();

    MYTITLENS("铜钱领取");
    MYSHOW(wxT("金币：")+JinBiReader.read_str());

    auto grid = new wxGridSizer(2,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1金币\n20铜钱"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyDarkRed);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(1)){
            MYMESSAGE("金币不足");
            return;
        }
        AncientVar::TongBiReader.addnum(20);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_tongqian(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("3金币\n65铜钱"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyDarkRed);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(3)){
            MYMESSAGE("金币不足");
            return;
        }
        AncientVar::TongBiReader.addnum(65);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_tongqian(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("6金币\n140铜钱"));
    btn3 -> SetFont(font17);
    btn3 -> SetForegroundColour(MyDarkRed);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(6)){
            MYMESSAGE("金币不足");
            return;
        }
        AncientVar::TongBiReader.addnum(140);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_tongqian(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("12金币\n300铜钱"));
    btn4 -> SetFont(font17);
    btn4 -> SetForegroundColour(MyDarkRed);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(12)){
            MYMESSAGE("金币不足");
            return;
        }
        AncientVar::TongBiReader.addnum(300);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_tongqian(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("24金币\n620铜钱"));
    btn5 -> SetFont(font17);
    btn5 -> SetForegroundColour(MyDarkRed);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(24)){
            MYMESSAGE("金币不足");
            return;
        }
        AncientVar::TongBiReader.addnum(620);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_tongqian(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::tsquare_jinbi);
}
void MyFrame::tsquare_jinbi_baoshi(WXBTNEVT&){
    MYINIT();

    MYTITLENS("宝石领取");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    auto grid = new wxGridSizer(2,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1金币\n5宝石"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyDarkRed);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(1)){
            MYMESSAGE("金币不足");
            return;
        }
        BaoShi::Reader.addnum(5);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_baoshi(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("3金币\n15宝石"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyDarkRed);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(3)){
            MYMESSAGE("金币不足");
            return;
        }
        BaoShi::Reader.addnum(15);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_baoshi(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("6金币\n35宝石"));
    btn3 -> SetFont(font17);
    btn3 -> SetForegroundColour(MyDarkRed);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(6)){
            MYMESSAGE("金币不足");
            return;
        }
        BaoShi::Reader.addnum(35);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_baoshi(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("12金币\n75宝石"));
    btn4 -> SetFont(font17);
    btn4 -> SetForegroundColour(MyDarkRed);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(12)){
            MYMESSAGE("金币不足");
            return;
        }
        BaoShi::Reader.addnum(75);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_baoshi(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("24金币\n155宝石"));
    btn5 -> SetFont(font17);
    btn5 -> SetForegroundColour(MyDarkRed);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(24)){
            MYMESSAGE("金币不足");
            return;
        }
        BaoShi::Reader.addnum(155);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_baoshi(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::tsquare_jinbi);
}
void MyFrame::tsquare_jinbi_yinbi(WXBTNEVT&){
    MYINIT();

    MYTITLENS("银币领取");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    auto grid = new wxGridSizer(2,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("3金币\n10银币"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyDarkRed);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(3)){
            MYMESSAGE("金币不足");
            return;
        }
        YinBiReader.addnum(10);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_yinbi(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("6金币\n25银币"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyDarkRed);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(6)){
            MYMESSAGE("金币不足");
            return;
        }
        YinBiReader.addnum(25);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_yinbi(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("12金币\n55银币"));
    btn3 -> SetFont(font17);
    btn3 -> SetForegroundColour(MyDarkRed);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(12)){
            MYMESSAGE("金币不足");
            return;
        }
        YinBiReader.addnum(55);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_yinbi(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("24金币\n115银币"));
    btn4 -> SetFont(font17);
    btn4 -> SetForegroundColour(MyDarkRed);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(24)){
            MYMESSAGE("金币不足");
            return;
        }
        YinBiReader.addnum(115);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_yinbi(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("36金币\n175银币"));
    btn5 -> SetFont(font17);
    btn5 -> SetForegroundColour(MyDarkRed);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(36)){
            MYMESSAGE("金币不足");
            return;
        }
        YinBiReader.addnum(175);
        MYMESSAGE("领取成功");
        this -> tsquare_jinbi_yinbi(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::tsquare_jinbi);
}
void MyFrame::ancient_shop_guwan(WXBTNEVT& _)
{
    MYINIT();

    MYTITLE("古玩店铺");

    auto grid = new wxGridSizer(4,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("普通古玩\n黄金5两"));
    btn1->SetFont(font17);
    btn1->SetForegroundColour(MyOrange);
    btn1->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.high(5)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(5);
        int luck = getrnd(0,100);
        if(luck<55) {
            MYMESSAGE("很遗憾，买到了假货");
        } else if(luck<90) {
            MYMESSAGE("恭喜获得玉佩*1");
            AncientVar::Guwan::YuPeiReader.addnum(1);
        } else {
            MYMESSAGE("恭喜获得瓷器*1");
            AncientVar::Guwan::CiQiReader.addnum(1);
        }
    });
    grid->Add(btn1,FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("高阶古玩\n黄金10两"));
    btn2->SetFont(font17);
    btn2->SetForegroundColour(MyOrange);
    btn2->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.high(10)) {
            MYMESSAGE("黄金不足");
            return;
        }
        AncientVar::HuangJinReader.minusnum(10);
        int luck = getrnd(0,100);
        if(luck<35) {
            MYMESSAGE("很遗憾，买到了假货");
        } else if(luck<65) {
            MYMESSAGE("恭喜获得玉佩*2");
            AncientVar::Guwan::YuPeiReader.addnum(2);
        } else if(luck<90) {
            MYMESSAGE("恭喜获得瓷器*1");
            AncientVar::Guwan::CiQiReader.addnum(1);
        } else {
            MYMESSAGE("恭喜获得碑刻*1");
            AncientVar::Guwan::ShiBeiReader.addnum(1);
        }
    });
    grid->Add(btn2,FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("珍藏古玩\n黄金30两"));
    btn3->SetFont(font17);
    btn3->SetForegroundColour(MyOrange);
    btn3->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.canminus(30)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck<15) {
            MYMESSAGE("很遗憾，买到了假货");
        } else if(luck<50) {
            MYMESSAGE("恭喜获得玉佩*2");
            AncientVar::Guwan::YuPeiReader.addnum(2);
        } else if(luck<75) {
            MYMESSAGE("恭喜获得瓷器*2");
            AncientVar::Guwan::CiQiReader.addnum(2);
        } else {
            MYMESSAGE("恭喜获得碑刻*1");
            AncientVar::Guwan::ShiBeiReader.addnum(1);
        }
    });
    grid->Add(btn3,FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("茶壶古玩\n黄金20两"));
    btn4->SetFont(font17);
    btn4->SetForegroundColour(MyOrange);
    btn4->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.canminus(20)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck<50) {
            MYMESSAGE("很遗憾，买到了假货");
        } else  {
            MYMESSAGE("恭喜获得茶壶*1");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaHu, 1);
        }
    });
    grid->Add(btn4,FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("茶盏古玩\n黄金30两"));
    btn5->SetFont(font17);
    btn5->SetForegroundColour(MyOrange);
    btn5->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.canminus(30)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck<50) {
            MYMESSAGE("很遗憾，买到了假货");
        } else  {
            MYMESSAGE("恭喜获得茶盏*4");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaZhan, 4);
        }
    });
    grid->Add(btn5,FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("茶具古玩\n黄金35两"));
    btn6->SetFont(font17);
    btn6->SetForegroundColour(MyOrange);
    btn6->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.canminus(35)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck<40) {
            MYMESSAGE("很遗憾，买到了假货");
        } else if(luck<75) {
            MYMESSAGE("恭喜获得茶壶*1");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaHu, 1);
        } else {
            MYMESSAGE("恭喜获得茶盏*4");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaZhan, 4);
        }
    });
    grid->Add(btn6,FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("综合古玩\n黄金50两"));
    btn7->SetFont(font17);
    btn7->SetForegroundColour(MyOrange);
    btn7->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.canminus(50)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int luck = getrnd(0,100);
        if ( luck < 10 ) {
            MYMESSAGE("很遗憾，买到了假货");
        } else if ( luck < 30 ) {
            AncientVar::Guwan::YuPeiReader.addnum(2);
            MYMESSAGE("恭喜获得玉佩*2");
        } else if ( luck < 45 ) {
            AncientVar::Guwan::CiQiReader.addnum(2);
            MYMESSAGE("恭喜获得瓷器*2");
        } else if ( luck < 55 ) {
            AncientVar::Guwan::ShiBeiReader.addnum(1);
            MYMESSAGE("恭喜获得碑刻*1");
        } else if ( luck < 80 ) {
            MYMESSAGE("恭喜获得茶壶*1");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaHu, 1);
        } else {
            MYMESSAGE("恭喜获得茶盏*4");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaZhan, 4);
        }
    });
    grid->Add(btn7,FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("诚信古玩\n黄金70两"));
    btn8->SetFont(font17);
    btn8->SetForegroundColour(MyOrange);
    btn8->Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
        if(!AncientVar::HuangJinReader.canminus(70)) {
            MYMESSAGE("黄金不足");
            return;
        }
        int luck = getrnd(0,100);
        if ( luck < 25 ) {
            AncientVar::Guwan::YuPeiReader.addnum(2);
            MYMESSAGE("恭喜获得玉佩*2");
        } else if ( luck < 45 ) {
            AncientVar::Guwan::CiQiReader.addnum(2);
            MYMESSAGE("恭喜获得瓷器*2");
        } else if ( luck < 55 ) {
            AncientVar::Guwan::ShiBeiReader.addnum(1);
            MYMESSAGE("恭喜获得碑刻*1");
        } else if ( luck < 80 ) {
            MYMESSAGE("恭喜获得茶壶*1");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaHu, 1);
        } else {
            MYMESSAGE("恭喜获得茶盏*4");
            GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaZhan, 4);
        }
    });
    grid->Add(btn8,FLAG_CENTER);

    vbox->Add(grid,FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_shopa,1);

    MYUSE();
}
void MyFrame::ancient_juanzeng_juanxian(WXBTNEVT&){
    MYINIT();

    AncientGuWanCha_Get(AncientVar::Guwan::ChaReader);

    MYTITLENS("古玩捐献");
    MYSHOW(wxString(wxT("捐赠值："))+AncientVar::JuanZeng::Reader.read_str()+NEWLINE+
            wxT("捐赠等级：")+TOSTR(AncientJuanZeng_GetLevel(
                AncientVar::JuanZeng::Reader.read_int()
            ))
    );

    auto grid = new wxGridSizer(2,3,5,5);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1玉佩\n10捐献值+15白银"));
    btn1 -> SetForegroundColour(MyDarkBlue);
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(AncientVar::Guwan::YuPeiReader.read_int() < 1){
            MYMESSAGE("玉佩不足");
            return;
        }
        AncientVar::Guwan::YuPeiReader.minusnum(1);
        AncientVar::JuanZeng::Reader.addnum(10);
        AncientVar::BaiYinReader.addnum(15);
        MYMESSAGE("捐赠成功");
        this -> ancient_juanzeng_juanxian(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("1瓷器\n15捐献值+20白银"));
    btn2 -> SetForegroundColour(MyDarkBlue);
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(AncientVar::Guwan::CiQiReader.read_int() < 1){
            MYMESSAGE("瓷器不足");
            return;
        }
        AncientVar::Guwan::CiQiReader.minusnum(1);
        AncientVar::JuanZeng::Reader.addnum(15);
        AncientVar::BaiYinReader.addnum(20);
        MYMESSAGE("捐赠成功");
        this -> ancient_juanzeng_juanxian(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("1碑刻\n25捐献值+30白银"));
    btn3 -> SetForegroundColour(MyDarkBlue);
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(AncientVar::Guwan::ShiBeiReader.read_int() < 1){
            MYMESSAGE("碑刻不足");
            return;
        }
        AncientVar::Guwan::ShiBeiReader.minusnum(1);
        AncientVar::JuanZeng::Reader.addnum(25);
        AncientVar::BaiYinReader.addnum(30);
        MYMESSAGE("捐赠成功");
        this -> ancient_juanzeng_juanxian(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("1茶壶\n20捐献值+30白银"));
    btn4 -> SetForegroundColour(MyDarkBlue);
    btn4 -> SetFont(font17);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(ChaHu < 1){
            MYMESSAGE("茶壶不足");
            return;
        }
        GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaHu, -1);
        AncientVar::JuanZeng::Reader.addnum(20);
        AncientVar::BaiYinReader.addnum(30);
        MYMESSAGE("捐赠成功");
        this -> ancient_juanzeng_juanxian(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("1茶盏\n5捐献值+5白银"));
    btn5 -> SetForegroundColour(MyDarkBlue);
    btn5 -> SetFont(font17);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(ChaZhan < 1){
            MYMESSAGE("茶盏不足");
            return;
        }
        GuWanChaFiles_Add(AncientVar::Guwan::ChaReader, AncientGuWanCha_ChaZhan, -1);
        AncientVar::JuanZeng::Reader.addnum(5);
        AncientVar::BaiYinReader.addnum(5);
        MYMESSAGE("捐赠成功");
        this -> ancient_juanzeng_juanxian(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_juanzeng);
}
void MyFrame::baoshi_get(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("宝石购买");

    auto grid = new wxGridSizer(2,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("5宝石\n700积分"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyDarkRed);
    btn1 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!JiFenReader.canminus(700)) {
            MYMESSAGE("积分不足");
            return;
        }
        BaoShiReader.addnum(5);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn1,FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("20宝石\n2600积分"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyDarkRed);
    btn2 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!JiFenReader.canminus(2600)) {
            MYMESSAGE("积分不足");
            return;
        }
        BaoShiReader.addnum(20);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn2,FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("50宝石\n6200积分"));
    btn3 -> SetFont(font17);
    btn3 -> SetForegroundColour(MyDarkRed);
    btn3 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!JiFenReader.canminus(6200)) {
            MYMESSAGE("积分不足");
            return;
        }
        BaoShiReader.addnum(50);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn3,FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("5宝石\n10000计算币"));
    btn4 -> SetFont(font17);
    btn4 -> SetForegroundColour(MyDarkRed);
    btn4 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!JiSuanBiReader.canminus(10000)) {
            MYMESSAGE("计算币不足");
            return;
        }
        BaoShiReader.addnum(5);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn4,FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("10宝石\n17000计算币"));
    btn5 -> SetFont(font17);
    btn5 -> SetForegroundColour(MyDarkRed);
    btn5 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT&) {
        if(!JiSuanBiReader.canminus(17000)) {
            MYMESSAGE("计算币不足");
            return;
        }
        BaoShiReader.addnum(10);
        MYMESSAGE("购买成功");
    });
    grid -> Add(btn5,FLAG_CENTER);

    vbox -> Add(grid,FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::baoshi_all);
}
void MyFrame::ancient_wenguan_zhengji(WXBTNEVT& _)
{
    MYINIT();

    MYTITLENS("我的政绩");
    MYSHOW(
        wxString("")+
        wxT("我的政绩：")+
        AncientZhengJiReader.read_str()
    );

    MYBUTTON(btn1,&MyFrame::ancient_zhengji_shengguan,"官升一级");
    MYBUTTON(btn2,&MyFrame::ancient_zhengji_jinjian,"直言进谏");
    MYBUTTON(btn3,&MyFrame::ancient_zhengji_zhenji, "赈济灾民");
    MYBUTTON(btn4,&MyFrame::ancient_zhengji_huilu, "贿赂权贵");
    MYBUTTON(btn5,&MyFrame::ancient_zhengji_miansheng, "进京面圣");

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_wenguan);
}
void MyFrame::tsquare_jinbimh_simple(WXBTNEVT&){
    MYINIT();

    MYTITLENS("普通盲盒");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    auto grid = new wxGridSizer(1,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("基础盲盒\n10金币"));
    btn1 -> SetForegroundColour(MyDarkOrange);
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(10)){
            MYMESSAGE("金币不足");
            return;
        }
        int jifen_get = 500+(getrnd(-5,5)*10);
        int yinbi_get = 15+(getrnd(-5,5));
        JiFenReader.addnum(jifen_get);
        YinBiReader.addnum(yinbi_get);
        MYSTRMESSAGE(
            wxString("")+
            wxT("恭喜获得")+
            TOSTR(jifen_get)+wxT("积分，")+
            TOSTR(yinbi_get)+wxT("银币")
        );
        this -> tsquare_jinbimh_simple(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("高阶盲盒\n20金币"));
    btn2 -> SetForegroundColour(MyDarkOrange);
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(20)){
            MYMESSAGE("金币不足");
            return;
        }
        int jifen_get = 1000+(getrnd(-20,25)*10);
        int yinbi_get = 30+(getrnd(-10,15));
        JiFenReader.addnum(jifen_get);
        YinBiReader.addnum(yinbi_get);
        MYSTRMESSAGE(
            wxString("")+
            wxT("恭喜获得")+
            TOSTR(jifen_get)+wxT("积分，")+
            TOSTR(yinbi_get)+wxT("银币")
        );
        this -> tsquare_jinbimh_simple(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("豪华盲盒\n40金币"));
    btn3 -> SetForegroundColour(MyDarkOrange);
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(40)){
            MYMESSAGE("金币不足");
            return;
        }
        int jifen_get = 1500+(getrnd(-30,40)*10);
        int yinbi_get = 45+(getrnd(-10,15));
        int baoshi_get = 50+(getrnd(-3,4)*5);
        JiFenReader.addnum(jifen_get);
        YinBiReader.addnum(yinbi_get);
        BaoShi::Reader.addnum(baoshi_get);
        MYSTRMESSAGE(
            wxString("")+
            wxT("恭喜获得")+
            TOSTR(jifen_get)+wxT("积分，")+
            TOSTR(yinbi_get)+wxT("银币，")+
            TOSTR(baoshi_get)+wxT("宝石")
        );
        this -> tsquare_jinbimh_simple(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::tsquare_jinbimh);
}
void MyFrame::tsquare_jinbimh_ancient(WXBTNEVT&){
    MYINIT();

    MYTITLENS("古代盲盒");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    auto grid = new wxGridSizer(1,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("基础盲盒\n10金币"));
    btn1 -> SetForegroundColour(MyDarkOrange);
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(10)){
            MYMESSAGE("金币不足");
            return;
        }
        int tongqian_get = 100+(getrnd(-3,3)*5);
        int baiyin_get = 10+(getrnd(-3,3));
        AncientVar::TongBiReader.addnum(tongqian_get);
        AncientVar::BaiYinReader.addnum(baiyin_get);
        MYSTRMESSAGE(
            wxString(wxT("恭喜获得"))+
            TOSTR(tongqian_get)+wxT("枚铜钱，")+
            TOSTR(baiyin_get)+wxT("两白银")
        );
        this -> tsquare_jinbimh_ancient(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("高级盲盒\n20金币"));
    btn2 -> SetForegroundColour(MyDarkOrange);
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(20)){
            MYMESSAGE("金币不足");
            return;
        }
        int tongqian_get = 200+(getrnd(-6,8)*5);
        int baiyin_get = 20+(getrnd(-4,5));
        AncientVar::TongBiReader.addnum(tongqian_get);
        AncientVar::BaiYinReader.addnum(baiyin_get);
        MYSTRMESSAGE(
            wxString(wxT("恭喜获得"))+
            TOSTR(tongqian_get)+wxT("枚铜钱，")+
            TOSTR(baiyin_get)+wxT("两白银")
        );
        this -> tsquare_jinbimh_ancient(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("豪华盲盒\n40金币"));
    btn3 -> SetForegroundColour(MyDarkOrange);
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON,[=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(40)){
            MYMESSAGE("金币不足");
            return;
        }
        int tongqian_get = 200+(getrnd(-6,8)*5);
        int baiyin_get = 20+(getrnd(-4,5));
        int huangjin_get = 5+(getrnd(-1,2));
        AncientVar::TongBiReader.addnum(tongqian_get);
        AncientVar::BaiYinReader.addnum(baiyin_get);
        AncientVar::HuangJinReader.addnum(huangjin_get);
        MYSTRMESSAGE(
            wxString(wxT("恭喜获得"))+
            TOSTR(tongqian_get)+wxT("枚铜钱，")+
            TOSTR(baiyin_get)+wxT("两白银，")+
            TOSTR(huangjin_get)+wxT("两黄金")
        );
        this -> tsquare_jinbimh_ancient(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);
    
    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::tsquare_jinbimh);
}
void MyFrame::tsquare_jinbi_xianbi(WXBTNEVT&){
    MYINIT();

    MYTITLENS("仙币领取");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    auto grid = new wxGridSizer(2,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1金币\n10仙币"));
    btn1 -> SetForegroundColour(MyOrange);
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(1)){
            MYMESSAGE("金币不足");
            return;
        }
        XianBiReader.addnum(10);
        MYMESSAGE("领取成功，获得10仙币");
        this -> tsquare_jinbi_xianbi(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("3金币\n35仙币"));
    btn2 -> SetForegroundColour(MyOrange);
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(3)){
            MYMESSAGE("金币不足");
            return;
        }
        XianBiReader.addnum(35);
        MYMESSAGE("领取成功，获得35仙币");
        this -> tsquare_jinbi_xianbi(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("6金币\n75仙币"));
    btn3 -> SetForegroundColour(MyOrange);
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(6)){
            MYMESSAGE("金币不足");
            return;
        }
        XianBiReader.addnum(75);
        MYMESSAGE("领取成功，获得75仙币");
        this -> tsquare_jinbi_xianbi(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("12金币\n155仙币"));
    btn4 -> SetForegroundColour(MyOrange);
    btn4 -> SetFont(font17);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(12)){
            MYMESSAGE("金币不足");
            return;
        }
        XianBiReader.addnum(155);
        MYMESSAGE("领取成功，获得155仙币");
        this -> tsquare_jinbi_xianbi(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("24金币\n305仙币"));
    btn5 -> SetForegroundColour(MyOrange);
    btn5 -> SetFont(font17);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!JinBiReader.canminus(24)){
            MYMESSAGE("金币不足");
            return;
        }
        XianBiReader.addnum(305);
        MYMESSAGE("领取成功，获得305仙币");
        this -> tsquare_jinbi_xianbi(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::tsquare_jinbi);
}
void MyFrame::xianji_get(WXBTNEVT&){
    MYINIT();

    MYTITLENS("仙籍购买");
    MYSHOW(wxString(wxT("仙籍："))+XianJi::Reader.read_str()+wxT("本"));

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("5仙籍\n2仙币"));
    btn1 -> SetForegroundColour(MyDarkRed);
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(2)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(5);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("12仙籍\n4仙币"));
    btn2 -> SetForegroundColour(MyDarkRed);
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(4)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(12);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("25仙籍\n8仙币"));
    btn3 -> SetForegroundColour(MyDarkRed);
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(8)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(25);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("55仙籍\n16仙币"));
    btn4 -> SetForegroundColour(MyDarkRed);
    btn4 -> SetFont(font17);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(16)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(55);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("110仙籍\n30仙币"));
    btn5 -> SetForegroundColour(MyDarkRed);
    btn5 -> SetFont(font17);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(30)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(110);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("225仙籍\n60仙币"));
    btn6 -> SetForegroundColour(MyDarkRed);
    btn6 -> SetFont(font17);
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(60)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(225);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("340仙籍\n90仙币"));
    btn7 -> SetForegroundColour(MyDarkRed);
    btn7 -> SetFont(font17);
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(90)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(340);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("455仙籍\n120仙币"));
    btn8 -> SetForegroundColour(MyDarkRed);
    btn8 -> SetFont(font17);
    btn8 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianBiReader.canminus(120)){
            MYMESSAGE("仙币不足");
            return;
        }
        XianJi::Reader.addnum(455);
        MYMESSAGE("购买成功");
        this -> xianji_get(evt);
    });
    grid -> Add(btn8, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xianji);
}
void MyFrame::xianji_use_fali(WXBTNEVT&){
    MYINIT();

    MYTITLENS("增强法力");
    MYSHOW(wxString(wxT("仙籍："))+XianJi::Reader.read_str()+wxT("本"));

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("2仙籍\n15法力"));
    MYSHOPBUTTON(btn1,MyOrange);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(2)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(15);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("4仙籍\n35法力"));
    MYSHOPBUTTON(btn2,MyOrange);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(4)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(35);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("8仙籍\n75法力"));
    MYSHOPBUTTON(btn3,MyOrange);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(8)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(75);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("16仙籍\n155法力"));
    MYSHOPBUTTON(btn4,MyOrange);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(16)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(155);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("24仙籍\n235法力"));
    MYSHOPBUTTON(btn5,MyOrange);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(24)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(235);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("32仙籍\n415法力"));
    MYSHOPBUTTON(btn6,MyOrange);
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(32)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(415);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("48仙籍\n575法力"));
    MYSHOPBUTTON(btn7,MyOrange);
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(48)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(575);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("64仙籍\n835法力"));
    MYSHOPBUTTON(btn8,MyOrange);
    btn8 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(64)){
            MYMESSAGE("仙籍不足");
            return;
        }
        FaLiReader.addnum(835);
        MYMESSAGE("兑换成功");
        this -> xianji_use_fali(evt);
    });
    grid -> Add(btn8, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xianji_use);
}
void MyFrame::xianji_use_xianqi(WXBTNEVT&){
    MYINIT();

    MYTITLENS("增强仙器");
    MYSHOW(wxString(wxT("仙籍："))+XianJi::Reader.read_str()+wxT("本"));

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("2仙籍\n10仙器法力"));
    MYSHOPBUTTON(btn1,MyDarkOrange);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(2)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(10);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("4仙籍\n25仙器法力"));
    MYSHOPBUTTON(btn2,MyDarkOrange);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(4)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(25);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("8仙籍\n55仙器法力"));
    MYSHOPBUTTON(btn3,MyDarkOrange);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(8)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(55);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("15仙籍\n110仙器法力"));
    MYSHOPBUTTON(btn4,MyDarkOrange);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(15)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(110);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("30仙籍\n225仙器法力"));
    MYSHOPBUTTON(btn5,MyDarkOrange);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(30)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(225);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("60仙籍\n555仙器法力"));
    MYSHOPBUTTON(btn6,MyDarkOrange);
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(60)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(555);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("90仙籍\n785仙器法力"));
    MYSHOPBUTTON(btn7,MyDarkOrange);
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(90)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(785);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("90仙籍\n785仙器法力"));
    MYSHOPBUTTON(btn8,MyDarkOrange);
    btn8 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!XianJi::Reader.canminus(90)){
            MYMESSAGE("仙籍不足");
            return;
        }
        XianQiFaLiReader.addnum(785);
        MYMESSAGE("兑换成功");
        this -> xianji_use_xianqi(evt);
    });
    grid -> Add(btn8, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xianji_use);
}
void MyFrame::fali_xiandan(WXBTNEVT&){
    MYINIT();

    MYTITLENS("炼制仙丹");
    MYSHOW(wxString(wxT("法力："))+FaLiReader.read_str());

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("20法力\n1粒普通丹"));
    MYSHOPBUTTON(btn1,MyDarkBlue);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(20)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::PuTong.addnum(1);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("60法力\n3粒普通丹"));
    MYSHOPBUTTON(btn2,MyDarkBlue);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(60)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::PuTong.addnum(3);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("130法力\n7粒普通丹"));
    MYSHOPBUTTON(btn3,MyDarkBlue);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(130)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::PuTong.addnum(7);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("45法力\n1粒碧丹"));
    MYSHOPBUTTON(btn4,MyDarkBlue);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(45)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::Bi.addnum(1);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("135法力\n3粒碧丹"));
    MYSHOPBUTTON(btn5,MyDarkBlue);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(135)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::Bi.addnum(3);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = new wxButton(panel,wxID_ANY,wxT("300法力\n7粒碧丹"));
    MYSHOPBUTTON(btn6,MyDarkBlue);
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(300)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::Bi.addnum(7);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = new wxButton(panel,wxID_ANY,wxT("100法力\n1粒青丹"));
    MYSHOPBUTTON(btn7,MyDarkBlue);
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(100)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::Qing.addnum(1);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = new wxButton(panel,wxID_ANY,wxT("300法力\n3粒青丹"));
    MYSHOPBUTTON(btn8,MyDarkBlue);
    btn8 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(300)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::Qing.addnum(3);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn8, FLAG_CENTER);

    auto btn9 = new wxButton(panel,wxID_ANY,wxT("680法力\n7粒青丹"));
    MYSHOPBUTTON(btn9,MyDarkBlue);
    btn9 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
        if(!FaLiReader.canminus(680)){
            MYMESSAGE("法力不足");
            return;
        }
        Xian::Dan::Qing.addnum(7);
        MYMESSAGE("炼丹成功");
        this -> fali_xiandan(evt);
    });
    grid -> Add(btn9, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::fali);
}
void MyFrame::xianqi_liandan(WXBTNEVT&){
  MYINIT();

  MYTITLE("仙器炼丹");

  auto grid = new wxGridSizer(3,3,4,4);

  auto btn1 = new wxButton(panel,wxID_ANY,wxT("10仙器法力+2普通丹\n1碧丹"));
  MYSHOPBUTTON(btn1, MyDarkOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(10)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::PuTong.high(2)){
      MYMESSAGE("普通丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(10);
    Xian::Dan::PuTong.minusnum(2);
    Xian::Dan::Bi.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn1, FLAG_CENTER);
  
  auto btn2 = new wxButton(panel,wxID_ANY,wxT("15仙器法力+2碧丹\n1青丹"));
  MYSHOPBUTTON(btn2, MyDarkOrange);
  btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(15)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Bi.high(2)){
      MYMESSAGE("碧丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(15);
    Xian::Dan::Bi.minusnum(2);
    Xian::Dan::Qing.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn2, FLAG_CENTER);

  auto btn3 = new wxButton(panel,wxID_ANY,wxT("20仙器法力+2青丹\n1紫丹"));
  MYSHOPBUTTON(btn3, MyDarkOrange);
  btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(20)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Qing.high(2)){
      MYMESSAGE("青丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(20);
    Xian::Dan::Qing.minusnum(2);
    Xian::Dan::Zi.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn3, FLAG_CENTER);
  
  auto btn4 = new wxButton(panel,wxID_ANY,wxT("25仙器法力+2紫丹\n1五色丹"));
  MYSHOPBUTTON(btn4, MyDarkOrange);
  btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(25)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Zi.high(2)){
      MYMESSAGE("紫丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(25);
    Xian::Dan::Zi.minusnum(2);
    Xian::Dan::WuSe.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn4, FLAG_CENTER);

  auto btn7 = new wxButton(panel,wxID_ANY,wxT("40仙器法力+4紫丹\n2五色丹"));
  MYSHOPBUTTON(btn7, MyDarkOrange);
  btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(40)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Zi.high(4)){
      MYMESSAGE("紫丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(40);
    Xian::Dan::Zi.minusnum(4);
    Xian::Dan::WuSe.addnum(2);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn7, FLAG_CENTER);

  auto btn5 = new wxButton(panel,wxID_ANY,wxT("30仙器法力+2五色丹\n1银丹"));
  MYSHOPBUTTON(btn5, MyDarkOrange);
  btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(30)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::WuSe.high(2)){
      MYMESSAGE("五色丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(30);
    Xian::Dan::WuSe.minusnum(2);
    Xian::Dan::Yin.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn5, FLAG_CENTER);
  
  auto btn6 = new wxButton(panel,wxID_ANY,wxT("50仙器法力+4五色丹\n2银丹"));
  MYSHOPBUTTON(btn6, MyDarkOrange);
  btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(50)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::WuSe.high(4)){
      MYMESSAGE("五色丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(50);
    Xian::Dan::WuSe.minusnum(4);
    Xian::Dan::Yin.addnum(2);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn6, FLAG_CENTER);  
  
  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianqi);
}
void MyFrame::xianji_liandan(WXBTNEVT&){
  MYINIT();

  MYTITLE("仙籍炼丹");

  auto grid = new wxGridSizer(2,3,4,4);

  auto btn1 = new wxButton(panel,wxID_ANY,wxT("10仙籍+2银丹\n1金丹"));
  MYSHOPBUTTON(btn1, MyOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(10)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(2)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(10);
    Xian::Dan::Yin.minusnum(2);
    Xian::Dan::Jin.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn1, FLAG_CENTER);

  auto btn2 = new wxButton(panel,wxID_ANY,wxT("20仙籍+4银丹\n2金丹"));
  MYSHOPBUTTON(btn2, MyOrange);
  btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(20)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(4)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(20);
    Xian::Dan::Yin.minusnum(4);
    Xian::Dan::Jin.addnum(2);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn2, FLAG_CENTER);

  auto btn3 = new wxButton(panel,wxID_ANY,wxT("35仙籍+8银丹\n4金丹"));
  MYSHOPBUTTON(btn3, MyOrange);
  btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(35)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(8)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(35);
    Xian::Dan::Yin.minusnum(8);
    Xian::Dan::Jin.addnum(4);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn3, FLAG_CENTER);

  auto btn4 = new wxButton(panel,wxID_ANY,wxT("60仙籍+16银丹\n8金丹"));
  MYSHOPBUTTON(btn4, MyOrange);
  btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(60)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(16)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(60);
    Xian::Dan::Yin.minusnum(16);
    Xian::Dan::Jin.addnum(8);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn4, FLAG_CENTER);

  auto btn5 = new wxButton(panel,wxID_ANY,wxT("20仙籍+2金丹\n1神丹"));
  MYSHOPBUTTON(btn5, MyOrange);
  btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(20)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Jin.high(2)){
      MYMESSAGE("金丹不足");
      return;
    }
    XianJi::Reader.minusnum(20);
    Xian::Dan::Jin.minusnum(2);
    Xian::Dan::Shen.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn5, FLAG_CENTER);

  auto btn6 = new wxButton(panel,wxID_ANY,wxT("55仙籍+6金丹\n3神丹"));
  MYSHOPBUTTON(btn6, MyOrange);
  btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(55)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Jin.high(6)){
      MYMESSAGE("金丹不足");
      return;
    }
    XianJi::Reader.minusnum(55);
    Xian::Dan::Jin.minusnum(6);
    Xian::Dan::Shen.addnum(3);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn6, FLAG_CENTER);

  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianji);
}
void MyFrame::xiandan_he_yindan(WXBTNEVT&){
    MYINIT();

    MYTITLE("银丹召鹤");

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1银丹召鹤"));
    MYSHOPBUTTON(btn1, MyDarkBlue);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(1)){
            MYMESSAGE("银丹不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck < 20){
            MYMESSAGE("召鹤成功，获得650积分+80金币");
            JiFenReader.addnum(650);
            JinBiReader.addnum(80);
        } else {
            MYMESSAGE("召鹤成功，获得500积分+50金币");
            JiFenReader.addnum(500);
            JinBiReader.addnum(50);
        }
    });
    vbox -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("3银丹召鹤"));
    MYSHOPBUTTON(btn2, MyDarkBlue);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(3)){
            MYMESSAGE("银丹不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck < 40){
            MYMESSAGE("召鹤成功，获得700积分+90金币");
            JiFenReader.addnum(700);
            JinBiReader.addnum(90);
        } else {
            MYMESSAGE("召鹤成功，获得550积分+55金币");
            JiFenReader.addnum(550);
            JinBiReader.addnum(55);
        }
    });
    vbox -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("5银丹召鹤"));
    MYSHOPBUTTON(btn3, MyDarkBlue);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(5)){
            MYMESSAGE("银丹不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck < 70){
            MYMESSAGE("召鹤成功，获得750积分+100金币");
            JiFenReader.addnum(750);
            JinBiReader.addnum(100);
        } else {
            MYMESSAGE("召鹤成功，获得600积分+60金币");
            JiFenReader.addnum(600);
            JinBiReader.addnum(60);
        }
    });
    vbox -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("10银丹召鹤"));
    MYSHOPBUTTON(btn4, MyDarkBlue);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(10)){
            MYMESSAGE("银丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得800积分+110金币");
        JiFenReader.addnum(800);
        JinBiReader.addnum(110);
    });
    vbox -> Add(btn4, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan_he);
}
void MyFrame::xiandan_he_jindan(WXBTNEVT&){
  MYINIT();

  MYTITLE("金丹召鹤");

  auto btn1 = new wxButton(panel, wxID_ANY, wxT("1金丹召鹤"));
  MYSHOPBUTTON(btn1, MyDarkOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(1) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    if(luck < 40) {
      MYMESSAGE("召鹤成功，获得1000积分+50金币");
      JiFenReader.addnum(1000);
      JinBiReader.addnum(50);
    } else {
      MYMESSAGE("召鹤成功，获得900积分+40金币");
      JiFenReader.addnum(900);
      JinBiReader.addnum(40);
    }
  });
  vbox -> Add(btn1, FLAG_CENTER);

  auto btn2 = new wxButton(panel, wxID_ANY, wxT("3金丹召鹤"));
  MYSHOPBUTTON(btn2, MyDarkOrange);
  btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(3) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    if(luck < 60) {
      MYMESSAGE("召鹤成功，获得1100积分+80金币");
      JiFenReader.addnum(1100);
      JinBiReader.addnum(80);
    } else {
      MYMESSAGE("召鹤成功，获得1000积分+60金币");
      JiFenReader.addnum(1000);
      JinBiReader.addnum(60);
    }
  });
  vbox -> Add(btn2, FLAG_CENTER);

  auto btn3 = new wxButton(panel, wxID_ANY, wxT("5金丹召鹤"));
  MYSHOPBUTTON(btn3, MyDarkOrange);
  btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(5) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    MYMESSAGE("召鹤成功，获得1300积分+100金币");
    JiFenReader.addnum(1300);
    JinBiReader.addnum(100);
  });
  vbox -> Add(btn3, FLAG_CENTER);

  auto btn4 = new wxButton(panel, wxID_ANY, wxT("10金丹召鹤"));
  MYSHOPBUTTON(btn4, MyDarkOrange);
  btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(10) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    MYMESSAGE("召鹤成功，获得2700积分+220金币");
    JiFenReader.addnum(2700);
    JinBiReader.addnum(220);
  });
  vbox -> Add(btn4, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xiandan_he);
}
void MyFrame::xiandan_he_shendan(WXBTNEVT&){
    MYINIT();

    MYTITLE("神丹召鹤");

    auto btn1 = new wxButton(panel, wxID_ANY, wxT("1神丹召鹤"));
    MYSHOPBUTTON(btn1, MyRed);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(1)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得1500积分+500仙币+40金币");
        JiFenReader.addnum(1500);
        XianBiReader.addnum(500);
        JinBiReader.addnum(40);
    });
    vbox -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel, wxID_ANY, wxT("2神丹召鹤"));
    MYSHOPBUTTON(btn2, MyRed);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(2)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得3000积分+1000仙币+85金币");
        JiFenReader.addnum(3000);
        XianBiReader.addnum(1000);
        JinBiReader.addnum(85);
    });
    vbox -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel, wxID_ANY, wxT("3神丹召鹤"));
    MYSHOPBUTTON(btn3, MyRed);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(3)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得4600积分+1500仙币+130金币");
        JiFenReader.addnum(4600);
        XianBiReader.addnum(1500);
        JinBiReader.addnum(130);
    });
    vbox -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel, wxID_ANY, wxT("6神丹召鹤"));
    MYSHOPBUTTON(btn4, MyRed);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(6)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得9300积分+3000仙币+270金币");
        JiFenReader.addnum(9300);
        XianBiReader.addnum(3000);
        JinBiReader.addnum(270);
    });
    vbox -> Add(btn4, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan_he);
}
