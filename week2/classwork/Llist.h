#pragma once

template <typename T>
class LList {
public:
	LList() {};

	void push(const T&);
	void print() const;

	T& operator[] (size_t i);
	T operator[] (size_t i) const;

	LList<T>& operator= (const LList<T>&);

	size_t size() const;

	~LList();

	void clear();

private:
	struct Box {
		T data;
		Box* next;
	};

	Box* first;

	void copy(Box*);

	Box* copy2(Box*);
};