#include "ppm.h"
#include "Commons.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace commons;

namespace imaging {

	float * ReadPPM(const char * filename, int * w, int * h) {
		
		Commons cm;
		vector<string> fileInput;
		fileInput = cm.split(filename, '.');
		//filename
		cout << fileInput[0] << "\n";
		//file extension
		cout << fileInput[1] << "\n";
		return nullptr;
	}
}
