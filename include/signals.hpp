#pragma once
#include <sigc++/sigc++.h>

struct _GlobalSignal {
    sigc::signal<void()> AncientBookstoreJiaomai;
};
inline _GlobalSignal GlobalSignal;
