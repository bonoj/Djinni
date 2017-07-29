//
// Created by John on 7/29/2017.
//

#ifndef THEJNI_CGENIE_H
#define THEJNI_CGENIE_H

#include <android/log.h>

#define APPNAME "DJINNI"

int performGenieOperations(int a) {

    __android_log_print(ANDROID_LOG_INFO, APPNAME, "Performing Genie Operations!");

    return a + 77;
}

#endif //THEJNI_CGENIE_H
