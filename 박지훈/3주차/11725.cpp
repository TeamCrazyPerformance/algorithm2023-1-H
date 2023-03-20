// C++20
#include <iostream>
#include <vector>
#include <queue>
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
		vi ans(mN + 1);
		ans[1] = 1;
		queue<int> box;
		box.push(1);
		while (!box.empty())
		{
			int now = box.front();
			box.pop();

			for (auto next : mEdges[now])
			{
				if (ans[next] != 0)
				{
					continue;
				}

				ans[next] = now;
				box.push(next);
			}
		}

		for (int i = 2; i <= mN; i++)
		{
			cout << ans[i] << "\n";
		}
	}


private:
	void init()
	{
		cin >> mN;
		mEdges.resize(mN + 1);

		int a, b;
		for (int i = 1; i < mN; i++)
		{
			cin >> a >> b;
			mEdges[a].push_back(b);
			mEdges[b].push_back(a);
		}
	}


private:
	vvi mEdges;
	int mN;

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