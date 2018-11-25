#define _CRT_SECURE_NO_WARNINGS

#include "Commons.h"

using namespace std;

namespace commons {

	int Commons::mystoi(string data) {
		return atoi(data.c_str());
	}

	vector<string> Commons::split(const char *str, char c) {
		vector<string> res;

		do {
			const char *begin = str;
			while (*str != c && *str)
				str++;
			res.push_back(string(begin, str));
		} while (0 != *str++);
		return res;
	}

	char* Commons::stringToChar(string &str) {
		char * charstr = new char[str.length() + 1];
		strcpy(charstr, str.c_str());
		return charstr;
	}
}