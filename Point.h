#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "math.h"

using namespace std;

class Point {
	private:
		float *values; //Máximo 100 puntos por punto
		int size;
		int pClass;
	public:
		Point(float* values, int size, int pClass) {
			this->values = values;
			this->size = size;
			this->pClass = pClass;
		}

		Point() {
			this->size = 0;
			this->pClass = -1;
		}

		~Point() {
			delete[] values;
			cout << "~Point()" << endl;
		}

		void print() {
			cout << "size: " << size << ", values: ";
			for (int i = 0; i < size; i++)
				cout << values[i] << ", ";
			cout << " pClass: " << pClass << endl;
		}

		int getSize() const {
			return this->size;
		}

		float getValue(int index) const {
			return this->values[index];
		}

		int getPClass() {
			return this->pClass;
		}

		float operator-(const Point* p) {
			float sum = 0;

			for (int i = 0; i < p->getSize(); i++) {
				sum += pow(p->getValue(i) - this->getValue(i), 2);
			}

			return sqrt(sum);
		}
};

#endif
