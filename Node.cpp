/*name:yehudit mendelboim*/
/*ID:313526675*/
#include "Node.h"
void Node::setData(const char* d) {/*Enter a value for data*/
	if (d != NULL) {
		int size;
		size = strlen(d) + 1;
		data = new char[size];
		strcpy(data, d);
	}
	else data = NULL;
}
void Node::setNext(Node* n) {/*Gets a value for next*/
	this->next = n;
}
Node::Node(const char* d, Node* n) {/*An initializing constructor that receives data*/
	setData(d);
	setNext(n);
}
Node::Node(const Node &a) {/*Copy constructor*/
	setData(a.data);
	next = a.next;
}
