#pragma once
#include <stdint.h>

typedef struct{
    char* MingZhu;
    char* YuDiao;
    char* YuBi;
    char* ChouDuan;
    int32_t AddNum;
} AncientBaoWuStruct;

typedef struct{
    int32_t MingZhu;
    int32_t YuDiao;
    int32_t YuBi;
    int32_t ChouDuan;
} AncientBaoWuResult;

AncientBaoWuStruct* AncientBaoWuStruct_Create(char*,char*,char*,char*,int32_t);
void AncientBaoWuStruct_Free(AncientBaoWuStruct*);
int32_t AncientBaoWuStruct_Write(AncientBaoWuStruct*,int32_t,int32_t);
AncientBaoWuResult* AncientBaoWuResult_CreateFrom(AncientBaoWuStruct*);
void AncientBaoWuResult_Free(AncientBaoWuResult*);