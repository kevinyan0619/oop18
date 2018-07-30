//============================================================================
// Name        : OOP.cpp
// Author      : Shucheng Yan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#include <string>

int main() {

	string line;
	string word;
	vector<string> token_list;
	map<string, int> map_list;
	cout << "enter the sentence: \n";
	getline(cin, line);

	stringstream s(line);

	while (s >> word) {

		if (map_list.count(word) > 0)
			map_list[word]++;
		else
			map_list[word] = 1;
	}

	map<string, int>::iterator itr;

	for (itr = map_list.begin(); itr != map_list.end(); itr++) {
		cout << itr->first << ": " << itr->second << '\n';
	}

	return 0;
}
