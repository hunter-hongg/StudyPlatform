#include <headers.hpp>

void MyFrame::all_thing_all(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("所有物品");

    MYBUTTON(button1,&MyFrame::things_all,"物品查看");
    MYBUTTON(button3,&MyFrame::things_shop,"物品商店");
    MYBUTTON(button5,&MyFrame::things_other,"物品主页");

    MYADDSPACER();

    MYBACK(&MyFrame::mine,1);

    MYUSE();
}
void MyFrame::card_all(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("所有卡牌");

    MYBUTTON(button1,&MyFrame::card1,"三国卡牌1");
    MYBUTTON(button2,&MyFrame::card2,"汉朝卡牌1");

    MYADDSPACER();

    MYBACK(&MyFrame::things_other,1);

    MYUSE();
}
void MyFrame::things_shop(WXBTNEVT& evt)
{
    MYINIT();

    MYTITLE("物品商城");

    auto gsizer = new wxGridSizer(3,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("三国卡牌1*3\n50积分"));
    btn1->SetFont(font17);
    btn1->SetForegroundColour(MyRed);
    btn1->Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        (void)evt;
        if(JiFenReader.read_int()<50) {
            MYMESSAGE("积分不足");
            return;
        }
        JiFenReader.minusnum(50);
        std::deque<int> ans=GetRandom(0,46 - 1,3);
        std::deque<std::string> realname;
        for(const auto& i : ans) {
            CardSanGuo1.Write(i);
            realname.push_back(CardSanGuo1[i]);
        }
        std::string showstr="恭喜获得卡牌：\n";
        for(const auto& i : realname) {
            showstr += i;
            showstr += " - 稀有\n";
        }
        MYSTRMESSAGE(wxString::FromUTF8(showstr.c_str()));
    });
    gsizer->Add(btn1,FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("仙币*10\n400积分"));
    btn2->SetFont(font17);
    btn2->SetForegroundColour(MyRed);
    btn2->Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        (void)evt;
        if(!JiFenReader.high(400)) {
            MYMESSAGE("积分不足");
            return;
        }
        JiFenReader.minusnum(400);
        XianBiReader.addnum(10);
        MYMESSAGE("兑换成功");
    });
    gsizer->Add(btn2,FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("法力*70\n450积分"));
    btn3->SetFont(font17);
    btn3->SetForegroundColour(MyRed);
    btn3->Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        (void)evt;
        if(!JiFenReader.high(450)) {
            MYMESSAGE("积分不足");
            return;
        }
        JiFenReader.minusnum(450);
        FaLiReader.addnum(70);
        MYMESSAGE("兑换成功");
    });
    gsizer->Add(btn3,FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("铜钱*150\n300积分"));
    btn4->SetFont(font17);
    btn4->SetForegroundColour(MyRed);
    btn4->Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        (void)evt;
        if(!JiFenReader.high(300)) {
            MYMESSAGE("积分不足");
            return;
        }
        JiFenReader.minusnum(300);
        AncientVar::TongBiReader.addnum(150);
        MYMESSAGE("兑换成功");
    });
    gsizer->Add(btn4,FLAG_CENTER);

    auto btn5 = new wxButton(panel,wxID_ANY,wxT("金币*3\n300积分"));
    btn5->SetFont(font17);
    btn5->SetForegroundColour(MyRed);
    btn5->Bind(wxEVT_BUTTON,[this](WXBTNEVT&) {
        if(!JiFenReader.canminus(300)) {
            MYMESSAGE("积分不足");
            return;
        }
        JinBiReader.addnum(3);
        MYMESSAGE("兑换成功");
    });
    gsizer->Add(btn5,FLAG_CENTER);

    vbox->Add(gsizer,FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::all_thing_all,1);

    MYUSE();
}
void MyFrame::calc_square(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("计算广场");
    MYSHOW(wxString(wxT("计算币："))+JiSuanBiReader.read_str());

    MYBUTTON(btn1,&MyFrame::calcs_normal,"计算币获得");
    MYBUTTON(btn2,&MyFrame::calcs_shop,"计算币商城");

    MYADDSPACER();

    MYBACKTOMAIN();

    MYUSE();
}
void MyFrame::calcs_normal(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("计算币获得");
    MYSHOW(wxString(wxT("计算币："))+JiSuanBiReader.read_str());

    MYBUTTON(btn1,&MyFrame::calcs_normal_a1,"加减练习");
    MYBUTTON(btn2,&MyFrame::calcs_normal_a2,"乘法练习");
    MYBUTTON(btn3,&MyFrame::calcs_normal_a3,"除法练习");
    MYBUTTON(btn4,&MyFrame::calcs_normal_a4,"因式分解");

    MYADDSPACER();

    MYBACK(&MyFrame::calc_square,1);

    MYUSE();
}
void MyFrame::calcs_shop(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("计算币商城");
    MYSHOW(wxString(wxT("计算币："))+JiSuanBiReader.read_str());

    auto grid = new wxGridSizer(4,3,4,4);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("积分*10\n200计算币"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyOrange);
    btn1 -> Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        if(!JiSuanBiReader.high(200)) {
            MYMESSAGE("计算币不足");
            return;
        }
        JiSuanBiReader.minusnum(200);
        JiFenReader.addnum(10);
        MYMESSAGE("兑换成功");
        this -> calcs_shop(evt);
    });
    grid -> Add(btn1,FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("铜钱*500\n300计算币"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyOrange);
    btn2 -> Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        if(!JiSuanBiReader.high(300)) {
            MYMESSAGE("计算币不足");
            return;
        }
        JiSuanBiReader.minusnum(300);
        AncientVar::TongBiReader.addnum(500);
        MYMESSAGE("兑换成功");
        this -> calcs_shop(evt);
    });
    grid -> Add(btn2,FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("汉朝卡牌1*1\n1500计算币"));
    btn3->SetFont(font17);
    btn3->SetForegroundColour(MyOrange);
    btn3->Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        if(!JiSuanBiReader.high(1500)) {
            MYMESSAGE("计算币不足");
            return;
        }
        JiSuanBiReader.minusnum(1500);
        int res = getrnd(0,45);
        std::string showstr="恭喜获得卡牌：\n";
        showstr += CardHan1[res];
        showstr += " - 珍藏";
        MYSTRMESSAGE(wxString::FromUTF8(showstr));
        CardHan1.Write(res);
        this -> calcs_shop(evt);
    });
    grid->Add(btn3,FLAG_CENTER);

    auto btn4 = new wxButton(panel,wxID_ANY,wxT("金币*2\n300计算币"));
    btn4 -> SetFont(font17);
    btn4 -> SetForegroundColour(MyOrange);
    btn4 -> Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt) {
        if(!JiSuanBiReader.canminus(300)) {
            MYMESSAGE("计算币不足");
            return;
        }
        JinBiReader.addnum(2);
        MYMESSAGE("兑换成功");
        this -> calcs_shop(evt);
    });
    grid -> Add(btn4,FLAG_CENTER);

    vbox->Add(grid,FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::calc_square,1);

    MYUSE();
}
void MyFrame::fali(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("我的法力");
    MYSHOW(wxString(wxT("法力："))+FaLiReader.read_str()+NEWLINE+
           wxT("等级：")+TOSTR(
               getlevel(FaLiReader.read_int())
           ));

    MYBUTTON(btn1,&MyFrame::fali_xianbi,"仙币增强");
    MYBUTTON(btn2,&MyFrame::fali_xiandan, "炼制仙丹");

    MYADDSPACER();

    MYBACK(&MyFrame::xianbi_square_2,1);

    MYUSE();
}
void MyFrame::xianbi_square(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("中国神话传说");
    MYSHOW(wxString(wxT("仙币："))+XianBiReader.read_str());

    MYBUTTON(btn_1, &MyFrame::xianbi_square_1, "我的物品");
    MYBUTTON(btn_5, &MyFrame::xianbi_square_2, "我的能力");
    MYBUTTON(btn5,&MyFrame::xianlu, "我的仙禄");
    
    MYADDSPACER();

    MYBACKTOMAIN();
    MYUSE();
}
void MyFrame::ancient_clothes(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("我的衣着");

    MYBUTTON(btn1,&MyFrame::ancient_clothes_sword,"我的佩剑");
    MYBUTTON(btn2,&MyFrame::ancient_clothes_pao,"我的锦袍");

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_things,1);

    MYUSE();
}
void MyFrame::ancient_things_money(WXBTNEVT& _)
{
    MYINIT();

    AncientJinYinZhu_Get(AncientVar::JinYinZhuReader);

    MYTITLE("我的财物");

    MYSHOWNSNCM(wxString(wxT("铜钱："))+AncientVar::TongBiReader.read_str()+wxT("枚"),tongbi_show);
    tongbi_show->SetForegroundColour(MyOrange);

    MYSHOWNSNCM(wxString(wxT("白银："))+AncientVar::BaiYinReader.read_str()+wxT("两"),baiyin_show);
    baiyin_show->SetForegroundColour(MyOrange);

    MYSHOWNSNCM(wxString(wxT("黄金："))+AncientVar::HuangJinReader.read_str()+wxT("两"),huangjin_show);
    huangjin_show->SetForegroundColour(MyOrange);

    MYSHOWNSNCM(wxString(wxT("金珠："))+TOSTR(JinZhu)+wxT("颗"),jinzhu_show);
    jinzhu_show->SetForegroundColour(MyOrange);

    MYSHOWNSNCM(wxString(wxT("银珠："))+TOSTR(YinZhu)+wxT("颗"),yinzhu_show);
    yinzhu_show->SetForegroundColour(MyOrange);

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_things,1);

    MYUSE();
}
void MyFrame::ancient_things_guwan(WXBTNEVT& _)
{
    MYINIT();

    AncientGuWanCha_Get(AncientVar::Guwan::ChaReader);

    MYTITLE("我的古玩");

    auto grid = new wxGridSizer(3,2,3,3);

    MYSHOWNSNCNBM(wxString(wxT("瓷器："))+AncientVar::Guwan::CiQiReader.read_str()+wxT("件"),ciqi_show);
    ciqi_show->SetForegroundColour(MyOrange);
    grid -> Add(ciqi_show, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("碑刻："))+AncientVar::Guwan::ShiBeiReader.read_str()+wxT("件"),beike_show);
    beike_show->SetForegroundColour(MyOrange);
    grid -> Add(beike_show, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("玉佩："))+AncientVar::Guwan::YuPeiReader.read_str()+wxT("件"),yupei_show);
    yupei_show->SetForegroundColour(MyOrange);
    grid -> Add(yupei_show, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("茶壶："))+TOSTR(ChaHu)+wxT("件"), chahu_show);
    chahu_show->SetForegroundColour(MyOrange);
    grid -> Add(chahu_show, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("茶盏："))+TOSTR(ChaZhan)+wxT("只"), chazhan_show);
    chazhan_show->SetForegroundColour(MyOrange);
    grid -> Add(chazhan_show, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_things,1);

    MYUSE();
}
void MyFrame::xianqi(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("我的仙器");
    MYSHOW(wxString(wxT("当前仙器："))+wxString::FromUTF8(swordToString(Other::Sword.get())));

    MYBUTTON(btn1,&MyFrame::xianqi_change,"仙器更换");
    MYBUTTON(btn2,&MyFrame::xianqi_fali,"仙器法力");
    MYBUTTON(btn3,&MyFrame::xianqi_liandan,"仙器炼丹");

    MYADDSPACER();

    MYBACK(&MyFrame::xianbi_square_1,1);

    MYUSE();
}
void MyFrame::xianqi_fali(WXBTNEVT& _)
{
    MYINIT();

    MYTITLENS("仙器法力");
    MYSHOW(wxT("仙器法力：")+XianQiFaLiReader.read_str());

    MYBUTTON(btn1,&MyFrame::xianqi_fali_xianbi,"仙币增强");
    // MYBUTTON(btn2,&MyFrame::xianqi_fali_jisuanbi,"计算币增强");

    MYADDSPACER();

    MYLAST(&MyFrame::xianqi);
}
void MyFrame::ancient_things_baowu(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("我的宝物");

    MYBUTTON(btn1,&MyFrame::ancient_things_baowu_show,"宝物查看");
    MYBUTTON(btn2,&MyFrame::ancient_things_baowu_maichu,"宝物卖出");

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_things);
}
void MyFrame::ancient_wenguan(WXBTNEVT& _)
{
    MYINIT();

    MYTITLENS("我的官位");
    MYSHOW(
        wxString("")+
        wxT("我的类别：文官\n")+
        wxT("我的品级：")+
        TOSTR(AncientWenGuanConfig_ReadLevel(AncientVar::WenGuan::WenGuanConf))+
        wxT("品")
    );

    MYBUTTON(btn1,&MyFrame::ancient_wenguan_fenglu,"我的俸禄");
    MYBUTTON(btn2,&MyFrame::ancient_wenguan_zhengji,"我的政绩");

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_square,1);

    MYUSE();
}
void MyFrame::baoshi_choujiang(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("宝石抽奖");

    MYBUTTON(btn1,&MyFrame::baoshi_choujiang1,"宝石抽奖一");

    MYADDSPACER();

    MYLAST(&MyFrame::baoshi_all);
}
void MyFrame::baoshi_all(WXBTNEVT&)
{
    MYINIT();

    MYTITLENS("我的宝石");
    MYSHOW(wxString("")+wxT("宝石：")+BaoShi::Reader.read_str()+wxT("颗"));

    MYBUTTON(btn1,&MyFrame::baoshi_get,"宝石获得");
    MYBUTTON(btn2,&MyFrame::baoshi_choujiang,"宝石抽奖");

    MYADDSPACER();

    MYLAST(&MyFrame::things_other);
}
void MyFrame::things_other(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("物品主页");

    MYBUTTON(btn2,&MyFrame::baoshi_all,"我的宝石");
    MYBUTTON(btn3,&MyFrame::yinbi_all, "我的银币");
    MYBUTTON(btn1,&MyFrame::card_all,"我的卡牌");
    
    MYADDSPACER();

    MYLAST(&MyFrame::all_thing_all);
}
void MyFrame::ancient_shop_nianjiu(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("拈阄店铺");

    auto grid = new wxGridSizer(3,3,3,3);

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("拈阄店铺一"));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyOrange);
    btn1 -> Bind(wxEVT_BUTTON,&MyFrame::ancient_shop_nianjiu1,this);
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("拈阄店铺二"));
    btn2 -> SetFont(font17);
    btn2 -> SetForegroundColour(MyOrange);
    btn2 -> Bind(wxEVT_BUTTON,&MyFrame::ancient_shop_nianjiu2,this);
    grid -> Add(btn2, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_shopa);
}
void MyFrame::ancient_juanzeng(WXBTNEVT&){
    MYINIT();

    MYTITLENS("我的捐赠");
    MYSHOW(wxString(wxT("捐赠值："))+AncientVar::JuanZeng::Reader.read_str()+NEWLINE+
            wxT("捐赠等级：")+TOSTR(AncientJuanZeng_GetLevel(
                AncientVar::JuanZeng::Reader.read_int()
            ))
    );

    MYBUTTON(btn2,&MyFrame::ancient_juanzeng_juanxian,"捐献古玩");
    MYBUTTON(btn1,&MyFrame::ancient_juanzeng_lingqu,"领取资助");

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_square);
}
void MyFrame::things_square(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("物品领取");

    MYBUTTON(btn1,&MyFrame::tsquare_free,"免费领取");
    MYBUTTON(btn2,&MyFrame::tsquare_jinbi,"金币领取");
    MYBUTTON(btn3,&MyFrame::tsquare_jinbimh, "金币盲盒");

    MYADDSPACER();

    MYBACKTOMAIN();

    MYUSE();
}
void MyFrame::ancient_shopa(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("古代店铺");

    MYBUTTON(btn1,&MyFrame::ancient_shop,"普通店铺");
    MYBUTTON(btn2,&MyFrame::ancient_shop_guwan,"古玩店铺");
    MYBUTTON(btn3,&MyFrame::ancient_shop_baowu,"宝物店铺");
    MYBUTTON(btn4,&MyFrame::ancient_shop_nianjiu,"拈阄店铺");

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_square,1);

    MYUSE();
}
void MyFrame::ancient_things(WXBTNEVT& _)
{
    MYINIT();

    MYTITLE("我的物品");

    MYBUTTON(btn1,&MyFrame::ancient_things_money,"我的财物");
    MYBUTTON(btn5,&MyFrame::ancient_clothes,"我的衣着");
    MYBUTTON(btn2,&MyFrame::ancient_things_guwan,"我的古玩");
    MYBUTTON(btn3,&MyFrame::ancient_things_baowu,"我的宝物");
    MYBUTTON(btn4,&MyFrame::ancient_things_bookshelf,"我的书籍");
    
    MYADDSPACER();

    MYBACK(&MyFrame::ancient_square,1);

    MYUSE();
}
void MyFrame::tsquare_jinbi(WXBTNEVT&){
    MYINIT();

    MYTITLENS("金币领取");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    MYBUTTON(btn1,&MyFrame::tsquare_jinbi_tongqian,"铜钱领取");
    MYBUTTON(btn2,&MyFrame::tsquare_jinbi_baoshi, "宝石领取");
    MYBUTTON(btn3,&MyFrame::tsquare_jinbi_yinbi, "银币领取");
    MYBUTTON(btn4,&MyFrame::tsquare_jinbi_xianbi, "仙币领取");

    MYADDSPACER();

    MYLAST(&MyFrame::things_square);
}
void MyFrame::tsquare_jinbimh(WXBTNEVT&){
    MYINIT();

    MYTITLENS("金币盲盒");
    MYSHOW(wxString(wxT("金币："))+JinBiReader.read_str());

    MYBUTTON(btn1,&MyFrame::tsquare_jinbimh_simple,"普通盲盒");
    MYBUTTON(btn2,&MyFrame::tsquare_jinbimh_ancient,"古代盲盒");

    MYADDSPACER();

    MYLAST(&MyFrame::things_square);
}
void MyFrame::xianji(WXBTNEVT&){
    MYINIT();

    MYTITLENS("我的仙籍");
    MYSHOW(wxString(wxT("仙籍："))+XianJi::Reader.read_str()+wxT("本"));

    MYBUTTON(btn1,&MyFrame::xianji_get,"仙籍购买");
    MYBUTTON(btn2,&MyFrame::xianji_use,"仙籍使用");
    MYBUTTON(btn3,&MyFrame::xianji_liandan,"仙籍炼丹");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square_1);
}
void MyFrame::xianji_use(WXBTNEVT&){
    MYINIT();

    MYTITLENS("仙籍使用");
    MYSHOW(wxString(wxT("仙籍："))+XianJi::Reader.read_str()+wxT("本"));

    MYBUTTON(btn1,&MyFrame::xianji_use_fali,"增强法力");
    MYBUTTON(btn2,&MyFrame::xianji_use_xianqi,"增强仙器");

    MYADDSPACER();

    MYLAST(&MyFrame::xianji);
}
void MyFrame::xiandan(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的仙丹");

    MYBUTTON(btn1,&MyFrame::xiandan_show,"仙丹查看");
    MYBUTTON(btn2,&MyFrame::xiandan_he,"仙丹召鹤");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square_1);
}
void MyFrame::xianlu(WXBTNEVT&){
    MYINIT();
    
    MYTITLENS("我的仙禄");
    MYSHOW(wxString(wxT("仙禄等级："))+Xian::Lu::Ji.read_str());

    MYBUTTON(btn1, &MyFrame::xianlu_next, "仙禄升级");
    MYBUTTON(btn2, &MyFrame::xianlu_get, "领取仙禄");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}

