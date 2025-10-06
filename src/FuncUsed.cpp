#include <headers.hpp>

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size),
      nowtime(nullptr)
{
    using namespace std::filesystem;
    using namespace std;
    panel = new wxPanel(this, wxID_ANY);

    std::error_code ec;
    if(!exists(FilePathBase,ec)){
        bool res = create_directory(FilePathBase,ec);
    }
    if(!exists(FilePath,ec)) {
        bool res = create_directory(FilePath,ec);
    }
    if(!exists(FilePathPao,ec)) {
        bool res = create_directory(FilePathPao,ec);
    }
    if(!exists(FilePathXianQi,ec)) {
        bool res = create_directory(FilePathXianQi,ec);
    }
    if(!exists(FilePathBaoWu,ec)) {
        bool res = create_directory(FilePathBaoWu,ec);
    }
    if(!exists(FilePathCard,ec)) {
        bool res = create_directory(FilePathCard,ec);
    }
    if(!exists(FilePathThingsSquare,ec)) {
        bool res = create_directory(FilePathThingsSquare,ec);
    }
    if(!exists(FilePathBaoShi,ec)) {
        bool res = create_directory(FilePathBaoShi,ec);
    }
    if(!exists(FilePathBookShelf,ec)) {
        bool res = create_directory(FilePathBookShelf,ec);
    }
    if(!exists(FilePathTongYong,ec)) {
        bool res = create_directory(FilePathTongYong,ec);
    }
    if(!exists(FilePathAncient,ec)) {
        bool res = create_directory(FilePathAncient,ec);
    }
    if(!exists(FilePathXianJi,ec)) {
        bool res = create_directory(FilePathXianJi,ec);
    }
    if(!exists(FilePathXianDan,ec)) {
        bool res = create_directory(FilePathXianDan, ec);
    }
    if(!exists(FilePathLiHeBool,ec)) {
      bool res = create_directory(FilePathLiHeBool, ec);
    }
    if(!exists(FilePathLiHe,ec)){
      bool res = create_directory(FilePathLiHe, ec);
    }
    if(!exists(FilePathXianLu,ec)){
        (void)create_directory(FilePathXianLu, ec);
    }
    if(!exists(FilePathAncientWuGuan,ec)){
        (void)create_directory(FilePathAncientWuGuan, ec);
    }
    if(!exists(FilePathBank,ec)){
        (void)create_directory(FilePathBank, ec);
    }
    if(!exists(FilePathTongYongReal,ec)){
        (void)create_directory(FilePathTongYongReal, ec);
    }

    nowtime = new wxStaticText(panel,wxID_ANY,wxT("测试"));
    this -> showtime();
    TimeTimer.Bind(wxEVT_TIMER,[this](wxTimerEvent& _) {
        this->showtime();
    });
    TimeTimer.Start(500);

    AncientVar::Sword.Add(static_cast<Ancient::Sword>(0));
    AncientVar::Pao.Add(static_cast<Ancient::Pao>(0));

    this -> start();
}
void MyFrame::things_all(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE("我的物品");

    auto grid = new wxGridSizer(4,3,5,5);

    MYSHOWNSNCNBM(wxString(wxT("积分："))+JiFenReader.read_str(),jifen_show);
    jifen_show->SetForegroundColour(MyBlue);
    grid -> Add(jifen_show,FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("仙币："))+XianBiReader.read_str(),xianbi_show);
    xianbi_show->SetForegroundColour(MyBlue);
    grid -> Add(xianbi_show,FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("宝石："))+BaoShi::Reader.read_str()+wxT("颗"),baoshi_show);
    baoshi_show->SetForegroundColour(MyBlue);
    grid -> Add(baoshi_show,FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("银币："))+YinBiReader.read_str(),yinbi_show);
    yinbi_show -> SetForegroundColour(MyBlue);
    grid -> Add(yinbi_show, FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("金币："))+JinBiReader.read_str(),tongyong_show);
    tongyong_show->SetForegroundColour(MyBlue);
    grid -> Add(tongyong_show,FLAG_CENTER);

    MYSHOWNSNCNBM(wxString(wxT("计算币："))+JiSuanBiReader.read_str(),jisuanbi_show);
    jisuanbi_show->SetForegroundColour(MyBlue);
    grid -> Add(jisuanbi_show,FLAG_CENTER);

    grid -> AddSpacer(1);

    MYSHOWNSNCNBM(wxString(wxT("卡牌："))+
                TOSTR(
                    Card::CardSanGuo1.Get().size()+
                    Card::CardHan1.Get().size()
                )+
                wxT("张"),
                card_show
               );
    card_show->SetForegroundColour(MyRed);
    grid -> Add(card_show,FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYADDSPACER();

    MYBACK(&MyFrame::all_thing_all,1);

    MYUSE();
}
void MyFrame::yinbi_all(WXBTNEVT&){
    MYINIT();

    MYTITLENS("银币抽奖");
    MYSHOW(wxString(wxT("银币："))+YinBiReader.read_str());

    auto grid = new wxGridSizer(4,4,0,0);

    std::deque<std::string> JiangPin({
        "积分\n50", "金币\n15", "铜钱\n50", "宝石\n5", 
        "三国\n卡牌1", "汉朝\n卡牌1" 
    });

    for(const auto& i: JiangPin){
        auto btn = new wxButton(panel,wxID_ANY,wxString::FromUTF8(i));
        btn -> SetFont(font15);
        btn -> SetForegroundColour(MyOrange);
        grid -> Add(btn, FLAG_CENTER);
    }

    vbox -> Add(grid, FLAG_CENTER);

    auto call = [=](WXBTNEVT& evt){
        if(!YinBiReader.canminus(5)){
            MYMESSAGE("银币不足");
            return;
        }
        const int LEVEL1 = 4, LEVEL2 = 2, LEVEL3 = 0;
        const int ALL = LEVEL1 * 10 + LEVEL2 * 5 + LEVEL3 * 2;
        int luck = getrnd(0,ALL);
        if ( luck < 10 ) {
            JiFenReader.addnum(50);
            MYMESSAGE("恭喜获得50积分");
        } else if ( luck < 20 ) {
            JinBiReader.addnum(15);
            MYMESSAGE("恭喜获得15金币");
        } else if ( luck < 30 ) {
            AncientVar::TongBiReader.addnum(50);
            MYMESSAGE("恭喜获得50铜钱");
        } else if ( luck < 40 ) {
            BaoShi::Reader.addnum(5);
            MYMESSAGE("恭喜获得5宝石");
        } else if ( luck < 45 ) {
            int ans = getrnd(0,46);
            std::string realname;
            CardSanGuo1.Write(ans);
            realname = CardSanGuo1[ans];
            std::string showstr="恭喜获得三国卡牌1 - ";
            showstr += realname;
            MYSTRMESSAGE(wxString::FromUTF8(showstr));
        } else if ( luck < 50 ) {
            int res = getrnd(0,45);
            std::string showstr="恭喜获得汉朝卡牌1 - ";
            showstr += CardHan1[res];
            MYSTRMESSAGE(wxString::FromUTF8(showstr));
            CardHan1.Write(res);
        } else {
            MYMESSAGE("程序执行出错");
        }
        this -> yinbi_all(evt);
    };
    MYBUTTONLAMBDA(btn1, call, "5银币抽奖");
    btn1 -> SetForegroundColour(MyDarkRed);

    MYADDSPACER();

    MYLAST(&MyFrame::things_other);
}
void MyFrame::lihe(WXBTNEVT&){
    using std::filesystem::exists;
    
    MYINIT();

    MYTITLE("我的礼盒");

    std::vector<LiHe::Types> alllihe;
    if(exists(FilePathLiHe+"xianbibasic_lihe.lihe")){
        alllihe.push_back(LiHe::Types::XianBiBasic);
    }
    if(exists(FilePathLiHe+"xiandanbasic_lihe.lihe")){
        alllihe.push_back(LiHe::Types::XianDanBasic);
    }

    if(alllihe.empty()){
      auto button = new wxButton(panel, wxID_ANY, wxT("未发现任何礼盒"));
      button -> SetFont(font17);
      button -> SetForegroundColour(MyRed);
      vbox -> Add(button,FLAG_CENTER);
    } else {
      for(const auto& i : alllihe){
        wxBoxSizer *hbox;
        wxButton *buttoninner1, *buttonuse1;
        switch(i){
        case LiHe::Types::XianBiBasic:
          hbox = new wxBoxSizer(wxHORIZONTAL);
          buttoninner1 = new wxButton(panel, wxID_ANY, wxT("礼盒 - 仙币基础礼盒"));
          buttoninner1 -> SetForegroundColour(MyBlue);
          buttoninner1 -> SetFont(font17);
          hbox -> Add(buttoninner1, FLAG_CENTER);
          buttonuse1 = new wxButton(panel, wxID_ANY, wxT("使用礼盒"));
          if(LiHe::IsUsed::XianBiBasic.CheckOk()){
            buttonuse1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
              (void)LiHe::IsUsed::XianBiBasic.IsOk();
              XianBiReader.addnum(1500);
              MYMESSAGE("恭喜获得1500仙币");
              this -> lihe(evt);
            });
          } else {
            buttoninner1 -> SetForegroundColour(MyOrange);
            buttonuse1 -> SetLabel(wxT("已使用"));
          }
          buttonuse1 -> SetFont(font17);
          buttonuse1 -> SetForegroundColour(MyGrey);
          hbox -> Add(buttonuse1, FLAG_CENTER);
          vbox -> Add(hbox, FLAG_CENTER_NOBORDER);
          break;
        case LiHe::Types::XianDanBasic:
          hbox = new wxBoxSizer(wxHORIZONTAL);
          buttoninner1 = new wxButton(panel, wxID_ANY, wxT("礼盒 - 仙丹基础礼盒"));
          buttoninner1 -> SetForegroundColour(MyBlue);
          buttoninner1 -> SetFont(font17);
          hbox -> Add(buttoninner1, FLAG_CENTER);
          buttonuse1 = new wxButton(panel, wxID_ANY, wxT("使用礼盒"));
          if(LiHe::IsUsed::XianDanBasic.CheckOk()){
            buttonuse1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
              (void)LiHe::IsUsed::XianDanBasic.IsOk();
              Xian::Dan::PuTong.addnum(60);
              MYMESSAGE("恭喜获得60普通丹");
              this -> lihe(evt);
            });
          } else {
            buttoninner1 -> SetForegroundColour(MyOrange);
            buttonuse1 -> SetLabel(wxT("已使用"));
          }
          buttonuse1 -> SetFont(font17);
          buttonuse1 -> SetForegroundColour(MyGrey);
          hbox -> Add(buttonuse1, FLAG_CENTER);
          vbox -> Add(hbox, FLAG_CENTER_NOBORDER);
          break;
 
        default:
          break;
        }
      }
    }   
    
    MYADDSPACER();

    MYLAST(&MyFrame::mine);
}
void MyFrame::xianbi_square_1(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的物品");

    MYBUTTON(btn2,&MyFrame::xianqi,"我的仙器");
    MYBUTTON(btn3,&MyFrame::xianji,"我的仙籍");
    MYBUTTON(btn4,&MyFrame::xiandan,"我的仙丹");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
void MyFrame::xianbi_square_2(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的能力");

    MYBUTTON(btn1,&MyFrame::fali,"我的法力");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
void MyFrame::xianbi_square_3(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的待遇");

    MYBUTTON(btn4,&MyFrame::xianlu, "我的仙禄");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
