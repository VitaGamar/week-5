// task14.cpp : Defines the entry point for the console application.
//14.	Сформувати з введених беззнакових цілих чисел список типу черга. Використовуючи функцію, 
//     яка витирає зі списку останній елемент, що містить непарне число, 
//	вилучити зі сформованої черги три останніх непарних числа.

#include "stdafx.h"
#include"task14_dec.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Queue que;
	que.push();
	que.printall();

	que.del3odd();
	cout<<"\n---------------------\n";
	cout<<"\n After removal: \n";
	que.printall();

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
void Q::push( )
{
	char ch;
	Data* pel;
	int c;
	do
	{
		pel = new Data;					//allocate in dynamic memory
		if (pel == NULL)				// error
		{
			cout<< " Error! There is no anought memory! ";
			exit(1);
		}
		do
		{
			cout<< "\n Enter long positive number: ";
			cin >> c;
			if ( c<0 )
				cout<< " \nNegative! Retry! ";
		}
		while ( c<0 );
		pel->ch = c;
		pel->next = NULL;
		if ( first == NULL)					// the list is empty, first element
			first = last = pel;
		else								//it's not first element
		{
			last->next = pel;
			last = pel;
		}

		cout<<" Continue? (y/n) ";
		cin>>ch;
		}
		while ( ch!= 'n');	
}

// print all list
void Q::printall()
{
	Data* pel = first;
	if ( pel == NULL )
		cout<< "List empty! ";
	while ( pel != NULL )
	{
		cout<< pel->ch <<"  ";
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

// find last odd number in list and delete it, if there is no more odd number - do nothing
void Queue::delodd()
{
	Data* pel = Q::Getfirst();
	Data* odd = NULL;
	while ( pel != NULL )
	{
		if ( pel->ch%2 != 0 )
			odd = pel;
		pel = pel->next;
	}
	if ( odd != NULL )
		delel(odd);
}

// delete last 3 odd element
void Queue::del3odd()
{
	for (int i=0; i<3; i++)
		delodd();
}

// removes element
void Queue::delel ( Data* d)
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

