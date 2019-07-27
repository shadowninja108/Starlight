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
        private:
        starlight::menu::BaseMenu* mPushMenu;
        std::stack<starlight::menu::BaseMenu*> mMenuStack;
        bool mIsRendering;
        bool mPop;
        
        public:

        View();

        void update();
        void render(sead::TextWriter*);

        void pushMenu(starlight::menu::BaseMenu*);
        void popMenu();
    };
};