#include <iostream>
#include "LinearStructures.h"

SingleConnectionList::SingleConnectionList(void)
{
	root = tail = nullptr;
}
SingleConnectionList::~SingleConnectionList(void)
{
	while (root != nullptr)
		this->RemoveRoot();
}
int SingleConnectionList::Count(void)
{
	Node* i = root;
	int count = 0;
	while (i != nullptr)
	{
		i = i->next;
		count++;
	}
	return count;
}
void SingleConnectionList::Add(int data)
{
	Node* node = new Node();
	node->data = data;
	node->next = nullptr;
	if (root == nullptr)
		root = node;
	else 
		tail->next = node;
	tail = node;
}
int SingleConnectionList::RemoveRoot(void)
{
	if (root == nullptr)
	{
		std::cout << "List is empty" << std::endl;
		return NULL;
	}
	Node* tmp = root->next; 
	int data = root->data;
	root->data = NULL;
	root->next = nullptr;
	if (root == tail)
		tail = nullptr;
	delete(root);
	root = tmp;
	return data;
}
void SingleConnectionList::Print(void)
{
	if (root == nullptr)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node* i = root;
	while (i != nullptr)
	{
		std::cout << i->data << ' ';
		i = i->next;
	}
	std::cout << std::endl << std::endl;
}
int SingleConnectionList::RemoveAt(int i)
{
	if (i >= this->Count() || i < 0)
	{
		std::cout << "Index out of range" << std::endl;
		return NULL;
	}
	Node* node = root, * tmp = nullptr;
	int data;
	while (i > 0)
	{
		if (i == 1)
			tmp = node;
		node = node->next;
		i--;
	}
	if (node == root)
		root = node->next;
	if (node == tail)
		tail = tmp;
	if (tmp != nullptr)
		tmp->next = node->next;
	data = node->data;
	node->data = NULL;
	node->next = nullptr;
	delete(node);
	return data;
}
void SingleConnectionList::ExchangeAt(int i)
{
	if (i + 1 >= this->Count() || i < 0)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	Node* node = root, * tmp = nullptr;
	while (i > 0)
	{
		if (i == 1)
			tmp = node;
		node = node->next;
		i--;
	}
	if (node == root)
		root = node->next;
	if (node->next == tail)
		tail = node;
	if (tmp != nullptr)
		tmp->next = node->next;
	tmp = node->next;
	node->next = tmp->next;
	tmp->next = node;
}