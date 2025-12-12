#pragma once
#include <stdint.h>

typedef struct {
    char* JinZhu;
    char* YinZhu;
    int32_t AddNum;
} AncientJinYinZhu;
AncientJinYinZhu* AncientJinYinZhu_New(char*, char*, int32_t);
void AncientJinYinZhu_Free(AncientJinYinZhu*);
int32_t AncientJinYinZhu_Read(AncientJinYinZhu*, int32_t);
void AncientJinYinZhu_Write(AncientJinYinZhu*, int32_t, int32_t);