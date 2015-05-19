#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	std::cout << "in de RGB constructor!!" << std::endl;
	pixelStorage = new RGB[250000];
	for (int i = 0; i < 100; ++i) {
		pixelStorage[i] = { { 0 } };
	}
	imageWidth = 500;
	imageHeight = 500;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.pixelStorage;
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	long size = width*height;
	pixelStorage = new RGB[size];
	for (int i = 0; i < size; ++i) {
		pixelStorage[i] = { {0} };
	}
	imageWidth = width;
	imageHeight = height;
}

RGBImageStudent::~RGBImageStudent() {
	delete[] pixelStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	int size = width*height;
	RGB* pixelStorageTemp = new RGB[size];
	for (int i = 0; i < size; ++i) {
		//pixelStorageTemp[i] = new RGB(pixelStorage[i + height]);
		pixelStorageTemp[i] = pixelStorage[i];
	}
	delete[] pixelStorage;
	pixelStorage = pixelStorageTemp;
	imageWidth = width;
	imageHeight = height;
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	int size = other.getWidth() * other.getHeight();
	for (int i = 0; i < size; i++) {
		//pixelStorage[i] = new RGB(other.pixelStorage[i + other.getHeight()]);
		pixelStorage[i] = other.pixelStorage[i];
	}
	imageWidth = other.getWidth();
	imageHeight = other.getHeight();
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixelStorage[y*imageWidth+x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	/*
	int pixelX = 0, pixelY =0;
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
	*/
	pixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelStorage[y*imageWidth + x];
}

RGB RGBImageStudent::getPixel(int i) const {
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