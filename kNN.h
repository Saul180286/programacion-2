#ifndef KNN_H
#define KNN_H

#include "Dataset.h"
#include "Sorting.h"
#include "BubbleSort.h"
#include "InsertionSort.h"

class kNN {
	private:
		Dataset *d;
		int k;
		int classes;
	public:
		kNN(Dataset *d, int k, int classes) {
			this->d = d;
			this->k = k;
			this->classes = classes;

			d->print();
		}

		int getClass(Point* p, char sortingMethod) {
			float distances[d->getSize()];
			int classes[d->getSize()];

			// Calcular distancias entre los puntos.
			for (int i = 0; i < d->getSize(); i++) {
				distances[i] = *(d->getPoint(i)) - p;
				classes[i] = d->getPoint(i)->getPClass();
			}

			// Ordenar las distancias.
			Sorting *s;

			switch (sortingMethod) {
				case 'B':
					s = new BubbleSort(distances, classes, d->getSize());
					break;
				case 'I':
					s = new InsertionSort(distances, classes, d->getSize());
					break;
				default:
					throw "ValueError: Método de ordenamiento no reconocido.";
			}

			s->sortAsc();

			// Cuantificar las clases.
			int classCount[this->classes];

			for (int i = 0; i < this->classes; i++)
				classCount[i] = 0;

			for (int i = 0; i < this->k; i++) {
				classCount[classes[i]]++;
			}

			// Obtener la clase con más apariciones.
			float may = classCount[0];
			int c = 0;

			for (int i = 0; i < this->classes; i++) {
				if (classCount[i] > may) {
					may = classCount[i];
					c = i;
				}
			}

			return c;
		}
};

#endif
