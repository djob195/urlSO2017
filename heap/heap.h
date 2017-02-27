#pragma once
#include "consts.h"
#include "node.h"
template <class T>
class heap
{
public:
	heap(order ord);
	~heap();
	order Order;
	bool isEmpty();
	void add(T element, int priority = 0);
	T peek();
	T pool();
	int getPriority();
private:
	long Length;
	node<T>* root;
};

template<class T>
heap<T>::heap(order ord)
{
	this->Order = ord;
	this->Length = 0;
}

template<class T>
heap<T>::~heap()
{
}

template <class T>
bool heap<T>::isEmpty()
{
	return this->Length == 0;
}

template<class T>
void heap<T>::add(T element, int priority)
{
	if (this->isEmpty())
	{
		this->root = new node<T>(element, priority);
	}
	else
	{
		long way = Length+1;
		node<T>* father = root;
		while (way>3)
		{
			if (way % 2 == 0)
			{
				father = father->foundChildren(true, element, priority, this->Order);
			}
			else
			{
				father = father->foundChildren(false, element, priority, this->Order);
			}
			way /= 2;
		}
		if (way % 2 == 0)
		{
			father->leftChild = new node<T>(element, priority);
		}
		else
		{
			father->rightChild = new node<T>(element, priority);
		}
	}
	Length++;
}

template<class T>
T heap<T>::peek()
{
	return this->root->data;
}

template<class T>
T heap<T>::pool()
{
	if (this->isEmpty())
	{
		return 0;
	}
	else if (this->Length == 1)
	{
		T data = this->root->data;
		this->Length--;
		return data;
	}
	T data = this->root->data;
	long way = Length;
	node<T>* father = this->root;
	bool isLeft = true;
	while (way > 3)
	{
		if (way % 2 == 0)
		{
			father = father->leftChild;
		}
		else
		{
			father = father->rightChild;
		}
		way /= 2;
	}
	if (way%2==0)
	{
		this->root->priority = father->leftChild->priority;
		this->root->data = father->leftChild->data;
		father->leftChild = 0;
	}
	else
	{
		this->root->priority = father->rightChild->priority;
		this->root->data = father->rightChild->data;
		father->rightChild = 0;
	}
	this->root->restructure(this->Order);
	this->Length--;
	return data;
}

template<class T>
inline int heap<T>::getPriority()
{
	if (this->isEmpty())
	{
		return 0;
	}
	return this->root->priority;
}