#pragma once
#include <iostream>
#include <queue>

using namespace std;
/*
*  자료구조 : 컨테이너를 변형해서 순서를 정해두고 사용하는 어댑터 자료구조입니다.
*  자료구조에 데이터를 저장할 때 먼저 들어간 자료가 먼저 나오늘 형태의 자료구조.
* 
*  큐 자료구조 구현
* - 데이터가 출력되는 인덱스를 front이름으로 표현
* - 데이터가 저장되는 인덱스를 rear이름으로 표현
* - 선형 큐 front rear 초기값으로 되돌아 갈 수 없다.
* 
*/

// 구현해야할 함수
// 입력 및 삭제 : Push(), Pop() 
// 필드 값 표현 : Empty(), Size(), Front(), Back() 

template <typename T>
class ArrayBasedQueue
{
private:
	T* queue;
	int front;
	int rear;
	int iCount;
public:
	ArrayBasedQueue(int size = 10)
	{
		queue = new T[size];
		front = 0; // 출력 위치를 가리키는 인덱스
		rear = 0; // 데이터 입력 위치를 가리키는 인덱스
		iCount = 0; // 현재 자료구조의 원소의 개수
	}
	~ArrayBasedQueue()
	{
		delete[] queue;
	}

	
	int Size()
	{
		return iCount;
	}

	int Front()
	{
		return queue[front];
	}

	int Back()
	{
		return queue[rear - 1];
	}

	bool Empty()
	{
		return iCount == 0 ? true : false;
	}

	void Push(T data)
	{
		queue[rear] = data; // queue 배열 data 삽입
		rear++;				// rear 변경
		iCount++;			// 개수 증가 
	}

	void Pop()
	{
		if (iCount != 0) // queue 비어있지 않을때
		{
			front++;		// queue 배열의 front 변경
			iCount--;		// 개수 감소
		}
		else
		{
			cout << "큐가 비어있습니다." << endl;
		}
	}

	void Print()
	{
		cout << "Front Index : " << front << endl;
		cout << "Rear Index : " << rear << endl;
		cout << "Queue Index : " << iCount << endl;
	}
};


template <typename T>
class LinkedQueue
{
private:
	struct QueueNode
	{
		T data;
		QueueNode* pNext;

		QueueNode(T _data, QueueNode* pNode)
		{
			data = _data;
			pNext = pNode;
		}

	};

	QueueNode* front;
	QueueNode* rear;
	int iCount;

public:
	LinkedQueue()
	{
		front = nullptr;
		rear = nullptr;
		iCount = 0;
	}
	~LinkedQueue() {}

	T Front() { return front->data; }

	T Back() { return rear->data; }

	int Size()
	{
		return iCount;
	}

	bool Empty()
	{
		return iCount == 0 ? true : false;
	}

	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data, nullptr);
		// QueueNode* newNode = new QueueNode;
		// newNode->data = data;
		// newNode->pNex = nullptr;
		if (Empty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->pNext = newNode;
			rear = newNode;
		}
		iCount++;
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "큐가 비었습니다." << endl;
			return;
		}

		QueueNode* oldNode = front;
		front = front->pNext;
		delete oldNode;
		iCount--;
	}
};

void IQueueExample()
{
	queue<int> m_q;

	m_q.push(1);
	m_q.push(2);
	m_q.push(3);
	m_q.push(4);
	m_q.push(5);

	cout << m_q.front() << endl;
	m_q.pop();
	cout << m_q.front() << endl;
	m_q.pop();
	cout << m_q.front() << endl;
	m_q.pop();
	cout << m_q.front() << endl;
	m_q.pop();
	cout << m_q.front() << endl;
	m_q.pop();

	// 배열 기반 큐 선언
	ArrayBasedQueue<int> myQueue;

	myQueue.Push(1);
	myQueue.Push(2);
	myQueue.Push(3);
	myQueue.Push(4);
	myQueue.Push(5);

	cout << myQueue.Front() << endl;
	myQueue.Pop();
	cout << myQueue.Front() << endl;
	myQueue.Pop();
	cout << myQueue.Front() << endl;
	myQueue.Pop();
	cout << myQueue.Front() << endl;
	myQueue.Pop();
	cout << myQueue.Front() << endl;
	myQueue.Pop();

	myQueue.Print();

	// linkedQueue;

	LinkedQueue<int> linkedQueue;

	linkedQueue.Push(1);
	linkedQueue.Push(2);
	linkedQueue.Push(3);
	linkedQueue.Push(4);
	linkedQueue.Push(5);

	cout << "Rear 포인터가 가리키고 있는 값 : " << linkedQueue.Back() << endl;
	cout << "Front 포인터가 가리키고 있는 값 : " << linkedQueue.Front() << endl;
	cout << "Queue의 갯 수 : " << linkedQueue.Size() << endl;

	cout << linkedQueue.Front() << endl;
	linkedQueue.Pop();
	cout << linkedQueue.Front() << endl;
	linkedQueue.Pop();
	cout << linkedQueue.Front() << endl;
	linkedQueue.Pop();
	cout << linkedQueue.Front() << endl;
	linkedQueue.Pop();
	cout << linkedQueue.Front() << endl;
	linkedQueue.Pop();
}

/// <summary>
/// 원형 큐는 선형 큐의 단점을 개선하기 위해 등장한 자료구조입니다.
/// 선형 큐는 Front, Rear를 재활용하기 힘들다.
/// Pop(Dequeue)  : Front = (Front + 1) % 최대 값
/// Push(Enqueue) : Rear  = (Rear  + 1)	% 최대 값
/// 
/// 단점 : Front, rear 무한 루프에 걸릴 수 있다, 시작과 끝을 파악하기 어렵다.
/// 
/// 언제 사용하면 좋을까? 큐를 반복해서 사용해야 하는데, 그 갯수가 많지 않을 때 사용하면 좋다.
/// </summary>


//  1. 선형 큐의 단점 :  Front, Rear가 계속 증가하고, 재활용이 힘들다. 
//  이를 개선하기 위한 원형 큐를 만들어 볼 수 있다.

//  2. 큐의 사용 예시 : 입력받은 순서대로 데이터를 저장할 수 있다. (커맨드를 저장 == 실행)


//  플레이어의 커맨드를 출력하는 기능을 구현해보세요.
// 
//  class의 상속 관계  command 상속해서 구현을 해볼겁니다.
//  == draw.io 다이어그램 ==
// 
//  std::in << input;
//  std::<queue> inputs 저장 
//  std::<queue>temp
//  temp.front(). pop()   
//  [            ]