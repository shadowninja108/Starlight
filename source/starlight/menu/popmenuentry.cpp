#include "starlight/menu/popmenuentry.hpp"

namespace starlight {
    namespace menu {
        PopMenuEntry::PopMenuEntry() : SimpleMenuEntry(){
        }

        std::string PopMenuEntry::render(){
            return std::string("Back");
        }
        
        void PopMenuEntry::selected(View* view){
            view->popMenu();
        }

    };
};