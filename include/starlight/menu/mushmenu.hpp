#pragma once

#include "types.h"
#include "starlight/collector.hpp"
#include "starlight/mush/mushview.hpp"
#include "simplemenu.hpp"

namespace starlight {

    namespace menu {

        class MushViewMenu : public BaseMenu {
            public:
            enum MushType {
                Map, Weapon, End
            };
            
            MushType mSelectedType;
            int mSelectedIndex;

            mush::MushView* mMushViews[MushType::End];

            MushViewMenu();

            virtual ~MushViewMenu();

            virtual void update(starlight::View*);
            virtual void render(sead::TextWriter*);
        };
    }; 
};