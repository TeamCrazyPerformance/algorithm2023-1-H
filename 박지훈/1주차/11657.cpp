// C++20
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector <long long > vl;

const int INF = (long long)1e10;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		vl dist = bellmanFord();
		if (isCycle(dist))
		{
			cout << "-1";
		}
		else
		{
			for (int i = 2; i <= mV; i++)
			{
				if (dist[i] >= INF)
				{
					cout << "-1\n";
				}
				else
				{
					cout << dist[i] << "\n";
				}
			}
		}
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
			mEdges[a].push_back({ b,cost });
		}

	}

	vl bellmanFord()
	{
		vl dist(mV + 1, INF);
		dist[1] = 0;

		for (int i = 1; i < mV; i++)
		{
			for (int i = 1; i <= mV; i++)
			{
				if (dist[i] == INF)
				{
					continue;
				}

				for (auto [next, cost] : mEdges[i])
				{
					auto newDist = dist[i] + cost;
					if (newDist < dist[next])
					{
						dist[next] = newDist;
					}
				}
			}
		}

		return dist;
	}

	bool isCycle(vl dist)
	{
		for (int i = 1; i <= mV; i++)
		{
			if (dist[i] == INF)
				continue;

			for (auto [next, cost] : mEdges[i])
			{
				auto newDist = dist[i] + cost;
				if (newDist < dist[next])
				{
					return true;
				}
			}
		}

		return false;
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