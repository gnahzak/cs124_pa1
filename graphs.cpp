/* Creates different types of random graphs */
#include "graphs.h"
#include <iostream>

const int large = 1000;

Graph::Graph(int n, int dim) {
	this->n = n;
	this->dim = dim;

	srand(time(NULL));

	float maxWeight = maxw(n, dim);

	if (dim == 0) {
		for (int i=0; i<n; ++i) {
			Vertex v;
			v.dim = dim;
			v.index = i;
			//`makeSet`
			v.parent = i;
			v.rank = 0;
			vertices.push_back(v);
			for (int j=0; j<i; j++) {
				Vertex u = vertices[j];
				Edge e;
				e.u = u;
				e.v = v;
				e.length = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				if (n < large || e.length < maxWeight) {
					edges.push_back(e);
				}
			}
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

int Graph::find(int x) {
	if (x != vertices[x].parent) {
		vertices[x].parent = find(vertices[x].parent);
	}
	return vertices[x].parent;
}

void Graph::combine(int x, int y) {
	link(find(x), find(y));
}

void Graph::link(int a, int b) {
	if (vertices[a].rank > vertices[b].rank) {
		vertices[b].parent = a;
	} else {
		if (vertices[a].rank == vertices[b].rank) {
			vertices[b].rank++;
		}
		vertices[a].parent = b;
	}
}

float Graph::maxw(int n, int dim){
	if (dim == 0){
		return (15.0 / (float)n);
	}
	else if (dim == 2){
		return (2.25 / pow((float)n, 0.5));
	}
	else if (dim == 3){
		return (1.75 / pow((float)n, 0.33));
	}
	else {
		return (1.65 / pow((float)n, 0.25));
	}
}


