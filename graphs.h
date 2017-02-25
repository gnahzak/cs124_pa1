/* Creates different types of random graphs */
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>

struct Vertex {
  int dim;
  std::vector<float> coords;
  Vertex* parent;
  int rank;
} Vertex;

//implement comparable
struct Edge {
  struct Vertex u;
  struct Vertex v;
  float length;
};

class Graph {

  public:
    int n, dim;
    std::vector<struct Vertex> vertices;
    std::vector<struct Edge> edges;

    void initGraph(int n, int dim);
    void makeSet(struct Vertex x);
    struct Vertex find(struct Vertex x);
    void combine(struct Vertex x, struct Vertex y);
    void link(struct Vertex x, struct Vertex y);
};

