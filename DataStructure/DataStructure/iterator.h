#pragma once

#include <vector>
#include <iostream>
#include <string>
// 포인터의 사용법

// int abc = 10;
// int* intptr = &abc;
// 포인터 연산자 *, ++, ++ ,==, !=, 

// class Item -> Inventory Items 자료구조 ->  std::vector<int><float>. Item.Print(); 포인터

// vector<Item> inventory




template <typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

	class Iterator
	{
	private:
		T* ptr;
	public:
		// 생성자
		Iterator() : ptr(nullptr) {}
		Iterator(T* ptr) : ptr(ptr) {}

		T& operator*()
		{
			return *ptr;
		}

		// 전위 연산자 ++it
		Iterator& operator++()
		{
			ptr++;
			return *this;
		}

		// 후위 연산자 it++
		Iterator& operator++(int)
		{
			Iterator temp = *this;
			ptr++;
			return temp;
		}

		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr;
		}

		Iterator operator+(const int count)
		{
			Iterator temp = *this;
			temp.ptr += count;
			return temp;
		}

	};

	// iterator 허용된 함수
	// iterator Iterator<int>
public:
	using iterator = Iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + size; }


	// Containter 자료구조의 기능 구현
public:
	Container(int _size = 3)
	{
		arr = new T[_size];
		size = 0;
		capacity = _size;
	}

	void push_back(T data)
	{
		arr[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;	 // 1. size > 0 비교 true -> (size - 1 )실행, false -> 0 결과를 size 대입
	}
};


class Item
{
private:
	float time;
	int idx;
public:
	Item() {}
	Item(float Time, int Idx) : time(Time), idx(Idx) {}

	void Print()
	{
		cout << "시간 : " << time << endl;
		cout << "NO." << idx << endl;
	}
};

void IteratorExample()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);


	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	auto it = vec.begin();

	cout << "iterator로 출력한 반복 결과문" << endl;

	for (it; it != vec.end(); it++)
	{
		cout << *it << endl;
	}

	// for반복문 : range based for loop

	cout << "범위 기반 루프 결과문" << endl;

	for (int elem : vec)   // iterator vec.begin() ~ vec.end()   it++
	{
		cout << elem << endl;
	}


	Container<int> myCon;
	myCon.push_back(10);
	myCon.push_back(20);
	myCon.push_back(30);

	auto myIt = myCon.begin();

	for (myIt; myIt != myCon.end(); myIt++)
	{
		cout << "이터레이터 출력한 결과 :" << *myIt << endl;
	}

	// range base for loop 
	// 범위 기반 for 반복문
	for (int& elem : myCon)
	{
		elem += 100;
		cout << "범위 기반 결과 출력 :" << elem << endl;
	}

	myIt = myCon.begin();

	for (myIt; myIt != myCon.end(); myIt++)
	{
		cout << "이터레이터 출력한 결과 :" << *myIt << endl;
	}

	// auto	: 자동으로 뒤에 있는 변수의 타입을 지정해준다.

	auto a = 10;
	auto b = 0.1f;
	auto c = 'c';
	auto d = "hello";

	cout << a << "," << b << "," << c << "," << d << endl;

	cout << "Item Class 사용 예시" << endl;

	Container<Item> inventory(10);

	Item item1(12.345f, 1);
	Item item2(32.167f, 2);

	inventory.push_back(item1);
	inventory.push_back(item2);

	auto itemIt = inventory.begin();

	// iterator for 반복문
	cout << "Item Iterator를 이용한 반복문" << endl;
	for (itemIt; itemIt != inventory.end(); itemIt++)
	{
		(*itemIt).Print();
	}
}