#pragma once
struct Node
	{
		int data;
		Node* next;
	};
class list
{
public:
	
	list();
	
	void addNode(int d);
	void printList();
	void delOdd();
	void del(Node* node);
	Node* returnNode(int number);
private:
	Node* head;
};

