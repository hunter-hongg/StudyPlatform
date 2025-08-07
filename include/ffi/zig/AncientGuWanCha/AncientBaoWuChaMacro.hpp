#pragma once
#define AncientGuWanCha_ChaHu 0
#define AncientGuWanCha_ChaZhan 1
#define AncientGuWanCha_Get(obj) \
    int ChaHu = GuWanChaFiles_Read(obj, 0); \
    int ChaZhan = GuWanChaFiles_Read(obj, 1);