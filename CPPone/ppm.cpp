﻿#include "ppm.h"
#include "Commons.h"
#include "Image.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

using namespace commons;

namespace imaging {

	// don't forget to delete[] the returned value when not needed anymore
	float * ReadPPM(const char * filename, int * w, int * h) {
		
		//-----Get filename and file extension from input
		//Commons cm;
		//vector<string> fileInput = cm.split(filename, '.');
		//cout << "File name: " << fileInput[0] << "\n";
		//cout << "file format: " << fileInput[1] << "\n";

		//cout << "Image dimensions are: " << im.getWidth() << " X " << im.getHeight() << "\n";


		ifstream file;
		file.open(filename, ios::in | ios::binary);
		if (!file.is_open()) {
			cerr << "Could not open file: " << filename << endl;
			return nullptr;
		}
/*
		string text;
		string line;
		vector<string> list;

		while (getline(file, line)) {
			text.append(line);
			text.append(" ");
			unsigned int position = line.find("255");
			if (position != string::npos) {
				break;
			}
		}		
*/

		string text = "";
		char c;
		unsigned int count_words = 0;
		bool reading_word = true;

		cout << "From header + a little:" << endl;
		if (isspace(c = file.get())) // check if first character is whitespace
			while (isspace(c))
				file.get(c); // skip all leading whitespace

		// over here, c already has some value that was read from the file (which is definitely not whitespace)
		while (true) { // will stop at "break;"
			// this algorithm says:
			// when i see whitespace, if i was reading a word and there's whitespace now, im gonna count one more word
			// but if this was the 4th word, im ending the loop. If it was just one more word, im adding a space to the text.
			// Else (if i didnt just read whitespace), i will just keep reading the word im reading, and add to the text.
			if (isspace(c)) {
				if (reading_word) {
					count_words++;
					if (count_words == 4)
						break;

					text += " ";
				}

				reading_word = false;
				file.get(c);
				continue;
			}
			reading_word = true; 

			text += c; // so we simply keep adding it to the text
			file.get(c);
		}

		// now the file's pointer is at the space before the data (exactly one space or '\n').
		// with file.read() it will ready the data exactly from the beginning

		vector<string> list;

		Commons cm;
		char* charText = cm.stringToChar(text);
		list = cm.split(charText, ' ');
		
		if (list[0] != "P6") {
			cerr << "The only supported format is P6." << endl;
			return nullptr;
		}
		if (!cm.is_number(list[1])) {
			cerr << "The width of the image is not specified." << endl;
			return nullptr;
		}
		if (!cm.is_number(list[2])) {
			cerr << "The height of the image is not specified." << endl;
			return nullptr;
		}
		if (!cm.is_number(list[3])) {
			cerr << "The maximum value is not specified." << endl;
			return nullptr;
		}
		if (cm.mystoi(list[3]) > 255) {
			cerr << "Only 24bit images allowed." << endl;
			return nullptr;
		}
		(*w) = cm.mystoi(list[1]);
		(*h) = cm.mystoi(list[2]);
		float maxvalue = (float)cm.mystoi(list[3]);

		int num_of_values = (*w) * (*h) * 3;
		char* data = new char[num_of_values];
		float* fdata = new float[num_of_values];

		file.read(data, num_of_values); // each value is 1 Byte
		file.close();

		for (int i = 0; i < num_of_values; i++) { // save the values in correct format in fdata
			unsigned char dataElement = (unsigned char)data[i];
			float fdataElement = dataElement / maxvalue;
			fdata[i] = fdataElement;
		}

		delete[] data;

		return fdata;
	}

	bool WritePPM(const float * data, int w, int h, const char * filename)
	{

		return false;
	}
}
