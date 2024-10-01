#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>  // swap( a1, a2)


using namespace std;

// 자료구조를 이용해서 데이터를 잘 저장하는 방법을 배웠다.
// 자료구조들 안에 있는 데이터를 가장 빠르고, 효율적으로 사용하는 방법 배워야합니다. => 알고리즘

// Heap
// 특징 : 완전 이진 트리의 형태를 갖고 있다.
// 종류 : 
// Max Heap : 우선순위가 높은 데이터(큰 수) 가장 큰 수가 위로 올라가는 형태
// Min Heap : 가장 작은 수가 Root 노드에 존재하는 Heap구조

// Heapify의 규칙
// root의 노드를 pop합니다.
// 가장 마지막에 들어온 노드를 root에 넣어줍니다.
// root의 자식들과 부모랑 비교를 해서 큰 수를 부모와 바꿉니다.  
// 최초에 root들어간 녀석이 더 이상 변경되지 않을 때 까지 반복합니다.

// 부모의 노드 구하는 공식 : (idx - 1) / 2
// 자식의 노드 left   : idx * 2 + 1
// 자식의 노드 right	 : idx * 2 + 2

// 다음의 내용을 기억해서 아래 코드를 구현해보세요.
//  while 반복문
//   부모 노드 < idx 노드(새로 들어온 노드) -> 새로 들어온 노드 swap  = false
// 
class PriorityQueue
{
private:
	vector<int> heap;

	void heapifyUp(int idx)	  // 마지막에 들어온 indx
	{

		while (heap[idx] > heap[(idx - 1) / 2]) // 새로 들어온 노드가 부모 노드보다 작다면 그만 두는 것
		{
			swap(heap[idx], heap[(idx - 1) / 2]);
			idx = (idx - 1) / 2;
		}
		//int a1 = 10;
		//int a2 = 20;
		//std::swap(a1, a2);
	}

	// 마지막 원소 : size - 1  -> root
	// left, right
	// int largest
	// while, 비교 

	void heapifyDown(int idx)  // 0
	{
		int size = heap.size();

		while (true)
		{
			int largest = idx;
			int left = idx * 2 + 1;
			int right = idx * 2 + 2;


			if (left < size && heap[largest] < heap[left])
			{
				largest = left;
			}

			if (right < size && heap[largest] < heap[right])
			{
				largest = right;
			}

			if (largest == idx)
			{
				break;
			}

			swap(heap[largest], heap[idx]);
			idx = largest;
		}
	}

public:
	void push(int _data)
	{
		heap.push_back(_data);
		heapifyUp(heap.size() - 1);

	}
	int pop()
	{
		// 예외 처리
		if (heap.empty())
		{
			throw out_of_range("힙이 비어있습니다.");
		}

		int root = heap[0];			// 1. 가장 큰 수를 root에 저장한다.
		heap[0] = heap.back();		// 3.비어있는 root. 가장 마지막 원소를 대입한다.
		heap.pop_back();			// 4. 가장 마지막 데이터의 공간이 비었다
		heapifyDown(0);				// 5. 힙의 특성에 맞게 재정렬
		return root;				// 2. 리턴 시킨다. (최대값을 출력했다.)
	}

	int top() const
	{
		if (heap.empty())
		{
			throw out_of_range("힙이 비어있습니다.");
		}
		return heap[0];
	}

	bool empty() const { return heap.empty(); }

	int size() const { return heap.size(); }
};

void PriorityQueueExample()
{
	PriorityQueue p_q;
	p_q.push(5);
	p_q.push(3);
	p_q.push(1);
	p_q.push(7);
	p_q.push(9);

	while (!p_q.empty())
	{
		cout << "우선 순위 큐 결과 : " << p_q.pop() << endl;
	}
}