/*name:yehudit mendelboim*/
/*ID:313526675*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define MAX_SIZE 100
#define MIN_SIZE 2
#include "Linkedlist.h"
#include"Stack.h"
#include"Queue.h"
void printOnScreen();/*Puts numbers into a queue in a loop as long as the number is different from '9999'*/
bool isbalanced(const char* str);
int main() {/*Selection menu in the loop until the user presses the number 3*/
	int choice;
	do{
		cout << "Insert 1 for number queue or 2 for parentheses string or 3 for exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			printOnScreen();
			main();
			break;
		case 2:
			char str[MAX_SIZE];
			cout << "Please insert a string(Up to 99 characters)" << endl;
			cin >> str;
			if (isbalanced(str)) {  /* Checks if the string is balanced or not balanced */
				cout << "The string is balanced" << endl;
			}
			else {
				cout << "The string is not balanced" << endl;
			}
			main();
			break;
		case 3:
			return 0;
		default:
			cout << "Incorrect character" << endl;
			break;
		}
	} while (choice == 3);

}
void printOnScreen() {/*Puts numbers into a queue in a loop as long as the number is different from '9999'*/
	Queue list;
	char *num;
	char number[SIZE];
	cout << "please enter numbers(Up to 9 digits):" << endl;
	cin >> number;
	num = number;
	while (strcmp(number,"9999") != 0) {/*Puts numbers into a queue in a loop as long as the number is different from '9999'*/
		list.enqueue(num);
		cin >> number;
	}
	list.print();
}
bool isbalanced(const char* str) { /* Checks if the string is balanced or not balanced */
	Stack list;
	char temp = '0';
	char exp1[MIN_SIZE];
	exp1[0] = temp;
	exp1[1] = '\0';
	char *pBracket = exp1;
	for (int i = 0; str[i] != '\0'; ++i) {/*Running on the string we received*/
		temp = str[i];
		exp1[0] = temp;
		exp1[1] = '\0';
		pBracket = exp1;
		char top[MIN_SIZE];
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
			list.push(pBracket);/*Opener bracket enters the stack*/
		}
		else {
			if (str[i] == '}') { 
				if (list.isEmpty() == false) {/*Checks that the stack is not empty*/
					return false;
				}
				strcpy(top, list.top());
				if (top[0] == '{') {
					list.pop();/*Deletes the last entry (Node) that enters the stack*/
				}
				else {
					return false;
				}
			}
			if (str[i] == ']') {
				if (list.isEmpty() == false) {/*Checks that the stack is not empty*/
					return false;
				}
				strcpy(top, list.top());
				if (top[0] == '[') {
					list.pop();/*Deletes the last entry (Node) that enters the stack*/
				}
				else {
					return false;
				}
			}
			if (str[i] == ')' ) {
				if (list.isEmpty() == false) {/*Checks that the stack is not empty*/
					return false;
				}
				strcpy(top, list.top());
				if (top[0] == '(') {
					list.pop();/*Deletes the last entry (Node) that enters the stack*/
				}
				else {
					return false;
				}
			}
		}
	}
	if (list.isEmpty() == true) {/*Checks that the stack is not empty*/
		return false;
	}
	return true;
}
