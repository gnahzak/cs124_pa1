/* Tests the MST algorithm on different types of graphs */

#include "graphs.h"
#include "binaryheap.h"
#include <iostream>

bool compareEdges(Edge e1, Edge e2);
float prim (Graph& g, int n);

float maxWeight = 0;

int main(int argc, char *argv[]) {

  // read in input from user
  if (argc != 5) {
    std::cout << "Failure: incorrect number of arguments\n";
    return 1;
  }

  // check for nonnegative numpoints and positive numtrials
  int numpoints = std::atoi(argv[2]);
  int numtrials = std::atoi(argv[3]);
  if (numpoints < 0 || numtrials <= 0){
    std::cout << "Failure: number of points and trials must be positive\n";
    return 2;
  }

  // if numpoints is 1 or 0, return 0

  if (numpoints == 1 || numpoints == 0){
    return 0.0;
  }

  // if dimension isn't 0, 2, 3, or 4, return an error
  int dim = std::atoi(argv[4]);
  if (dim < 0 || dim > 4 || dim == 1){
    std::cout << "Dimension must be 0, 2, 3, or 4\n";
    return 3;
  }

  // for numtrials, creates an appropriate graph and sums weight
  float avg = 0.;
  for (int i = 0; i < numtrials; i++){
    //std::cout << "Trial " << i << ": ";
    //std::cout << "Creating graph\n";
    Graph g = Graph(numpoints, dim);
    std::cout << "Completed Graph Creation\n";
    avg += prim(g, numpoints);
    sleep(1); //to properly reseed random number generator
  }
  avg /= numtrials;

  // return output
  //std::cout << "max edge weight: " << maxWeight << std::endl;
  std::cout << avg << " " << numpoints << " " << numtrials << " " << dim << std::endl;
  return 0;
}

// MST algorithm
// takes in a graph, stored as a ___, the number of
// nodes in the graph, and an empty set
// adds the edges in the MST to the empty set

float prim (Graph& g, int n) {
  float weight = 0.;

  float dist[n];
  bool inMST[n];
  int prev[n];

  for (int i=0; i<n; ++i) {
    dist[i] = std::numeric_limits<float>::max();
    inMST[i] = false;
    prev[i] = -1;
  }


  BinaryHeap H = BinaryHeap(n);
  H.Insert(0,0);
  //vertex 0 as source
  dist[0] = 0;
  inMST[0] = true;
  prev[0] = 0;


  while (H.size > 0) {
    HeapElement he = H.DeleteMin();
    // std::cout << "delete\n";
    // for (int i=0; i<H.heapValues.size(); ++i) {
    //   std::cout << H.heapValues[i].vindex << " ";
    // }
    // std::cout << std::endl;
    weight += he.dist;
    //std::cout << he.vindex << " " << prev[he.vindex] << " " << weight << std::endl;
    Vertex v = g.vertices[he.vindex];
    inMST[v.index] = true;

    if (g.dim > 0) {
      for (int i=0; i<n; ++i) {
        Vertex w = g.vertices[i];
        if (w.index != v.index) {
          if (!inMST[w.index]) {
            float elength = 0;
            for (int d=0; d<g.dim; ++d) {
              elength += pow((w.coords[d] - v.coords[d]),2);
            }
            elength = sqrt(elength);
            if (dist[w.index] > elength) {
              dist[w.index] = elength;
              prev[w.index] = v.index;
              H.Insert(w.index,elength);
            }
          }
        }
      }
    } else {
      for (int i=0; i<v.v_edges.size(); ++i) {
        Edge e = v.v_edges[i];
        Vertex w = g.vertices[e.u];
        if (w.index == v.index) {
          w = g.vertices[e.v];
        }
        if (!inMST[w.index] && (dist[w.index] > e.length)) {
          //std::cout << w.index << " " << inMST[w.index];
          dist[w.index] = e.length;
          prev[w.index] = v.index;
          H.Insert(w.index,e.length);
        }
        // for (int i=0; i<H.heapValues.size(); ++i) {
        //   std::cout << H.heapValues[i].vindex << " ";
        // }
        // std::cout << std::endl;
      }
    }
  }
  weight /= n;
  return weight;
}

bool compareEdges (Edge e1, Edge e2) {
  return e1.length < e2.length;
}
