// YunGoon
#include <bits/stdc++.h>
using namespace std;

int conv(string& t) {
	int h = (t[0] - 48) * 10 + t[1] - 48;
	int m = (t[3] - 48) * 10 + t[4] - 48;
	return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> vec[10000];
	for (auto & record: records) {
		stringstream ss(record);
		string a, b, c;
		ss >> a >> b >> c;
		vec[stoi(b)].push_back(conv(a));
	}

	vector<int> ans;
	for (int i = 0; i < 10000; i++) if (!vec[i].empty()) {
		if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);

		int sum = 0; 
		for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j-1];

		int val = fees[1];
		if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];

		ans.push_back(val);
	}

	return ans; 
}
