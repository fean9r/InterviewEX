#include "Edge.h"
#include <vector>

#ifndef GRAPH_H_
#define GRAPH_H_
class Graph {
	std::vector<int> Nodes;
	std::vector<Edge> Edges;
public:
	Graph(std::vector<int> N , std::vector<Edge> E);

	std::vector<Edge> adjacentEdges(int node);
	int adjacentVertex(int node, Edge e );
	void printGraph();

};
#endif /* GRAPH_H_ */
