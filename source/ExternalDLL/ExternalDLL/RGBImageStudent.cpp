#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.pixelStorage;
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelStorage = new RGB*[width];
	for (int i = 0; i < width; ++i) {
		pixelStorage[i] = new RGB[height];
	}
	imageWidth = width;
	imageHeight = height;
}

RGBImageStudent::~RGBImageStudent() {
	delete[] pixelStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	RGB** pixelStorageTemp = new RGB*[width];
	for (int i = 0; i < height; i++) {
		pixelStorageTemp[i] = new RGB(*pixelStorage[i]);
	}
	delete[] pixelStorage;
	pixelStorage = pixelStorageTemp;
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < other.getHeight(); i++) {
		pixelStorage[i] = new RGB(*other.pixelStorage[i]);
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixelStorage[x][y] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int pixelX = 0, pixelY =0;
	for (int index; index < i; index++) {
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelStorage[x][y];
}

RGB RGBImageStudent::getPixel(int i) const {
	int pixelX = 0, pixelY = 0;
	for (int index; index < i; index++) {
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