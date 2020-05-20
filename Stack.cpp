/*name:yehudit mendelboim*/
/*ID:313526675*/
#include"Stack.h"
Stack::~Stack() {
	while (listS.length()) {/*Remove all values from the stack.*/
		listS.remove(listS.length());
	}
}
const char* Stack::top() const{/*Get the value from the top of the stack.*/
	int size = listS.length();
	if (size) {
		return listS.at(size);
	}
	else {
		cout << "This list is empty" << endl;
		return nullptr;
	}
}
void Stack::pop(){/*Remove the value from the top of the stack.*/
	int size = listS.length();
	listS.remove(size);
}
void Stack::push(const char* data){/*Place a new value at the top of the stack.*/
	listS.append(data);
}
bool Stack::isEmpty() const{/*Whether or not the current stack contains values.*/
	return listS.isEmpty();
}
void Stack::print() const{/*Print the contents of the stack.*/
	if (listS.isEmpty() == false) {
		cout << "The list is empty" << endl;
	}
	else {
		int size, i = 1;
		for (size = listS.length(); size > 0; --size) {
			cout << "The data in the " << i << " Node of the stack:" << listS.at(size) << endl;
			++i;
		}
	}
}

