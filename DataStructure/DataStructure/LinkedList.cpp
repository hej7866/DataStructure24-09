#include "LinkedList.h"

ILinkedList::ILinkedList()
{
}

ILinkedList::~ILinkedList()
{
}

void ILinkedList::PushFront(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	if (nullptr == pHead) // Head가 가리키고 있는 포인터 null 비어있는 자료구조.
	{
		// Head 포인터를 새로운 노드로 변경해준다.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pNewNode->pNext = pHead;  // 새로운 노드의 next 주소를 head를 가리키도록 만들어라.
	pHead = pNewNode;         // 기존 head를 새로운 노드로 변경해라

	++iCount; // 자료구조에 들어있는 데이터의 총 갯수
}

void ILinkedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	// 데이터가 처음 들어갈 때 조건
	if (nullptr == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}

	// 꼬리 tail의 다음 주소에 노드를 생성하는 코드 

	pTail->pNext = pNewNode;      //  꼬리의 다음 포인터가 새로운 노드가 된다.
	pTail = pNewNode;			  //  꼬리의 포인터가 새로운 노드가 된다.
	++iCount;
}

void ILinkedList::RemoveFront()
{

	if (nullptr == pHead)  // bool IsEmpty()
	{
		std::cout << "데이터가 없습니다. 실행을 취소합니다." << std::endl;
		return;
	}

	IntNode* pOldNode = pHead;          // pHead 임시 데이터를 생성해준다.

	if (nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pOldNode->pNext;            // pHead->pNext : head로 만든다.
		// tail을 찾아서 할당해주는 코드 (while... node->pNext == nullPtr) : tail
	}
	delete pOldNode;	                // oldNode 메모리를 해제해준다.

	iCount--;
}

void ILinkedList::RemoveBack()
{
	if (nullptr == pHead)
	{
		std::cout << "데이터가 없습니다. 실행을 취소합니다." << std::endl;
		return;
	}

	// iCount를 이용해서 구현할 수 있다.

}

void ILinkedList::FrontValue()
{
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << "," << "첫번째 원소의 값 출력 : " << pHead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << "," << "첫번째 원소의 값 출력 : " << pTail->value << std::endl;
}