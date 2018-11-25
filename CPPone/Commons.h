#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <istream>

namespace commons {

	class Commons {
		public:	
			int mystoi(string data);

			vector<string> split(const char *str, char c = ' ');

			char* stringToChar(string &str);
	};
}