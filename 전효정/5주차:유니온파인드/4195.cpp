#include <iostream>
#include <map>
#include <vector>
using namespace std; 

int parents[100001]; 

map<string, string> friends;
map<string, int> rootCount;


string Find(string name) {
	if (friends[name].compare(name) == 0) return name; 
	else friends[name] = Find(friends[name]); 
}

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b); 

	if (rootA < rootB) friends[rootB] = friends[rootA]; 
	else friends[rootA] = friends[rootB]; 
}

int main()
{
	int T, F; 
	cin >> T;

	friends.insert(make_pair<"minhyeok", 1>); 

	string firstName, lastName;

	for (int i = 0; i < T; i++) {
		cin >> F;
		friends.clear(); 
		for (int j = 1; j <= F; j++) {
			cin >> firstName >> lastName;
			auto item = friends.find(firstName); 
			if (item != friends.end()) {
				
			}
		}
	}
}