/* Tests the MST algorithm on different types of graphs */

#include "graphs.h"
#include <iostream>

bool compareEdges(Edge e1, Edge e2);
float kruskal (Graph& g, int n);

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
    std::cout << "Trial " << i << "\n";
    std::cout << "Creating graph\n";
    Graph g = Graph(numpoints, dim);
    avg += kruskal(g, numpoints);
  }
  avg /= numtrials;

  // return output
  std::cout << avg << " " << numpoints << " " << numtrials << " " << dim << std::endl;
  return 0;
}

// MST algorithm
// takes in a graph, stored as a ___, the number of
// nodes in the graph, and an empty set
// adds the edges in the MST to the empty set

float kruskal (Graph& g, int n) {

  float weight = 0.;

  // sort edges in e
  std::cout << "sorting\n";
  std::sort(g.edges.begin(), g.edges.end(), compareEdges);
  std::cout << "sortingcomplete\n";

  // make sets for all vertices
  // for (int w=0; w < g.vertices.size(); ++w){
  //   g.makeSet(g.vertices[w]);
  // }

  // iterate through edges in increasing order until n-1 edges
  // have been added to the MST
  // simultaneously, add the weight of the edge to the MST
  int mstedges = 0;
  int i = 0;
  while (mstedges < n - 1){
    if (g.find(g.edges[i].u.index) != g.find(g.edges[i].v.index)){
      weight += g.edges[i].length;
      g.combine(g.edges[i].u.index, g.edges[i].v.index);
      mstedges++;
    }
    i++;
  }

  return weight;
}

bool compareEdges (Edge e1, Edge e2) {
  return e1.length < e2.length;
}
