#pragma once
#include "sigc++/signal.h"
#include <sigc++/sigc++.h>

struct _GlobalSignal {
    sigc::signal<void()>         AncientBookstoreJiaomai;
    sigc::signal<void()>         AncientBookstoreJiaomaiPushed;
    sigc::signal<void()>         AncientBookstoreJiaomaiPushedDone;
    sigc::signal<void()>         BankJuanUseJiFen;
    sigc::signal<void(int)>      BankJuanUseJiFenUse;
    sigc::signal<void()>         AncientBookstoreChaoLuAll;
};
inline _GlobalSignal GlobalSignal;
