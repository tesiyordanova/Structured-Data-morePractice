#include "LList.h"
#include <iostream>
#include <exception>

template <typename T>
LList<T>::LList() {
	first = nullptr;
}

template <typename T>
void LList<T>::push(const T& x) {
	first = new LList<T>::Box(x, first);
	/*
	LList<T>::Box* newBox = new LList<T>::Box;
	newBox->data=x;
	newBox->next=first;
	first=newBox;
	*/
}

template <typename T>
void LList<T>::print()const {
	for (LList<T>::Box *crr=first; crr!=nullptr; crr=crr->next)
	{
		std::cout << crr->data << std::endl;
	}
	/*
	LList<T>::Box *crr = first;
	while(crr!=nullptr)
	{
		std::cout<<crr->data<<std::endl;
		crr=crr->next;
	}
	*/
}

template <typename T>
size_t LList<T>::size()const {
	LList<T>::Box* crr = first;
	size_t count = 0;
	while (crr!=nullptr)
	{
		++count;
		crr = crr->next;
	}
	return count;
}

template <typename T>
T& LList<T>::operator[](size_t i) {
	LList<T>::Box* crr = first;
	for (size_t count = 0; count < i; count++)
	{
		if (crr==nullptr)
		{
			throw std::out_of_range("Index out of bounds");
		}
		crr = crr->next;
	}
	return crr->data;
}

template <typename T>
T LList<T>::operator[](size_t i) const {
	LList<T>::Box* crr = first;
	for (size_t count = 0; count < i; ++count)
	{
		if (crr == nullptr)
		{
			throw std::out_of_range("Index out of bounds");
		}
		crr = crr->next;
	}
	return crr->data;
}

template <typename T>
void LList<T>::clear() {
	LList<T>::Box* save = first;
	while (first!=nullptr)
	{
		save = first->next;
		delete first;
		first = save;
	}
}

template <typename T>
LList<T>::~LList()
{

}

template <typename T>
LList<T>& LList<T>::operator=(const LList<T>& other) {
	if (this!=&other)
	{
		clear();
		first = copy2(other.first);
	}

	return this*;
}

template <typename T>
void LList<T>::copy(LList<T>::Box* other_first) {
	if (other_first == nullptr) return;

	LList<T>::Box* lastCreated = nullptr;
	while (other_first!=nullptr)
	{
		LList<T>::Box* newBox = new LList<T>::Box(other_first->data, nullptr);
		if (lastCreated!=nullptr)
		{
			lastCreated->next = newBox;
		}
		else
		{
			first = newBox;
		}
		lastCreated = newBox;
		other_first = other_first->next;
	}
}

template <typename T>
typename LList<T>::Box* LList<T>::copy2(LList<T>::Box* other) {
	if (other == nullptr) return nullptr;
	return new LList<t>::Box{ other->data, copy2(other->next) };
}