#include "FileSystem.h"

FileSystem::FileSystem()
{
	char path[MAX_PATH];
	GetCurrentDirectory(sizeof(path), path);

	this->currentPath = strToWstr(path);
	this->networkPath = this->currentPath;
}

FileSystem::~FileSystem()
{
}

wstring FileSystem::getCurDir()
{
	return (this->currentPath);
}

void FileSystem::organizeLayer(const string & networkName, const string & layerID)
{
	createNetworkDir(strToWstr(networkName));
}

void FileSystem::createNetworkDir(wstring name)
{
	wstring path = this->currentPath;
	path.append(L"\\");
	path.append(name);
	CreateDirectoryW(path.c_str(), NULL);
	this->networkPath = path;
}

void FileSystem::createLayerDir(wstring name)
{
	wstring path = this->networkPath;
	path.append(L"\\");
	path.append(name);
	CreateDirectoryW(path.c_str(), NULL);
	this->networkPath = path;
}

int FileSystem::StringToWString(std::wstring & ws, const std::string & s)
{
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;

	return 0;
}

wstring FileSystem::strToWstr(const string & s)
{
	wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(s);
}