// C++20
#include <iostream>
#include <vector>
#include <algorithm>
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
		int cnt = 1;
		int n, m;
		while (true)
		{
			cin >> n >> m;
			if (n == 0 && m == 0)
			{
				break;
			}

			vvi edges(n + 1);
			int a, b;
			while (m--)
			{
				cin >> a >> b;
				edges[a].push_back(b);
				edges[b].push_back(a);
			}

			vi check(n + 1);
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (check[i] != 0)
				{
					continue;
				}

				check[i] = 1;
				queue<pii> box;
				box.push({ i, 0 });
				bool isTree = true;
				while (!box.empty())
				{
					auto [now, prev] = box.front();
					box.pop();

					for (auto next : edges[now])
					{
						if (next == prev)
						{
							continue;
						}

						if (check[next] == 0)
						{
							check[next] = 1;
							box.push({ next, now });
						}
						else
						{
							isTree = false;
						}
					}
				}

				if (isTree)
				{
					ans++;
				}
			}

			cout << "Case " << cnt << ": ";
			if (ans == 0)
				cout << "No trees.\n";
			else if (ans == 1)
				cout << "There is one tree.\n";
			else
				cout << "A forest of " << ans << " trees.\n";
			cnt++;
		}
	}


private:
	void init()
	{
	}

private:

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