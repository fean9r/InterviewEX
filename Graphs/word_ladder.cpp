// Given two words (start and end), and a dictionary, 
// find the length of shortest transformation sequence from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.


#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include "Graph.h"

using namespace std;

int BFS (Graph G , int v, int Final){

	queue <int> GreyQueue;
	set <int> V;
	GreyQueue.push(v);
	int temp=0, u=0;
	Edge edge(0,0);
	vector<Edge>::iterator it;
	vector<Edge> adjacents;

	while(!GreyQueue.empty()){
		temp= GreyQueue.front();
		GreyQueue.pop();
		if(temp == Final)
			return temp;

		adjacents=G.adjacentEdges(temp);
		for (it=adjacents.begin(); it<adjacents.end(); it++){
			edge= *it;
			u = edge.adiacent(temp);
            if (V.find(u)==V.end()){
                V.insert(u);
                GreyQueue.push(u);
            }             
		}
	}
}


int main(){
	vector<int> Nodes ;
	vector<Edge> Edges;
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	int n5 = 5;
	int n6 = 6;
	int n7 = 7;
	int n8 = 8;
	vector<int>::iterator it;
	it = Nodes.insert( it ,n1);
	it = Nodes.insert( it ,n2);
	it = Nodes.insert( it ,n3);
	it = Nodes.insert( it ,n4);
	it = Nodes.insert( it ,n5);
	it = Nodes.insert( it ,n6);
	it = Nodes.insert( it ,n7);
	it = Nodes.insert( it ,n8);
	Edge e1 (n1,n2);
	Edge e2 (n1,n3);
	Edge e3 (n2,n3);
	Edge e4 (n2,n5);
	Edge e5 (n3,n4);
	Edge e6 (n4,n5);
	Edge e7 (n5,n7);
	Edge e8 (n7,n6);
	Edge e9 (n6,n8);
	vector<Edge>::iterator it2;
	it2 = Edges.begin();
  	it2 = Edges.insert ( it2 , e1 );
  	it2 = Edges.insert ( it2 , e2 );
  	it2 = Edges.insert ( it2 , e3 );
  	it2 = Edges.insert ( it2 , e4 );
  	it2 = Edges.insert ( it2 , e5 );
  	it2 = Edges.insert ( it2 , e6 );
  	it2 = Edges.insert ( it2 , e7 );
  	it2 = Edges.insert ( it2 , e8 );
	it2 = Edges.insert ( it2 , e9 );
	Graph G (Nodes,Edges);
	//G.printGraph();

	cout<< BFS(G,1,8)<<endl;

	return 0;
}