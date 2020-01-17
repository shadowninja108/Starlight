#pragma once

#include <vector>
#include <string>
#include "../collector.hpp"
#include "../view.hpp"
#include "sead/textwriter.h"

namespace starlight {
    
    class View;

    namespace menu {
        
        class BaseMenu {
            public:

            virtual ~BaseMenu() = 0;

            virtual void update(starlight::View*) = 0;
            virtual void render(sead::TextWriter*) = 0;
        };

        class BaseMenuEntry {
            public:

            virtual void update(starlight::View*) = 0;
            virtual std::string render() = 0;
            virtual void selected(starlight::View*) = 0;
        };
    };
};