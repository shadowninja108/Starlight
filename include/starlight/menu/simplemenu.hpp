#pragma once

#include "types.h"
#include <functional>
#include "menu.hpp"
#include "operator.h"
#include "../view.hpp"

namespace starlight {
    
    class View;

    namespace menu {

        class SimpleMenu : public BaseMenu {
            public:
            std::vector<BaseMenuEntry*> mEntries;
            signed int mSelectedIndex;

            virtual ~SimpleMenu();

            virtual void update(starlight::View*);
            virtual void render(sead::TextWriter*);
        };

        class SimpleMenuEntry : public BaseMenuEntry {
            public: 
            std::function<void()> mUpdateCallback;
            std::function<std::string()> mRenderCallback;
            std::function<void(starlight::View*)> mSelectedCallback;

            SimpleMenuEntry();

            virtual void update();
            virtual std::string render();
            virtual void selected(starlight::View*);
        };
    };
};