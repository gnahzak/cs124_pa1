/* Creates different types of random graphs */
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>

//implement comparable
typedef struct Edge {
  int u;
  int v;
  float length;
} Edge;

typedef struct Vertex {
  int dim;
  std::vector<float> coords;
  std::vector<Edge> v_edges;
  int index;
} Vertex;

class Graph {

  public:
    int n, dim;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

    Graph(int n, int dim);
};

