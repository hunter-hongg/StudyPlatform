#pragma once
#include <stdint.h>

typedef struct {
    char* ChaHu;
    char* ChaZhan;
    int32_t AddNum;
} BaoWuChaFiles;
BaoWuChaFiles* BaoWuChaFiles_Make(char*, char*, int32_t);
void BaoWuChaFiles_Free(BaoWuChaFiles*);
int32_t BaoWuChaFiles_Read(BaoWuChaFiles*, int32_t);
void BaoWuChaFiles_Add(BaoWuChaFiles*, int32_t, int32_t);