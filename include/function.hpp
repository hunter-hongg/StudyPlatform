#include <wx/wx.h>
#include <type.hpp>
#include <utils/new/timer/timer.hpp>
#include <macro.hpp>
#include <utils/poly.hpp>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:

    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void clean_panel();

protected:

    void start();

    void time_clock(WXBTNEVT&);
    void study_start(WXBTNEVT&);
    void study_end(WXBTNEVT&);
    void study_rule(WXBTNEVT&);

    void mine(WXBTNEVT&);

    void lihe(WXBTNEVT&);

    void all_thing_all(WXBTNEVT&);

    void things_all(WXBTNEVT&);
    void things_shop(WXBTNEVT&);
    void things_other(WXBTNEVT&);

    void card_all(WXBTNEVT&);
    void card1(WXBTNEVT&);
    void card2(WXBTNEVT&);

    void baoshi_all(WXBTNEVT&);

    void baoshi_get(WXBTNEVT&);
    void baoshi_choujiang(WXBTNEVT&);
    void baoshi_choujiang1(WXBTNEVT&);

    void yinbi_all(WXBTNEVT&);

    void calc_square(WXBTNEVT&);

    void calcs_normal(WXBTNEVT&);
    void calcs_normal_a1(WXBTNEVT&);
    void calcs_normal_a2(WXBTNEVT&);
    void calcs_normal_a3(WXBTNEVT&);
    void calcs_normal_a4(WXBTNEVT&) oldblock; // 因式分解板块

    void calcs_shop(WXBTNEVT&);

    void xianbi_square(WXBTNEVT&);
    void xianbi_square_1(WXBTNEVT&);
    void xianbi_square_2(WXBTNEVT&);
    void xianbi_square_3(WXBTNEVT&);

    void fali(WXBTNEVT&);
    void fali_xianbi(WXBTNEVT&);
    void fali_xiandan(WXBTNEVT&);

    void xianqi(WXBTNEVT&);
    void xianqi_change(WXBTNEVT&) oldblock; // 仙器更换板块
    void xianqi_fali(WXBTNEVT&);
    void xianqi_fali_xianbi(WXBTNEVT&);
    void xianqi_liandan(WXBTNEVT&);

    void xianji(WXBTNEVT&);
    void xianji_get(WXBTNEVT&);
    void xianji_use(WXBTNEVT&);
    void xianji_use_fali(WXBTNEVT&);
    void xianji_use_xianqi(WXBTNEVT&);
    void xianji_liandan(WXBTNEVT&);

    void xiandan(WXBTNEVT&);
    void xiandan_show(WXBTNEVT&);
    void xiandan_he(WXBTNEVT&);
    void xiandan_he_yindan(WXBTNEVT&);
    void xiandan_he_jindan(WXBTNEVT&);
    void xiandan_he_shendan(WXBTNEVT&);

    void xianlu(WXBTNEVT&);
    void xianlu_next(WXBTNEVT&);
    void xianlu_get(WXBTNEVT&);

    void ancient_square(WXBTNEVT&);

    void ancient_shopa(WXBTNEVT&); // 总板块
    void ancient_shop(WXBTNEVT&);
    void ancient_shop_guwan(WXBTNEVT&);
    void ancient_shop_baowu(WXBTNEVT&);
    void ancient_shop_bianli_all(WXBTNEVT&); // 便利商店最新总板块
    void ancient_shop_bianli(WXBTNEVT&);
    void ancient_shop_bianli_baiyin(WXBTNEVT&);
    void ancient_shop_bianli_huangjin(WXBTNEVT&);
    void ancient_shop_bianli_tongbi(WXBTNEVT&);
    void ancient_shop_bianli_book(WXBTNEVT&);
    void ancient_shop_bianli_book_simple(WXBTNEVT&);
    void ancient_shop_bianli_book_zhengui(WXBTNEVT&);
    void ancient_shop_nianjiu(WXBTNEVT&);
    void ancient_shop_nianjiu1(WXBTNEVT&);
    void ancient_shop_nianjiu2(WXBTNEVT&);

    void ancient_clothes(WXBTNEVT&);
    void ancient_clothes_sword(WXBTNEVT&);
    void ancient_clothes_pao(WXBTNEVT&);

    void ancient_things(WXBTNEVT&);
    void ancient_things_money(WXBTNEVT&);
    void ancient_things_guwan(WXBTNEVT&);
    void ancient_things_baowu(WXBTNEVT&);
    void ancient_things_baowu_show(WXBTNEVT&);
    void ancient_things_baowu_maichu(WXBTNEVT&);
    void ancient_things_bookshelf(WXBTNEVT&);

    void ancient_guan(WXBTNEVT&);

    void ancient_wenguan(WXBTNEVT&);
    void ancient_wenguan_fenglu(WXBTNEVT&);
    void ancient_wenguan_zhengji(WXBTNEVT&);
    void ancient_zhengji_jinjian(WXBTNEVT&);
    void ancient_zhengji_shengguan(WXBTNEVT&);
    void ancient_zhengji_zhenji(WXBTNEVT&);
    void ancient_zhengji_huilu(WXBTNEVT&);
    void ancient_zhengji_miansheng(WXBTNEVT&);

    void ancient_wuguan(WXBTNEVT&);
    void ancient_wuguan_1(WXBTNEVT&);

    void ancient_wuguan_zhaomu(WXBTNEVT&);
    void ancient_wuguan_show(WXBTNEVT&);
    void ancient_wuguan_bingli(WXBTNEVT&);
    void ancient_wubingli_get(WXBTNEVT&);
    void ancient_wubingli_plus(WXBTNEVT&);
    void ancient_wuguan_chuzheng(WXBTNEVT&);
    void ancient_wuguan_chuzheng_1(WXBTNEVT&);

    void ancient_juanzeng(WXBTNEVT&);
    void ancient_juanzeng_lingqu(WXBTNEVT&);
    void ancient_juanzeng_juanxian(WXBTNEVT&);

    void things_square(WXBTNEVT&);

    void tsquare_free(WXBTNEVT&);
    void tsquare_free_jifen(WXBTNEVT&);
    void tsqaure_free_xianbi(WXBTNEVT&);
    void tsquare_free_tongqian(WXBTNEVT&);
    void tsquare_free_baoshi(WXBTNEVT&);
    void tsquare_free_jinbi(WXBTNEVT&);

    void tsquare_jinbi(WXBTNEVT&);
    void tsquare_jinbi_tongqian(WXBTNEVT&);
    void tsquare_jinbi_baoshi(WXBTNEVT&);
    void tsquare_jinbi_yinbi(WXBTNEVT&);
    void tsquare_jinbi_xianbi(WXBTNEVT&);

    void tsquare_jinbimh(WXBTNEVT&);
    void tsquare_jinbimh_simple(WXBTNEVT&);
    void tsquare_jinbimh_ancient(WXBTNEVT&);

    void bank_square(WXBTNEVT&);
    void bank_store(WXBTNEVT&);
    void bank_get(WXBTNEVT&);

    void tongy_all(WXBTNEVT&);
    void tongy(WXBTNEVT&);
    void tongy_show(WXBTNEVT&);

private:

    wxPanel* panel;
    wxStaticText* nowtime;
    timer study_timer;
    wxTimer TimeTimer;

    void showtime();
    void empfunc(WXBTNEVT&) {};
    void main_func(WXBTNEVT&) {
        this -> start() ;
    }

    void onclickys1(poly,wxTextCtrl*,wxTextCtrl*,WXEVT,wxButton*) oldblock;

    void CallBack1(WXBTNEVT&);

    void acz_win();
    void acz_lose();

    poly ys1User[6] oldblock;
    int count oldblock;

};
