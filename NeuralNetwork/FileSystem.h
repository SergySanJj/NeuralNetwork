#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>

using namespace std;

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	wstring getCurDir();
	void organizeLayer(const string &networkName, const string &layerID);
private:
	wstring currentPath = L""; // path to .exe file
	wstring networkPath = L""; // path to network dir

	void createNetworkDir(wstring name);
	void createLayerDir(wstring name);
	int StringToWString(std::wstring &ws, const std::string &s);
	wstring strToWstr(const string &s);
};
