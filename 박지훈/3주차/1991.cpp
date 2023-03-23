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
		printPreorder();
		cout << "\n";
		printInorder();
		cout << "\n";
		printPostorder();
	}


private:
	void init()
	{
		cin >> mN;
		mEdges.resize(mN, vi(2, -1));
		char P, l, r;
		for (int i = 0; i < mN; i++)
		{
			cin >> P >> l >> r;
			if (l != '.')
			{
				mEdges[P - 'A'][0] = l - 'A';
			}
			if (r != '.')
			{
				mEdges[P - 'A'][1] = r - 'A';
			}
		}
	}

	void printPreorder(int now = 0)
	{
		cout << char(now + 'A');

		if (mEdges[now][0] >= 0)
		{
			printPreorder(mEdges[now][0]);
		}
		if (mEdges[now][1] >= 0)
		{
			printPreorder(mEdges[now][1]);
		}
	}

	void printInorder(int now = 0)
	{
		if (mEdges[now][0] >= 0)
		{
			printInorder(mEdges[now][0]);
		}

		cout << char(now + 'A');

		if (mEdges[now][1] >= 0)
		{
			printInorder(mEdges[now][1]);
		}
	}

	void printPostorder(int now = 0)
	{
		if (mEdges[now][0] >= 0)
		{
			printPostorder(mEdges[now][0]);
		}
		if (mEdges[now][1] >= 0)
		{
			printPostorder(mEdges[now][1]);
		}

		cout << char(now + 'A');
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