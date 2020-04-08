// Lab4_2 Вершинина.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "list.h"
using namespace std;
int main()
{
	list newList = list();
	newList.addNode(3);
	newList.addNode(4);
	newList.addNode(4);
	newList.addNode(3);
	newList.addNode(1);
	newList.addNode(1);
	newList.addNode(5);
	newList.printList();
	Node* node = newList.returnNode(3);
	cout<<endl<<"Node number 3= "<< node->data <<endl;
	newList.delOdd();
	cout << endl << "new" << endl;
	newList.printList();
	system("pause");
	return 0;
}

