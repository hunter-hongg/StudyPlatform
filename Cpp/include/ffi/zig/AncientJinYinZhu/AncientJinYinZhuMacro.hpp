#pragma once
#define AncientJinYinZhu_JinZhu 0
#define AncientJinYinZhu_YinZhu 1
#define AncientJinYinZhu_Get(obj) \
    int JinZhu = AncientJinYinZhu_Read(obj, 0); \
    int YinZhu = AncientJinYinZhu_Read(obj, 1);