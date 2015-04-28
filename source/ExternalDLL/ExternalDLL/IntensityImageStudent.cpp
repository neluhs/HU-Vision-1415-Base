#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.pixelStorage;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage = new Intensity*[width];
	for (int i = 0; i < width; ++i) {
		pixelStorage[i] = new Intensity[height];
	}
	imageWidth = width;
	imageHeight = height;
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelStorage;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	Intensity** pixelStorageTemp = new Intensity*[width];
	for (int i = 0; i < height; i++) {
		pixelStorageTemp[i] = new Intensity(*pixelStorage[i]);
	}
	delete[] pixelStorage;
	pixelStorage = pixelStorageTemp;
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < other.getHeight(); i++) {
		pixelStorage[i] = new Intensity(*other.pixelStorage[i]);
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelStorage[x][y] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int pixelX = 0, pixelY = 0;
	for (int index = 0; index < i; index++) {
		pixelStorage[pixelX][pixelY];
		pixelY = index%imageWidth;
		if (pixelX < imageWidth) {
			pixelX++;
		}
		else {
			pixelX = 0;
		}
	}
	pixelStorage[pixelX][pixelY] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelStorage[x][y];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int pixelX = 0, pixelY = 0;
	for (int index = 0; index < i; index++) {
		pixelStorage[pixelX][pixelY];
		pixelY = index%imageWidth;
		if (pixelX < imageWidth) {
			pixelX++;
		}
		else {
			pixelX = 0;
		}
	}
	return pixelStorage[pixelX][pixelY];
}