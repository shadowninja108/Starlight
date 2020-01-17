#include "starlight/menu/selectormenuentry.hpp"

namespace starlight {
    namespace menu {

        void SelectorMenuEntry::update(starlight::View*) {

            if(mSelections.empty())
                return;

            int size = mSelections.size();
            int index = mSelectedIndex;

            if(Collector::mController.isPressed(Controller::Buttons::LeftDpad))
                index--;
            if(Collector::mController.isPressed(Controller::Buttons::RightDpad))
                index++;

            if(index < 0)
                index = size - 1;
            if(size <= index)
                index = 0;


            if(mSelectedIndex != index){
                if(mSelectionChangedCallback != NULL)
                    mSelectionChangedCallback(mSelectedIndex, mSelections.at(mSelectedIndex));

                mSelectedIndex = index;
            }
        }

        std::string SelectorMenuEntry::render() {
            if(!mSelections.empty())
                return "< " + mSelections.at(mSelectedIndex) + " >";
            else
                return "<>";
        }

        void SelectorMenuEntry::selected(starlight::View* view) {
            if(mSelectedCallback != NULL)
                mSelectedCallback(view);
        }
    };
};