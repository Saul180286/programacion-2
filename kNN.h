#ifndef KNN_H
#define KNN_H

#include "Dataset.h"
#include "Bubble.h"

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

		int getClass(Point* p) {
			float distances[d->getSize()];
			int classes[d->getSize()];

			for (int i = 0; i < d->getSize(); i++) {
				distances[i] = *(d->getPoint(i)) - p;
				classes[i] = d->getPoint(i)->getPClass();
			}

			Bubble *s = new Bubble(distances, classes, d->getSize());
			s->sortAsc();

			int classCount[this->classes];

			for (int i = 0; i < this->classes; i++)
				classCount[i] = 0;

			for (int i = 0; i < this->k; i++) {
				classCount[classes[i]]++;
			}

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
