// C++20
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector <long long > vl;

const int INF = (long long)1e8;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		if (bellmanFord())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


private:
	void init()
	{
		int e, w;
		cin >> mV >> e >> w;

		mEdges.resize(mV + 1);
		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b,cost });
			mEdges[b].push_back({ a,cost });
		}

		while (w--)
		{
			cin >> a >> b >> cost;
			mEdges[a].push_back({ b, -cost });
		}
	}

	bool bellmanFord()
	{
		vl dist(mV + 1, INF);
		dist[1] = 0;

		for (int i = 1; i < mV; i++)
		{
			for (int j = 1; j <= mV; j++)
			{
				for (auto [next, cost] : mEdges[j])
				{
					auto newDist = dist[j] + cost;
					if (newDist < dist[next])
					{
						dist[next] = newDist;
					}
				}
			}
		}

		return isCycle(dist);
	}

	bool isCycle(vl& dist)
	{
		for (int i = 1; i <= mV; i++)
		{
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
	//T = 1;
	cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}