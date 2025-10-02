#include <headers.hpp>

void MyFrame::start()
{
    // lmut t = BigInt(Bank::BankStore.Read());
    // t.Add(BigInt(5));
    // Bank::BankStore.Write(t.toString());
    Bank::BankStore.Add(5);
    Simple::Message(Bank::BankStore.Read());
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
    MYBUTTON(button7,&MyFrame::bank_square,"积分银行");
    button7 -> SetFont(font19);

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
    MYBUTTON(btn4,&MyFrame::ancient_guan,"我的官职");
    MYBUTTON(btn5,&MyFrame::ancient_juanzeng,"我的捐赠");

    MYADDSPACER();

    MYBACKTOMAIN();

    MYUSE();
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
void MyFrame::xiandan_he(WXBTNEVT&){
    MYINIT();
  
    MYTITLE("仙丹召鹤");

    MYBUTTON(btn1, &MyFrame::xiandan_he_yindan, "银丹召鹤");
    MYBUTTON(btn2, &MyFrame::xiandan_he_jindan, "金丹召鹤");
    MYBUTTON(btn3, &MyFrame::xiandan_he_shendan, "神丹召鹤");
  
    MYADDSPACER();
  
    MYLAST(&MyFrame::xiandan);
}
void MyFrame::ancient_wuguan_show(WXBTNEVT&){
    MYINIT();

    MYTITLE("查看士兵");

    auto grid = new wxGridSizer(3,3,5,5);

    MYSHOWNSNBM(
        wxString(wxT("新兵："))+AncientVar::WuGuan::LiLiang::Xin.read_str()+wxT("人"), 
        btn0, MyDarkRed
    );
    grid -> Add(btn0);

    MYSHOWNSNBM(
        wxString(wxT("普通兵："))+AncientVar::WuGuan::LiLiang::PuTong.read_str()+wxT("人"), 
        btn1, MyDarkRed
    );
    grid -> Add(btn1);

    MYSHOWNSNBM(
        wxString(wxT("初级兵："))+AncientVar::WuGuan::LiLiang::ChuJi.read_str()+wxT("人"), 
        btn2, MyDarkRed
    );
    grid -> Add(btn2);

    MYSHOWNSNBM(
        wxString(wxT("中级兵："))+AncientVar::WuGuan::LiLiang::ZhongJi.read_str()+wxT("人"), 
        btn3, MyDarkRed
    );
    grid -> Add(btn3);

    MYSHOWNSNBM(
        wxString(wxT("高级兵："))+AncientVar::WuGuan::LiLiang::GaoJi.read_str()+wxT("人"), 
        btn4, MyDarkRed
    );
    grid -> Add(btn4);

    MYSHOWNSNBM(
        wxString(wxT("精锐兵："))+AncientVar::WuGuan::LiLiang::JingRui.read_str()+wxT("人"), 
        btn5, MyDarkRed
    );
    grid -> Add(btn5);

    MYSHOWNSNBM(
        wxString(wxT("王牌兵："))+AncientVar::WuGuan::LiLiang::WangPai.read_str()+wxT("人"), 
        btn6, MyDarkRed
    );
    grid -> Add(btn6);

    MYSHOWNSNBM(
        wxString(wxT("神级兵："))+AncientVar::WuGuan::LiLiang::ShenJi.read_str()+wxT("人"), 
        btn7, MyDarkRed
    );
    grid -> Add(btn7);

    vbox -> Add(grid, FLAG_CENTER);

    MYEND(&MyFrame::ancient_wuguan_1);
}
