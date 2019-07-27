#pragma once

#include "types.h"
#include "operator.h"
#include "simplemenu.hpp"
#include "../view.hpp"

namespace starlight {
    
    class View;

    namespace menu {

        class PopMenuEntry : public SimpleMenuEntry {
            public: 
            std::string str;

            PopMenuEntry();

            virtual std::string render();
            virtual void selected(starlight::View*);
        };
    };
};