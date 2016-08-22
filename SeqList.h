#pragma once
#include<stack>

struct Node
{
	int _data;
	Node* _next;
	Node(int data)
		:_data(data)
		, _next(NULL)
	{}
};

void Insert(Node** head, int data)
{
	Node* newnode = new Node(data);
	if (*head == NULL)
	{
		*head = newnode;
		return;
	}		

	Node* node = *head;
	while (node->_next)
	{
		node = node->_next;
	}
	node->_next = newnode;
}

void Delete(Node** head)
{
	Node* node = *head;
	while (node)
	{
		Node* del = node;
		node = node->_next;
		delete del;
		del = NULL;
	}
}
#if 0
//·ÇµÝ¹éÄæÐò´òÓ¡µ¥Á´±í
void TailToHeadPrint1(Node* head)
{
	if (head == NULL)
		return;

	Node* node = head;
	stack<Node*> stack;
	while (node)
	{
		stack.push(node);
		node = node->_next;
	}

	while (!stack.empty())
	{
		Node* newnode = stack.top();
		cout << newnode->_data << "->";
		stack.pop();
	}
	cout << "NULL" << endl;
}
//µÝ¹éÄæÐò´òÓ¡µ¥Á´±í
void TailToHeadPrint2(Node* head)
{
	if (head != NULL)
	{
		if (head->_next)
		{
			TailToHeadPrint2(head->_next);
		}
		cout << head->_data << "->";
	}	
}

//O(1)É¾³ýÒ»¸ö½Úµã
void DeleteNode(Node** pHead,Node* DelNode)
{
	if (pHead && DelNode)
		return;

	if (DelNode->_next)
	{
		Node* next = DelNode->_next;
		DelNode->_next = next->_next;
		DelNode->_data = next->_data;

		delete next;
		next = NULL;
	}
	else if (*pHead == DelNode)
	{
		delete DelNode;

		DelNode = *pHead = NULL;
	}
	else
	{
		Node* node = *pHead;
		while (node->_next != DelNode)
		{
			node = node->_next;
		}

		node->_next = NULL;
		delete DelNode;
		DelNode = NULL;
	}
}
#endif

void SeqListTest()
{
	Node* node = NULL;

	Insert(&node, 1);
	Insert(&node, 2);
	Insert(&node, 3);
	Insert(&node, 4);
	Insert(&node, 5);

#if 0
	TailToHeadPrint1(node);
	TailToHeadPrint2(node);
#endif

	Delete(&node);
}