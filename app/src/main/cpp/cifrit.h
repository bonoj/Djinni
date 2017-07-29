//
// Created by John on 7/29/2017.
//

#ifndef THEJNI_CIFRIT_H
#define THEJNI_CIFRIT_H

#include <android/log.h>

#define APPNAME "DJINNI"

int undoGenieOperations(int a) {

    __android_log_print(ANDROID_LOG_INFO, APPNAME, "Undoing Genie Operations!");

    return a - 77;
}

#endif //THEJNI_CIFRIT_H
