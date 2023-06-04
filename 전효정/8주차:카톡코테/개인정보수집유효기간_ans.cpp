// 김세원
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std; 
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	int year = stoi(today.substr(0, 4));
	int month = stoi(today.substr(5, 2));
	int days = stoi(today.substr(8));
	int todayD = (year)*12 * 28 + (month - 1) * 28 + days;

	vector<int> ar(privacies.size());
	map<char, int> mp;
	for (int i = 0; i < terms.size(); i++) {
		stringstream ss(terms[i]);
		char c; 
		int month;
		ss >> c >> month;
		mp[c] = month;
	}
	for (int i = 0; i < privacies.size(); i++) {
		int y = stoi(privacies[i].substr(0, 4));
		int m = stoi(privacies[i].substr(5, 2));
		int d = stoi(privacies[i].substr(8, 2));
		char c = privacies[i].back();
		ar[i] = (y)*12 * 28 + (m-1) * 28 + d + mp[c] * 28 - 1;
	}
	for (int i = 0; i < ar.size(); i++) {
		if (ar[i] < todayD) {
			answer.push_back(i + 1); 
		}
	}
	return answer;
}