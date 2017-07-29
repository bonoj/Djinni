#include <jni.h>
#include <string>
#include "cgenie.h"
#include "cifrit.h"
#include <android/log.h>

#define APPNAME "DJINNI"

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
Java_me_bonoj_thejni_MainActivity_intFromJNI(JNIEnv *env) {
    return 5;
}

extern "C"
JNIEXPORT
jfloat
JNICALL
Java_me_bonoj_thejni_MainActivity_getMemberFieldFromNative(
        JNIEnv *env,
        jobject callingObject,
        jobject obj) //obj is the MeshData java object passed
{
    float result = 0.0f;

    //Get the passed object's class
    jclass cls = env->GetObjectClass(obj);

    // get field [F = Array of float
    jfieldID fieldId = env->GetFieldID(cls, "VertexCoords", "[F");

    // Get the object field, returns JObject (because it’s an Array)
    jobject objArray = env->GetObjectField (obj, fieldId);

    // Cast it to a jfloatarray
    jfloatArray* fArray = reinterpret_cast<jfloatArray*>(&objArray);

    jsize len = env->GetArrayLength(*fArray);

    // Get the elements
    float* data = env->GetFloatArrayElements(*fArray, 0);

    for(int i=0; i<len; ++i)
    {
        result += data[i];
    }

    // Don't forget to release it
    env->ReleaseFloatArrayElements(*fArray, data, 0);

    return result;
}

extern "C"
JNIEXPORT jint

JNICALL
Java_me_bonoj_thejni_MainActivity_getSizeFieldFromLamp(
        JNIEnv *env,
        jobject callingObject,
        jobject obj) {

    int size = -1;

    jobject copiedObj = copyObj(obj);

    jint facetParam = 10;
    jobject createdMeshDataObj = createMeshDataObject(env, 10);

    // Get the passed object's class
    jclass  cls = env->GetObjectClass(obj);

    // Get the desired fieldId
    jfieldID fieldId = env->GetFieldID(cls, "size", "I");

    __android_log_print(ANDROID_LOG_INFO, APPNAME, "Logging from C++");

    size = env->GetIntField (obj, fieldId);

    int sizeModifiedByGenie = performGenieOperations(size);
    sizeModifiedByGenie = undoGenieOperations(sizeModifiedByGenie);

    return sizeModifiedByGenie;
}

