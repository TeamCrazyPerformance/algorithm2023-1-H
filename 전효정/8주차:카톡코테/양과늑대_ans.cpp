// 박진한
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std; 

constexpr int INF = 1e9 + 7;

int solution(vector<int> info, vector<vector<int>> edge) {
	// 1. 
	const int n = info.size();
	vector<vector<int>> adj(n);
	for (const auto& i : edge) {
		adj[i[0]].push_back(i[1]);
		adj[i[1]].push_back(i[0]);
	}

	// 2.
	vector<int> par(n, -1);
	auto DFS1 = [&](int cur, int prv, auto&& DFS1) -> void {
		par[cur] = prv;
		for (const auto& nxt : adj[cur]) {
			if (nxt == prv) continue;
			DFS1(nxt, cur, DFS1);
		}
	};
	DFS1(0, -1, DFS1); 

	// 3.
	auto GetCnt = [&](int state) -> pair<int, int> {
		int sheep = 0, wolf = 0; 
		for (int i = 0; i < n; i++) if (state & 1 << i) {
			if (info[i]) wolf++;
			else sheep++;
		}
		return { sheep, wolf };
	};

	auto DFS2 = [&](int state, auto&& DFS2) -> int {
		auto [sheep, wolf] = GetCnt(state);
		if (sheep <= wolf) return -INF;
		int ret = sheep;
		for (int i = 1; i < n; i++) {
			if (state & 1 << i || ~state & 1 << par[i]) continue;
			ret = max(ret, DFS2(state | 1 << i, DFS2));
		}
		return ret;
	};
	return DFS2(1, DFS2); 
}