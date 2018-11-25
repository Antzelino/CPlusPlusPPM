#include "Image.h"
#include "Commons.h"

using namespace std;
using namespace commons;

namespace imaging {

	Color * Image::getRawDataPtr()
	{
		return buffer;
	}

	Color Image::getPixel(unsigned int x, unsigned int y)const {
		Color col;
		col.r = 0;
		col.g = 0;
		col.b = 0;

		if ((x < getWidth() && x >= 0) && (y < getHeight() && y >= 0)) {
			Color* temp = (Color*)buffer;

			col.r = temp[y * getWidth() + x].r;
			col.g = temp[y * getWidth() + x].g;
			col.b = temp[y * getWidth() + x].b;
		}

		return col;
	}
	
	void Image::setPixel(unsigned int x, unsigned int y, Color& value) {
		if ((x < getWidth() && x >= 0) && (y < getHeight() && y >= 0)) {
			Color* temp = (Color*)buffer;

			temp[y * getWidth() + x].r = value.r;
			temp[y * getWidth() + x].g = value.g;
			temp[y * getWidth() + x].b = value.b;
		}
	}

	void Image::setData(const Color* & data_ptr) {
		memcpy(buffer, data_ptr, getWidth() * getHeight() * 3 * sizeof(Color));
	}

	Image::Image(unsigned int width, unsigned int height) {
		(*this).width = ZERO;
		(*this).height = ZERO;
		(*this).buffer = nullptr;
	}

	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr) {
		(*this).width = width;
		(*this).height = height;
		(*this).buffer = new Color[3 * width * height];
		(*this).setData(data_ptr);
	}

	Image::Image() {
		(*this).width = width;
		(*this).height = height;
		(*this).buffer = new Color[3 * width * height];
	}

	Image::Image(const Image &src) {
		(*this).width = src.getWidth();
		(*this).height = src.getHeight();
		(*this).buffer = new Color[3 * width * height];
		(*this).buffer = src.buffer;
	}

	Image::~Image() {
		delete[] buffer;
	}

	Image & Image::operator=(const Image & right)
	{
		Image temp(right);
		return temp;
	}

	bool Image::load(const std::string & filename, const std::string & format)
	{
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

		Commons cm;
		char* charText = cm.stringToChar(text);
		list = cm.split(charText, ' ');
		if (list[0] == "P3") {
			cerr << "P3 format is not supported." << endl;
			return false;
		}
		if (list[1] == "") {
			cerr << "The width of the image is not specified." << endl;
			return false;
		}
		width = cm.mystoi(list[1]);
		if (list[2] == "") {
			cerr << "The height of the image is not specified." << endl;
			return false;
		}
		height = cm.mystoi(list[2]);
		if (list[3] == "") {
			cerr << "The maximum value is not specified." << endl;
			return false;
		}
		if (cm.mystoi(list[3]) > 255) {
			cerr << "Maximum value is over 255!" << endl;
			return false;
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

		//Image *image = new Image(width, height, (component_t*)fdata);
		//delete[] data;
		return true;
	}
}

