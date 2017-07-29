#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_me_bonoj_thejni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_me_bonoj_thejni_MainActivity_anotherStringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string helloAgain = "Hello again from C++";
    return env->NewStringUTF(helloAgain.c_str());
}

extern "C"
JNIEXPORT jint

JNICALL
Java_me_bonoj_thejni_MainActivity_intFromJNI() {
    return 5;
}
