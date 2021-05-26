#pragma once
#include<iostream>

template<class elemType>
class List
{
protected:
	int* list;
	int length;
	int maxSize;
public:
	bool isEmpty()const;
	bool isFull()const;
	int listSize()const;
	int maxsize()const;
	void print();
	bool isItemEqual(int location, const elemType& item)const;
	void insertAt(int location,  elemType insertItem);
	void insertEnd( int& insertItem)const;
	void removeAt(int location);
	void retrieveAt(int location, int retItem)const;
	void replaceAt(int location, int repItem)const;
	void clearlist();
	int seqSearch(elemType item)const;
	void insert(elemType insertItem);
	void remove(elemType insertItem);
	List(int size );
	List(const List& otherlist);
	~List();




};


