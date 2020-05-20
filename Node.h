#define _CRT_SECURE_NO_WARNINGS
#ifndef CPP_NODE_H
#define CPP_NODE_H
#include <iostream>
/*name:yehudit mendelboim*/
/*ID:313526675*/
#include <sstream>
#include <string>
using namespace std;
class Node {
private:
	char* data;
	Node* next;
public:
	void setData(const char* d);/*Enter a value for data*/
	char* getData() { return data; };/*Returns the value in data*/
	void setNext(Node* n);/*Gets a value for next*/
	Node* getNext() { return next; };/*Returns the value in next*/
	Node(const char* d = NULL, Node* n = NULL); /*An initializing constructor that receives data*/
	Node(const Node &a);/*Copy constructor*/
	~Node() {/*distructor*/
		if (data) {
			delete[]data;
		}
	}
};
#endif