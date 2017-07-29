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

jobject copyObj(jobject obj) {
    return obj;
}

jobject createMeshDataObject(JNIEnv *env, jint param) {
    jclass cls = env->FindClass("me/bonoj/thejni/data/MeshData");
    jmethodID  methodId = env->GetMethodID(cls, "<init>", "(I)V");

    jobject obj = env->NewObject(cls, methodId, param);

    __android_log_print(ANDROID_LOG_INFO, APPNAME, "Returning new MeshData object");

    return obj;
}

#endif //THEJNI_CGENIE_H
