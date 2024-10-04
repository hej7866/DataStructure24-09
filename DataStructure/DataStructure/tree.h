#pragma once

// 트리 : 나무, 생김새가 나무처럼 생긴 자료구조.

// 트리의 노드가 가질 수 있는 최대 수에 따른 분류
// 2개 : 이진 트리 (binary tree)	 - 주로 다루어 볼 것
// 3개 : Ternary tree
// 4개 : Octree

// 트리의 용어 :
// 노드 : 트리의 기본요소로 데이터를 저장하는 단위
// 루트 : 최상위에 있는 노드. 부모 노드가 없는 유일 노드입니다.
// 부모 노드 : 하위의 노드와 직접 연결된 노드.
// 자식 노드 : 부모 노드의 하위에 직접 연결된 노드.
// 형제 노드 : 같은 부모를 가진 노드들입니다.
// 조상 노드 : 특정 노드에서 루트까지 경로에 있는 모든 노드들입니다.
// 후손 노드 : 특정 노드의 모든 자식, 자식의 자식 들을 포함한 노드들입니다.
// 레벨 : 루트로 부터의 거리.  루트노드 레벨 : 0
// 높이 : 트리에서 가장 깊은 레벨을 의미한다.
// 서브 트리 : 트리 내부의 노드와 그 후손들로 구성된 트리
// 차수 (degree) : 하나의 노드가 가진 자식 노드의 수 
// 경로 : 하나의 노드에서 다른 노드로 이동할 때 거치는 노드들의 순서

// 트리
// 1. 루트가 한 개이어야 합니다.
// 2. 노드들이 순환하지 않아야 합니다.

// 이진 트리의 종류
// 이진 트리 : 모든 노드들이 가질 수 있는 자식의 수(degree) 2개 이하로 구성된 자료구조
// 이진 탐색, 중간 삽입 삭제 빠른 자료구조 - 이진 검색 트리
// Full binary tree	 
// complete binary tree
// perfect binary tree

// 트리의 순회 방식
// PreOrder 전위 순회
// InOrder 중위 순회
// PostOrder 후위 순회

// 균형 잡힌 이진 검색 트리 
// Red - Black Tree,  AVL Tree

// 1. 모든 노드는 빨간색 혹은 검은색이다.
// 2. 루트 노드는 검은색이다.
// 3. NIL(Null leaf) 리프 노드들은 검은색이다. Null Left : 자료를 갖지 않고 트리의 끝을 나타내는 노드
// 4. 빨간색 노드의 자식은 검은색이다. (NO DOUBLE RED) // 검은색의 자식이 검은색이어도 된다.
// 5. 모든 리프 노드에서 Blcak Depth는 같다.  // 모든 리프 노드에서 특정 노드로 가는 검은색 노드의 갯수가 같아야 한다.

#include <iostream>

using namespace std;

class Tree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	};

	void PreOrder(Node* root)
	{
		// 재귀 함수 : 자기 자신의 함수를 호출하는 함수 
		if (root == nullptr) return;

		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	void InOrder(Node* root)
	{
		if (root == nullptr) return;

		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
	void PostOrder(Node* root)
	{
		if (root == nullptr) return;

		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << " ";
	}

};

// BST : 이진 검색 트리
// 선형 자료구조에서 이진 검색이 비효율적이다. 이진 검색을 효율적으로 할 수 있는 자료구조

// 이진 검색을 하기 위해서 다음의 규칙을 따릅니다.
// 노드의 기준으로 왼쪽 노드는 자신 노드보다 작은 값, 오른쪽 노드는 자신보다 큰 값을 저장한다.
// 중복은 허용하지 않습니다.

// 검색에 걸리는 시간 : logn
// 중간 삽입 삭제 : logn 
// Insert
// Delete


// 삭제의 방법

// 1. 삭제하고자 하는 노드의 자식이 없을 때

// 2. 삭제하고자 하는 노드의 왼쪽에만 자식이 있을 때

// 3. 삭제하고자 하는 노드의 오른쪽에만 자식이 있을 때

// 4. 양쪽에 자식이 있을 때

class BinarySearchTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	};

private:
	Node* root;

	Node* insert(Node* root, int value)
	{
		if (root == nullptr)
			return new Node(value);

		if (value < root->data)
		{
			root->left = insert(root->left, value);
		}

		if (value > root->data)
		{
			root->right = insert(root->right, value);
		}

		return root;
	}

	Node* search(Node* root, int target)
	{
		if (root == nullptr || root->data == target)
		{
			return root;
		}

		if (target < root->data)
		{
			return search(root->left, target);
		}
		else if (target > root->data)
		{
			return search(root->right, target);
		}

	}

	// 노드의 삭제

	// 1. 리프 노드	또는 자식이 1개만 있을 경우 : 노드를 삭제하고 자식 노드를 부모 노드와 연결 시켜 준다.

	// 2. 자식이 2개가 있을 경우 : case1, case2 그림 설명 (선택)

	Node* removeNode(Node* root, int target)
	{
		if (root == nullptr) return root;

		// 1. 삭제할 노드를 찾는다.
		if (target < root->data)
		{
			root->left = removeNode(root->left, target);
		}
		else if (target > root->data)
		{
			root->right = removeNode(root->right, target);
		}
		else  // 2. 노드를 찾았다면
		{
			// 그 노드의 자식이 1개만 존재하거나, 리프 노드일 경우

			if (root->left == nullptr)
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Node* temp = root->left;
				delete root;
				return temp;
			}

			// 자식이 2개가 있을 경우
			// 왼쪽 노드를 부모로 올릴지, 오른쪽 노드를 부모로 올릴지 선택
			// 오른쪽을 선택한다고 가정, 오른쪽 노드 중에서 가장 왼쪽 아래에 있는 노드를 부모로 변경해준다.

			Node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = removeNode(root->right, temp->data);
		}

		return root;
	}

	Node* minValueNode(Node* node)
	{
		Node* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	void inOrder(Node* root)
	{
		// LNR
		if (root == nullptr) return;

		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

public:
	BinarySearchTree() : root(nullptr) {}

	void insert(int value)
	{
		root = insert(root, value);
	}

	bool search(int value)
	{
		return search(root, value) != nullptr;
	}

	void InOrder()
	{
		inOrder(root); // root를 인자로 갖는 inOrder 함수를 구현해보세요.
		cout << endl;
	}

	void remove(int target)
	{
		removeNode(root, target);
	}

	void leftRotate(Node* oldTop)
	{
		bool isRoot = false;

		if (oldTop->data == root->data)
			isRoot = true;

		Node* newTop = oldTop->right;
		oldTop->right = newTop->left;
		newTop->left = oldTop;

		if (isRoot)
			root = newTop;
	}

	void rightRotate(Node* oldTop)
	{
		bool isRoot = false;

		if (oldTop->data == root->data)
			isRoot = true;

		Node* newTop = oldTop->left;
		oldTop->left = newTop->right;
		newTop->right = oldTop;

		if (isRoot)
			root = newTop;
	}

	Node* GetRoot() { return root; }
};

void TreeExample()
{
	// Tree 자료구조에 저장되어 있는 상태 root
	// 데이터를 순회하는 방법 :  preOrder, InOrder, PostOrder
	Tree::Node* root = new Tree::Node(19);
	root->left = new Tree::Node(24);
	root->right = new Tree::Node(35);
	root->left->left = new Tree::Node(40);
	root->left->right = new Tree::Node(52);

	Tree myTree;

	// preorder의 결과 : 1 - 2 - 4 - 5 - 3
	cout << " == 전위 순회 preOrder == " << endl;
	myTree.PreOrder(root);
	cout << endl;
	// Inorder의 결과 : 4 - 2 - 5 -1 3
	cout << " == 중위 순회 InOrder == " << endl;
	myTree.InOrder(root);
	cout << endl;
	// PostOrder의 결과 : 	4 -5 - 2 -3- 1
	cout << " == 후위 순회 postOrder ==" << endl;
	myTree.PostOrder(root);
	cout << endl;
	// 10, 7,  25, 8 , 49



	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(49);
	bst.insert(17);
	bst.insert(40);
	bst.remove(7);
	bst.remove(25);

	bst.rightRotate(bst.GetRoot());

	bst.InOrder();

	cout << "탐색 결과 :" << (bst.search(30) ? "찾음" : "못찾음") << endl;
}