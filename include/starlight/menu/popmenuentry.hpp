#pragma once

#include "types.h"
#include "simplemenu.hpp"
#include "operator.h"
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