#pragma once

#include "Android/AndroidJava.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

#include <iostream>
#include <string>

using namespace std;

class JavaConvert
{
public:
	//============== ������� ��� ��������������� � Java ���� / Functions for converting to Java types ===================================

	// TArray<FString> to jobjectArray
	static jobjectArray ConvertToJStringArray(const TArray<FString>& stringArray);

	// TArray<bool> to jbooleanArray
	static jbooleanArray ConvertToJBooleanArray(const TArray<bool>& boolArray);

	// TArray<int> to jintArray
	static jintArray ConvertToJIntArray(const TArray<int>& intArray);

	// TArray<unsigned char> to jbyteArray
	static jbyteArray ConvertToJByteArray(const TArray<uint8>& byteArray);

	// TArray<long> to jlongArray
	static jlongArray ConvertToJLongArray(const TArray<long>& longArray);
	
	// TArray<float> to jfloatArray
	static jfloatArray ConvertToJFloatArray(const TArray<float>& floatArray);

	// jbyteArray to TArray<unsigned char>
	static TArray<uint8> ConvertToByteArray(jbyteArray javaArray);
	
	// jfloatArray to TArray<float>
	static TArray<float> ConvertToFloatArray(jfloatArray javaArray);
	
	// jfloatArray to TArray<int>
	static TArray<int> ConvertToIntArray(jintArray javaArray);

	// jlongArray to TArray<long>
	static TArray<long> ConvertToLongArray(jlongArray javaArray);

	// jobjectArray to TArray<FString>
	static TArray<FString> ConvertToStringArray(jobjectArray javaStringArray);

	// FString to jstring
	static jstring GetJavaString(FString string);

	// string to jstring
	static jstring GetJavaString(string str);

	// const char* to jstring
	static jstring GetJavaString(const char* str);

	// jstring to FString
	static FString FromJavaFString(jstring javaString);

	// jstring to string
	static string FromJavaString(jstring javaString);
};
