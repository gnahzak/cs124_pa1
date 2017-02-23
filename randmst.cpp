/* Tests the MST algorithm on different types of graphs */
using namespace std;

#include graphs.cpp

int main() {
  // carry out testing for all functions

  return 0;
}

// MST algorithm
// takes in a graph, stored as a ___, the number of
// nodes in the graph, and an empty set
// adds the edges in the MST to the empty set

void kruskal (vector<>& e, set<int>& v, int n, set<>& x) {

  // sort edges in e
  std::sort(e.begin(), e.end(), compareEdges);

  // make sets for all vertices
  for (j = v.begin(); j != v.end(); j++){
    makeSet(v[j]);
  }

  // iterate through edges in increasing order until n-1 edges
  // have been added to the MST
  int i = 0;
  while (i < n - 1){
    if find(e[i][0]) != find(e[i][1]){
      x.add(e[i]);
      union(e[i][0], e[i][1])
    }

    i++;
  }

  return;
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
