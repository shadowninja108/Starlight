#pragma once

#include "types.h"
#include <stack>
#include "starlight/menu/menu.hpp"
#include "sead/textwriter.h"

namespace starlight {

    namespace menu {
        class BaseMenu;
    };

    class View {
        public:
        std::stack<starlight::menu::BaseMenu*> mMenuStack;

        bool mIsRendering;
        bool mPop;
        starlight::menu::BaseMenu* mPushMenu;

        View();

        void update();
        void render(sead::TextWriter*);

        void pushMenu(starlight::menu::BaseMenu*);
        void popMenu();
    };
};