/* Creates different types of random graphs */
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>

typedef struct Vertex {
  int dim;
  std::vector<float> coords;
  int parent;
  int index;
  int rank;
} Vertex;

//implement comparable
typedef struct Edge {
  struct Vertex u;
  struct Vertex v;
  float length;
} Edge;

class Graph {

  public:
    int n, dim;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

    Graph(int n, int dim);
//    void makeSet(Vertex& x);
    int find(int x);
    void combine(int x, int y);
    void link(int a, int b);
};

