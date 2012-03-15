// task9.cpp : Defines the entry point for the console application.
//9.	Сформувати з введених довгих цілих чисел список типу черга. Створити новий список типу стек, 
//в який перенести введені елементи в порядку зростання їх значень. Використати функцію для визначення 
//найменшого елемента списку-черги. 

#include "stdafx.h"
#include"cl.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Stack st;
	Queue que;
	que.queadd();
	cout<<"\n----------\n";
	elem* pel;
	while ( pel = que.min())
		st.stadd(pel);
	st.stprint();
	system("pause");
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

// enter data and allocate it dynamic memory, return pointer
elem* List::put ( )
	{
		elem* pel;
		pel = new elem;			//allocate in dynamic memory
		if (pel == NULL)		// error
		{
			cout<< " Error! There is no anought memory! ";
			exit(1);
		}
		cout<<" \n Enter long number: ";
		cin>>pel->data;
		pel->is = false;			
		return pel;
	}

// write down number to pdat, delete first element
void List::pop ( long* pdat)
	{
		elem* pel = first;
		if (pel == NULL)				//  no element
		{
			cout<<" \nEmpty! ";
			*pdat = 0;					//
		}
		else
		{
			*pdat = pel->data;
			first = first->next;
			delete pel;
		}
	}

// display number
void List::popel()
{
	long li;	
	pop( &li );
	if ( li ) 
		cout<<li<<" ";
}

// free memory
void List::clear ()
{
	elem* pel;
	while ( first != NULL)
	{
		pel = first;
		first = first->next;
		delete pel;
	}
}

// print all list
void List::print()
{
	elem* pel = first;
	if ( pel == NULL)
		cout<<" Empty! ";
	while ( pel!=NULL )
	{
		cout << pel->data<<"  ";
		pel = pel->next;
	}
}

////////////////////////////////////////////////////////////////////////

// display first element
void Queue::quepop()
	{
		List::popel();
	}

//add new element to the list
void Queue::queadd ()
	{
		char ch;
		elem* pel;
		do
		{
			pel = List::put();
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

//find minimal element and return pointer on it
elem* Queue::min( )
{
	elem* pel = first;
	elem* m;				//minimal element
	bool flag = true;		
	if ( first == last )		//only one element
	{
		if ( first->is == false )		//we have not returned it yet
		{
			first->is = true;			// mark this element
			return first;				// and return
		}
		else
			return NULL;				// already done it
	}
	while ( flag == true && pel!=NULL )		//until the end and we still have items that we have not returned
	{
		if ( pel->is == false)		//we have not returned it yet
		{
			flag = false;			// mark this 
			m = pel;				// consider its minimum
			continue;
		}
		pel = pel->next;
	}
	if ( flag == true ) return NULL;			//all items were considered
	pel = first->next;							// starting search minimum from second element
	while ( pel !=NULL )
	{
		if ( (pel->is == false) && (pel->data < m->data) )
			m = pel;
		pel = pel->next;
	}

	m->is = true;
	return m;
}


///////////////////////////////////////////////////////////////////////////

  // display first element
void Stack::stpop()
{
	List::popel();
}

//add new element to the list
void Stack::stadd( elem* p)
{
	elem* pel = new elem;
	pel->data = p->data;
	if ( first == NULL)
	{
		pel->next = NULL;
		first =  pel;
	}
	else
	{
		pel->next = first;
		first = pel;
	}
}
