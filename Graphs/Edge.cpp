
#include "Edge.h"

Edge::Edge(int f, int s) {
	Edge::e = std::make_pair(f,s);
}
	int Edge::adiacent(int n){
		if(Edge::e.first==n)
			return Edge::e.second;
		if(Edge::e.second==n)
			return Edge::e.first;
		return -1;
	}
	int Edge::first(){ return Edge::e.first;}
	int Edge::second(){return Edge::e.second;}
// int main(){
// 	Edge e (1,2);
// 	return 0;
// }