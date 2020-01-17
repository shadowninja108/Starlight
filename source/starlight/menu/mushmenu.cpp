#include "starlight/menu/mushmenu.hpp"

namespace starlight {

    namespace menu {

        MushViewMenu::MushViewMenu() {
            mSelectedType = MushType::Map;
            mMushViews[MushType::Map] = new mush::MapMushView();
            mMushViews[MushType::Weapon] = new mush::WeaponMushView();
        }

        MushViewMenu::~MushViewMenu() {
            for(int i = 0; i < MushType::End; i++)
                delete mMushViews[i];
        }
        
        void MushViewMenu::update(starlight::View* view){
            signed int selectedType = mSelectedType;

            if(Collector::mController.isPressed(Controller::LeftDpad)){
                selectedType--;
            }
            if(Collector::mController.isPressed(Controller::RightDpad)){
                selectedType++;
            }

            if(selectedType < 0 || MushType::End <= selectedType)
                mSelectedType = (MushType) 0;
            else
                mSelectedType = (MushType) selectedType;

            if(Collector::mController.isPressed(Controller::B))
                view->popMenu();

                
            if(Collector::mController.isPressed(Controller::UpDpad)){
                mSelectedIndex--;
            }
            if(Collector::mController.isPressed(Controller::DownDpad)){
                mSelectedIndex++;
            }

            if(mSelectedIndex < 0)
                mSelectedIndex = 0;
            else if(mMushViews[mSelectedType]->getSize() <= mSelectedIndex)
                mSelectedIndex = 0;
        }

        void MushViewMenu::render(sead::TextWriter* textWriter){
            textWriter->printf("%i %i\n", mSelectedIndex, mSelectedType);

            mMushViews[mSelectedType]->render(textWriter, mSelectedIndex);
        }
    };
};