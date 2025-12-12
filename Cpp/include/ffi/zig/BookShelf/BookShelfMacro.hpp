#pragma once
#define BookShelfResult_Get(bookshelf) \
    auto bookshelfresult = BookShelfFiles_Read(bookshelf); \
    int Level1 = bookshelfresult->Level1; \
    int Level2 = bookshelfresult->Level2; \
    int Level3 = bookshelfresult->Level3; \
    BookShelfResult_Free(bookshelfresult);
