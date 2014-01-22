#ifndef NODE_H_
#define NODE_H_
class Node {
public:
	Node* Right;
	Node* Left;
	int Value;
	Node(int Val);
};
#endif /*NODE_H_ */