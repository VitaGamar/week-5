#include<iostream>
#include<string.h>
using namespace std;

class Data								
{
friend class Q;
friend class Queue;
	char* kod;					// code
	int count;					// amount
	Data* next;					// pointer to the next element
	static int n;				// number of objects
public:
	Data ( ) { kod = NULL; count = 0; next = NULL; n++; }				
	Data (char* k, int cn) : kod(k), count(cn) { n++; next = NULL;}
	Data (const Data& d)
	{
		next = d.next;
		kod = "";
		kod = strcat(kod, d.kod);
		n++;
	}
	void print()
	{
		cout<<"\n Code: "<< kod;
		cout<<"  Amount: "<< count<<endl;
	}
	~Data( ) { n--; };
};

int Data::n=0;

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
	void push (char*, int);					// put element to queue
	void printall();						// print all list
	int getn () { return Data::n; }			// get number of element in list
	~Q();
};

/////////////////////////////////////////////////////
// Derivative class, could remove the element if it has the letters in code
class Queue: private Q
{
	bool islet ( Data* );					// checks for letters in a code
	void delelem (Data*);					// removes element
public:	
	Queue (): Q() {}
	Data* pop () { return Q::pop(); }
	void push (char* str, int cn) { Q::push(str,cn); }
	void printall() { Q::printall(); }
	void delletter ( );						// removes the element if it has the letters in code
	int getn () { return Q::getn(); }		// get number of element in list
	~Queue();
};
