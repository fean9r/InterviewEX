
#include <utility>


#ifndef EDGE_H_
#define EDGE_H_
class Edge {
	std::pair<int,int> e;
public:
	Edge(int f, int s);
	int first();
	int second();
	int adiacent(int n);
};
#endif /*EDGE_H_ */
