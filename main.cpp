#include <iostream>
#include "Point.h"
#include "Dataset.h"
#include "kNN.h"

int main() {
	int k = 3, classes = 3;
	int claseFinal;

	Dataset* d = new Dataset("iris.data.csv");
	kNN knn(d, k, classes);

	claseFinal = knn.getClass(new Point(new float[4]{7, 7, 7, 7}, 4, 1));
	cout << "Clase pronosticada: " << claseFinal << endl;

	delete d;

	return 0;
}
