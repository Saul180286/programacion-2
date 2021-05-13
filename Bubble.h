#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>

using namespace std;

// #include "Sorting.h"

// class Bubble : public Sorting {
class Bubble {
	private:
		float* distances;
		int* classes;
		int size;
	public:
		Bubble(float* distances, int* classes, int size) {
			this->distances = distances;
			this->classes = classes;
			this->size = size;
		}

		void sortAsc() {
			float tmp;
			int tmpClass;
			bool sorted;

			do {
				sorted = true;

				for (int i = 0; i < size - 1; i++) {
					if (distances[i] > distances[i + 1]) {
						tmp = distances[i];
						distances[i] = distances[i + 1];
						distances[i + 1] = tmp;

						tmpClass = classes[i];
						classes[i] = classes[i + 1];
						classes[i + 1] = tmpClass;

						sorted = false;
					}
				}
			} while(!sorted);

			cout << "Impresión de las distancias ordenadas" << endl;
			cout << "Index \t Distance \t classes" << endl;

			for (int i = 0; i < size; i++) {
				cout << i << "\t\t" << distances[i] << "\t\t" << classes[i] << endl;
			}
		}
};

#endif
