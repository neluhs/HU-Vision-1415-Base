#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {

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
	Intensity* pixelStorageTemp = new Intensity[size];
	for (int i = 0; i < size; ++i) {
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
		pixelStorage[i] = other.pixelStorage[i];
	}
	imageWidth = other.getWidth();
	imageHeight = other.getHeight();
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelStorage[(y*IntensityImage::getWidth()) + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelStorage[i] = pixel;

}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelStorage[(y*IntensityImage::getWidth()) + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixelStorage[i];
}