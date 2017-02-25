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
			v.parent = i;
			v.rank = 0;
			v.coords.push_back((float)i);
			for (int j=0; j<n; j++) {
				Vertex u = vertices[j];
				Edge e;
				e.u = u;
				e.v = v;
				e.length = static_cast <float> (rand());
				edges.push_back(e);
			}
		}
	}

	else {
		for (int i=0; i<n; ++i) {
			Vertex v;
			v.dim = dim;
			v.index = i;
			v.parent = i;
			v.rank = 0;
			for (int j=0; j<dim; ++j) {
				v.coords.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
			}

			for (int k=0; k < i; ++k) {
				Vertex u = vertices[k];
				float sqsum = 0;
				for (int d=0; d<dim; ++d) {
					sqsum += pow((v.coords[d] - u.coords[d]),2);
				}
				Edge e;
				e.u = u;
				e.v = v;
				e.length = sqrt(sqsum);
				edges.push_back(e);
			}

			vertices.push_back(v);
		}
	}

	for (int q = 0; q < edges.size(); q++) {
		std::cout << edges[q].u.index << " " << edges[q].v.index << " " << edges[q].length << std::endl;
	}
}

// void Graph::makeSet(Vertex& x) {
// 	x.parent = &x;
// 	std::cout << x.parent << " " << &x << std::endl;
// 	x.rank = 0;
// }

int Graph::find(Vertex& x) {
	if (x.index != x.parent) {
		x.parent = find(vertices[x.parent]);
	}
	return x.index;
}

void Graph::combine(Vertex& x, Vertex& y) {
	link(vertices[find(x)], vertices[find(y)]);
}

void Graph::link(Vertex& a, Vertex& b) {
	if (a.rank > b.rank) {
		b.parent = a.parent;
	}else {
		if (a.rank == b.rank) {
		b.rank++;
		}
		a.parent = b.parent;
	}
	//return b;
}

