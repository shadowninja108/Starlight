#pragma once

#include "types.h"

#include "menu.hpp"
#include <functional>


namespace starlight 
{
    namespace menu {

        class SelectorMenuEntry : BaseMenuEntry {

            public:
            SelectorMenuEntry();

            std::vector<std::string> mSelections;
            int mSelectedIndex;
            std::function<void(int, std::string&)> mSelectionChangedCallback;
            std::function<void(starlight::View*)> mSelectedCallback;

            virtual void update(starlight::View*);
            virtual std::string render();
            virtual void selected(starlight::View*);
        };
    };
};