#include "elementStack.h"
#pragma once
template <class T>
class stack
{
public:
	stack();
	~stack();
	elementStack<T>* root;
	bool isEmpty();
	void push(T element);
	T pop();
	T top();
};

template<class T>
inline stack<T>::stack()
{
	this->root = 0;
}

template<class T>
inline stack<T>::~stack()
{
}

template<class T>
inline bool stack<T>::isEmpty()
{
	return this->root == 0;
}

template<class T>
inline void stack<T>::push(T element)
{
	if (this->isEmpty())
	{
		this->root = new elementStack<T>(element);
	}
	else
	{
		this->root = new elementStack<T>(element, this->root);
	}
}

template<class T>
inline T stack<T>::pop()
{
	if (isEmpty())
	{
		return 0;
	}
	T data = this->root->Data;
	this->root = this->root->Next;
	return data;
}

template<class T>
inline T stack<T>::top()
{
	if (isEmpty())
	{
		return 0;
	}
	return this->root->Data;
}