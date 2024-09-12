#include "DoubliyLinkedList.h"

void DoubliyLinkedList::PushFront(const string _data)
{
	StringNode* newNode = new StringNode; // 동적 할당 Node 구현. next, prev
	newNode->value = _data;           // 노드->value =  _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)         // head가 nullptr일 때
	{
		pHead = newNode;
		pTail = newNode;
	}

	// 그 이외의 경우 - 맨 앞에 헤드 노드를 배치하고, 기존 헤드를 새로운 헤드 노드로 변경한다.
	newNode->pPrev = nullptr;   // 새로운 노드의 prev 비어있어야한다.
	newNode->pNext = pHead;     // 새로운 노드의 next 기존의 head여야 한다.    
	pHead = newNode;           	// 새로운 머리를 새로운 노드로 변경해준다.

	iCount++;
}

void DoubliyLinkedList::PushBack(const string _data)
{
	StringNode* newNode = new StringNode; // 동적 할당 Node 구현. next, prev
	newNode->value = _data;           // 노드->value =  _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)         // head가 nullptr일 때
	{
		pHead = newNode;
		pTail = newNode;
	}

	// 그 이외의 경우 - 맨 앞에 헤드 노드를 배치하고, 기존 헤드를 새로운 헤드 노드로 변경한다.
	newNode->pPrev = pTail;           // 새로운 노드의 prev 기존의 tail
	newNode->pNext = nullptr;         // 새로운 노드의 next 비어있어야 한다.  
	pTail->pNext = newNode;           // 새로운 노드 이전 노드의 다음 노드가 newNode
	pTail = newNode;           	      // 새로운 꼬리를 새로운 노드로 변경해준다.

	iCount++;
}

void DoubliyLinkedList::Insert(int index, const string _data)
{
	// iCount  0보다 작으면 iCount

	if (index < 0 || index >= iCount)
	{
		cout << "인덱스 에러 발생!" << endl;
		return;
	}
	else if (index == 0) 	// index 0 (PushFront 함수 실행)
	{
		PushFront(_data);
	}
	else if (index == iCount) 	// index iCount - 1 (PushBack 함수 실행)
	{
		PushBack(_data);
	}
	else	   	// Node ->  NewNode   ->Node
	{
		StringNode* newNode = new StringNode;
		newNode->value = _data;
		newNode->pNext = nullptr;
		newNode->pPrev = nullptr;

		StringNode* cur = pHead;

		// index가 n이라고 가정.

		int i = 0;
		while (i < index - 1)
		{
			cur = cur->pNext;
			i++;
		}

		newNode->pPrev = cur;        // 새로운 노드의 이전 : 기존 노드
		newNode->pNext = cur->pNext; // 새로운 노드의 이후 : 기존 노드의 next 노드
		cur->pNext->pPrev = newNode; // 기존 노드의 이후 노드가 가리키고 있던 이전 : 새로운 노드
		cur->pNext = newNode;        // 기존 노드의 이후 : 새로운 노드

		iCount++;
		//cur = pHead->pNext;
		//cur = pHead->pNext->pNext;
		//newNode = pHead->pNext... n
	}
}

void DoubliyLinkedList::Print()
{
	StringNode* printNode = pHead;

	while (nullptr != printNode)
	{
		// printNode 마지막일 때는 printNode->value
		if (printNode->pNext == nullptr) // printNode->next nullptr
		{
			cout << printNode->value << endl;
		}
		else
		{
			cout << printNode->value << " " << "<->" << " ";
		}

		printNode = printNode->pNext;
	}
}

void DoubliyLinkedList::RemoveFront()
{
	if (pHead != nullptr)
	{
		StringNode* remove = pHead;

		// phead->next null이면 1개만 존재

		if (nullptr == remove->pNext)
		{
			pHead = pTail = nullptr;
		}
		else // 아닐 때
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
			delete remove;
		}
		iCount--;
	}
}

void DoubliyLinkedList::RemoveBack()
{
}

void DoubliyLinkedList::RemoveAt(int index)
{
}