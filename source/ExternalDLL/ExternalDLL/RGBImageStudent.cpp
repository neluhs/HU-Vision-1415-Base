#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	
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

/* OLD SHIZZLE
void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	int size = width*height;
	RGB* pixelStorageTemp = new RGB[size];
	for (int i = 0; i < size; ++i) {
		pixelStorageTemp[i] = pixelStorage[i];
	}
	delete[] pixelStorage;
	pixelStorage = pixelStorageTemp;
	imageWidth = width;
	imageHeight = height;
}
*/

void RGBImageStudent::set(const int width, const int height) {
	RGB* newImage = new RGB[width*height];
	int oldSize = this->getHeight() * this->getWidth();
	for (int i = 0; (oldSize ? i<width*height : i < oldSize); i++){
		newImage[i] = (oldSize ? RGB{} : pixelStorage[i]);
	}
	RGBImage::set(width, height);
	RGB * tmp = pixelStorage;
	delete[] tmp;
	pixelStorage = newImage;
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	RGB * tmp = pixelStorage;
	delete[] tmp;
	pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	int maxSize = other.getWidth() * other.getHeight();
	for (int i = 0; i < maxSize; i++){
		pixelStorage[i] = other.getPixel(i);
	}
}


void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	int size = other.getWidth() * other.getHeight();
	for (int i = 0; i < size; i++) {
		pixelStorage[i] = other.pixelStorage[i];
	}
	imageWidth = other.getWidth();
	imageHeight = other.getHeight();
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixelStorage[(y*RGBImage::getWidth()) + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelStorage[(y*RGBImage::getWidth()) + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixelStorage[i];
}