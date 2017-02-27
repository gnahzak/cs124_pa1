/* Creates different types of random graphs */
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>

typedef struct HeapElement {
  int vindex;
  float dist;
} HeapElement;

class BinaryHeap {

  public:
    int size;
    std::vector<HeapElement> heapValues;
    std::vector<int> positions; //positions[i] contains the heapValues index of any given vertex

    BinaryHeap(int numNodes);
    void Insert(int vindex, float dist);
    HeapElement DeleteMin();
    void heapify(int i);

  private:
    int left(int i);
    int right(int i);
    int parent(int i);
};