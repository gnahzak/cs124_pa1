/* Creates different types of random graphs */
#include "graphs.h"
#include <iostream>

Graph::Graph(int n, int dim) {
	this->n = n;
	this->dim = dim;

	srand(time(NULL));

	std::cout << "here7";

	if (dim == 0) {
		for (int i=0; i<n; ++i) {
			Vertex v;
			v.dim = dim;
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

	std::cout << "here8\n";

	for (int i=0; i<n; ++i) {
		Vertex v;
		v.dim = dim;
		for (int j=0; j<dim; ++j) {
			v.coords.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		}

		std::cout << "here9";

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

		std::cout << "here10";

		vertices.push_back(v);

		std::cout << "here11" << i << std::endl;
	}

	std::cout << "here12" << std::endl;
}

void Graph::makeSet(Vertex& x) {
	x.parent = &x;
	x.rank = 0;
}

Vertex* Graph::find(Vertex& x) {
	if (&x != x.parent) {
		x.parent = find(*x.parent);
	}
	return x.parent;
}

void Graph::combine(Vertex& x, Vertex& y) {
	link(*find(x),*find(y));
}

void Graph::link(Vertex& x, Vertex& y) {
	if (x.rank > y.rank) {
		Vertex tmp = x;
		x = y;
		y = tmp;
	}else if (x.rank == y.rank) {
		y.rank++;
	}
	x.parent = &y;
	//return y;
}

