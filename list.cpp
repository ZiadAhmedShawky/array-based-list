#include "List.h"
#include<iostream>
using namespace std;
template<class elemType>
inline bool List<elemType>::isEmpty() const
{
	return(length == 0);

}

template<class elemType>
bool List<elemType>::isFull() const
{
	return (length==maxSize);
}

template<class elemType>
int List<elemType>::listSize() const
{
	return length;
}

template<class elemType>
int List<elemType>::maxsize() const
{
	return maxSize;
}

template<class elemType>
bool List<elemType>::isItemEqual(int location, const elemType& item) const
{
	return(list[location] == item);
}

template<class elemType>
void List<elemType>::insertAt(int location, elemType insertItem)
{
	if (location < 0 || location >= maxSize)
	
		cout << " the position is out of range " << endl;

	else if (length == maxSize)
	
		cout << "the list is full" << endl;
	
	else
	{
		for (int i = length; i > location; i--)
		{
			list[i] = list[i - 1];
		}
			list[location] = insertItem;
			length++;
		
	}

}

template<class elemType>
void List<elemType>::insertEnd( int& insertItem) const
{
	if (length >= maxSize)
		cout << "full list " << endl;
	else
	{
		list[length] = insertItem;
		length++;
	}
}

template<class elemType>
void List<elemType>::removeAt(int location)
{
	if (location < 0 || location >= maxSize)
	{
		cout << "position is out of range " << endl;
	}
	else if (length >= maxSize)
	{
		cout << "list is full " << endl;
	}
	else
	{
		for (int i = location; i < length - 1; i++)
		{
			list[i] = list[i + 1];
		}
			length--;
		
	}
}

template<class elemType>
void List<elemType>::print()
{
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
}


template<class elemType>
void List<elemType>::retrieveAt(int location, int retItem) const
{
	if (location < 0 || location >= maxsize)
	{
		cout << " the position is out of range " << endl;
	}
	else
	retItem = list[location];
}

template<class elemType>
void List<elemType>::replaceAt(int location, int repItem) const
{
	if (location < 0 || location >= maxsize)
	{
		cout << " the position is out of range " << endl;
	}
	else
	list[location] = repItem;
}

template<class elemType>
void List<elemType>::clearlist()
{
	length = 0;
}

template<class elemType>
int List<elemType>::seqSearch(elemType item) const
{
	int loc;
	int found = false;
	for ( loc = 0; loc < length;loc++)
	{
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	}
	if (found)
		return loc;
	else
		return -1;
}

template<class elemType>
void List<elemType>::insert(elemType insertItem)
{
	int loc;
	if (length == 0)
		list[length++] = insertItem;
	else
		if (length == maxSize)
			cout << "list is full " << endl;
		else
		{
			loc = seqSearch(insertItem);
			if (loc == -1)
				list[length++] = insertItem;
			else
				cout << "the item is inserted before...no duplication allowed" << endl;
		}

}

template<class elemType>
void List<elemType>::remove(elemType insertItem)
{
	int loc;
	if (length == 0)
		cout << "cannot delete from an empty list " << endl;
	else
	{
		loc = seqSearch(insertItem);
		if (loc != 0)
		{
			removeAt(loc);
		}
		else
		{
			cout << "the item is not at the list" << endl;
		}


	}
}

template<class elemType>
List<elemType>::List(int size)
{
	if (size < 0)
	{
		cout << "size must be positive " << endl;
			maxSize = 100;
	}
	else
		maxSize = size;
	list = new elemType[length];
}

template<class elemType>
List<elemType>::List(const List& otherlist)
{
	maxSize = otherlist.maxSize;
	length = otherlist.length;
	list = new elemType[maxSize];
	for (int i = 0; i < length; i++)
	{
		list[i] = otherlist.list[i];
	}
}

template<class elemType>
List<elemType>::~List()
{
	delete[]list;
}

