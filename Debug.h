#pragma once

#include <string>
#include <sstream>
#include <Windows.h>

#include <iostream>

using namespace std;

static class Debug
{
public:

	static void NumberDebug();
	//static void StringDebug(string _message);

	template <class Debug>
	static void StringDebug(Debug _message)
	{
		stringstream str_strm;
		str_strm << _message;
		std::cout << str_strm.str();

		char sz[1024] = { 0 };
		sprintf_s(sz, "%s \n", str_strm.str().c_str());
		OutputDebugStringA(sz);
	}
};

//https://www.tutorialspoint.com/stringstream-in-cplusplus
//https://www.cplusplus.com/doc/oldtutorial/templates/
//https://www.tutorialspoint.com/how-to-write-a-singleton-class-in-cplusplus