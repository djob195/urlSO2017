#pragma once
template <class T>
class elementStack
{
public:
	elementStack(T data, elementStack<T>* next = 0);
	~elementStack();
	T Data;
	elementStack<T>* Next;
};

template<class T>
inline elementStack<T>::elementStack(T data, elementStack<T>* next)
{
	Data = data;
	Next = next;
}

template<class T>
inline elementStack<T>::~elementStack()
{
}
