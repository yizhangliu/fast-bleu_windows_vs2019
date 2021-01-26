// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。
#include<iostream>

using namespace std;

extern "C" _declspec(dllexport) int myAdd(int a, int b)
{
    cout << "function__myAdd " << endl;
    return a + b;
}

extern "C" _declspec(dllexport) int myMax(int a, int b)
{
    return a > b ? a : b;
}

