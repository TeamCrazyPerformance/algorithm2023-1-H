// C++20
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = (int)1e8;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int sub1, sub2;
		cin >> sub1 >> sub2;

		int route1 = 0, route2 = 0;
		auto distance = dijkstra(1);
		route1 += distance[sub1];
		route2 += distance[sub2];

		distance = dijkstra(sub1);
		route1 += distance[sub2];
		route2 += distance[mV];

		distance = dijkstra(sub2);
		route1 += distance[mV];
		route2 += distance[sub1];

		int ans = min(route1, route2);
		if (ans >= INF)
			cout << "-1";
		else
			cout << ans;
	}


private:
	void init()
	{
		int e;
		cin >> mV >> e;

		mEdges.resize(mV + 1);
		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mEdges[b].push_back({ a, cost });
		}
	}

	vi dijkstra(int source)
	{
		vi ans(mV + 1, INF);
		ans[source] = 0;

		auto cmp = [](pii& a, pii& b) -> bool
		{
			return a.second > b.second;
		};
		priority_queue < pii, vector<pii>, decltype(cmp)> box(cmp);

		box.push({ source, 0 });
		while (!box.empty())
		{
			auto [nowV, nowCost] = box.top();
			box.pop();

			for (auto [nextV, nextCost] : mEdges[nowV])
			{
				int cost = nowCost + nextCost;
				if (cost < ans[nextV])
				{
					ans[nextV] = cost;
					box.push({ nextV, cost });
				}
			}
		}

		return ans;
	}


private:
	vector<vector<pii>> mEdges; // mEdges[출발 정점] = { 도착 정점, 거리 }
	int mV, mS;
};


int main()
{
	fastio;

	int T;
	T = 1;
	//cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}