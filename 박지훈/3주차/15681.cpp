// C++20
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;

const int INF = int(1e8);


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int u;
		for (int i = 0; i < mQ; i++)
		{
			cin >> u;
			cout << mTree[u] << "\n";
		}
	}


private:
	void init()
	{
		int root;
		cin >> mN >> root >> mQ;
		mTree.resize(mN + 1, 1);

		vvi edges;
		edges.resize(mN + 1);
		int a, b;
		for (int i = 1; i < mN; i++)
		{
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		for (auto next : edges[root])
		{
			mTree[root] += calcSubsetSizeRecur(next, root, edges);
		}
	}

	int calcSubsetSizeRecur(int now, int prev, vvi& edges)
	{
		if (edges[now].size() == 1)
		{
			return 1;
		}

		for (auto next : edges[now])
		{
			if (next == prev)
				continue;

			mTree[now] += calcSubsetSizeRecur(next, now, edges);
		}

		return mTree[now];
	}


private:
	vi mTree;
	int mN, mQ;

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