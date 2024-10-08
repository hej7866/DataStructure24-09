#pragma once

#include <unordered_map>
#include <unordered_set>
#include <iostream>


using namespace std;

void HashExample()
{
	unordered_set<string> unordSet;

	unordSet.reserve(50000);

	unordSet.emplace("abc");
	unordSet.emplace("def");
	unordSet.emplace("hij");	
	unordSet.emplace("abc2");
	unordSet.emplace("def2");
	unordSet.emplace("hij2");

	for (const string& str : unordSet)
	{
		cout << str << endl;
	}

	cout << "abc : " << hash<string>{}("abc");
	cout << "bucket 수 : " << unordSet.bucket_count();

	unordSet.find("abc");
}