#pragma once
#define AncientBaoWuCha_ChaHu 0
#define AncientBaoWuCha_ChaZhan 1
#define AncientBaoWuCha_Get(obj) \
    int ChaHu = BaoWuChaFiles_Read(obj, 0); \
    int ChaZhan = BaoWuChaFiles_Read(obj, 1);