#include "starlight/view.hpp"
#include "starlight/menu/menu.hpp"
#include "operator.h"

namespace starlight {
    View::View() {
        mMenuStack = std::stack<menu::BaseMenu*>();
        mPop = false;
        mPushMenu = NULL;
    }

    void View::update(){
        if(mPop){
            delete mMenuStack.top();
            mMenuStack.pop();
            mPop = false;
        }
        if(mPushMenu != NULL){
            mMenuStack.push(mPushMenu);
            mPushMenu = NULL;
        }

        if(!mMenuStack.empty()){
            menu::BaseMenu *peek = mMenuStack.top();
            peek->update(this);
        }
    }

    void View::render(sead::TextWriter* textWritter){
        if(!mMenuStack.empty()){
            menu::BaseMenu* peek = mMenuStack.top();
            peek->render(textWritter);
        }
    }

    void View::pushMenu(menu::BaseMenu* menu){
        mPushMenu = menu;
    }


    void View::popMenu(){
        mPop = true;
    }
};