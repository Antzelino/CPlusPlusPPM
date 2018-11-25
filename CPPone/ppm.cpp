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
		vector<string> fileInput = cm.split(filename, '.');
		cout << "File name: " << fileInput[0] << "\n";
		cout << "file format: " << fileInput[1] << "\n";

		//-----load with the load function
		Image im;
		bool loader = im.load(fileInput[0], fileInput[1]);

		//-----Return nullptr if loader returns false
		if (!loader) {
			return nullptr;
		}
		else {
			//Print Image dimensions
			cout << "Image dimensions are: " << im.getWidth() << " X " << im.getHeight() << "\n";
		}

		//πρέπει να επιστρέφει float *
		return nullptr;
	}

	bool WritePPM(const float * data, int w, int h, const char * filename)
	{

		return false;
	}
}
