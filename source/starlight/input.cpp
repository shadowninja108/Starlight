#include "starlight/input.hpp"

namespace starlight {

    Controller::Controller() {}

    Controller::Controller(Lp::Sys::Ctrl *controller){
        mController = controller;
    }

    void Controller::update(){
        mLastPoll = mController->mData1.mButtons;
    }

    long Controller::isHeld(Buttons inputs) {
        return mController->mData1.mButtons & inputs;
    }

    long Controller::isPressed(Buttons inputs) {
        bool buttonHeld = mController->mData1.mButtons & inputs;
        return buttonHeld & !(mController->mData1.mButtons & mLastPoll & inputs);
    }
};