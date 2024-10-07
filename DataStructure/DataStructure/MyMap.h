#pragma once

#include <map>
#include <iostream>
#include <string>

using namespace std;

class student
{
private:
	string name;
	int score;
public:
	student() {}
	student(string name, int score) : name(name), score(score) {}

	string GetName() const { return name; }
	int GetScore() const { return score; }
};

// map

void mapExample()
{
	pair<int, student> myPair;

	map<int, student*> myMap;

	//map에 데이터를 입력하는 방법
	myMap.emplace(make_pair(1, new student("AAA", 200)));

	myMap.insert(make_pair(2, new student("BBB", 400)));

	myMap.insert({ 4, new student("CCC", 100) });

	myMap.insert(pair<int, student*>(5, new student("DDD", 200)));

	// begin, end

	for (auto i = myMap.begin(); i != myMap.end(); i++)
	{
		cout << i->first << "," << i->second->GetName() << "," << i->second->GetScore() << endl;
	}




}

