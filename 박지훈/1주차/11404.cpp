//C++20
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector <int > vi;

const int INF = int(1e9);


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		floyd();
		printAns();
	}


private:
	void init()
	{
		int e;
		cin >> mV >> e;
		mEdges.resize(mV + 1, vi(mV + 1, INF));

		int a, b, cost;
		while (e--)
		{
			cin >> a >> b >> cost;
			mEdges[a][b] = min(mEdges[a][b], cost);
		}
		for (int i = 1; i <= mV; i++)
		{
			mEdges[i][i] = 0;
		}
	}

	void floyd()
	{
		for (int k = 1; k <= mV; k++)
		{
			for (int i = 1; i <= mV; i++)
			{
				for (int j = 1; j <= mV; j++)
				{
					mEdges[i][j] = min(mEdges[i][j], mEdges[i][k] + mEdges[k][j]);
				}
			}
		}
	}

	void printAns()
	{
		for (int i = 1; i <= mV; i++)
		{
			for (int j = 1; j <= mV; j++)
			{
				cout << (mEdges[i][j] == INF ? 0 : mEdges[i][j]) << " ";
			}
			cout << "\n";
		}
	}

private:
	vector<vi> mEdges;
	int mV;
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