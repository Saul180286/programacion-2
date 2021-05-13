#include <iostream>
#include "Point.h"
#include "Dataset.h"
#include "kNN.h"

int main() {
	int points = 3;
	int k = 3;
	int classes = 3;

	Point* p1 = new Point(new float[2]{0, 1},  2, 0);
	Point* p2 = new Point(new float[2]{1, 0},  2, 0);
	Point* p3 = new Point(new float[2]{1, 1},  2, 0);

	p1->print();
	p2->print();
	p3->print();

	Dataset* d = new Dataset(points);
	d->add(p1);
	d->add(p2);
	d->add(p3);

	kNN knn(d, k, classes);

	cout << "Clase pronosticada: ";
	cout << knn.getClass(new Point( new float[2]{7, 7}, 2, 1)) << endl;

	delete d;

	delete p1;
	delete p2;
	delete p3;

	return 0;
}
