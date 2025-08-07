#pragma once
#define AncientBaoWuResult_Get() \
    AncientBaoWuResult* BaoWuResult = AncientBaoWuResult_CreateFrom(AncientVar::BaoWuStruct); \
    int MingZhu = BaoWuResult -> MingZhu; \
    int YuDiao = BaoWuResult -> YuDiao; \
    int YuBi = BaoWuResult -> YuBi; \
    int ChouDuan = BaoWuResult -> ChouDuan; \
    AncientBaoWuResult_Free(BaoWuResult)
#define AncientBaoWu_MingZhu 0
#define AncientBaoWu_YuDiao 1
#define AncientBaoWu_YuBi 2
#define AncientBaoWu_ChouDuan 3