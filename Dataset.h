#ifndef DATASET_H
#define DATASET_H

#include <fstream>
#include "Point.h"

class Dataset{
	private:
		Point* points[150];
		int index;
		int size;

		ifstream myfile;
		string filename;
		int features;
	public:
		Dataset(int size) {
			this->index = 0;
			this->size = size;
		}

		~Dataset() {
			cout << "~Dataset()" << endl;
		}

		void add(Point* p) {
			this->points[index] = p;
			index++;
		}

		void print() {
			for (int i = 0; i < size; i++) {
				cout << "Index: " << i << "\t";
				points[i]->print();
			}
		}

		int getSize() {
			return this->size;
		}

		Point* getPoint(int index) {
			return this->points[index];
		}

		int getClass(int index) {
			return this->points[index]->getPClass();
		}
};

#endif
