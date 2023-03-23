// C++20
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef std::tuple<int, int, int, int> ti4;

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
		printPostorder(0, mN - 1);
	}

private:
	void init()
	{
		int x;
		while (cin >> x)
		{
			mTree.push_back(x);
		}

		mN = int(mTree.size());
	}

	void printPostorder(int head, int tail)
	{
		if (head > tail)
		{
			return;
		}
		if (head == tail)
		{
			cout << mTree[head] << "\n";
			return;
		}

		int rightHead = tail + 1;
		for (int i = head; i <= tail; i++)
		{
			if (mTree[head] < mTree[i])
			{
				rightHead = i;
				break;
			}
		}

		printPostorder(head + 1, rightHead - 1);
		printPostorder(rightHead, tail);

		cout << mTree[head] << "\n";
	}

private:
	vi mTree;
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