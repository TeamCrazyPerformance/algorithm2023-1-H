#include <iostream>
#include <map>
using namespace std; 

map<string, int> m; 
int parents[100001];

void initialize() {
	for (int i = 0; i < 100001; i++) {
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

	if (parents[rootA] < parents[rootB]) parents[rootB] = parents[rootA]; 
	else parents[rootA] = parents[rootB]; 
}

int main()
{
	int T;
	cin >> T;

	int F; 
	string firstName, lastName; 

	int rootFirst, rootLast; 

	int count;

	m.insert(make_pair("minhyeok", 1)); 
	for (int i = 0; i < T; i++) {
		cin >> F; 
		initialize(); 
		 
		for (int j = 1; j <= F; j++) {
			count = 1;
			cin >> firstName >> lastName;
			if (m.find(firstName) == m.end()) {
				m.insert(make_pair(firstName, m.size())); 
			}
			if (m.find(lastName) == m.end()) {
				m.insert(make_pair(lastName, m.size())); 
			}
			rootFirst = m.find(firstName) -> second; 
			rootLast = m.find(lastName) -> second;

			Union(rootFirst, rootLast);

			rootFirst = m.find(firstName) -> second; 
			rootLast = m.find(lastName) -> second;

			if (Find(rootFirst) == 1 || Find(rootLast) == 1) {
				cout << ++count; 
			}
			
			cout << count << "\n";
		}
	}
}