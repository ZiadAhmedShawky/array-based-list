#include<iostream>
#include"List.h"
#include"List.cpp"

using namespace std;
int main()
{
	List<int>intList(100);
	int item;
	cout << "enter 5 integers : ";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " item : ";
		cin >> item;
		intList.insertAt(i, item);
	}
	cout << endl;
	cout << "the list you entered : ";
	intList.print();

}