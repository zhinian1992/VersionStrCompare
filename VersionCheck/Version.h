#pragma once
#include <vector>


class Version
{
public:
	Version();
	~Version();

	Version(std::string str);

	Version& operator= (std::string str);

	Version& operator= (Version &v);

	std::string to_string();

	int compare(Version &v);

private:
	bool Prase(std::string &str);

private:
	std::string str;
	std::string split;
	std::vector<std::string> ver;

	FRIEND_TEST(VersionTest, HandlePrase);
};

