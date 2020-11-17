#include "PLUGIN_NAMEBPLibrary.h"
#include "PLUGIN_NAME.h"
#include "Async/Async.h"
#include "Engine.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"

#include "Android/Utils/AndroidUtils.h"
#endif

#if PLATFORM_IOS

#endif


//==== ���� ������ / Class body==============================================
UPLUGIN_NAMEBPLibrary::UPLUGIN_NAMEBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

// #~~~~~~~~~~~~~~~~~~~~~~~~~~~ begin 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//------- ���������� ����� ��������� ���� / Synchronous invocation of native code -------
FString UPLUGIN_NAMEBPLibrary::HelloWorld(FString String)
{
#if PLATFORM_ANDROID	
	/*
	* "com/epicgames/ue4/TestJavaClass" - package(������������ com/epicgames/ue4) � ��� ������ Java ������ / package (used by com/epicgames/ue4) and the name of your Java class.
	* "HelloWorldOnAndroid" - ��� ����� Java ������� / Name of your Java function.
	* false - ���������� ����� �� ���������� Activity UE4 � Java / Determines whether to pass Activity UE4 to Java.
	* String -
	* ������ ����� ���������� � Java �������(���� ��� ���������� � Java ���� ����������� �������� jobject,
	* ��� ������� ����� ������� ������� ������������������) /
	* A list of your parameters in the Java function(if the variable type in the Java code is specific, such as jobject, it should be converted before calling the function).
	*/

	String = AndroidUtils::CallNativeAndroid<FString>("com/epicgames/ue4/TestJavaClass", "HelloWorldOnAndroid", false, String);
	
#endif //Android

#if PLATFORM_IOS

#endif// IOS

	return String;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ end 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// #~~~~~~~~~~~~~~~~~~~~~~~~~~~ begin 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//==== ������������ ���������� ���������� / Initialization of static variables===========
FTypeDispacth UPLUGIN_NAMEBPLibrary::FStaticValueDispatch;

//------- ����������� ����� ��������� ���� / Asynchronous calling of native code ------
void UPLUGIN_NAMEBPLibrary::asyncHelloWorld(const FTypeDispacth& CallBackDispatch, FString String)
{
	UPLUGIN_NAMEBPLibrary::FStaticValueDispatch = CallBackDispatch;

#if PLATFORM_ANDROID
	AndroidUtils::CallNativeAndroidVoid("com/epicgames/ue4/TestJavaClass", "asyncHelloWorldOnAndroid", true, String);

#endif //Android

#if PLATFORM_IOS

#endif// IOS
}

//------- �������� ������� Java ���� / Native functions in Java code ---------
#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_TestJavaClass_CallBackCPP(JNIEnv* env, jclass clazz, jstring returnStr)
{
	FString result = JavaConvert::FromJavaFString(returnStr);
	UE_LOG(LogTemp, Warning, TEXT("asyncHelloWorld callback caught in C++! - [%s]"), *FString(result)); //Debug log for UE4
	UPLUGIN_NAMEBPLibrary::FStaticFunctDispatch(result);//������� ���������
}
#endif //PLATFORM_ANDROID

//-------���� ���������� / Dispatcher body --------------------------
void UPLUGIN_NAMEBPLibrary::FStaticFunctDispatch(FString FValueReturnDispatch)
{
	//������ ������� ��� ����������/Lambda function for the dispatcher
	AsyncTask(ENamedThreads::GameThread, [=]() {
		FStaticValueDispatch.ExecuteIfBound(FValueReturnDispatch);
		});
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~ end 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// #~~~~~~~~~~~~~~~~~~~~~~~~~~ begin 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//------- ����� ������������ ��������� / Calling a pop-up message ------------------
void UPLUGIN_NAMEBPLibrary::ShowToastMobile(FString String, ToastLengthMessage length)
{
#if PLATFORM_ANDROID
	FString TextForToast = FString("Your message: " + String);

	TextForToast += " Your phone: ";
	TextForToast += FString(AndroidUtils::CallNativeAndroid<FString>("com/epicgames/ue4/TestJavaClass", "getBrand", false));
	TextForToast += " " + FString(AndroidUtils::CallNativeAndroid<FString>("com/epicgames/ue4/TestJavaClass", "getModel", false));
	TextForToast += " ID: ";
	TextForToast += FString(AndroidUtils::CallNativeAndroid<FString>("com/epicgames/ue4/TestJavaClass", "getAndroidId", true));

	AndroidUtils::CallNativeAndroidVoid("com/epicgames/ue4/TestJavaClass", "showToast", true, TextForToast, length);

#endif //Android

#if PLATFORM_IOS

#endif// IOS
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ end 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// #~~~~~~~~~~~~~~~~~~~~~~~~~~ begin 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// -------- ������ ������ � ��������� / Example of working with arrays  ----------------
void UPLUGIN_NAMEBPLibrary::ExampleArray()
{
#if PLATFORM_ANDROID
	//������ � ������� ���������� ����� TArray/Working with an array is done via TArray

	//argType = FString, string, bool, int, long, float
	TArray<FString> a1;//  or/���  std::string
	TArray<bool> a2;
	TArray<int> a3;
	TArray<long> a4;
	TArray<float> a5;

	//returnType = FString, int, float
	TArray<FString> TestStrArr = AndroidUtils::CallNativeAndroid<TArray<FString>>("com/epicgames/ue4/TestJavaClass", "TestArray", false, a1, a2, a3, a4, a5);
#endif //Android
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~ end 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~