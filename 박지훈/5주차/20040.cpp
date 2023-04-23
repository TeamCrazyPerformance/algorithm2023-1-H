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
		int a, b;
		for (int i = 1; i <= mM; i++)
		{
			cin >> a >> b;
			if (merge(a, b))
			{
				cout << i;
				return;
			}
		}
		cout << 0;
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mHead.resize(mN << 1, -1);
	}

	int find(int e)
	{
		if (mHead[e] < 0)
			return e;
		mHead[e] = find(mHead[e]);
		return mHead[e];
	}

	bool merge(int a, int b)
	{
		if (a == b)
			return true;

		int A = find(a),
			B = find(b);
		if (A == B)
			return true;

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
		return false;
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