#include "Image.h"
#include "ppm.h"
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

	bool Image::load(const string & filename, const string & format)
	{
		if (format != "ppm") {
			cerr << "Only .ppm format extension is supported" << endl;
			return false;
		}

		
		string fullFilename = filename + '.' + format;

		int w, h; // width and height
		float* data = ReadPPM(fullFilename.c_str(), &w, &h);
		if (data == nullptr)
			return false;

		cout << "Image dimensions are: " << w << " X " << h << endl;


		delete[] data;
		return true;
	}

	bool Image::save(const std::string & filename, const std::string & format)
	{
		if (format != "ppm") {
			cerr << "Only .ppm format extension is supported" << endl;
			return false;
		}
		return true;
	}
}

