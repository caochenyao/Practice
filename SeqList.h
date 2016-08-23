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
//非递归逆序打印单链表
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
//递归逆序打印单链表
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

//O(1)删除一个节点
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

//找到倒数第k个节点
Node* FindKthToTail(Node* pHead,int k)
{
	if (pHead == NULL || k <= 0)
		return NULL;

	Node* firstNode = pHead;
	Node* secondNode = NULL;
	for (int i = 0; i < k - 1; ++i)
	{
		if (firstNode->_next == NULL)
			return NULL;
		firstNode = firstNode->_next;
	}

	secondNode = pHead;
	while (firstNode->_next)
	{
		firstNode = firstNode->_next;
		secondNode = secondNode->_next;
	}
	return secondNode;
}

//链表的逆置
Node* ReverseList(Node* pHead)
{
	Node* prehead = NULL;
	Node* node = pHead;
	Node* prev = NULL;

	while (node)
	{
		Node* next = node->_next;
		if (next == NULL)
			prehead = node;

		node->_next = prev;
		prev = node;
		node = next;
	}
	return prehead;
}

//合并两个排序链表
Node* Merge(Node* pHead1,Node* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	Node* pnewNode = NULL;
	if (pHead1->_data < pHead2->_data)
	{
		pnewNode = pHead1;
		pnewNode->_next = Merge(pHead1->_next,pHead2);
	}
	if (pHead2->_data < pHead1->_data)
	{
		pnewNode = pHead2;
		pnewNode->_next = Merge(pHead2->_next, pHead1);
	}

	return pnewNode;
}
#endif


void SeqListTest()
{
	Node* node = NULL;
	Node* node1 = NULL;

	Insert(&node, 1);
	Insert(&node, 3);
	Insert(&node, 5);
	Insert(&node, 7);
	Insert(&node, 9);
#if 0
	Insert(&node1, 2);
	Insert(&node1, 4);
	Insert(&node1, 6);
	Insert(&node1, 8);
	Insert(&node1, 10);


	TailToHeadPrint1(node);
	TailToHeadPrint2(node);

	Node* pnode = FindKthToTail(node,5);

	Node* renode = ReverseList(node);

	Node* mergenode = Merge(node,node1);
#endif


	Delete(&node);
}