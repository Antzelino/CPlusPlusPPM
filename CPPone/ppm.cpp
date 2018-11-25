#include "ppm.h"
#include "Commons.h"
#include "Image.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace commons;

namespace imaging {

	float * ReadPPM(const char * filename, int * w, int * h) {
		
		//-----Get filename and file extension from input
		Commons cm;
		vector<string> fileInput;
		fileInput = cm.split(filename, '.');
		//filename
		cout << fileInput[0] << "\n";
		//file extension
		cout << fileInput[1] << "\n";

		//-----load them in the load function
		Image im;
		bool loader = im.load(fileInput[0], fileInput[1]);

		//-----Return nullptr if loader returns false
		if (!loader) {
			return nullptr;
		}


		return nullptr;
	}
}
