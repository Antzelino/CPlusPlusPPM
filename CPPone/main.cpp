#include <iostream>
#include "Image.h"
#include "ppm.h"
#include "Color.h"

#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include <cstring>

using namespace std;
using namespace imaging;


/*
Image* ReadPPM(const char* filename) {
	ifstream file(filename, ios_base::binary);
	if (!file) {
		return NULL;
	}

	string text;
	string line;
	unsigned short width, height;
	bool correcttype = false;
	vector<string> list;
	while (getline(file, line)) {
		text.append(line);
		text.append(" ");
		unsigned position = line.find("255");
		if (position != string::npos) {
			break;
		}
	}

	char* charText = stringToChar(text);
	list = split(charText, ' ');
	if (list[0] == "P3") {
		cerr << "P3 format is not supported." << endl;
		return NULL;
	}
	if (list[1] == "") {
		cerr << "The width of the image is not specified." << endl;
		return NULL;
	}
	width = mystoi(list[1]);
	if (list[2] == "") {
		cerr << "The height of the image is not specified." << endl;
		return NULL;
	}
	height = mystoi(list[2]);
	if (list[3] == "") {
		cerr << "The maximum value is not specified." << endl;
		return NULL;
	}
	if (mystoi(list[3]) > 255) {
		cerr << "Maximum value is over 255!" << endl;
		return NULL;
	}

	char* data = new char[width * height * 3];
	float* fdata = new float[width * height * 3];
	file.read(data, width * height * 3 * sizeof(char));

	for (int i = 0; i < width * height * 3; i++) {
		char t = data[i];
		unsigned char tt = (unsigned char)t;
		float pp = tt / 255.0f;
		fdata[i] = pp;
	}

	Image *image = new Image(width, height, (component_t*)fdata);
	delete[] data;
	return image;
}
*/

int main()
{
	
	// 0) DONE �� ����� ��� ����������� ������ �� ����� neg.exe 
	//     �� ����� ��� ������� ���� ������� ������� �� ������, ������ �������� ���� ��� ��������
	// 1a) readPPM --> ������� ��� ������ ��� ��� ��� ���������� �� ��� instance ��� ������ Image
	//     ���������� �� ���� [0,255] �� [0.0,1.0]
	//     �� �������� ��� �������� ��� �������, ����������� ��� ��� �������� ������ ���������
	//     �������� ��� ������ �� ���������, ������ �� �������������:
	//        - ��� ������� �� ������ ��� ����������� �� ��������� � ��� �������
	//        - ��� ����� ����� P6
	//        - ������ � ��������� �/��� � ������ �������� ��� �������
	//        - ������� �� ��������� � ������� ���� ����������� � ����� ���������� ��� 255
	// 1b) �� ��������� ���������� ��� ���������� ��� ������� ��� �� �������� ��� 
	//	   � �������� ���� ���� ����� ������������ �� Negt(Pixel(x,y))=(1,1,1)-Pixel(x,y)
	// 1c) writePPM --> ���������� ��� ������ �� ��� ������ ppm, �� �������	_neg (i.e, photo1_neg.ppm)
	// 1d) �� ��� 2 ������� �� ����������� ��� ppm.cpp ��� �� ������������� ��� ppm.lib
	// 
	// 2) ��������� ��� ������� ��� ������� Image. H load �� ������������ ��� readPPM, ��� � save ��� writePPM ��� ��� ppm.lib
	// 3) ��������� ��� main ���������������� ��� 1, �� ����� ��� ppm.lib.
	
	int i;
	cout << "Please enter an integer value: ";
	cin >> i;
	cout << "The value you entered is " << i;
	cout << " and its double is " << i * 2 << ".\n";
	return 0;
}