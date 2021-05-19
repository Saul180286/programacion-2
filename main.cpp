#include <iostream>
#include "Point.h"
#include "Dataset.h"
#include "kNN.h"

int main() {
	int k = 3, classes = 3;
	int claseFinal;
	char metodoOrdenamiento;

	Dataset* d = new Dataset("iris.data.csv");
	kNN knn(d, k, classes);

	cout << "[?] Ingrese el método de ordenamiento a utilizar (B, I): ";
	cin >> metodoOrdenamiento;

	try {
		claseFinal = knn.getClass(new Point(new float[4]{7, 7, 7, 7}, 4, 1), metodoOrdenamiento);
		cout << "Clase pronosticada: " << claseFinal << endl;
	} catch(const char* error) {
		cout << error << endl;
	}

	delete d;

	return 0;
}
