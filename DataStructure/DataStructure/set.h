#pragma once
#include <iostream>
#include <set>

// set 자료구조의 특징
// Red-black트리로 구현되어 있다.
// 정렬되어 있는 자료구조.
// 중복을 허용하지 않는다.

using namespace std;


void SetExample()
{
	set<int> mySet;

	mySet.emplace(1);
	mySet.emplace(-1000);
	mySet.emplace(10);
	mySet.emplace(15);
	mySet.emplace(1000);
	mySet.emplace(25);

	for (const int num : mySet)
	{
		std::cout << num << " ";
	}

}