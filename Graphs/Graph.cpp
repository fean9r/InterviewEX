#include "Graph.h"
#include "Edge.h"
#include <iostream>
using namespace std;
Graph::Graph( std::vector<int> N , std::vector<Edge> E){
	Graph::Nodes =N;
	Graph::Edges =E;
}
	vector<Edge> Graph::adjacentEdges(int node){
		vector<Edge> adjacents ;
		vector<Edge>::iterator it;
		vector<Edge>::iterator it2;
		Edge tmp(0,0);
		for (it=Graph::Edges.begin(); it<Graph::Edges.end(); it++){
			tmp= *it;
    		if(tmp.first()==node)
    			it2=adjacents.insert(it2,tmp);
		}
    	return adjacents;
	}

	void Graph::printGraph(){
		vector<int>::iterator it;
		vector<Edge>::iterator it2;
		std::vector<Edge> ris;
		Edge tEdge(0,0);
		int tmp;
		for (it=Graph::Nodes.begin(); it<Graph::Nodes.end(); it++){
			tmp= *it;
    		ris = adjacentEdges(tmp);
    			for (it2=ris.begin(); it2<ris.end(); it2++){
    				tEdge = *it2;
    				std::cout << tmp<< " "<<tEdge.first()<< " "<< tEdge.second() << std::endl;
    			}
		}


	}


int main2(){
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
	G.printGraph();
	return 0;
};

