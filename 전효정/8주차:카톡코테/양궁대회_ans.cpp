// 어려어
#include <string>
#include <vector>
#include <iostream>
using namespace std; 

int N, ans; 
vector<int> answer;
int a[11];
int r[11];
void solve(int cnt, int idx) {
	if (cnt == N) {
		int asum = 0; 
		int rsum = 0; 
		for (int i = 0; i <= 10; i++) {
			if (a[i]==r[i] && a[i]==0) continue;
			if (r[i] > a[i]) rsum += i;
			else asum += i; 
		}
		if (ans < rsum-asum) {
			ans = rsum-asum;
			answer.clear();
			for (int i = 10; i >= 0; i--) {
				answer.push_back(r[i]);
			}
		}
	}
	for (int i = idx; i <= 10; i++) {
		if (a[i] >= r[i]) {
			r[i]++;
			solve(cnt+1, i);
			r[i]--;
		}
	}

	vector<int> solution(int n, vector<int> info) {
		N = n;
		for (int i = 10; i >= 0; i--) a[10-i] = info[i];
		solve(0, 0);
		if(answer.empty()) answer.push_back(-1);
		return answer; 
	}
}