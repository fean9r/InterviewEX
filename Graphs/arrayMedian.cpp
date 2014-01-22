// median of two sorted arrays
// there are two sorted arrays A and B of size m and n respectively. 
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


#include <vector>
#include <iostream>
#include <iomanip>
#include "Node.h"

// length(A) 14
//std::vector<int > A ={1,2,5,6,8,10,23,46,67,89,120,135,321,568};
// length(B) 18
//std::vector<int > B ={4,5,7,12,17,21,23,35,56,67,70,80,111,124,126,135,245,578};


int valInA=0;
int valInB=0;
typedef void (*CallbackType)(int);

void callbackA(int valA){
	valInA=valInA+valA;
}
void callbackB(int valB){
	valInB=valInB+valB;
}

void traversal(Node * node , CallbackType callback ){
	if (node==0)
		return ;
	traversal(node->Left,callback);
	callback(node->Value);
	traversal(node->Right,callback);
}

float arrayMedian(Node *A,Node *B){

	traversal(A,callbackA);
	traversal(B,callbackB);

	return float(valInA+valInB)/(5+5);
}


int main(){
	Node head1(3);
	Node n1(2);
	Node n2(1);
	Node n3(5);
	Node n4(6);
	head1.Left=&n1;
	head1.Right=&n3;
	n1.Left=&n2;
	n3.Right=&n4;

	Node head2(9);
	Node n1b(8);
	Node n2b(2);
	Node n3b(10);
	Node n4b(11);
	head2.Left=&n1b;
	head2.Right=&n3b;
	n1b.Left=&n2b;
	n3b.Right=&n4b;

	std::cout << " the median of the two arrays is : " << std::setprecision( 2 )<< arrayMedian(&head1,&head2)<<std::endl;

	return 0;
}