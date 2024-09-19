#pragma once

#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include <random> // c++ 지원하는 랜덤 라이브러리

using namespace std;

int ReturnRandomNumber(int endNumber)
{
	srand(time(nullptr)); // 현재 시간을 시드로하여 난수발생
	int randNumber = rand() % endNumber + 1; // 1부터 endNumber - 1 까지의 숫자가 반환된다.

	return randNumber;
}

int R_Number(int startNumber, int endNumber)
{
	random_device rd; // 시드를 생성하기 위한 객체
	mt19937 gen(rd()); // mt19937 알고리즘을 사용하여 난수를 생성한다.
	uniform_int_distribution<> distrib(startNumber, endNumber);
	int randomNumber = distrib(gen);
	return randomNumber;
}