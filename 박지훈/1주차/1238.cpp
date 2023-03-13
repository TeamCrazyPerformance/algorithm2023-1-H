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
		vi dist1 = dijkstra(mEdges);
		vi dist2 = dijkstra(mInvEdges);

		int ans = 0;
		for (int i = 1; i <= mV; i++)
		{
			ans = max(ans, dist1[i] + dist2[i]);
		}

		cout << ans;
	}


private:
	void init()
	{
		int e;
		cin >> mV >> e >> mS;

		mEdges.resize(mV + 1);
		mInvEdges.resize(mV + 1);
		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, cost });
			mInvEdges[b].push_back({ a, cost });
		}
	}

	vi dijkstra(vector<vector<pii>> edges)
	{
		vi ans(mV + 1, INF);
		ans[mS] = 0;

		auto cmp = [](pii& a, pii& b) -> bool
		{
			return a.second > b.second;
		};
		priority_queue < pii, vector<pii>, decltype(cmp)> box(cmp);

		box.push({ mS, 0 });
		while (!box.empty())
		{
			auto [nowV, nowCost] = box.top();
			box.pop();

			for (auto [nextV, nextCost] : edges[nowV])
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
	vector<vector<pii>> mEdges, mInvEdges; // mEdges[출발 정점] = { 도착 정점, 거리 }
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