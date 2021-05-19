#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sorting.h"

class InsertionSort: public Sorting {
	public:
		InsertionSort(float* distances, int* classes, int length):
			Sorting(distances, classes, length) {}

		void sortAsc() {
			float tmpD;
			int tmpC, j;

			for (int i = 0; i < length; i++) {
				tmpD = distances[i];
				tmpC = classes[i];
				j = i - 1;

				while (j >= 0 && distances[j] > tmpD) {
					distances[j + 1] = distances[j];
					classes[j + 1] = classes[j];
					j--;
				}

				distances[j + 1] = tmpD;
				classes[j + 1] = tmpC;
			}

			// Imprimir los valores ordenados (así estaba en el código anterior).
			this->print();
		}
};

#endif
