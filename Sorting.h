#ifndef SORTING_H
#define SORTING_H

#include <iostream>

using namespace std;

class Sorting {
	protected:
		float* distances;
		int* classes;
		int length;
	public:
		Sorting(float* distances, int* classes, int length):
			distances(distances), classes(classes), length(length) {}

		virtual void sortAsc() {
			cout << "[i] Estoy dentro de la función sortAsc()" << endl;
		}

		void print() {
			cout << "Impresión de las distancias ordenadas" << endl;
			cout << "Index \t Distance \t Classes" << endl;

			for (int i = 0; i < this->length; i++) {
				cout << i << "\t\t" << distances[i] << "\t\t" << classes[i] << endl;
			}
		}
};

#endif
