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
			// for (int j=0; j<i; j++) {
			// 	Vertex u = vertices[j];
			// 	Edge e;
			// 	e.u = u.index;
			// 	e.v = v.index;
			// 	e.length = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			// 	edges.push_back(e);
			// 	vertices[e.u].v_edges.push_back(e);
			// 	v.v_edges.push_back(e);
			// }

		}
	}

	else {
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


