#pragma once

// 기본적인 틀은 단일 열결 리스트와 일치합니다.
// 원형 연결 리스트는 꼬리의 넥스트가 머리를 가르키면된다.

// 이중 연결 리스트
// 노드가 앞과 뒤 연결
// 이중 원형 연결 리스트

// newNode Tail->newt = head;

// 원형 리스트의 장점?
// Head를 따로 지정하지 않아도 된다. -> 모든 노드가 시작점이 될 수 있다.

// 단일 연결 리스트의 시작점 => head : head->prev : nullptr; <- 자료구조에서 처음 입력하는 데이터

// 원형 연결 리스트의 시작점 => 0, 1, 2, 3, 4, 5
// 원형 연결 리스트의 마지막을 파악하는 함수 : 처음 시작점 head 자료구조를 생성할 때 지정을 해준다. 시작점과 똑같은 노드가 들어올때 : 한바퀴

struct  cNode
{
	int value;
	cNode* pNext;
};

class CircularLinkedList
{
private:
	cNode* pHead; // 시작점
	int iCount;

public:
	CircularLinkedList() {}
	~CircularLinkedList() {}

	bool IsEnd()
	{
		cNode* cur = pHead;
		int iCount = 0;
		while (true)
		{
			iCount++;
			cur = cur->pNext;

			if (cur == pHead)
			{
				return true;
			}
		}
		return iCount;
	}
};