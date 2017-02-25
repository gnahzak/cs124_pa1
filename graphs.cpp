/* Creates different types of random graphs */
#include "graphs.h"

Graph::Graph(int n, int dim) {
	this->n = n;
	this->dim = dim;

	srand(time(NULL));

	if (dim == 0) {
		for (int i=0; i<n; ++i) {
			Vertex* v = (Vertex*)malloc(sizeof(Vertex));
			v->dim = dim;
			v->coords.push_back((float)i);
			for (int j=0; j<n; j++) {
				Vertex* u = &vertices[j];
				Edge* e = (Edge*)malloc(sizeof(Edge));
				e->u = *u;
				e->v = *v;
				e->length = static_cast <float> (rand());
				edges.push_back(*e);
			}
		}
	}

	for (int i=0; i<n; ++i) {
		Vertex* v = (Vertex*)malloc(sizeof(Vertex));
		v->dim = dim;
		for (int j=0; j<dim; ++j) {
			v->coords.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		}

		for (int j=0; j < vertices.size(); ++j) {
			Vertex* u = &vertices[j];
			float sqsum = 0;
			for (int d=0; d<dim; ++d) {
				sqsum += pow((v->coords[d] - u->coords[d]),2);
			}
			Edge* e = (Edge*)malloc(sizeof(Edge));
			e->u = *u;
			e->v = *v;
			e->length = sqrt(sqsum);
			edges.push_back(*e);
		}

		vertices.push_back(*v);
	}
}

void Graph::makeSet(Vertex x) {
	x.parent = &x;
	x.rank = 0;
}

Vertex* Graph::find(Vertex x) {
	if (&x != x.parent) {
		x.parent = find(*x.parent);
	}
	return x.parent;
}

void Graph::combine(Vertex x, Vertex y) {
	link(*find(x),*find(y));
}

void Graph::link(Vertex x, Vertex y) {
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

