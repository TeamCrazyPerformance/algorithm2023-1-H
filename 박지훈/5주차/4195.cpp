// C++20
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
		unordered_map<string, int> nameToIdx;
		string n1, n2;
		for (int i = 0; i < mN; i++)
		{
			cin >> n1 >> n2;
			nameToIdx.insert({ n1, nameToIdx.size() });
			nameToIdx.insert({ n2, nameToIdx.size() });
			merge(nameToIdx[n1], nameToIdx[n2]);
			cout << -mHead[find(nameToIdx[n1])] << "\n";
		}
	}


private:
	void init()
	{
		cin >> mN;
		mHead.resize(mN << 1, -1);
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