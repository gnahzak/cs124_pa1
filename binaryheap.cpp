#include "binaryheap.h"
#include <iostream>

BinaryHeap::BinaryHeap(int numNodes) {
	size = 0;
	for (int i=0; i<numNodes; ++i) {
		positions.push_back(-1);
	}
}

void BinaryHeap::Insert(int vindex, float dist) {
	if (positions[vindex] != -1) {
		heapValues[positions[vindex]].dist = dist;
		heapify(positions[vindex]);
		return;
	}

	HeapElement v;
	v.vindex = vindex;
	v.dist = dist;
	size++;

	int i = size-1;
	while (i > 0 && (heapValues[parent(i)].dist > v.dist)) {
		if (i == size-1) {
			heapValues.push_back(heapValues[parent(i)]);
		} else {
			heapValues[i] = heapValues[parent(i)];
		}
		positions[heapValues[i].vindex] = i;
		i = parent(i);
	}
	if (i == size-1) {
		heapValues.push_back(v);
	} else {
		heapValues[i] = v;
	}
	positions[heapValues[i].vindex] = i;

	// std::cout << "positions ";
	// for (int i=0; i<positions.size(); ++i) {
	// 	std::cout << positions[i] << " ";
	// }
	// std::cout << std::endl;
}

HeapElement BinaryHeap::DeleteMin() {
	if (size < 1) {
		std::cerr << "No elements\n";
	}
	HeapElement min = heapValues[0];
	heapValues[0] = heapValues[size-1];
	positions[heapValues[0].vindex] = 0;
	heapValues.pop_back();
	positions[min.vindex] = -1;
	size--;
	heapify(0);

	// std::cout << "positions ";
	// for (int i=0; i<positions.size(); ++i) {
	// 	std::cout << positions[i] << " ";
	// }
	// std::cout << std::endl;

	return min;
}

void BinaryHeap::heapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l <= size && heapValues[l].dist < heapValues[i].dist) {
		smallest = l;
	}
	if (r <= size && heapValues[r].dist < heapValues[smallest].dist) {
		smallest = r;
	}
	if (smallest != i) {
		int tmpvindex = heapValues[i].vindex;
		float tmpdist = heapValues[i].dist;
		heapValues[i].vindex = heapValues[smallest].vindex;
		heapValues[i].dist = heapValues[smallest].dist;
		heapValues[smallest].vindex = tmpvindex;
		heapValues[smallest].dist = tmpdist;
		positions[heapValues[i].vindex] = i;
		positions[heapValues[smallest].vindex] = smallest;
		heapify(smallest);
	}
}

// treat as 1-indexed
int BinaryHeap::left(int i) {
	return (2*(i+1))-1;
}

int BinaryHeap::right(int i) {
	return (2*(i+1)+1)-1;
}

int BinaryHeap::parent(int i) {
	return ((i+1)/2)-1; //parent -1 means it is root
}