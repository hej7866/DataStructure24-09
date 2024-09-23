#pragma once
#include <iostream>
/*
*  자료구조 컨테이너 : Array,  Vector, Linked List
*
*  기존 컨테이너를 변형해서 (자료를 삽입, 삭제) 기능을 제한해서 프로그래밍 최적화를 구현한 자료구조다.
*/

// Stack 자료구조
// 번역 : 무엇인가를 쌓다.
// 세탁용 바구니에 옷을 쌓아서 한번에 세탁기에 넣을려고 한다.
// 옷은 가장 마지막에 쌓인 녀석부터 세탁기에 들어간다.
// 가장 첫번째로 들어온 녀석이(First In) 가장 마지막에 나간다.(Last Out) -> FILO
// 가장 마지막에 들어온 녀석이(Last In) 가장 먼저 나간다.(First Out) -> LIFO

// Vector, Linked list, Array 자료구조를 잘 사용하고 있었는데, 
// Stack, Queue, Priority Queue 왜 사용해야 할까요?

// 스택의 장점
// 1. 클래스 구현하기가 쉽다.
// 2. LIFO 방식으로, 순서대로 저장합니다.

// 1. 실행 취소(Undo) : Ctrl + z  스택으로 구현을 하지 않는다면.. int count..
// 2. 후위 표기법     : 구현하기가 편리하다. 컴퓨터가 읽기에 쉽게 표현된 연산 표기법입니다.
// ex) 1+1+2    =>     112++ 

// 배열 기반 Stack
template <typename T>
class MyArrayStack
{
	// 필드
private:
	T* stackArray;  // 스택 데이터 저장하기위한 배열
	int capacity;    // 스택의 최대 크기
	int top;		 // 현재 가장 상단에 있는 인덱스
	// 기능
public:
	// 생성자
	// capacity (size :int) 최대 크기를 할당하는 생성자를 구현해보세요. 

	// top이 가리키는 인덱스를 "-1" : 데이터가 생성되지 않음을 표현하기 위한 수 -1
	// top이 가리키는 인덱스를 "0"  : 사람이 세는 수의 시작으로 표현할 수 있다.
	// stackArray를 capacity로 동적 할당해준다.
	MyArrayStack(int size)
	{
		stackArray = new T[size];
		capacity = size;
		top = -1;
	}

	~MyArrayStack()
	{
		// stackArray null이 아닐때만 삭제하세요.
		if (stackArray != nullptr)
			delete[] stackArray;
	}

	// Resize(int _capacity)

	// T타입의 newArray 동적할당 합니다.
	// stackArray 인덱스 0 부터 top까지의 데이터를 newArray 저장한다.
	// 기존 stackArray delete[] 해줍니다.
	// stackArray newArray의 데이터로 새로 할당한다.
	// this.capacity = _capacity;

	void Resize(int newSize)
	{
		T* newArray = new T[newSize];

		for (int i = 0; i < top; i++)
		{
			newArray[i] = stackArray[i];
		}
		delete[] stackArray;
		stackArray = newArray;
		capacity = newSize;
	}

	// IsFull()
	// top == capacity - 1	    : 

	bool IsFull() { return  top == capacity - 1 ? true : false; }

	// IsEmpty()
	// top이 가리키고 있는 녀석이 "-1" true, false
	bool IsEmpty() { return top <= -1 ? true : false; }

	// push()

	// 만약에 Full이라면 Resize( capacity *2 );
	// stackArray 데이터 추가  [top] <-- 데이터 추가
	// top 을 1 증가 시켜준다.

	void Push(T data)
	{
		if (IsFull())
		{
			Resize(2 * capacity);
		}

		top++;
		stackArray[top] = data;
	}

	// pop()

	// isEmpty() -> 현재 스택에 데이터가 비었습니다 출력
	// return
	// top 1 감소시킨다.

	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "현재 스택에 데이터가 없습니다. Stack is UnderFlow, 데이터 출력을 할 수 없습니다." << std::endl;
			return;
		}
		std::cout << Top() << std::endl;
		--top;
	}

	T Top()	const
	{
		return 	stackArray[top];
	}

	void Clear()
	{
		capacity = 10;
		top = -1;
	}

};


// 연결형 리스트 기반 Stack

// StackNode  next

// StackNode* pHead

// push     

// pop

void StackExample()
{
	MyArrayStack<int> mStack(10);
	mStack.Push(5);
	mStack.Push(4);
	mStack.Push(3);
	mStack.Push(2);
	mStack.Push(1);

	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
}