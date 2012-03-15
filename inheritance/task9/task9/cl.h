#include<iostream>
using namespace std;

struct elem				
{
	long data;			// long number
	bool is;			// sign - this number we have already seen
	elem* next;			// next element
};

///////////////////////////////////////////////////////////////////
class List					// parent class
{
protected:
	elem* first;			// first element of the list, top
public:
	List() : first(0) {}		
	void pop ( long* pdat);		// write down number to pdat, delete first element
	void popel();				// display this element
	elem* put();				// enter data and allocate it dynamic memory, return pointer
	void print();				// print list
	void clear ();				
	~List()
	{
		clear();
	}
};
////////////////////////////////////////////////////////////////////

class Queue: private List				// Queue, inheritance
{
	elem* last;							// pointer to the last element of the list
public:
	Queue(): List() { last = NULL; }
	void quepop();						// display first element
	void queadd ();						//add new element to the list
	void queprint() { List::print(); }
	elem* min ( );						//find minimal element and return pointer on it
	~Queue() 
	{ 
			clear(); 
			last = NULL;
	}
};
///////////////////////////////////////////////////////////////////

class Stack: private List			     // Stack, inheritance
{
public:
	Stack() : List() {}
	void stpop();					    // display first element
	void stadd( elem* );				//add new element to the list
	void stprint() { List::print(); }
	~Stack()
	{
		clear();
	}
};