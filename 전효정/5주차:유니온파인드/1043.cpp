#include <iostream>
#include <vector>
#include <algorithm>
using name1space std; 

int parents[51]; 
int truthTable[51];
vector<int> members[51]; 
vector<pair<int, int> > priority; 

bool cmp(pair<int, int> a, pair<int, int>  b) {
	return a.first > b.first;
}

void initialize() {
	for (int i = 0; i <= 50; i++) {
		parents[i] = i; 
	}
}

int Find(int num) {
	if (parents[num] == num) return num;
	return parents[num] = Find(parents[num]); 
}

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b); 

	if (rootA < rootB) parents[rootB] = parents[rootA];
	else parents[rootA] = parents[rootB]; 
}

int main()
{
	int N, M; 
	cin >> N >> M; 

	int numberOfMembers;
	cin >> numberOfMembers;

	initialize();

	int knowsTruth;
	for (int i = 0; i < numberOfMembers; i++) {
		cin >> knowsTruth; 
		parents[knowsTruth] = 0; 
	}

	int numOfPeople, member;

	int flag;

	// M 개의 파티만큼.
	for (int i = 1; i <= M; i++) {
		cin >> numOfPeople;
		flag = 0; 

		for (int j = 0; j < numOfPeople; j++) {
			cin >> member; 
			members[i].push_back(member); 
		}

		for (int j = 0; j < members[i].size() - 1; j++) { 
			Union(members[i][j], members[i][j+1]); 
		}
		// priority <인원수, 파티넘버>
		priority.push_back(make_pair(numOfPeople, i)); 
	}


	sort(priority.begin(), priority.end(), cmp); 

	for (int i = 0; i < priority.size(); i++) {
		flag = 0; 
		// priority 인원수 만큼 for 문을 돔.
		for (int j = 0; j < priority[i].first; j++) {
			int root = Find(members[priority[i].second][j]);
			if (root == 0) { // 반드시 그 파티에서는 진실만을 말해야 함. 
				truthTable[priority[i].second] = 1;
				flag = 1; 
				break;
			}
		}
		if (flag) {
			for (int j = 0; j < priority[i].first; j++) {  
				// priority[i].first (인원수) 만큼 돌아야 하는데, prioirty[i].second (파티넘버) 만큼 돌고 있어서 에러난듯. 
				parents[members[priority[i].second][j]] = 0; 
			}
		} 
	}	

	int count = 0; 
	for (int i = 1; i <= M; i++) {
		if (truthTable[i] == 0) count++;
	}

	cout << count; 

}