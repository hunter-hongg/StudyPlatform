#include <headers.hpp>

using namespace Files;
using namespace Card;
using namespace Check;
using std::stringstream;

bool MyApp::OnInit()
{
    int const A=710;
    MyFrame *frame = new MyFrame(wxT("学习平台"), wxPoint(0,0), wxSize(A,A));
    frame->Show(true);
    return true;
}

void MyFrame::clean_panel()
{
    if (!panel) return;
    wxSizer* sizer = panel->GetSizer();
    if (!sizer) return;
    wxSizerItemList& items = sizer->GetChildren();
    for (wxSizerItemList::iterator it = items.begin(); it != items.end(); ++it) {
        wxSizerItem* item = *it;
        if (item->IsWindow()) {
            wxWindow* window = item->GetWindow();
            if (window) {
                if (wxStaticText* staticText = wxDynamicCast(window, wxStaticText)) {
                    staticText->SetLabel(wxT(""));
                }
            }
        }
    }
    sizer->Clear(true);
    panel->SetSizer(sizer);
    panel->Layout();
}
void MyFrame::study_start(WXBTNEVT& evt)
{
    (void)evt;
    if(study_timer.start()) {
        MYMESSAGE("开始计时失败");
        logfile << "ERROR: 开始计时失败" << Endline;
        return;
    }
    MYMESSAGE("开始计时成功");
    logfile << "INFO: 成功开始计时" << Endline;
}

void MyFrame::study_end(WXBTNEVT& evt)
{
    (void)evt;
    if(study_timer.stop()) {
        MYMESSAGE("结束计时失败");
        logfile << "ERROR: 结束计时失败" << Endline;
        return;
    }
    long long spend = study_timer.get_seconds();
    long long spend_minutes = to_minutes(spend);
    int get_jifen = jifen::get_from_minutes(spend_minutes);
    JiFenReader.addnum(get_jifen);

    stringstream tmpa;
    tmpa << "结束计时成功，本次计时" << spend << "秒，" << NEWLINE
         << "去尾得" << spend_minutes << "分钟，" << NEWLINE
         << "获得" << get_jifen << "积分";
    MYSTRMESSAGE(wxString::FromUTF8(tmpa.str()));
}
void MyFrame::card1(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("三国卡牌1");

    auto gSizer=new wxGridSizer(5,10,4,4);
    auto cards_array=CardSanGuo1.Get();
    for(const auto& i: cards_array) {
        auto box=new wxStaticBox(panel,wxID_ANY,wxT(""));
        auto sizer=new wxStaticBoxSizer(box,wxVERTICAL);
        auto text=new wxStaticText(sizer->GetStaticBox(),wxID_ANY,
                                   wxString::Format(wxT("稀有\n%s"),wxString::FromUTF8(i))
                                  );
        text->SetFont(font13);
        auto color=wxColour(255,0,0);
        text->SetForegroundColour(color);
        sizer->Add(text, wxSizerFlags(0).Border(wxALL, 5).Align(wxALIGN_CENTER_HORIZONTAL));
        gSizer->Add(sizer, wxSizerFlags(0).Border(wxALL));
    }
    vbox->Add(gSizer, wxSizerFlags(0).Border(wxALL, 10).Align(wxALIGN_CENTER_HORIZONTAL));

    MYADDSPACER();

    MYBACK(&MyFrame::card_all,1);

    MYADDSPACER();

    MYUSE();
}
void MyFrame::study_rule(WXBTNEVT& evt)
{
    (void)evt;
    MYMESSAGE("计时规则如下：\n"
              "1. 结束计时后，取得秒数，用去尾法获取分钟数\n"
              "2. 8分钟及以下无积分\n"
              "3. 8分钟以上部分，每分钟10积分");
}
void MyFrame::showtime()
{
    auto now = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(now);
    tm* local_time = std::localtime(&time);
    std::stringstream ss;
    ss << local_time->tm_year + 1900 << "-";
    if(local_time->tm_mon + 1 < 10) ss << "0";
    ss << local_time->tm_mon + 1 << "-";
    if(local_time->tm_mday < 10) ss << "0";
    ss << local_time->tm_mday << " ";
    if(local_time->tm_hour < 10) ss << "0";
    ss << local_time->tm_hour << ":";
    if(local_time->tm_min < 10) ss << "0";
    ss << local_time->tm_min << ":";
    if(local_time->tm_sec < 10) ss << "0";
    ss << local_time->tm_sec;
    nowtime->SetLabel(wxString::FromUTF8(ss.str()));
}
void MyFrame::calcs_normal_a1(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("加减练习");

    int a = getrnd(1000,99999);
    int b = getrnd(1000,99999);
    char ops;
    if(getrnd(0,2) == 1) ops = '-';
    else ops = '+';
    std::stringstream ss;
    ss << "请计算：" << a << ops << b;

    auto btn1 = new wxButton(panel,wxID_ANY,wxString::FromUTF8(ss.str()));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyYellow);
    vbox -> Add(btn1, FLAG_LEFT);

    auto tc = new wxTextCtrl(panel,wxID_ANY,wxT("输入答案..."));
    vbox -> Add(tc, FLAG_LEFT);

    auto submit = new wxButton(panel,wxID_ANY,wxT("提交"));
    submit -> SetFont(font17);
    submit -> Bind(wxEVT_BUTTON,[this,tc,a,b,ops](WXBTNEVT& evt) {
        if(!JiSuanBiCheck1.CheckTimes()) {
            MYMESSAGE("次数已达上限");
            return;
        }
        int realans;
        if(ops == '+') realans = a + b;
        else realans = a - b;
        std::string userans = tc->GetValue().ToStdString();
        int ruserans = atoi(userans.c_str());
        if(ruserans == realans) {
            MYMESSAGE("计算正确，增加50计算币");
            JiSuanBiReader.addnum(50);
        } else {
            MYMESSAGE("计算错误");
        }
        this->calcs_normal_a1(evt);
    });
    vbox -> Add(submit,FLAG_LEFT);

    MYADDSPACER();

    MYBACK(&MyFrame::calcs_normal,1);

    MYUSE();
}
void MyFrame::calcs_normal_a2(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("乘法练习");

    int a = getrnd(10,200);
    int b = getrnd(5,30);
    stringstream ss;
    ss << "请计算：" << a << "*" << b;

    auto btn1 = new wxButton(panel,wxID_ANY,wxString::FromUTF8(ss.str()));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyYellow);
    vbox -> Add(btn1, FLAG_LEFT);

    auto tc = new wxTextCtrl(panel,wxID_ANY,wxT("输入答案..."));
    vbox -> Add(tc, FLAG_LEFT);

    auto submit = new wxButton(panel,wxID_ANY,wxT("提交"));
    submit -> SetFont(font17);
    submit -> Bind(wxEVT_BUTTON,[this,tc,a,b](WXBTNEVT& evt) {
        if(!JiSuanBiCheck2.CheckTimes()) {
            MYMESSAGE("次数已达上限");
            return;
        }
        int realans = a * b;
        std::string userans = tc->GetValue().ToStdString();
        int ruserans = atoi(userans.c_str());
        if(ruserans == realans) {
            MYMESSAGE("计算正确，增加50计算币");
            JiSuanBiReader.addnum(50);
        } else {
            MYMESSAGE("计算错误");
        }
        this->calcs_normal_a2(evt);
    });
    vbox -> Add(submit,FLAG_LEFT);

    MYADDSPACER();

    MYBACK(&MyFrame::calcs_normal,1);

    MYUSE();
}
void MyFrame::calcs_normal_a3(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("除法练习");

    int b = getrnd(5,20);
    int ta = getrnd(10,100);
    int a = ta*b;
    stringstream ss;
    ss << "请计算：" << a << "/" << b;

    auto btn1 = new wxButton(panel,wxID_ANY,wxString::FromUTF8(ss.str()));
    btn1 -> SetFont(font17);
    btn1 -> SetForegroundColour(MyYellow);
    vbox -> Add(btn1, FLAG_LEFT);

    auto tc = new wxTextCtrl(panel,wxID_ANY,wxT("输入答案..."));
    vbox -> Add(tc, FLAG_LEFT);

    auto submit = new wxButton(panel,wxID_ANY,wxT("提交"));
    submit -> SetFont(font17);
    submit -> Bind(wxEVT_BUTTON,[this,tc,a,b,ta](WXBTNEVT& evt) {
        if(!JiSuanBiCheck3.CheckTimes()) {
            MYMESSAGE("次数已达上限");
            return;
        }
        int realans = ta;
        std::string userans = tc->GetValue().ToStdString();
        int ruserans = atoi(userans.c_str());
        if(ruserans == realans) {
            MYMESSAGE("计算正确，增加75计算币");
            JiSuanBiReader.addnum(75);
        } else {
            MYMESSAGE("计算错误");
        }
        this->calcs_normal_a3(evt);
    });
    vbox -> Add(submit,FLAG_LEFT);

    MYADDSPACER();

    MYBACK(&MyFrame::calcs_normal,1);

    MYUSE();
}
void MyFrame::fali_xianbi(WXBTNEVT& evt)
{
    if(wxMessageBox(wxT("是否消耗10仙币兑换50法力"),"message",wxYES_NO|wxICON_INFORMATION)
            == wxYES) {
        if(!XianBiReader.high(10)) {
            MYMESSAGE("仙币不足");
            return;
        }
        XianBiReader.minusnum(10);
        FaLiReader.addnum(50);
        MYMESSAGE("兑换成功");
    }
    this->fali(evt);
}
void MyFrame::time_clock(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("学习计时");

    MYBUTTON(button1,&MyFrame::study_start,"开始计时");
    MYBUTTON(button2,&MyFrame::study_end,"结束计时");
    MYBUTTON(button3,&MyFrame::study_rule,"计时规则");

    MYADDSPACER();

    MYBACK(&MyFrame::mine,1);

    MYUSE();
}
void MyFrame::ancient_clothes_sword(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLENS("我的佩剑");
    MYSHOW(wxString("")+
           wxT("当前佩剑：")+wxString::FromUTF8(TOSTR(AncientVar::Sword.GetNow()))
          );

    auto grid = new wxGridSizer(3,3,10,10);
    auto rawall = AncientVar::Sword.GetAll();
    std::vector<int> realall;
    for(const auto& i : rawall) {
        realall.push_back((int)i);
    }
    for(const auto& i : realall) {
        auto btn = new wxButton(panel,wxID_ANY,wxString::FromUTF8(TOSTR(static_cast<Ancient::Sword>(i))));
        btn -> SetFont(font17);
        btn -> SetForegroundColour(MyOrange);
        btn -> Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
            AncientVar::Sword.Change(static_cast<Ancient::Sword>(i));
            this->ancient_clothes_sword(_);
        });
        grid -> Add(btn,FLAG_CENTER);
    }

    vbox -> Add(grid,FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::ancient_clothes,1);

    MYUSE();
}
void MyFrame::ancient_wenguan_fenglu(WXBTNEVT& _)
{
    if(!AncientVar::WenGuan::FengLuCheck.CheckTimes()) {
        MYMESSAGE("今日已领取俸禄");
        return;
    }
    int tmp = (int)AncientWenGuanConfig_GetFengLu(AncientVar::WenGuan::WenGuanConf);
    AncientVar::HuangJinReader.addnum(tmp);
    MYSTRMESSAGE(wxString("")+wxT("成功领取")+TOSTR(tmp)+wxT("两黄金作为俸禄"));
}
void MyFrame::ancient_zhengji_jinjian(WXBTNEVT& _)
{
    if(!AncientZhengJi::JinJian::Check.CheckTimes()) {
        MYMESSAGE("上谏失败，今日已进行过上谏");
        return;
    }
    int tmp = JinJian::GetResult();
    switch(tmp) {
    case 1:
        MYMESSAGE("上谏成功，政绩+2");
        AncientZhengJiReader.addnum(2);
        break;
    case -1:
        MYMESSAGE("上谏成功，官降一品");
        AncientWenGuanConfig_LevelDown(AncientVar::WenGuan::WenGuanConf);
        break;
    default:
        MYMESSAGE("上谏无效，明日再来");
        break;
    }
    this->ancient_wenguan_zhengji(_);
}
void MyFrame::ancient_zhengji_shengguan(WXBTNEVT& _)
{
    bool can = ShengGuan(
                   AncientWenGuanConfig_ReadLevel(AncientVar::WenGuan::WenGuanConf),
                   AncientZhengJiReader.read_int()
               );
    if(!can) {
        MYMESSAGE("政绩不足，无法升官");
    } else {
        MYMESSAGE("升官成功");
        int usezhengji = UseZhengJi(
                             AncientWenGuanConfig_ReadLevel(AncientVar::WenGuan::WenGuanConf)
                         );
        AncientZhengJiReader.minusnum(usezhengji);
        AncientWenGuanConfig_LevelUp(AncientVar::WenGuan::WenGuanConf);
        this -> ancient_wenguan_zhengji(_);
    }
}
void MyFrame::ancient_clothes_pao(WXBTNEVT& _)
{
    MYINIT();

    MYTITLENS("我的锦袍");
    MYSHOW(wxString("")+wxT("当前锦袍：")+wxString::FromUTF8(TOSTR(AncientVar::Pao.GetNow())));

    auto grid = new wxGridSizer(3,3,10,10);
    auto rawall = AncientVar::Pao.GetAll();
    std::vector<int> realall;
    for(const auto& i : rawall) {
        realall.push_back((int)i);
    }
    for(const auto& i : realall) {
        auto btn = new wxButton(panel,wxID_ANY,wxString::FromUTF8(TOSTR(static_cast<Ancient::Pao>(i))));
        btn -> SetFont(font17);
        btn -> SetForegroundColour(MyOrange);
        btn -> Bind(wxEVT_BUTTON,[=](WXBTNEVT& _) {
            AncientVar::Pao.Change(static_cast<Ancient::Pao>(i));
            this->ancient_clothes_pao(_);
        });
        grid -> Add(btn,FLAG_CENTER);
    }

    vbox -> Add(grid,FLAG_CENTER);

    MYBACK(&MyFrame::ancient_clothes,1);

    MYUSE();
}
void MyFrame::xianqi_fali_xianbi(WXBTNEVT& _)
{
    if(wxMessageBox(wxT("是否消耗5仙币兑换40仙器法力"),"message",wxYES_NO | wxICON_INFORMATION)
            == wxYES) {
        if(!XianBiReader.high(5)) {
            MYMESSAGE("仙币不足");
            return;
        }
        XianBiReader.minusnum(5);
        XianQiFaLiReader.addnum(40);
        MYMESSAGE("兑换成功");
        this->xianqi_fali(_);
    }
}
void MyFrame::card2(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("汉朝卡牌1");

    auto gSizer=new wxGridSizer(5,10,4,4);
    auto cards_array=CardHan1.Get();
    for(const auto& i: cards_array) {
        auto box=new wxStaticBox(panel,wxID_ANY,wxT(""));
        auto sizer=new wxStaticBoxSizer(box,wxVERTICAL);
        auto text=new wxStaticText(sizer->GetStaticBox(),wxID_ANY,
                                   wxString::Format(wxT("珍藏\n%s"),wxString::FromUTF8(i))
                                  );
        text->SetFont(font13);
        auto color=wxColour(255,0,0);
        text->SetForegroundColour(color);
        sizer->Add(text, wxSizerFlags(0).Border(wxALL, 5).Align(wxALIGN_CENTER_HORIZONTAL));
        gSizer->Add(sizer, wxSizerFlags(0).Border(wxALL));
    }
    vbox->Add(gSizer, wxSizerFlags(0).Border(wxALL, 10).Align(wxALIGN_CENTER_HORIZONTAL));

    MYADDSPACER();

    MYBACK(&MyFrame::card_all,1);

    MYADDSPACER();

    MYUSE();
}
void MyFrame::tsquare_free_jifen(WXBTNEVT&)
{
    if(!ThingsSquare::JiFenCheck.CheckTimes()) {
        MYMESSAGE("今日已经领取");
        return;
    }
    JiFenReader.addnum(20);
    MYMESSAGE("成功领取20积分");
}
void MyFrame::tsqaure_free_xianbi(WXBTNEVT&)
{
    if(!ThingsSquare::XianBiCheck.CheckTimes()) {
        MYMESSAGE("今日已经领取");
        return;
    }
    XianBiReader.addnum(2);
    MYMESSAGE("恭喜获得2仙币");
}
void MyFrame::tsquare_free_tongqian(WXBTNEVT&)
{
    if(!ThingsSquare::TongQianCheck.CheckTimes()) {
        MYMESSAGE("今日已经领取");
        return;
    }
    AncientVar::TongBiReader.addnum(20);
    MYMESSAGE("恭喜获得20枚铜钱");
}
void MyFrame::tsquare_free_baoshi(WXBTNEVT&)
{
    if(!ThingsSquare::BaoShiCheck.CheckTimes()) {
        MYMESSAGE("今日已经领取");
        return;
    }
    BaoShiReader.addnum(1);
    MYMESSAGE("恭喜获得1颗宝石");
}
void MyFrame::baoshi_choujiang1(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("宝石抽奖一");

    MYSHOWNSNCM(wxString("")+
                wxT("获得概率：")+NEWLINE+
                wxT("汉朝卡牌1*2：5%")+NEWLINE+
                wxT("铜钱*50：20%")+NEWLINE+
                wxT("积分*50：25%")+NEWLINE+
                wxT("仙币*30：50%"),btnshow1);
    btnshow1 -> SetForegroundColour(MyBlue);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("5宝石抽奖"));
    btn2 -> SetFont(font15);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        if(!BaoShi::Reader.canminus(5)) {
            MYMESSAGE("宝石不足");
            return;
        }
        auto res = BaoShiChouJiang1_GetAnswer();
        if(res == BAOSHICHOUJIANG1_CARD) {
            std::unique_ptr<int> ans(getrnds(0,45,2));
            std::deque<std::string> realname;
            for(int i = 0; i < 2; ++i) {
                CardHan1.Write(ans.get()[i]);
                realname.push_back(CardHan1[ans.get()[i]]);
            }
            std::string showstr="恭喜获得卡牌：\n";
            for(const auto& i : realname) {
                showstr += i;
                showstr += " - 珍藏\n";
            }
            MYSTRMESSAGE(wxString::FromUTF8(showstr.c_str()));
        } else if(res == BAOSHICHOUJIANG1_TONGQIAN) {
            MYMESSAGE("恭喜获得铜钱50枚");
            AncientVar::TongBiReader.addnum(50);
        } else if(res == BAOSHICHOUJIANG1_JIFEN) {
            MYMESSAGE("恭喜获得50积分");
            JiFenReader.addnum(50);
        } else {
            MYMESSAGE("恭喜获得30仙币");
            XianBiReader.addnum(30);
        }
    });
    vbox -> Add(btn2,FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::baoshi_choujiang);
}
void MyFrame::ancient_shop_nianjiu1(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("拈阄店铺一");

    auto grid = new wxGridSizer(3,3,1,1);

    std::vector<wxButton*> buttons;
    for(int i=0; i<9; ++i) {
        wxButton* tmp = new wxButton(panel,wxID_ANY,wxT("翻开\n此牌"));
        tmp -> SetFont(font19);
        tmp -> SetForegroundColour(MyRed);
        grid -> Add(tmp, FLAG_CENTER);
        buttons.push_back(tmp);
    }

    vbox -> Add(grid,FLAG_CENTER);

    auto showbtn = new wxButton(panel,wxID_ANY,wxT("5两白银/次"));
    showbtn -> SetFont(font17);
    showbtn -> SetForegroundColour(MyDarkRed);
    vbox -> Add(showbtn, FLAG_CENTER);

    int i=0;
    for(const auto& tmp: buttons) {
        tmp -> Bind(wxEVT_BUTTON,[this, i, buttons, showbtn](WXBTNEVT&) {
            if(!AncientVar::BaiYinReader.canminus(5)) {
                MYSTRMESSAGE(
                    wxEmptyString+
                    wxString(wxT("白银不足5两，仅有"))+
                    AncientVar::BaiYinReader.read_str()+
                    wxT("两")
                );
                return;
            }
            MYSTRMESSAGE(wxString(wxT("现有白银"))+AncientVar::BaiYinReader.read_str()+wxT("两"));
            int result = getrnd(0,9);
            int z = 0;
            for(const auto& j: buttons) {
                j -> Bind(wxEVT_BUTTON, [](WXBTNEVT&) {});
                wxString label = (z == result)?(wxT("中")):(wxT("不中"));
                j -> SetLabel(label);
                z++;
            }
            if(i == result) {
                MYMESSAGE("恭喜中奖了，获得40两白银");
                AncientVar::BaiYinReader.addnum(40);
                MYSTRMESSAGE(wxString(wxT("现有"))+AncientVar::BaiYinReader.read_str()+wxT("两白银"));
            } else {
                MYMESSAGE("很遗憾未中奖");
            }
            showbtn -> SetLabel(wxT("重置"));
            showbtn -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_nianjiu1, this);
        });
        ++i;
    }

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_shop_nianjiu);
}
void MyFrame::ancient_things_bookshelf(WXBTNEVT&)
{
    MYINIT();

    BookShelfResult_Get(BookShelf::Reader);
    int ShouCangZhi = BookShelf_GetShouCangZhi(Level1, Level2, Level3);
    int Level = BookShelf_GetShouCangLevel(ShouCangZhi);

    MYTITLE("我的书籍");

    MYSHOWNSNCM(wxString(wxT(""))+
           wxT("普通书籍：")+TOSTR(Level1)+wxT("本")+NEWLINE+
           wxT("珍贵书籍：")+TOSTR(Level2)+wxT("本")+NEWLINE+
           wxT("典藏书籍：")+TOSTR(Level3)+wxT("本"), 
           btn1);
    btn1 -> SetForegroundColour(MyBlue);

    MYSHOWNSNCM(wxString(wxT(""))+
           wxT("珍藏值：")+TOSTR(ShouCangZhi)+NEWLINE+
           wxT("珍藏等级：")+TOSTR(Level), 
           btn2);
    btn2 -> SetForegroundColour(MyBlue);
 
    MYADDSPACER();

    MYLAST(&MyFrame::ancient_things);
}
void MyFrame::tsquare_free_jinbi(WXBTNEVT&)
{
    if(!ThingsSquare::JinBiCheck.CheckTimes()) {
        MYMESSAGE("今日已经领取");
        return;
    }
    JinBiReader.addnum(1);
    MYMESSAGE("成功领取1金币");
}
void MyFrame::ancient_zhengji_zhenji(WXBTNEVT& evt) {
    if(!AncientVar::BaiYinReader.high(100)) {
        MYMESSAGE("白银不足");
        return;
    }
    MYMESSAGE("现有灾民百人，每人需一两白银，共计一百两白银");
    if(wxMessageBox(wxT("是否赈济"), "message", wxYES_NO | wxICON_INFORMATION) == wxYES) {
        if(!AncientVar::WenGuan::ZhengJi::ZhenJi::Check.CheckTimes()) {
            MYMESSAGE("今日已赈济灾民");
            return;
        }
        AncientVar::BaiYinReader.minusnum(100);
        AncientZhengJiReader.addnum(10);
        MYMESSAGE("赈济成功，政绩+10");
    }
    this -> ancient_wenguan_zhengji(evt);
}
void MyFrame::ancient_juanzeng_lingqu(WXBTNEVT&){
    if(!AncientVar::JuanZeng::LingQuCheck.CheckTimes()){
        MYMESSAGE("今日已领取过资助");
        return;
    }
    int level = AncientJuanZeng_GetLevel(
        AncientVar::JuanZeng::Reader.read_int()
    );
    int res = AncientJuanZeng_GetHuangJin(level);
    AncientVar::HuangJinReader.addnum(res);
    MYSTRMESSAGE(wxString(wxT("成功领取"))+TOSTR(res)+wxT("两黄金"));
}
void MyFrame::ancient_shop_nianjiu2(WXBTNEVT&)
{
    MYINIT();

    MYTITLE("拈阄店铺二");

    auto grid = new wxGridSizer(4,4,1,1);

    std::vector<wxButton*> buttons;
    for(int i=0; i<16; ++i) {
        wxButton* tmp = new wxButton(panel,wxID_ANY,wxT("翻开\n此牌"));
        tmp -> SetFont(font19);
        tmp -> SetForegroundColour(MyRed);
        grid -> Add(tmp, FLAG_CENTER);
        buttons.push_back(tmp);
    }

    vbox -> Add(grid,FLAG_CENTER);

    auto showbtn = new wxButton(panel,wxID_ANY,wxT("5两白银/次"));
    showbtn -> SetFont(font17);
    showbtn -> SetForegroundColour(MyDarkRed);
    vbox -> Add(showbtn, FLAG_CENTER);

    int i=0;
    for(const auto& tmp: buttons) {
        tmp -> Bind(wxEVT_BUTTON,[this, i, buttons, showbtn](WXBTNEVT&) {
            if(!AncientVar::BaiYinReader.canminus(5)) {
                MYSTRMESSAGE(
                    wxEmptyString+
                    wxString(wxT("白银不足5两，仅有"))+
                    AncientVar::BaiYinReader.read_str()+
                    wxT("两")
                );
                return;
            }
            MYSTRMESSAGE(wxString(wxT("现有白银"))+AncientVar::BaiYinReader.read_str()+wxT("两"));
            int result1 = getrnd(0,15);
            int result2 = getrnd(0,15);
            while(result2 == result1){
                result2 = getrnd(0,15);
            }
            int z = 0;
            for(const auto& j: buttons) {
                j -> Bind(wxEVT_BUTTON, [](WXBTNEVT&) {});
                wxString label = ((z == result1) || (z == result2))?(wxT("中")):(wxT("不中"));
                j -> SetLabel(label);
                z++;
            }
            if((i == result1) || (i == result2)) {
                MYMESSAGE("恭喜中奖了，获得40两白银");
                AncientVar::BaiYinReader.addnum(40);
                MYSTRMESSAGE(wxString(wxT("现有"))+AncientVar::BaiYinReader.read_str()+wxT("两白银"));
            } else {
                MYMESSAGE("很遗憾未中奖");
            }
            showbtn -> SetLabel(wxT("重置"));
            showbtn -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_nianjiu2, this);
        });
        ++i;
    }

    MYADDSPACER();

    MYLAST(&MyFrame::ancient_shop_nianjiu);
}
void MyFrame::ancient_zhengji_huilu(WXBTNEVT& evt){
    int jinzhu_need = getrnd(4,7);
    AncientJinYinZhu_Get(AncientVar::JinYinZhuReader);
    MYSTRMESSAGE(wxString(wxT("今需"))+TOSTR(jinzhu_need)+wxT("颗金珠"));
    if(wxMessageBox(wxT("是否给出？"), "msg", wxYES_NO | wxICON_QUESTION) == wxYES){
        if(JinZhu < jinzhu_need){
            MYMESSAGE("金珠不足，贿赂失败");
            return;
        }
        AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_JinZhu, -jinzhu_need);
        MYMESSAGE("贿赂成功，政绩+40");
        AncientZhengJiReader.addnum(40);
        this -> ancient_wenguan_zhengji(evt);
    }
}
void MyFrame::ancient_zhengji_miansheng(WXBTNEVT& evt){
    AncientJinYinZhu_Get(AncientVar::JinYinZhuReader);
    if(YinZhu < 10){
        MYMESSAGE("银珠不足");
        return;
    }
    if(!AncientZhengJi::MianSheng::Check.CheckTimes()){
        MYMESSAGE("今日已进行面圣");
        return;
    }
    AncientJinYinZhu_Write(AncientVar::JinYinZhuReader, AncientJinYinZhu_YinZhu, -10);
    AncientZhengJiReader.addnum(25);
    MYMESSAGE("面圣成功，政绩+25");
    this -> ancient_wenguan_zhengji(evt);
}
void MyFrame::xiandan_show(WXBTNEVT&){
    MYINIT();

    MYTITLE("仙丹查看");

    auto grid = new wxGridSizer(3,3,4,4);

    MYSHOWNSNBM(
        wxString(wxT("普通丹："))+Xian::Dan::PuTong.read_str()+wxT("粒"), 
        btn1, MyDarkRed
    );
    grid -> Add(btn1, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("碧丹："))+Xian::Dan::Bi.read_str()+wxT("粒"), 
        btn2, MyDarkRed
    );
    grid -> Add(btn2, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("青丹："))+Xian::Dan::Qing.read_str()+wxT("粒"), 
        btn3, MyDarkRed
    );
    grid -> Add(btn3, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("紫丹："))+Xian::Dan::Zi.read_str()+wxT("粒"), 
        btn4, MyDarkRed
    );
    grid -> Add(btn4, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("五色丹："))+Xian::Dan::WuSe.read_str()+wxT("粒"), 
        btn5, MyDarkRed
    );
    grid -> Add(btn5, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("银丹："))+Xian::Dan::Yin.read_str()+wxT("粒"), 
        btn6, MyDarkRed
    );
    grid -> Add(btn6, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("金丹："))+Xian::Dan::Jin.read_str()+wxT("粒"), 
        btn7, MyDarkRed
    );
    grid -> Add(btn7, FLAG_CENTER);

    MYSHOWNSNBM(
        wxString(wxT("神丹："))+Xian::Dan::Shen.read_str()+wxT("粒"), 
        btn8, MyDarkRed
    );
    grid -> Add(btn8, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan);
}
