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
	
	string i;
	Commons cm;
	cout << "Please enter the full name (with extension) of the ppm image: ";
	cin >> i;
	cout << "File entered: " << i << "\n";
	int * w = NULL;
	int * h = NULL;
	ReadPPM(cm.stringToChar(i), w, h);

	return 0;
}