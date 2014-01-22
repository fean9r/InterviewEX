#include "Node.h"

#ifndef BinTree_H_
#define BinTree_H_
typedef void (*CallbackType)(int);

class BinTree {
public:
	BinTree();
	void Insert(Node* node, int value);
	bool Delete(Node* node, int value);
	Node Search(int key);
	void Traversal(Node * node , CallbackType callback );
	int Size(Node* node);
};
#endif /*NODE_H_ */