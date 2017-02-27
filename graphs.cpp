/* Creates different types of random graphs */
#include "graphs.h"
#include <iostream>

Graph::Graph(int n, int dim) {
	this->n = n;
	this->dim = dim;

	srand(time(NULL));

	if (dim == 0) {
		for (int i=0; i<n; ++i) {
			Vertex v;
			v.dim = dim;
			v.index = i;
			vertices.push_back(v);
		}
	} else {
		for (int i=0; i<n; ++i) {
			//generate n vertices with random coordinates of dim `dim`
			Vertex v;
			v.dim = dim;
			v.index = i;
			for (int j=0; j<dim; ++j) {
				v.coords.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
			}
			vertices.push_back(v);
		}
	}
}


