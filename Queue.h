/*name:yehudit mendelboim*/
/*ID:313526675*/
#pragma once
#include"LinkedList.h"
#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H
class Queue {
private:
	LinkedList	listQ;
public:
	Queue() :listQ() {};
	/**
	* Remove all values from the queue.
	*/
	~Queue();
	/**
	* Place a new value at the front of the queue.
	*
	* @param data The data to be inserted.
	*/
	void enqueue(const char* value);
	/**
	* Remove the value from the from of the queue.
	*/
	void dequeue();
	/**
	* Get the value from the front of the queue.
	*/
	const char* front() const;
	/**
	* Whether or not the current queue contains values.
	*
	* @return True if at least one value exists.
	*/
	bool isEmpty() const;

	/**
	* Print the contents of the queue.
	*/
	void print() const;
};
#endif
