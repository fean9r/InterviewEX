#include "Node.h"
#include <iostream>
	Node::Node(int Val){
		Node::Value=Val;
		Node::Left=0;
		Node::Right=0;
	}


	int main2(){

		Node head(3);
		Node n1(2);
		Node n2(1);
		Node n3(5);
		Node n4(6);

		head.Left=&n1;
		head.Right=&n3;
		n1.Left=&n2;
		n3.Right=&n4;
		std::cout<< (head.Left->Left->Left==0)<< std::endl;

	}