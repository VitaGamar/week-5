// task11.cpp : Defines the entry point for the console application.
//11.	Сформувати список типу черга з введених записів, що мають поля: <код>, <кількість>. 
//Вилучити зі списку всі записи, у кодах яких крім цифр є літери. Визначити відсоток вилучених елементів. 
//Використати окрему функцію для перевірки коду запису. 

#include "stdafx.h"
#include"task11_op.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Queue que;
	que.push("125l6", 2);
	que.push("457i", 4);
	que.push("78w788", 7);
	que.push("111", 1);
	que.printall();

	int nold =  que.getn();
	cout<<" \n Number of element:   "<< nold;
	cout<<"\n------------------\n";
	que.delletter();
	cout<<"\n After removal: \n";
	que.printall();

	int nnew = que.getn();
	cout<<"\n Number of element:   "<< nnew;
	cout<<"\n------------------\n";
	cout<<"\n \tPercent of deleted elements: "<< (double)nnew/nold*100<<"%"<<endl;

	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
// get element from queue
Data* Q::pop ()
{
	Data* temp = first;

	if (temp == NULL)						//no element
		cout<<" \nEmpty! ";		
	else									
		first = first->next;

	return temp;		// return first element
}

// put element to queue
void Q::push(char* k, int c)
{
	Data* pel;
	pel = new Data;			//allocate in dynamic memory
	if (pel == NULL)		// error
	{
		cout<< " Error! There is no anought memory! ";
		exit(1);
	}
	pel->kod = new char[strlen(k)];			// fill in field
	strcpy(pel->kod, k);
	pel->count = c;
	pel->next = NULL;
	if ( first == NULL)					// the list is empty, first element
		first = last = pel;
	else								//it's not first element
	{
		last->next = pel;
		last = pel;
	}
}

// print all list
void Q::printall()
{
	Data* pel = first;
	if ( pel == NULL )
		cout<< "List empty! ";
	while ( pel != NULL )
	{
		pel->print();
		pel = pel->next;
	}
}

//delete all list, free memory
void Q::clear()
{
	Data* pel;
	while ( first != NULL)
	{
		pel = first;
		first = first->next;
		delete pel;
	}
}

Q::~Q()
{
	clear();
}

//////////////////////////////////////////////////////////////////////////////////

Queue::~Queue()
{
	Q::clear();
}

// checks for letters in a code. Return true if it has letter, so we should delete this element
bool Queue::islet(Data* d)
{
	char s[20];
	strcpy(s, d->kod);
	int len = strlen(s);
	int i=0;
	while ( isdigit(s[i]) && i<len )
		i++;
	if ( i == len )				//we have come to the end		
		return false;			//there is no letter, only digit
	else
		return true;		// code has a letter
}

// removes the element if it has the letters in code
void Queue::delletter ( )
{
	Data* pel = Getfirst();
	Data* p;
	while ( pel != NULL )
	{
		if ( islet(pel) )				//  code has a letter
		{
			p=pel->next;				// move to the next
			delelem (pel);				// delete this element
			pel = p;
		}
		else
			pel = pel->next;		// move to the next
	}
}

// removes element
void Queue::delelem ( Data* d)
{
	Data* l = Q::Getlast();
	Data* f = Q::Getfirst();

	if ( d == f )							//if we should delete first element
	{
		if ( d == l )						// it also is the last
		{
			Q::Setfirst(NULL);				// so, the list is empty
			Q::Setlast(NULL);
		}
		else								// it is not last element
			Q::Setfirst(d->next);			// move to the next
		delete d;							// delete this element
	}

	else								// it's not first
		if ( d == l )					// but last element
		{
			while ( f->next != d)
				f = f->next;			//find last but one
			f->next = NULL;				
			Q::Setlast(f);				//make it last
			delete d;					// and delete d
		}
		else							// element is in the middle of the list
		{
			f = Q::Getfirst();
			l = f->next;
			while ( l!=d )
			{
				f = f->next;
				l= l->next;
			}
			f->next = l->next;	
			delete d;
		}
}