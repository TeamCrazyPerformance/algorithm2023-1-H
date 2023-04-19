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
		vi root(mM);
		for (auto& i : root)
			cin >> i;

		int head = find(root[0]);
		for (int i = 1; i < mM; i++)
		{
			if (head != find(root[i]))
			{
				cout << "NO";
				return;
			}
		}

		cout << "YES";
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mHead.resize(mN + 1, -1);
		int possible;
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mN; j++)
			{
				cin >> possible;
				if (possible == 1)
					merge(i, j);
			}
		}
	}

	int find(int e)
	{
		if (mHead[e] < 0)
			return e;
		mHead[e] = find(mHead[e]);
		return mHead[e];
	}

	void merge(int a, int b)
	{
		if (a == b)
			return;

		int A = find(a),
			B = find(b);
		if (A == B)
			return;

		if (mHead[A] < mHead[B])
		{
			mHead[A] += mHead[B];
			mHead[B] = A;
		}
		else
		{
			mHead[B] += mHead[A];
			mHead[A] = B;
		}
	}


private:
	vi mHead;
	int mN, mM;

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