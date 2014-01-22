#include "BinTree.h"
#include <iostream>
	BinTree::BinTree(){}

void BinTree::Insert(Node* node, int value) {
    if (value < node->Value) {
        if (node->Left == 0)
            node->Left = new Node(value);
        else
            Insert(node->Left, value);
    } else {
        if(node->Right == 0)
            node->Right = new Node(value);
        else
            Insert(node->Right, value);
    }
}

bool BinTree::Delete(Node* node, int value){
	if (value < node->Value) {
        if (node->Left == 0)
            return false;
        else
        	if(node->Left->Value ==value)
            	Insert(node->Left, value);
    } else {
        if(node->Right == 0)
            return false;
        else
            Insert(node->Right, value);
    }

	}
Node BinTree::Search(int key){

	}

void BinTree::Traversal(Node * node , CallbackType callback ){
	if (node==0)
		return ;
	Traversal(node->Left,callback);
	callback(node->Value);
	Traversal(node->Right,callback);
}

void callback(int val){
	std::cout<< val <<std::endl;
}
int main(){

	Node head(1);
	BinTree b;
	b.Insert(&head,2);
	b.Insert(&head,3);
	b.Insert(&head,4);
	b.Insert(&head,21);
	b.Insert(&head,33);
	b.Insert(&head,44);
	b.Insert(&head,23);
	b.Insert(&head,13);
	b.Insert(&head,54);
	b.Insert(&head,122);
	b.Insert(&head,30);
	b.Insert(&head,14);

	b.Traversal(&head,callback);	
	return 0;
}
