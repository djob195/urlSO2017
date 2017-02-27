#include "consts.h"
#pragma once
template <class T>
class node
{
public:
	node(T element, int _priority);
	~node();
	int priority;
	T data;
	node<T>* leftChild;
	node<T>* rightChild;
	void cmpHeap(T& element, int& _priority, order ord);
	node<T>* foundChildren(bool isLeft, T& element, int& _priority, order ord);
	void restructure(order ord);
private:
	node<T>* changeRight(node<T>*sRightChild, order ord, bool &isChange);
	node<T>* changeLeft(node<T>*sLeftChild, order ord, bool &isChange);
	void changeValues(node<T>* sor);
	void changeValues(T& element, int& _priority);
};

template<class T>
node<T>::node(T element, int _priority)
{
	priority = _priority;
	data = element;
	leftChild = 0;
	rightChild = 0;
}

template<class T>
node<T>::~node(){}

template<class T>
void node<T>::cmpHeap(T &element, int &_priority, order ord)
{
	if (ord == order::asc)
	{
		if (_priority>this->priority)
		{
			this->changeValues(element, _priority);
		}
	}
	else
	{
		if (_priority<this->priority)
		{
			this->changeValues(element, _priority);
		}
	}
}

template<class T>
node<T>* node<T>::foundChildren(bool isLeft, T& element, int& _priority, order ord)
{
	cmpHeap(element, _priority, ord);
	if (isLeft)
	{
		return this->leftChild;
	}
	else
	{
		return this->rightChild;
	}
}

template<class T>
void node<T>::changeValues(T &element, int & _priority)
{
	int auxPriority = this->priority;
	this->priority = _priority;
	_priority = auxPriority;
	T auxData = this->data;
	this->data = element;
	element = auxData;
}

template <class T>
void node<T>::restructure(order ord)
{
	bool isChange = true;
	node<T>* nowNode = this;
	while (isChange)
	{
		if ((nowNode->leftChild != 0) && (nowNode->rightChild != 0))
		{
			if (ord == order::asc)
			{
				if (nowNode->leftChild->priority > nowNode->rightChild->priority)
				{
					nowNode = nowNode->changeLeft(nowNode->leftChild, ord, isChange);
				}
				else
				{
					nowNode = nowNode->changeRight(nowNode->rightChild, ord, isChange);
				}
			}
			else
			{
				if (nowNode->leftChild->priority < nowNode->rightChild->priority)
				{
					nowNode = nowNode->changeLeft(nowNode->leftChild, ord, isChange);
				}
				else
				{
					nowNode = nowNode->changeRight(nowNode->rightChild, ord, isChange);
				}
			}
		}
		else if (nowNode->leftChild != 0)
		{
			nowNode = nowNode->changeLeft(nowNode->leftChild, ord, isChange);
		}
		else if (nowNode->rightChild != 0)
		{
			nowNode = nowNode->changeRight(nowNode->rightChild, ord, isChange);
		}
		else
		{
			isChange = false;
		}
	}
}

template<class T>
inline node<T>* node<T>::changeRight(node<T>* sRightChild, order ord, bool & isChange)
{
	if (ord == order::asc)
	{
		if (sRightChild->priority > this->priority)
		{
			isChange = true;
			changeValues(sRightChild);
		}
		else
		{
			isChange = false;
		}
	}
	else
	{
		if (sRightChild->priority < this->priority)
		{
			isChange = true;
			changeValues(sRightChild);
		}
		else
		{
			isChange = false;
		}
	}
	return sRightChild;
}

template<class T>
inline node<T>* node<T>::changeLeft(node<T>* sLeftChild, order ord, bool & isChange)
{
	if (ord == order::asc)
	{
		if (sLeftChild->priority > this->priority)
		{
			isChange = true;
			changeValues(sLeftChild);
		}
		else
		{
			isChange = false;
		}
	}
	else
	{
		if (sLeftChild->priority < this->priority)
		{
			isChange = true;
			changeValues(sLeftChild);
		}
		else
		{
			isChange = false;
		}
	}
	return sLeftChild;
}

template<class T>
void node<T>::changeValues(node<T>* sor)
{
	int auxPriority = this->priority;
	this->priority = sor->priority;
	sor->priority = auxPriority;
	T auxData = this->data;
	this->data = sor->data;
	sor->data = auxData;
}