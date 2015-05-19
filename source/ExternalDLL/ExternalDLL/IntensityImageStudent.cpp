#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	std::cout << "in de INTENSITY constructor!!" << std::endl;
	pixelStorage = new Intensity[250000];
	for (int i = 0; i < 100; ++i) {
		pixelStorage[i] = { 0 };
	}
	imageWidth = 500;
	imageHeight = 500;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.pixelStorage;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	long size = width*height;
	pixelStorage = new Intensity[size];
	for (int i = 0; i < size; ++i) {
		pixelStorage[i] = { 0 };
	}
	imageWidth = width;
	imageHeight = height;
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelStorage;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	int size = width*height;
	std::cout << "size is: " << size << std::endl;
	Intensity* pixelStorageTemp = new Intensity[size];
	for (int i = 0; i < size; ++i) {
		//pixelStorageTemp[i] = new Intensity(pixelStorage[i + height]);
		pixelStorageTemp[i] = pixelStorage[i];
	}
	delete[] pixelStorage;
	pixelStorage = pixelStorageTemp;
	imageWidth = width;
	imageHeight = height;
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	int size = other.getWidth() * other.getHeight();
	for (int i = 0; i < size; i++) {
		//pixelStorage[i] = new RGB(other.pixelStorage[i + other.getHeight()]);
		pixelStorage[i] = other.pixelStorage[i];
	}
	imageWidth = other.getWidth();
	imageHeight = other.getHeight();
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelStorage[y*imageWidth + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	/*
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
	pixelStorage[i] = pixel;

}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelStorage[y*imageWidth + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	/*
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
	*/
	return pixelStorage[i];
}