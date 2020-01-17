#include "starlight/menu/simplemenu.hpp"

namespace starlight {

    namespace menu {
        
        void SimpleMenu::update(starlight::View* view) {
            // handle inputs
            if(Collector::mController.isPressed(Controller::Buttons::UpDpad))
                mSelectedIndex--;
            if(Collector::mController.isPressed(Controller::Buttons::DownDpad))
                mSelectedIndex++;

            // handle under/overflow
            int size = mEntries.size();
            if(mSelectedIndex < 0)
                mSelectedIndex = size-1;
            if(mSelectedIndex >= size)
                mSelectedIndex = 0;

            // update entries
            std::vector<BaseMenuEntry*>::iterator it;
            int i = 0;
            for (it = mEntries.begin(); it != mEntries.end(); ++it){
                auto& entry = *it;
                entry->update(view);
                if(Collector::mController.isPressed(Controller::Buttons::L))
                    if(i == mSelectedIndex)
                        entry->selected(view);
                i++;
            }
        }

        void SimpleMenu::render(sead::TextWriter* textWriter){
            int i = 0;
            std::vector<BaseMenuEntry*>::iterator it;
            for (it = mEntries.begin(); it != mEntries.end(); ++it){
                auto& entry = *it;
                const char* prefix = " ";
                if(i == mSelectedIndex){
                    prefix = ">";
                }
                
                std::string str = entry->render();
                textWriter->printf("%s%s\n", prefix, str.c_str());

                i++;
            }
        }

        SimpleMenu::~SimpleMenu(){
            for(auto const& value: mEntries) {
                delete value;
            }
        }

        SimpleMenuEntry::SimpleMenuEntry(){
        }

        void SimpleMenuEntry::update(starlight::View*) {
            if(mUpdateCallback != NULL)
                mUpdateCallback();
        }

        std::string SimpleMenuEntry::render(){
            if(mRenderCallback != NULL)
                return mRenderCallback();
            else
                return std::string();
        }

        void SimpleMenuEntry::selected(View* view){
            if(mSelectedCallback != NULL)
                mSelectedCallback(view);
        }
    };
};