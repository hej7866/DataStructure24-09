#pragma once

// 그래프 Graph
// 1. 그래프란? vertex(점)와 edge(선)으로 데이터 간의 연결 관계를 범용적으로 표현한 자료구조다.

// 그래프의 특색(feature)

// 1. 방향성 갖거나, 갖지 않는다.  (directed  vs unDirected)
// 2. 선이 가중치를 갖는가?  weighted, 연결된 선의 가중치를 부여할 수 있다. 부여하지 않으면 0,1로 표현한다.
// 3. 순회하는가?           cyclic graph	 vs  Acyclic graph


// Graph Theroy 그래프 이론
// DAG ( Directed ACyclic Grpah) : 트리의 한 종류입니다.

// 그래프의 표현 

// 1. adjacent Matrix 인접 매트릭스

// 2. adjacent list	인접 리스트

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Graph_Matrix
{
private:
	int Vertex;  // 정점의 수
	vector<vector<int>> adjMatrix;	  // 그래프들의 연결 관계 정보 표현

public:
	Graph_Matrix(int vertices) : Vertex(vertices), adjMatrix(vertices, vector<int>(vertices, 0))
	{
	}


	void addEdgeMatrix(int v1, int v2)
	{
		adjMatrix[v1][v2] = 1;
		adjMatrix[v2][v1] = 1;
	}


	void printGraph()
	{
		for (int i = 0; i < Vertex; i++)
		{
			for (int j = 0; j < Vertex; j++)
			{
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}

};

class Graph_List
{
private:
	int Vertex;  // 정점의 수
	vector<vector<int>> adjList;	  // 그래프들의 연결 관계 정보 표현

public:
	Graph_List(int vertices) : Vertex(vertices)
	{
		adjList.resize(Vertex);
	}

	void addEdgeList(int v1, int v2) // directed, undirected
	{
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}

	void printGraph()
	{
		for (int i = 0; i < Vertex; i++)
		{
			cout << "정점 " << i << "의 인접 매트릭스:";
			for (auto x : adjList[i])
			{
				cout << " ->" << x;
			}
			cout << endl;
		}
	}
};


void GraphExample()
{
	Graph_List graph_L(5);
	graph_L.addEdgeList(0, 2);
	graph_L.addEdgeList(0, 3);
	graph_L.addEdgeList(1, 3);
	graph_L.addEdgeList(1, 4);
	graph_L.addEdgeList(2, 4);

	//graph_M.printGraphList();
	graph_L.printGraph();

	cout << "Graph Matrix" << endl;

	Graph_Matrix graph_M(5);
	graph_M.addEdgeMatrix(0, 2);
	graph_M.addEdgeMatrix(0, 3);
	graph_M.addEdgeMatrix(1, 3);
	graph_M.addEdgeMatrix(1, 4);
	graph_M.addEdgeMatrix(2, 4);

	graph_M.printGraph();
}

// 그래프 탐색 문제
// 0번 문 :  1,3 연결
// 1번 문 : 0,1,3,5 연결
// 2번 문 : 2,4 연결
// 3번 문 : 0,2 연결
// 4, 5번 문 : 연결이 안되어 있습니다.

// 이 문이 전체가 연결되어 있으면 true 반환, 아니면 false반환하도록 코드를 작성해보세요.

class VisitAllRooms
{
private:
	vector<vector<int>> rooms; // 방들을 그래프로 표현하는 2차원 배열
	set<int> seen; // 탐색한 방을 저장하는 자료구조 

	// 재귀 방식
	void recurDFS(vector<vector<int>>& rooms)
	{
		// stack : 인접한 vertex 대입, seen 넣고, 출력


		// recurDfs(0);
	}

	// iterative
	void iterDFS()
	{

	}

	void BFS()
	{


		// queue
	}
};