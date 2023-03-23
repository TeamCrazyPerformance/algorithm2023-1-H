// C++20
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = (int)1e8;
class Tri
{
public:
	int next, cost;

	bool operator<(const Tri& other) const
	{
		return cost > other.cost;
	}
};

class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		vi dist_s = dijkstra(mS),
			dist_g = dijkstra(mG),
			dist_h = dijkstra(mH);

		int dist_gh = dist_g[mH]; // 최단거리만 지나간다는 조건이므로 g_h를 지나는 경로의 바로 cost는 g_h의 최단거리가 됨
		vi ans;
		for (auto t : mT)
		{
			if (dist_s[t] == dist_s[mG] + dist_gh + dist_h[t] ||
				dist_s[t] == dist_s[mH] + dist_gh + dist_g[t])
				ans.push_back(t);
		}
		sort(ans.begin(), ans.end());

		for (const auto& i : ans)
			cout << i << " ";
		cout << "\n";
	}


private:
	void init()
	{
		int e, t;
		cin >> mV >> e >> t >> mS >> mG >> mH;
		mEdges.resize(mV + 1);
		mT.resize(t);

		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mEdges[b].push_back({ a, cost });
		}

		for (auto& i : mT)
		{
			cin >> i;
		}
	}

	vi dijkstra(int source)
	{
		vi ret(mV + 1, INF);
		ret[source] = 0;

		priority_queue <Tri> box;

		box.push({ source, 0 });
		while (!box.empty())
		{
			auto [nowV, nowCost] = box.top();
			box.pop();

			for (auto [nextV, nextCost] : mEdges[nowV])
			{
				int cost = nowCost + nextCost;
				if (cost < ret[nextV])
				{
					ret[nextV] = cost;
					box.push({ nextV, cost });
				}
			}
		}

		return ret;
	}


private:
	vector<vector<pii>> mEdges; // mEdges[출발 정점] = { 도착 정점, 거리 }
	vi mT;
	int mV, mS, mG, mH;
};


int main()
{
	fastio;

	int T;
	//T = 1;
	cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}