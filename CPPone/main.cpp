#include <iostream>
#include "Image.h"
#include "Commons.h"
#include "ppm.h"
#include "Color.h"

#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include <cstring>

using namespace std;
using namespace imaging;
using namespace commons;


int main(int argc, char* argv[]) {

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
	
	string file;
	if (argc != 2) {
		cout << "Please enter the full name (with extension) of the ppm image: ";
		//getline(cin, file);
		cin >> file;
	}
	else {
		file = argv[1];
	}

	Commons cm;
	cout << "File: " << file << "\n";
	int * w = NULL;
	int * h = NULL;
	const char * filenameInChar = cm.stringToChar(file);
	vector<string> filenameSplitted = cm.split(filenameInChar, '.');
	float * imageData = ReadPPM(filenameInChar, w, h);

	/*

	//Save negative
	bool saver = WritePPM(imageData, 500, 200, cm.stringToChar(filenameSplitted[0])+'_neg'+'.ppm');
	if (saver) {
		cout << "Please enter the full name (with extension) of the ppm image: ";
	}
	*/
	return 0;
}