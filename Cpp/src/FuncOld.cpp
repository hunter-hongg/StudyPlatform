#include <headers.hpp>

using namespace Files;
using namespace Check;

void oldblock MyFrame::calcs_normal_a4(WXBTNEVT& evt)
{
    (void)evt;
    MYINIT();

    MYTITLE(/*wxT(*/"因式分解"/*)*/);

    MYADDSPACER()/*MY_STRETCHSPACER*/;

    vector<poly> poly4;
    std::unique_ptr<int[]> zz(/*GenMultiRandInts(1,10,10)*/getrnds(1,10,10));
    for(int i=0; i<10; ++i) std::cerr << zz[i] << " ";
    for(int i1=0; i1<4; ++i1) {
        vector<double> a;
        a.push_back(zz[i1*2]);
        a.push_back(zz[i1*2+1]);
        poly tmp(a);
        poly4.push_back(tmp);
    }
    poly product = {1};
    for(const auto& i:poly4) {
        product *= i;
    }
    wxString showtt1=wxT("因式分解：");
    for(int i=product.degree(); i>=0; --i) {
        if(i>0) {
            showtt1+=TOSTR((int)product[i])+wxT("x^")+TOSTR(i)+wxT("+");
        } else {
            showtt1+=TOSTR((int)product[i]);
        }
    }
    /*MY_NEWBUTTON(showtt1,showt2)*/auto showt2 = new wxButton(panel,wxID_ANY,showtt1);
    showt2->SetForegroundColour(MyYellow);
    showt2->SetFont(font15);
    vbox->Add(showt2,FLAG_CENTER);
    /*MY_NEWBUTTON(wxT("已提交0个因式"),showt3)*/auto showt3 = new wxButton(panel,wxID_ANY,wxT("已提交0个因式"));
    showt3->SetForegroundColour(MyYellow);
    showt3->SetFont(font15);
    vbox->Add(showt3,FLAG_CENTER);

    auto tc=new wxTextCtrl(panel,wxID_ANY,wxString(wxT("请输入一次项系数")));
    auto tc2=new wxTextCtrl(panel,wxID_ANY,wxString(wxT("请输入常数")));
    vbox->Add(tc,/*MY_LEFT*/FLAG_LEFT);
    vbox->Add(tc2,/*MY_LEFT*/FLAG_LEFT);
    count=0;

    /*MY_NEWBUTTON(wxT("提交"),tj)*/auto tj = new wxButton(panel,wxID_ANY,wxT("提交"));
    tj->SetFont(font15);
    tj->Bind(wxEVT_BUTTON,[this,product,tc,tc2,showt3](WXEVT& evt) {
        this->onclickys1(product,tc,tc2,evt,showt3);
    });
    vbox->Add(tj,/*MY_LEFT*/FLAG_LEFT);

    MYADDSPACER();

    MYBACK(&MyFrame::/*square_h1n*/calcs_normal,1);

    MYADDSPACER();

    /*
    MY_SETSIZER;
    MY_LAYOUT;
    */

    MYUSE();
}
void oldblock MyFrame::onclickys1(poly product,wxTextCtrl* tc,wxTextCtrl*tc2,
                                  WXEVT evt,wxButton*showt3)
{
    poly tmp= {atoi(tc2->GetValue().ToStdString().c_str()),
               atoi(tc->GetValue().ToStdString().c_str())
              };
    membervar(poly) ys1User[membervar(int) count++]=tmp;
    showt3->SetLabel(wxT("已提交")+TOSTR(membervar(int) count)+wxT("个因式"));
    tc->SetValue(wxT("请输入一次项系数"));
    tc2->SetValue(wxT("请输入常数"));
    if(count==5) {
        if(!/*jiSuanBiCheck4->check(3)*/JiSuanBiCheck4.CheckTimes()) {
            MYSTRMESSAGE(wxT("次数已达上限"));
            return;
        }
        count=0;
        MYSTRMESSAGE(wxT("已提交所有因式"));
        showt3->SetLabel(wxT("已提交")+TOSTR(count)+wxT("个因式"));
        poly productUSR= {1};
        for(int i=0; i<5; ++i) {
            productUSR*=ys1User[i];
        }
        if(product==productUSR) {
            MYSTRMESSAGE(wxT("因式分解结果正确，增加60计算币"));
            JiSuanBiReader.addnum(60);
        } else {
            MYSTRMESSAGE(wxT("因式分解结果错误"));
        }
        this->/*square_h1n*/calcs_normal(evt);
    }
}
void oldblock MyFrame::xianqi_change/*j225_h1*/(WXEVT& evt)
{
    (void)evt;
    /*
    MY_CLEAN;
    MY_NEWVBOX;
    */
    MYINIT();

    MYTITLENS(/*wxT(*/"仙器更换"/*)*/);
    MYSHOW(/*showt1,*/wxT("当前仙器：")+
                      /*TOGBK*/wxString::FromUTF8(swordToString(/*swdf1*/Other::Sword/*->*/.get())));

    MYADDSPACER();

    auto grid1=new wxGridSizer(2,3,4,4);
    for(int i=0; i<5; ++i) {
        auto button=new wxButton(panel/*_start*/,wxID_ANY,
                                 /*wxT("更换为\n")+*/
                                 wxString::FromUTF8(swordToString(
                                             static_cast<functions::SwordEnum>(i))));
        button->Bind(wxEVT_BUTTON,[i,this](WXEVT& evt) {
            /*(this->swdf1)*/Other::Sword/*->*/.set(static_cast<functions::SwordEnum>(i));
            this->/*j225_h1*/xianqi_change(evt);
        });
        button->SetFont(font17);
        button->SetForegroundColour(MyOrange);
        grid1->Add(button,FLAG_CENTER);
    }
    vbox->Add(grid1,FLAG_CENTER);

    MYADDSPACER();

    /*
    MY_BACKBUTTON(&MyFrame::jbh2h2_h5);

    MY_STRETCHSPACER;

    MY_SETSIZER;
    MY_LAYOUT;
    */

    MYLAST(&MyFrame::xianqi);
}
