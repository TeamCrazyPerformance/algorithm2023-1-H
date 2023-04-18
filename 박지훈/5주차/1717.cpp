// C++20
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int m;
		cin >> m;

		int q, a, b;
		while (m--)
		{
			cin >> q >> a >> b;

			if (q == 0) // union a, b
			{
				merge(a, b);
			}
			else // query a, b
			{
				if (find(a) == find(b))
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}


private:
	void init()
	{
		cin >> mN;
		mHead.resize(mN + 1, -1);
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
	int mN;

};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T;
	//cin >> T;
	T = 1;

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}