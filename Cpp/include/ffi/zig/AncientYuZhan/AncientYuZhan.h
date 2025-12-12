#pragma once
struct YuZhan {
    char* file;
    int AddNum;
};
YuZhan* YuZhan_Create(char*, int);
void YuZhan_Free(YuZhan*);
int YuZhan_Get(YuZhan*);
void YuZhan_Write(YuZhan*, int);