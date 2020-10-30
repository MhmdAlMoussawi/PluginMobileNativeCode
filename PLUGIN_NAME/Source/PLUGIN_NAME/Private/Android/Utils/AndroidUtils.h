#pragma once

#include "Android/AndroidJava.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "JavaConvert.h"

#include <iostream>
#include <string>

using namespace std;

class AndroidUtils
{
public:
	//==============Call Target Jni===================================
	static FString CallJniStringMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...);
	static bool CallJniBoolMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...);
	static int CallJniIntMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...);
	static long CallJniLongMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...);
	static jobject CallJniObjectMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...);
	static void CallJniVoidMethod(const ANSICHAR* ClassName, const ANSICHAR* MethodName, const ANSICHAR* MethodSignature, ...);

	//================Override Tempalte===========================
	static string GetTypeName(void);
	static string GetTypeName(bool b);
	static string GetTypeName(unsigned char uc);
	static string GetTypeName(char c);
	static string GetTypeName(short s);
	static string GetTypeName(int i);
	static string GetTypeName(long l);
	static string GetTypeName(float f);
	static string GetTypeName(double d);
	static string GetTypeName(const char* str);
	static string GetTypeName(string str);
	static string GetTypeName(FString str);
	static string GetTypeName(jstring str);
	static string GetTypeName(jobject jo);
	//------------ Convert ---------------------------------------------------	
	template <typename anyType>
	static const anyType& convertArg(const anyType& value);
	static jstring convertArg(const char* str);
	static jstring convertArg(string str);
	static jstring convertArg(FString str);
	//-----------------------------------------------------------------------------------------------	
	static void GetType(string&);

	template <typename T, typename... Args>
	static void GetType(string& signatureString, T Tvalue, Args... args);
	//-----------------------------------------------------------------------------------------------	
	// FString
	template <typename... Args>
	static FString CallJNI(FString str, const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);

	// string
	template <typename... Args>
	static string CallJNI(string str, const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);

	// bool
	template <typename... Args>
	static bool CallJNI(bool b, const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);

	// int
	template <typename... Args>
	static int CallJNI(int i, const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);

	// long
	template <typename... Args>
	static long CallJNI(long l, const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);

	// jobject
	template <typename... Args>
	static jobject CallJNI(jobject jo, const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);

	// void
	template <typename... Args>
	static void CallVoidJni(const char* ClassName, const char* MethodName, const char* MethodSignature, Args... args);







	//============����� ��������� ���� Android �� C++ / Calling native Android code from C++===============
	/**
	* ����� ������������ ���� Java � ������������ ��������� / Calling native Java code with the return value
	*
	* @param ClassName - package(������������ com/epicgames/ue4) � ��� ������ Java ������ / package (used by com/epicgames/ue4) and the name of your Java class.
	* @param FunctionName - ��� ����� Java ������� / Name of your Java function.
	* @param isActivity - ���������� ����� �� ���������� Activity UE4 � Java / Determines whether to pass Activity UE4 to Java.
	* @param args... -
	* ������ ����� ���������� � Java �������(���� ��� ���������� � Java ���� ����������� �������� jobject,
	* ��� ������� ����� ������� ������� ������������������) /
	* A list of your parameters in the Java function(if the variable type in the Java code is specific, such as jobject, it should be converted before calling the function).
	*/
	template <typename MethodType, typename... Args>
	static MethodType CallNativeAndroid(const char* ClassName, const char* FunctionName, bool isActivity, Args... args);

	/**
	* ����� ������������ ���� Java ��� ������������� �������� / Calling native Java code without a return value
	*
	* @param ClassName - package(������������ com/epicgames/ue4) � ��� ������ Java ������ / package (used by com/epicgames/ue4) and the name of your Java class.
	* @param FunctionName - ��� ����� Java ������� / Name of your Java function.
	* @param isActivity - ���������� ����� �� ���������� Activity UE4 � Java / Determines whether to pass Activity UE4 to Java.
	* @param args... -
	* ������ ����� ���������� � Java �������(���� ��� ���������� � Java ���� ����������� �������� jobject,
	* ��� ������� ����� ������� ������� ������������������) /
	* A list of your parameters in the Java function(if the variable type in the Java code is specific, such as jobject, it should be converted before calling the function).
	*/
	template <typename... Args>
	static void CallNativeAndroidVoid(const char* ClassName, const char* FunctionName, bool isActivity, Args... args);
	//========================================================
};
