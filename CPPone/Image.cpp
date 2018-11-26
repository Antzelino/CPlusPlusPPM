#include "Image.h"
#include "ppm.h"
#include "Commons.h"

#define RED 0
#define GRN 1
#define BLU 2


using namespace std;
using namespace commons;

namespace imaging {

	Color * Image::getRawDataPtr() {
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
		if (this->buffer == nullptr || this->width == 0 || this->height == 0) // just like Image.h says, exit immediately in this case
			return;

		memcpy(this->buffer, data_ptr, getWidth() * getHeight() * sizeof(Color));
	}

	Image::Image() {
		this->width = 0;
		this->height = 0;
		this->buffer = nullptr;
	}

	Image::Image(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height;
		this->buffer = nullptr;
	}

	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr) {
		this->width = width;
		this->height = height;
		this->buffer = new Color[width * height];
		this->setData(data_ptr); // copies the array
	}

	Image::Image(const Image &src) { // deep copy
		this->width = src.getWidth();
		this->height= src.getHeight();
		if (this->buffer != nullptr)
			delete[] this->buffer;

		this->buffer = new Color[this->width * this->height];
		const Color* tmp = src.buffer;
		this->setData(tmp); // copies the array
	}

	Image::~Image() {
		if (buffer != nullptr)
			delete[] buffer;
	}

	Image & Image::operator=(const Image & right) { // deep copy
		if (this != (&right)) { // protect against invalid self-assignment
			this->width = right.getWidth();
			this->height = right.getHeight();
			if (this->buffer != nullptr)
				delete[] this->buffer;

			this->buffer = new Color[this->width * this->height];
			const Color* tmp = right.buffer;
			this->setData(tmp);
		}

		return (*this);
	}

	bool Image::load(const string & filename, const string & format) {
		if (format != "ppm") {
			cerr << "Only .ppm format extension is supported." << endl;
			return false;
		}
		
		string fullFilename = filename + '.' + format;

		int w, h; // width and height
		float* data = ReadPPM(fullFilename.c_str(), &w, &h);
		if (data == nullptr)
			return false;

		cout << "Image dimensions are: " << w << " X " << h << endl;

		Color* pixels = new Color[w * h];
		for (int i = 0; i < (w * h); i++) {
			pixels[i][RED] = data[(3 * i)+RED];
			pixels[i][GRN] = data[(3 * i)+GRN];
			pixels[i][BLU] = data[(3 * i)+BLU];
		}
		if (this->buffer != nullptr)
			delete[] this->buffer;

		this->width = w;
		this->height = h;
		this->buffer = pixels;

		delete[] data;
		return true;
	}

	bool Image::save(const std::string & filename, const std::string & format) {
		if (format != "ppm") {
			cerr << "Only .ppm format extension is supported." << endl;
			return false;
		}

		if (this->buffer == nullptr || this->height == 0 || this->width == 0)
			return false;

		const string completeFilename = filename + "." + format;
		float* data = new float[3 * this->width * this->height];
		for (size_t i = 0; i < (this->width) * (this->height); i++) {
			data[(i * 3) + RED] = this->buffer[i][RED];
			data[(i * 3) + GRN] = this->buffer[i][GRN];
			data[(i * 3) + BLU] = this->buffer[i][BLU];
		}

		return WritePPM(data, this->width, this->height, completeFilename.c_str());
	}
}

