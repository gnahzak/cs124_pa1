/* Creates different types of random graphs */
#include "graphs.h"

class Graph {

	void initGraph(int n, int dim) {
		this->n = n;
		this->dim = dim;

		srand(time(NULL));

		for (int i=0; i<n; ++i) {
			Vertex* v = malloc(sizeof(Vertex));
			v->dim = dim;
			for (int j=0; j<dim; ++j) {
				v->coords.insert(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
			}

			for (Vertex u : vertices) {
				float sqsum = 0;
				for (int d=0; d<dim; ++d) {
					sqsum += pow((v[d] - u[d]),2);
				}
				Edge* e = malloc(sizeof(Edge));
				e->u = u;
				e->v = v;
				e->length = sqrt(sqsum);
			}

			vertices.insert(v);
		}
	}

	void makeSet(Vertex x) {
		x.parent = &x;
		x.rank = 0;
	}

	Vertex find(Vertex x) {
		if (x != x.parent) {
			x.parent = find(*x.parent);
		}
		return *x.parent;
	}

	void combine(Vertex x, Vertex y) {
		link(find(Vertex x),find(Vertex y));
	}

	void link(Vertex x, Vertex y) {
		if (x.rank > y.rank) {
			Vertex tmp = x;
			x = y;
			y = tmp;
		}else if (x.rank == y.rank) {
			y.rank++;
		}
		x.parent = &y;
		return y;
	}
};

