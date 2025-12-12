#include <stdint.h>

typedef struct {
    char* file;
    int32_t addnum;
} AncientWenGuanConfig;

extern AncientWenGuanConfig* AncientWenGuanConfig_Create(const char*,int32_t);
extern void AncientWenGuanConfig_Free(AncientWenGuanConfig*);
extern int32_t AncientWenGuanConfig_ReadLevel(AncientWenGuanConfig*);
extern int32_t AncientWenGuanConfig_NewLevel(AncientWenGuanConfig*,int32_t);
extern int32_t AncientWenGuanConfig_LevelUp(AncientWenGuanConfig*);
extern int32_t AncientWenGuanConfig_LevelDown(AncientWenGuanConfig*);
extern int32_t AncientWenGuanConfig_GetFengLu(AncientWenGuanConfig*);
