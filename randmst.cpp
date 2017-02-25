/* Tests the MST algorithm on different types of graphs */

#include "graphs.h"
#include <iostream>

int main(int argc, char *argv[]) {

  // read in input from user
  if (argc != 4) {
    std::cout << "Failure: incorrect number of arguments";
    return 1;
  }

  // check for nonnegative numpoints and positive numtrials
  int numpoints = argv[2] - '0';
  int numtrials = argv[3] - '0';
  if (numpoints < 0 || numtrials <= 0){
    std::cout << "Failure: number of points and trials must be positive";
    return 2;
  }
  // if numpoints is 1 or 0, return 0

  if (numpoints == 1 || numpoints == 0){
    return 0.0;
  }

  // if dimension isn't 0, 2, 3, or 4, return an error
  int dim = argv[4];
  if (dim < 0 || dim > 4 || dim == 1){
    std::cout << "Dimension must be 0, 2, 3, or 4";
    return 3;
  }

  // for numtrials, creates an appropriate graph and sums weight
  float avg = 0.;
  for (int i = 0; i < numtrials; i++){
    g = Graph.initGraph(numpoints, dim);
    avg += kruskal(g.edges, g.vertices, numpoints);
  }
  avg /= numtrials

  // return output
  std::cout << avg << " " << numpoints << " " << numtrials << " " << dim << endl;
  return 0;
}

// MST algorithm
// takes in a graph, stored as a ___, the number of
// nodes in the graph, and an empty set
// adds the edges in the MST to the empty set

float kruskal (std::vector<Edge>& e, std::vector<Vertex>& v, int n) {

  float weight = 0.;

  // sort edges in e
  std::sort(e.begin(), e.end(), compareEdges);

  // make sets for all vertices
  for (Vertex w : vertices){
    makeSet(w);
  }

  // iterate through edges in increasing order until n-1 edges
  // have been added to the MST
  // simultaneously, add the weight of the edge to the MST
  int i = 0;
  while (i < n - 1){
    if find(e[i][0]) != find(e[i][1]){
      weight += e[i].length;
      combine(e[i].u, e[i].v);

      i++;
    }
  }

  return weight;
}


bool compareEdges (Edge e1, Edge e2) {
  return e1.length < e2.length;
}

// uses mergesort to sort the edges from least to greatest length
// void sort(vector<>& edges){
//   int half1size = edges.size()/2;
//   int half2size = edges.size()-half1size;

//   if (half1size == 2) {

//   }
// }
