#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sorting.h"

class BubbleSort: public Sorting {
	public:
		BubbleSort(float* distances, int* classes, int length):
			Sorting(distances, classes, length) {}

		void sortAsc() {
			float tmpD;
			int tmpC;

			for (int i = 0; i < length - 1; i++) {
				for (int j = 0 ; j < length - 1; j++) {
					if (distances[j] > distances[j + 1]) {
						// Intercambio de distancias.
						tmpD = distances[j];
						distances[j] = distances[j + 1];
						distances[j + 1] = tmpD;

						// Intercambio de clases.
						tmpC = classes[j];
						classes[j] = classes[j + 1];
						classes[j + 1] = tmpC;
					}
				}
			}

			// Imprimir los valores ordenados (así estaba en el código anterior).
			this->print();
		}
};

#endif
