#include "stdafx.h"
#include "Version.h"
#include <string>
#include <assert.h>

using namespace std;


Version::Version()
{
}

Version::~Version()
{
}

/// <summary>
/// create object by string
/// </summary>
/// <param name=""></param>
Version::Version(std::string str)
{
	Parse(str);
}

/// <summary>
/// copy value by string
/// </summary>
/// <param name=""></param>
Version & Version::operator=(std::string str)
{
	Parse(str);

	return *this;
}

/// <summary>
/// copy value by version object
/// </summary>
/// <param name=""></param>
Version & Version::operator=(Version & v)
{
	this->split = v.split;
	this->str = v.str;
	this->ver = v.ver;

	return *this;
}

/// <summary>
/// version string value
/// </summary>
/// <param name=""></param>
std::string Version::to_string()
{
	return str;
}

/// <summary>
/// compare two version
/// </summary>
/// <param name=""></param>
int Version::compare(Version & v)
{
	if (this->ver.size() != 0 && v.ver.size() != 0) {
		if (this->ver.size() != v.ver.size()) {
			return 3;
		}
		else {
			for (int i = 0; i < v.ver.size(); i++) {
				if (this->ver[i] > v.ver[i]) {
					return 1;
				}
				else if (this->ver[i] < v.ver[i]) {
					return 2;
				}
				else {
					continue;
				}
			}
			return 0;
		}
	}
	return -1;
}

/// <summary>
/// prase version string
/// </summary>
/// <param name=""></param>
bool Version::Parse(std::string &str)
{
	auto praseByChar = [](string data, string split,vector<string>& vec) {
		if (data.length() == 0 || split.length() == 0) {
			return false;
		}

		string::size_type position;
		position = data.find(split);
		if (position == string::npos) {
			return false;
		}

		while (position != string::npos) {
			vec.push_back(data.substr(0, position));
			data = data.substr(position + 1);
			position = data.find(split);
		}
		if (data.length() != 0)
			vec.push_back(data);
		return true;
	};

	/*add support splits*/
	string splits[] = {".","_","-"};

	for (int i = 0; i < splits->size(); i++) {
		if (praseByChar(str, splits[i],this->ver)) {
			this->str = str;
			return true;
		}
	}

	return false;
}
