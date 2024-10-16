#pragma once

#include <deque>
#include <vector>
#include <iostream>
/*
*  학습 목표 : Deque에 대해 이해하고 구현한다.
*
*    Vector와 Deque을 비교해서 설명
*
*  Vector
* - 임의의 원소 접근 하는 시간 O(1)
* - 뒤에서 부터 원소를 삽입할 때 효율적이다.O(1)
* - 중간에 원소를 삽입 삭제 O(n)                   - Node기반 구현하면 O(1)
*
* Deque
* - 임의의 원소 접근 하는 시간 O(1)
* - 앞과 뒤에서 원소를 삽입할 때 효율적이다.O(1)
* - 중간에 원소를 삽입 삭제 O(n)                   - Node기반 구현하면 O(1)
*/

template <typename T>
class MyDeque
{
private:
    vector<T*> blocks;
    int blockSize;
    int frontIndex;
    int backIndex;
    int iCount;

    void allocateBlock()
    {
        blocks.push_back(new T[blockSize]());
        frontIndex = blockSize / 2;  // 중앙에서 시작
        backIndex = frontIndex + 1;  // back은 front 다음에서 시작
    }

    void addFrontBlock()
    {
        blocks.insert(blocks.begin(), new T[blockSize]());
        frontIndex = blockSize - 1;
    }

    void addBackBlock()
    {
        blocks.push_back(new T[blockSize]());
        backIndex = 0;
    }

public:
    MyDeque(int blockSize) : blockSize(blockSize), frontIndex(0), backIndex(0), iCount(0)
    {
        allocateBlock();
    }

    ~MyDeque() {
        for (T* block : blocks)
        {
            delete[] block;
        }
    }

    int getSize() const { return iCount; }
    bool isEmpty() const { return iCount == 0; }

    T& getFront() const
    {
        if (isEmpty())
        {
            throw out_of_range("덱이 비었음");
        }
        return blocks[0][frontIndex + 1];
    }

    T& getBack() const
    {
        if (isEmpty())
        {
            throw out_of_range("덱이 비었음");
        }
        return blocks.back()[backIndex - 1];
    }

    void pushFront(const T& data)
    {
        if (frontIndex < 0)
        {
            addFrontBlock();
        }
        blocks[0][frontIndex--] = data;
        ++iCount;
    }

    void pushBack(const T& data)
    {
        if (backIndex == blockSize)
        {
            addBackBlock();
        }
        blocks.back()[backIndex++] = data;
        ++iCount;
    }

    void popFront()
    {
        if (isEmpty())
        {
            return;
        }
        ++frontIndex;
        --iCount;

        if (frontIndex == blockSize)
        {
            delete[] blocks.front();
            blocks.erase(blocks.begin());
            frontIndex = 0;
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            return;
        }
        --backIndex;
        --iCount;

        if (backIndex < 0)
        {
            delete[] blocks.back();
            blocks.pop_back();
            backIndex = blockSize - 1;
        }
    }
};

void IDequeExample()
{
	MyDeque<int> M_Deq(1000);

	// main method

	M_Deq.pushBack(10);
	M_Deq.pushBack(20);
	M_Deq.pushBack(30);
	M_Deq.pushBack(50);
	M_Deq.pushFront(5);
	M_Deq.pushFront(1);
	M_Deq.pushFront(7);

	cout << "머리 : " << M_Deq.getFront() << endl;
	cout << "꼬리 : " << M_Deq.getBack() << endl;

	M_Deq.popBack();
	M_Deq.popFront();

	cout << "머리 : " << M_Deq.getFront() << endl;
	cout << "꼬리 : " << M_Deq.getBack() << endl;

}