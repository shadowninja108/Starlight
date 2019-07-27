#include "starlight/input.hpp"

namespace starlight {

    Controller::Controller() {}

    Controller::Controller(Lp::Sys::Ctrl *controller){
        mController = controller;
    }

    void Controller::update(){
        mLastPoll = mController->data;
    }

    long Controller::isHeld(Buttons inputs) {
        return mController->data & inputs;
    }

    long Controller::isPressed(Buttons inputs) {
        bool buttonHeld = mController->data & inputs;
        return buttonHeld & !(mController->data & mLastPoll & inputs);
    }
};