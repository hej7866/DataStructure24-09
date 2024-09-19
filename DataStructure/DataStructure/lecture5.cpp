#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"

// 학습 목표 : 가변 배열 vector

void lecture5()
{
	MyVector<int> i_vec(20);
	MyVector<int> i_vec2;
	MyVector<float> f_vec;

	if (i_vec != i_vec2)
	{
		cout << " 연산자 오버로딩이 정상적으로 구현됨!" << endl;
	}

	f_vec.push_back(0.1f);
	f_vec.push_back(0.2f);
	f_vec.push_back(0.3f);
	f_vec.Print();

	int r_index = R_Number(0, f_vec.GetSize());
	cout << "f_vec 랜덤 원소에 접근 : " << r_index << endl;
	cout << "랜덤 값: " << f_vec[r_index] << endl;

	cout << "f_vec 0번째 원소에 접근 : " << f_vec[0] << endl;

	cout << "private 선언된 vec에 직접 접근함 : " << f_vec.GetVector()[0] << endl;

	f_vec.pop_back();
	f_vec.Print();

	// 간단한 도전과제
	// vector의 특징. 임의의 원소에 접근하는 시간이 O(1);
	// vector 랜덤 원소에 접근하는 기능 구현
}