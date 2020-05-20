/*name:yehudit mendelboim*/
/*ID:313526675*/
#include "LinkedList.h"
LinkedList::LinkedList() {	/* Create an empty list. */
	head = NULL;
	tail = NULL;
	size = 0;
}
LinkedList::LinkedList(const LinkedList& other) {/*Copy an existing list by reference.*/
	if (other.size > 0) {
		Node* temp = other.get(1);
		while (temp != NULL) {
			this->append(temp->getData());
			temp = temp->getNext();
		}
	}
	else {
		LinkedList();
	}
}
Node* LinkedList::createNode(const char* data , Node* next ) { /*Alias of the node constructor, will also increment the list size.*/
	Node *a;
	a = new Node(data,next);
	++size;
	return a;
}
Node* LinkedList::get(int index) const {/* Get a node at a given index.*/
	Node* point;
	if (index > size || index < 1)
	{
		return NULL;
	}
	point = this->head;
	for (int i = 1; i < index ; ++i) {
		point = point->getNext();
	}
	return point;
}
void LinkedList::prepend(const char* data) {/*Add a new node to the beginning of the list.*/
	Node *a = createNode(data,this ->head);
	this->head = a;
	if (size == 1) {
		tail = a;
	}
}
void LinkedList::append(const char* data) {/*Add a new node to the end of the list.*/
	Node *a = createNode(data);
	if (size == 1) {
		head = a;
		tail = a;
	}
	else {
		Node *b = this->head;
		for (int i = 0; b->getNext() != NULL; ++i) {
			b = b->getNext();
		}
		b->setNext(a);
		tail = a;
	}
}
void LinkedList::insert(const char* data, int index) {/* Insert a new node at the given index.*/
	if (index  > size + 1 || index < 0) {
		return;
	}
		if (index == 1) {
			prepend(data);
		}
		else {
			Node *temp2 = get(index - 1);
			Node *newnode = createNode(data, temp2->getNext());
			temp2->setNext(newnode);
		}
	
}
void LinkedList::remove(int index) {/*Remove the node at the given index.*/
	if (this->isEmpty() == true) {
		Node *temp;
		if (index == 1) {
			temp = head;
			temp = temp->getNext();
			delete head;
			head = temp;
			--size;
		}
		else if (index == size) {
			temp = get(index - 1);
			delete tail;
			temp->setNext(NULL);
			tail = temp;
			--size;
		}
		else if ((index > 1) && (index < size)) {
			Node *temp1 = get(index - 1);
			Node *temp2 = get(index);
			Node *temp3 = get(index + 1);
			delete temp2;
			temp1->setNext(temp3);
			--size;
		}
	}
}
bool LinkedList::contains(const char* value) const {/* Whether or not the list contains a given value.*/
	Node *a = this->head;
	if (!(strcmp(a->getData(), value))) {
		return true;
	}
	for (int i = 1; i < size; ++i) {
		a = a->getNext();
		if (!(strcmp(a->getData(), value))) {
			return true;
		}
	}
	return false;
}
bool LinkedList::isEmpty() const {/*Whether or not the current list contains nodes.*/
	if (size > 0) {
		return true;
	}
	return false;
}
unsigned LinkedList::length() const {/* Get the length of the list.*/
	return this->size;
}
void LinkedList::print() const {/*Print the contents of the list.*/
	if (isEmpty() == true) {
		Node *a = this->head;
		cout << "The data in the 1 Node:" << a->getData() << endl;
		for (int i = 2; i <= size; ++i) {
			a = a->getNext();
			cout << "The data in the " << i << " Node:" << a->getData() << endl;
		}
	}
	else {
		cout << "The list is empty "<< endl;
	}
}
const char* LinkedList::at(int index) const {/*Get the value of a node at a given index.*/
	Node *a = get(index);
	return a->getData();
}
bool LinkedList::operator==(const LinkedList& other) const {/*Compare two lists to see if they contain the same values.*/
	if (this->size != other.size) {
		return false;
	}
	if(this->size == 0 && other.size == 0){
		return true;
	}
	Node *temp = other.head;
	for (int i = 0; temp != NULL; ++i) {
		if (this->contains(temp->getData())) {
			temp = temp->getNext();
		}
		else{
			return false;
		}
	}
	return true;
}
LinkedList::~LinkedList() {/*Remove all node from the list.*/
	while(size)
	{
		this->remove(1);
	}
}
