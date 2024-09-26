#pragma once
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Command
{
protected:
	string key;

public:
	Command(string key) : key(key) {} // 커맨드 클래스의 생성자
	virtual ~Command() = default;              // 가상 소멸자 : 부모 클래스가 가장 마지막에 소멸되도록 해주는 문법
	virtual string execute() const = 0;   // 모든 커맨드의 실행 기능
	string GetKey() { return key; }
};


class FireBall : public Command
{
public:
	FireBall(string key) : Command(key) {}
	string execute() const override
	{
		return "파이어볼 시전!";
	}
};


class IceBall : public Command
{
public:
	IceBall(string key) : Command(key) {}
	string execute() const override
	{
		return "아이스볼 시전!";
	}
};

template <typename T>
class CiruclarQueue
{
private:
	T* arr;	       // T 타입의 배열 이름
	int iCount;	   // 현재 원소의 수
	int iMaxCount; // 최대 저장 가능한 수
	int front;	   // front index
	int rear;      // rear index
public:
	CiruclarQueue(int size = 4)	   // 생성자
	{
		iMaxCount = size;
		arr = new T[size];
		iCount = 0;
		front = 0;
		rear = 0;
	}
	// 접근자 Accessor ( T Front.. Rear.. Size..)
	T Front() { return arr[front]; }
	T Rear() { return arr[rear]; }
	int Size() { return iCount; }
	// Helper Method	( Empty.. Full..)
	bool IsEmpty()
	{
		return rear == front ? true : false;
	}

	bool IsFull()
	{
		return (rear + 1) % iMaxCount == front ? true : false;
	}

	// Main   Method	( Push, Pop..)   enqueue dequeue

	void push(T data)
	{
		if (IsFull())
		{
			std::cout << "원형 큐가 가득찼습니다." << std::endl;
			return;
		}
		else
		{
			arr[rear] = data;
			rear = (rear + 1) % iMaxCount; // rear++
			iCount++;
		}
	}

	void pop()
	{
		if (IsEmpty())
		{
			std::cout << "원형 큐가 비었습니다." << std::endl;
			return;
		}
		else
		{
			front = (front + 1) % iMaxCount;
			iCount--;
		}
	}

};


class CommandSystem
{
private:
	// Command를 가장 효율적으로 저장할 수 있는 자료구조
	vector<Command*> Commands; // 특별한 이유가 없으면 vector가 효율적이다. 원소가 적을수록 효율적임
	CiruclarQueue<string> inputs; // 유저가 보낸 신호를 순서대로 저장을 해야 하는 데이터
public:
	void AddCommand(Command* command)
	{
		Commands.push_back(command);
	}

	void AddInput(const string input)
	{
		if (inputs.Size() < 3)
		{
			inputs.push(input);
		}
		else if (inputs.Size() == 3)
		{
			ProcessCommand();
			ClearQueue();
		}
	}

	void ProcessCommand()
	{
		string userCommand = "";
		// 유저가 입력한 순서대로 커맨드가 실행되어야 한다.

		while (!inputs.IsEmpty())	  // 큐가 0이 될 때까지 실행한다.
		{
			userCommand += inputs.Front();
			inputs.pop();
		}

		// 커맨드의 Key와 userCommand 비교 값이 일치하는 게 있다.

		for (int i = 0; i < Commands.size(); i++)
		{
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}

		std::cout << "일치하는 커맨드가 없습니다." << std::endl;
	}

	void ClearQueue()
	{
		while (!inputs.IsEmpty())
		{
			inputs.pop();
		}
	}

	void ShowCommandList()
	{
		cout << "=== 커맨드 목록 ===" << endl;
		cout << "FireBall 커맨드 : " << "ABC" << endl;
		cout << "IceBall 커맨드	: " << "DEF" << endl;
		cout << "=== ========== === " << endl;
	}

	void ShowPlayerInput()
	{
		cout << "현재 입력 값 : [ ";
		CiruclarQueue<std::string> temp = inputs;

		while (!temp.IsEmpty())	  // 큐가 0이 될 때까지 실행한다.
		{
			cout << temp.Front() << " ";
			temp.pop();
		}

		cout << "]" << endl;
	}
};


void CommandSystemExample()
{
	CommandSystem manager;

	FireBall command1("ABC");
	IceBall command2("DEF");

	manager.AddCommand(&command1);
	manager.AddCommand(&command2);

	std::string input;

	while (true)
	{
		manager.ShowCommandList();
		manager.ShowPlayerInput();

		cin >> input;
		manager.AddInput(input);

		if (input == "Q")
		{
			cout << "시스템 종료 " << endl;
			break;
		}
	}
}