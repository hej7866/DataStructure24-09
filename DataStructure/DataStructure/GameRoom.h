#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 학습 목표 : 방과 유저사이의 시스템을 자료구조를 사용해서 클래스로 구현하는 것
// 1. List<사용자 정의형 클래스> iList <- 자료구조에 새로운 클래스 타입을 저장한다.
// 2. class GameRoom { private : vector m_vector; }

// 방에 들어온 유저의 정보
// (private)필드 : string name / int id / int level
// (public)기능 : GetName(), GetId(), GetLevel(), GetUserInfo()

// GameRoom 유저를 저장하는 클래스
// UserInfo - 배열, 가변배열, 연결형 리스트로 저장
// addPlayer, deletePlayer, showPlayerList, BanPlayer

struct UserInfo
{
private:
	string name;
	int id;
	int level;
public:
	UserInfo() : name(nullptr) {}
	UserInfo(string name, int id, int level) : name(name), id(id), level(level) {}

	void GetName() 
	{
		cout << "유저 이름 : " << name << endl;
	}
	void GetId()
	{
		cout << "유저 아이디 : " << id << endl;
	}
	void GetLevel()
	{
		cout << "유저 레벨 : " << level << endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};

// 연결형 리스트 vs 가변 배열
// 중간 삽입 , 삭제 가능여부 
// 랜덤 접근 가능여부

class GameRoom
{
// 배열로 userInfo를 표현했을 때 문제점
// 6인모드 8인모드.. 12인모드.. 정해져있지않음

// 가변 배열 vector 사용
private:
	vector<UserInfo> users;
	int maxCount;  // 방 최대 인원 수
	int userCount; // 현재 방 인원 수
public:
	GameRoom(int max)
	{
		maxCount = max;
		userCount = 0;
	}

	void AddPlayer(UserInfo& user)
	{
		// 방이 가득 찼을 때
		if (!IsFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			cout << "방이 가득찼습니다." << endl;
		}
	}

	void BanPlayer(int order)
	{
		if (0 <= order && order <= users.size())
		{
			users[order].GetName();
			cout << "을(를) 추방했습니다." << endl;

			users.erase(users.begin() + order);

			userCount--;
		}
		else
		{
			cout << "인덱스가 유효하지 않습니다." << endl;
		}
	}

	void ShowListPlayer()
	{
		if (IsEmpty())
		{
			cout << "방에 사람이 없습니다." << endl;
			return;
		}
		// 시작부터 마지막까지 유저정보
		for (int i = 0; i < userCount; i++)
		{
			users[i].ShowUserInfo();
		}
	}

	bool IsEmpty()
	{
		return userCount <= 0 ? true : false;
	}

	bool IsFull()
	{
		return userCount >= maxCount ? true : false;
	}

	void IsClear()
	{
		while (!IsEmpty())
		{
			users.pop_back(); // 끝에서부터 하나씩 날린다.
			userCount--;
		}
	}

	void IsClear2()
	{
		users.erase(users.begin(), users.end());
		userCount = 0;
	}
};


void IGameRoomExample()
{
	cout << "GameRoom 예시 입니다." << endl;
	
	// 가상의 유저 3명을 생성해 본다.
	UserInfo user1("A", 1000, 10); // 유저 1 : 이름은 A이고 id는 1000 레벨은 10
	//user1.ShowUserInfo();
	UserInfo user2("B", 1001, 5); // 유저 2 : 이름은 B이고 id는 1001 레벨은 5
	//user2.ShowUserInfo();
	UserInfo user3("C", 1002, 15); // 유저 3 : 이름은 C이고 id는 1002 레벨은 15
	//user3.ShowUserInfo();

	GameRoom room(3);
	room.AddPlayer(user1);
	room.AddPlayer(user2);
	room.AddPlayer(user3);

	room.BanPlayer(1);

	room.ShowListPlayer();

	room.IsClear();
	room.ShowListPlayer();
}

