// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
struct Array {
	T* arr;
	size_t size;
};

template <typename T>
Array<T> input() {
	size_t n;
	std::cout << "Enter size of array: " << std::endl;
	std::cin >> n;

	Array<T> crr;
	crr.arr = new T[n];
	crr.size = n;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> crr.arr[i];
	}
	return crr;
}

//4.01
template <typename T, typename N>
void changeElements(Array<T> &first,Array<N> &second) {
	if (first.size!=second.size)
	{
		std::cout << "Size must be equal!";
		return;
	}
	Array<T> temp;
	temp.arr= new T[first.size];
	for (size_t i = 0; i < first.size; i++)
	{
		temp.arr[i] = first.arr[i];
		first.arr[i] = second.arr[i];
		second.arr[i] = temp.arr[i];
	}

}



template <typename T>
void print(Array<T> crr) {
	for (size_t i = 0; i < crr.size; i++)
	{
		std::cout << crr.arr[i];
	}
	std::cout << std::endl;
}

//4.02
template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

//4.03
bool duplicates(long* pointers[]) {
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = i+1; j < 3; j++)
		{
			if (*pointers[i]==*pointers[j]) return true;
			
		}
	}
	return false;
}

//4.07
void reverse(size_t n) {
	if (n==0) return;

	int number;
	std::cin >> number;
	reverse(n - 1);
	std::cout << number << " ";
	
}

//4.08
void getMax(long* pmax, size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		long number;
		std::cin >> number;
		if (*pmax < number)
		{
			*pmax = number;
		}
	}
}

void getMaxRec(long* pmax, size_t n) {
	if (n == 0) return;
	long number;
	std::cin >> number;
	if (*pmax<=number)
	{
		*pmax = number;
		getMaxRec(pmax, n - 1);
	}
	else
	{
		getMaxRec(pmax, n - 1);
	}
}
int main()
{
	/*
	Array<int> f;
	Array<int> s;
	f = input<int>();
	s = input<int>();
	changeElements(f, s);
	print(f);
	print(s);

	int a = 1, b = 2;
	swap(a, b);
	std::cout << a << " " << b << std::endl;

	long one = 1, two = 2, three = 3;
	long* ptrOne = &one, * ptrTwo = &two, * ptrThree = &three;
	long* pointers[] = {ptrOne, ptrTwo, ptrThree};

	std::cout << std::boolalpha << duplicates(pointers); 

	int n;
	std::cin >> n;
	reverse(n); */

	long max = -1;
	getMaxRec(&max, 3);
	std::cout << max;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
