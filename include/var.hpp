#pragma once
#include <string>
#include <cstdlib>
#include <utils/files/PasswordFile.hpp>
#include <utils/files/Cards.hpp>
#include <utils/files/CheckFile.hpp>
#include <utils/files/BoolFile.h>
#include <functions/xianbi/sword.hpp>
#include <functions/ancient/sword.hpp>
#include <functions/ancient/pao.hpp>
#include <ffi/zig/AncientWenGuan/AncientWenGuanCpp.hpp>
#include <ffi/zig/AncientBaoWu/AncientBaoWuCpp.hpp>
#include <ffi/zig/BookShelf/BookShelfCpp.hpp>
#include <ffi/zig/AncientYuZhan/AncientYuZhanCpp.hpp>
#include <ffi/zig/AncientJinYinZhu/AncientJinYinZhuCpp.hpp>
#include <ffi/zig/AncientBaoWuCha/AncientBaoWuChaCpp.hpp>
#include <ffi/zig/AncientGuWanCha/AncientGuWanChaCpp.hpp>

const std::string User = getenv("USER");

// 文件

const std::string FilePathBase = getenv("HOME")+std::string("/.store/");
const std::string FilePath = FilePathBase+"学习平台储存/";
const std::string FilePathPao = FilePath + "apcdir/";
const std::string FilePathXianQi = FilePath + "xqptdir/";
const std::string FilePathBaoWu = FilePath + "baocdiran/";
const std::string FilePathCard = FilePath + "fpcdiralf/";
const std::string FilePathThingsSquare = FilePath + "tssqudirdpg/";
const std::string FilePathBaoShi = FilePath + "baosdirfos/";
const std::string FilePathBookShelf = FilePath + "sjdirspf/";
const std::string FilePathTongYong = FilePath + "tyhbdirapbb/";
const std::string FilePathAncient = FilePath + "adirspfm/";
const std::string FilePathXianJi = FilePath + "xjccdir.fjdo/";
const std::string FilePathXianDan = FilePath + "xdccdir.fdso.so12/";
const std::string FilePathLiHe = FilePathBase + "礼盒储存/";
const std::string FilePathLiHeBool = FilePath + "lhccc.dir.sdo/";

namespace Files
{
static PasswordFile JiFenReader(FilePath+"jifc.txt","hsiep10475");
static PasswordFile JiSuanBiReader(FilePath+"jsbc.txt","woda2fj341");
static PasswordFile XianBiReader(FilePath+"xianbc.conc","woapf20sl1");
static PasswordFile FaLiReader(FilePath+"falc.conc","fjmep20kl1");
static PasswordFile XianQiFaLiReader(FilePathXianQi+"xqfl.conc","hjq40tp586");
static PasswordFile JinBiReader(FilePathTongYong+"rd.conc","apslfnt104");
static PasswordFile YinBiReader(FilePathTongYong+"yb.conc.sdpg.1659", "apfjr12409");
namespace XianJi
{
static PasswordFile Reader(FilePathXianJi+"xjrd.dso.349fern.cc", "sdoih14853");
}
namespace Xian{
namespace Dan{
static PasswordFile PuTong(FilePathXianDan+"pt.cc.xdcc.1304", "sdpf24j109");
static PasswordFile Bi(FilePathXianDan+"bd.c.xdccm.eo4", "fqoeirm124");
static PasswordFile Qing(FilePathXianDan+"qd.c.xdcc.ej.e", "fdoiem2401");
static PasswordFile Zi(FilePathXianDan+"zd.c.xdcc.edos", "zdgofe2405");
static PasswordFile WuSe(FilePathXianDan+"ws.cd.gfgoi.xdcc", "dsoi23w105");
static PasswordFile Yin(FilePathXianDan+"yd.c.xdcc.fdor", "sdognf3214");
static PasswordFile Jin(FilePathXianDan+"jd.cc.xdcc.23dsj", "adogfn2104");
static PasswordFile Shen(FilePathXianDan+"sd.cc.xdcc.239fh", "sdonv29810");
}
}
namespace BookShelf
{
static BookShelfFiles* Reader = BookShelfFiles_New(
                                    (char*)(FilePathBookShelf+"lv1cc.conc").c_str(),
                                    (char*)(FilePathBookShelf+"lv2cc.conc").c_str(),
                                    (char*)(FilePathBookShelf+"lv3cc.conc").c_str(),
                                    3406
                                );
}
namespace BaoShi
{
static PasswordFile Reader(FilePathBaoShi+"mbsc.conc","rosl3510dm");
}
}

namespace Card
{
static std::vector<std::string> emptyVector;

// SanGuo1Card
static std::vector<std::string> SanGuo1Vec( {
    "卧龙","凤雏","曹操","孙权","刘备",
    "关羽","张飞","马超","黄忠","赵云",
    "张辽","徐晃","张郃","于禁","乐进",
    "许褚","典韦","关兴","张苞","曹纯",
    "周瑜","鲁肃","吕蒙","陆逊","陆抗",
    "徐盛","丁奉","马忠","潘璋","黄盖",
    "郭嘉","程昱","荀彧","荀攸","荀谌",
    "张昭","顾雍","阚泽","程秉","虞翻",
    "张南","冯习","魏延","姜维","邓艾","钟会",
}
                                          );
static Cards CardSanGuo1(FilePath+"capsgc1.txt",SanGuo1Vec,9573);

// Ming1Card
static std::vector<std::string> Han1Vec( {
    "刘邦","刘盈","刘恒","刘启","刘彻",
    "刘询","刘秀","刘庄","刘炟","刘贺",
    "萧何","韩信","张良","英布","吕后",
    "周勃","陈平","曹参","卫青","霍光",
    "王莽","邓禹","寇恂","班超","班固",
    "班昭","张骞","马援","苏武","李广",
    "刘安","刘长","刘歆","刘玄","王匡",
    "王凤","董卓","刘辩","刘协","刘宏",
    "伏完","董承","杨彪","王允","孔融",
}
                                       );
static Cards CardHan1(FilePathCard+"h1cac1.cac",Han1Vec,7184);

}

namespace Check
{
static CheckFile JiSuanBiCheck1(FilePath+"jisbck1.txt",1049,5);
static CheckFile JiSuanBiCheck2(FilePath+"jisbck2.txt",305,5);
static CheckFile JiSuanBiCheck3(FilePath+"jisbck3.chkl",302,3);
static CheckFile JiSuanBiCheck4(FilePath+"jisbchk4.chkl",205,5);
}

namespace Other
{
static functions::SwordInFile Sword(FilePath+"swdif.conc");
}

namespace AncientVar
{
static Ancient::AncientSword Sword(FilePath+"avswd.avc",FilePath+"avswa.avc");
static Ancient::AncientPao Pao(FilePathPao+"paon.paoc",FilePathPao+"paoa.paoac");
static AncientBaoWuStruct* BaoWuStruct = AncientBaoWuStruct_Create(
            (char*)(FilePathBaoWu+"baoyemz.bacc").c_str(),
            (char*)(FilePathBaoWu+"yudc.bacc").c_str(),
            (char*)(FilePathBaoWu+"byubc.bacc").c_str(),
            (char*)(FilePathBaoWu+"baochoc.bacc").c_str(),
            2109
        );
static YuZhan* YuZhanReader = YuZhan_Create(
            (char*)(FilePathBaoWu+"baoyzex.bacce").c_str(),
            2024
);
static AncientJinYinZhu* JinYinZhuReader = AncientJinYinZhu_New(
            (char*)(FilePathBaoWu+"jzcc.conc").c_str(), 
            (char*)(FilePathBaoWu+"yzcc.conc").c_str(),
            1657
        );
static BaoWuChaFiles* BaoWuChaReader = BaoWuChaFiles_Make(
            (char*)(FilePathBaoWu+"bwcrdc1.onc").c_str(),
            (char*)(FilePathBaoWu+"bwcrd2.onc").c_str(),
            2017
        );

static PasswordFile TongBiReader(FilePath+"tb.avc","hifo356sjl");
static PasswordFile BaiYinReader(FilePath+"bay.avc","3ifnyl1042");
static PasswordFile HuangJinReader(FilePath+"huaj.avc","dgp395sk10");

namespace Guwan
{
static PasswordFile CiQiReader(FilePath+"cq.avgwc","so3pfm10a2");
static PasswordFile ShiBeiReader(FilePath+"shb.avgwc","sudo1048qp");
static PasswordFile YuPeiReader(FilePath+"yup.avgwc","sofp194327");
static GuWanChaFiles* ChaReader = GuWanChaFiles_Make(
    (char*)(FilePathAncient+"apdfn.gwcc1.conc").c_str(),
    (char*)(FilePathAncient+"asofn.gwcc2.conc").c_str(),
    2353
);
}

namespace WenGuan
{
static CheckFile FengLuCheck(FilePath+"flchk.awgcc",4034,1);
static AncientWenGuanConfig* WenGuanConf = AncientWenGuanConfig_Create((FilePath+"awcfg.awgcc").c_str(),1052); // 不接受std::string
namespace ZhengJi
{
static PasswordFile ZhengJiReader(FilePath+"zhejrder.awgcc","eso1pam360");
namespace JinJian
{
static CheckFile Check(FilePath+"zhejjjchk.chklawgcc",1039,1);
}
namespace ZhenJi
{
static CheckFile Check(FilePathAncient+"zjzjck.ckawgcc",4059,1);
}
namespace MianSheng
{
static CheckFile Check(FilePathAncient+"msmsck.ckawgcc.dsi.1234",2125,1);
}
}
}
namespace JuanZeng
{
static PasswordFile Reader(FilePathAncient+"jzrd.conc","dfpwm13058");
static CheckFile LingQuCheck(FilePathAncient+"jzrd.conc.lqck.conc",1250,1);
}
}

namespace ThingsSquare
{
static CheckFile JiFenCheck(FilePathThingsSquare+"tsjfcc.ck",6402,1);
static CheckFile XianBiCheck(FilePathThingsSquare+"tsxbcc.ck",2202,1);
static CheckFile TongQianCheck(FilePathThingsSquare+"tqchk.ck",2212,1);
static CheckFile BaoShiCheck(FilePathThingsSquare+"fospbsck.dogck",1127,1);
static CheckFile JinBiCheck(FilePathThingsSquare+"sdogh.dogck",2035,1);
}

namespace LiHe
{
  enum class Types{
    XianBiBasic,
  };
  namespace IsUsed{
    static BoolFile XianBiBasic(FilePathLiHeBool+"xbbsc.cc.sdo", "pedifs", "SDogSd");
  }
}

// 简单符号

#define NEWLINE "\n"
#define SPACE " "

// 别名
namespace AncientZhengJi = AncientVar::WenGuan::ZhengJi;
#define AncientZhengJiReader AncientZhengJi::ZhengJiReader
#define BaoShiReader Files::BaoShi::Reader
