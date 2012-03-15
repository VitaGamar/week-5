#include<iostream>
#include<conio.h>
using namespace std;

struct Data
{
	unsigned long int ch;
	Data* next;
};


///////////////////////////////////////////////////////////////
//parent class. Queue
class Q 
{
	Data* first;							// first element in Queue
	Data* last;								// last element in Queue
protected:
	Data* Getfirst() {return first; }
	Data* Getlast() {return last; }
	void Setfirst( Data* f) { first = f; }
	void Setlast( Data* l) { last = l; }
	void clear();
public:
	Q() { first = last = NULL; }
	Data* pop ();							// get element from queue
	void queadd ();
	void push ();					// put element to queue
	void printall();						// print all list
	~Q();
};

/////////////////////////////////////////////////////
// Derivative class, could remove the element if it has the letters in code
class Queue: private Q
{
	//Data* findodd ( );					// checks for letters in a code
	void delel ( Data*);						// removes the element if it has the letters in code
	void delodd ( );					// removes odd element
public:	
	Queue (): Q() {}
	Data* pop () { return Q::pop(); }
	void push ( ) { Q::push( ); }
	void printall() { Q::printall(); }
	void del3odd(void) ;
	~Queue();
};
