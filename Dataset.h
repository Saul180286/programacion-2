#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <sstream>
#include <fstream>
#include "Point.h"

class Dataset{
	private:
		Point* points[150];
		int index;
		int size;
	public:
		Dataset(int size) {
			this->index = 0;
			this->size = size;
		}

		Dataset(string filename) {
			ifstream csv(filename);
			string row, tmpNumber;
			int columnas, filas;

			// Obtener primera línea: filas y columnas.
			getline(csv, row);
			stringstream fila1(row); // Permite usar getline en string
			getline(fila1, tmpNumber, ' '); filas = stoi(tmpNumber);
			getline(fila1, tmpNumber); columnas = stoi(tmpNumber);

			// Inicializar valores como en el constructor por defecto.
			this->index = 0;
			this->size = filas;

			// Rellenar el data set con los puntos.
			while (getline(csv, row)) {
				stringstream line(row);
				float* x = new float[columnas];
				string label;

				for (int i = 0; i < columnas; i++) {
					getline(line, tmpNumber, ' '); // Obtiene cada x hasta encontrar un espacio.
					x[i] = stof(tmpNumber); // stof: string -> float
				}
				getline(line, label); // Obtiene el valor final de la fila.

				Point* p = new Point(x, columnas, stoi(label));
				this->add(p);
			}
		}

		~Dataset() {
			cout << "~Dataset()" << endl;
		}

		void add(Point* p) {
			this->points[index] = p;
			index++;
		}

		void print() {
			for (int i = 0; i < index; i++) {
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
