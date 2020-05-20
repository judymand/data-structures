/*name:yehudit mendelboim*/
/*ID:313526675*/
#include"Queue.h"
Queue::~Queue(){/*Remove all values from the queue.*/
	listQ.~LinkedList();
}
void Queue::enqueue(const char* value){/*Place a new value at the front of the queue.*/
	listQ.append(value);
}
void Queue::dequeue(){/*Remove the value from the front of the queue.*/
	listQ.remove(1);
}
const char* Queue::front() const{/* Get the value from the front of the queue.*/
	if (listQ.isEmpty()) {
		return listQ.at(1);
	}
	cout << "Empty list" << endl;
	return nullptr;
}
bool Queue::isEmpty() const{/*Whether or not the current queue contains values.*/
	return listQ.isEmpty();
}
void Queue::print() const{/*Print the contents of the queue.*/
	listQ.print();
}
