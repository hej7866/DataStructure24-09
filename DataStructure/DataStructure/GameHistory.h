#pragma once
// Game에서 최근 로그아웃한 시간을 출력하는 클래스를 직접 구현해볼 것
#include <stack>
#include <string>
#include <iostream>

class GameData
{
private:
	std::string iDate;   // "2024-09-23/16:00:00"

public:
	GameData(std::string _date) : iDate(_date) {}

	std::string GetDate() { return iDate; }

	void Print()
	{
		std::cout << "로그아웃 한 시간 : " << iDate << std::endl;
	}
};

class GameHistory
{
private:
	// 자료구조 : 클래스 구현할 때 가장 적합하게 데이터를 저장할 수 있는 것을 배우는 것.
	// Stack 자료구조
	std::stack<GameData> GameDatas;

	// GameData*       m_Data;
	// int			   capacity
	// int			   top
	// pop , push, empty, isfull
public:
	void SaveLogoutTime(GameData time)
	{
		GameDatas.push(time);
	}

	void PrintLogoutTime()
	{
		GameData printData = GameDatas.top();
		printData.Print();
		GameDatas.pop();
	}
};

// GameData
// std::string iDate; "2024-09-23/16:57:00"
// Print() { "게임 로그아웃 시간 : " << iDate  }

// class GameHistory 
// Stack<GameData>
// Pop, push 
// SaveLogoutTime(std::string 시간)     push
// PrintLogoutTime()     pop

void iGameHistoryExample()
{
	// 로그아웃한 이력
	GameData data1("2024-09-20/17:00");
	GameData data2("2024-09-21/17:00");
	GameData data3("2024-09-22/17:00");
	GameData data4("2024-09-23/17:00");

	// 특정 유저가 로그아웃한 시간을 출력할 수 있는 기능

	GameHistory GameDatas;
	GameDatas.SaveLogoutTime(data1);
	GameDatas.SaveLogoutTime(data2);
	GameDatas.SaveLogoutTime(data3);
	GameDatas.SaveLogoutTime(data4);

	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();

}