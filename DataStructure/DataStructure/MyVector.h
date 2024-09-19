#pragma once

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class MyVector
{
private:
	T* vec; // 원소를 담을 시작 주소
	int size; // vec에 현재 담겨 있는 크기
	int capacity; // 최대로 담을 수 있는 크기
public:
	MyVector(T temp = 10) // 클래스를 생성할 때 int 값을 인자로 넘겨주지 않으면 10 크기가 자동으로 할당된다.
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;
	}

	~MyVector()
	{
		delete[] vec;
	}

	// 연산자 오버로딩 [], ==, !=

	T& operator[](int index)
	{
		return vec[index];
	}

	bool operator==(MyVector<T>& other)
	{
		if (size != other.size) { return false; } // 현재 자료구조의 원소 개수와 other의 원소 갯수를 비교하여 크기가 다르면 다르다.
		
		if (capacity != other.capacity) { return false; }

		for (int i = 0; i < size; i++)
		{
			if (vec[i] != other[i]) { return false; }
		}

		return true;
	}

	bool operator!=(MyVector<T>& other)
	{
		return !(*this == other);
	}

	// 원소 추가 삭제
	// 새롭게 배열을 할당하는 작업이 적을 수록 시간이 적게 걸린다.

	void ResizeVector(int capacity)
	{
		// 1. 동적 할당 : new 키워드 capacity  크기 만큼 T타입의 데이터 배열을 만든다.
		T* newVec = new T[capacity];

		// 2. 새로 만든 배열에 기존 배열을 대입한다.

		for (int i = 0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		if (capacity <= size) 
		{ 
			capacity *= 2;				// 최대 수용량을 2배로 늘린다.
			ResizeVector(capacity);		// 기존 배열 -> 새로 만든 배열 옮기는 작업
		}

		vec[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;
	}

	void Print()
	{
		cout << "-----------------------------------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << "번째 값 출력 : " << vec[i] << endl;
		}
		cout << "-----------------------------------------------------" << endl;
	}

	T* GetVector() { return vec; } // vec에 직접 접근할 수 있는 GetVector 함수

	int GetSize() { return size; } // 현재 vec의 원소 갯수를 리턴하는 함수
};
