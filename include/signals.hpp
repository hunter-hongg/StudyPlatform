#pragma once
#include "sigc++/signal.h"
#include <sigc++/sigc++.h>

struct _GlobalSignal {
    sigc::signal<void()> AncientBookstoreJiaomai;
    sigc::signal<void()> AncientBookstoreJiaomaiPushed;
};
inline _GlobalSignal GlobalSignal;
