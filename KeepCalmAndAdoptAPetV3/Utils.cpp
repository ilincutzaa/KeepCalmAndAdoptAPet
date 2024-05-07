#include "Utils.h"

std::vector<std::string> tokenize(std::string str, char delimiter) {
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delimiter)) {
		token.erase(token.find_last_not_of(" \t") + 1);
		token.erase(0, token.find_first_not_of(" \t"));
		result.push_back(token);
	}
	return result;
}

bool compareStrings(std::string str1, std::string str2) {
	if (str1.length() != str2.length())
		return false;

	for (int i = 0; i < str1.length(); ++i) {
		if (tolower(str1[i]) != tolower(str2[i]))
			return false;
	}

	return true;
}
