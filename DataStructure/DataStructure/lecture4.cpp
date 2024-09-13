#include "lectures.h"
#include <list>
#include <string>

// 연결리스트를 템플릿으로 만든것 std::list template

// 게임 아이템 삭제, 추가 => 인벤토리에서 관리한다.
// 배열 - 연결 리스트
// 장점 : 임의의 원소 접근이 빠르다. <-> 임의의 원소 접근이 불가능하다.
// 단점 : 데이터의 삭제 및 추가가 느리다. <-> 데이터 삭제 및 추가가 빠르다.

class Item
{
private:
	int itemCode;
	string name;
public:
	Item(int _itemCode, string _name) : itemCode(_itemCode), name(_name) {}

	void ShowInfo()
	{
		cout << "아이템 코드 : " << itemCode << endl;
		cout << "아이템 이름 : " << name << endl;
	}
};

template<typename T>
class Node
{
	T value;
	Node* next;
};

template<typename T>
class LinkedList
{
	
};

class Pos
	{
		int posX;
		int posY;
		char tag;
	public:
		Pos(int x, int y, char v) : posX(x), posY(y), tag(v) {}
	};

class Point
	{
	public:
		Pos data;
		Point* next;
		Point(Pos _data) : data(_data) {}
	};

void lecture4()
{
	cout << "STL : 연결 리스트 사용" << endl;

	// list<int>* iList = new list<int>(); <= 동적 할당
	//list<int> iList; // 클래스 생성

	list<Item> invectory;

	// 데이터 앞에 저장 PushFront - push_front
	// 데이터 앞에 저장 PushBack - push_back
	// 데이터 앞에 저장 RemoveFront - pop_front
	// 데이터 앞에 저장 RemoveBack - pop_front

	Item* newItem = new Item(1001, "대검");
	Item* newItem2 = new Item(1002, "한손검");
	Item* newItem3 = new Item(1003, "해머");

	invectory.push_front(*newItem);
	invectory.push_front(*newItem2);
	invectory.push_front(*newItem3);

	list<Item>::iterator iPos = invectory.begin();

	invectory.insert(iPos, 3, *newItem2); // iPos위치로부터 3개 newItem2추가
	// 특정 인덱스iList.insert()에 값을 넣는 insert함수를 만들었었다.

	// iterator : 포인터를 일반화시킨 클래스
	list<Item>::iterator iterEnd = invectory.end();

	// for(int i=0; i<배열.size(); i++) 와 같은것.
	for (list<Item>::iterator iterPos = invectory.begin(); iterPos != iterEnd; ++iterPos)
	{
		iterPos->ShowInfo();
	}



	// 클래스 구현

	// list, LinkedList.h - int, DoubliyLinkedList.h - string

	// LinkedList<int> iList1;
	// list<int> iList2;

	// DoubliyLinkedList dList1;
	// list<string> dList2;

	// 예제 문제

	// 도형을 클래스로 정의할 것이다.
	// A(50,200) B(20, 80) C(75, 10) D(130, 80) E(100, 200)
	// class Pos(posX, posY)
	// Pos value로 갖는 노드를 재정의
	list<Pos> Star;

	Pos A = Pos(50, 200, 'A');
	Pos B = Pos(20, 80, 'B');
	Pos C = Pos(75, 10, 'C');
	Pos D = Pos(130, 80, 'D');
	Pos E = Pos(100, 200, 'E');

	// (1)

	Star.push_back(A);
	Star.push_back(B);
	Star.push_back(C);
	Star.push_back(D);
	Star.push_back(E);
	
	// (2)

	Point A_P = Point(A);
	Point B_P = Point(B);
	Point C_P = Point(C);
	Point D_P = Point(D);
	Point E_P = Point(E);

	A_P.next = &B_P;
	B_P.next = &C_P;
	C_P.next = &D_P;
	D_P.next = &E_P;
	E_P.next = &A_P;
}