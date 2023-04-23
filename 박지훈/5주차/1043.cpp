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
		if (mHeadT < 0)
			cout << mParty.size();
		else
		{
			mHeadT = find(mHeadT);
			int cnt = 0;
			for (auto partyHead : mParty)
			{
				if (mHeadT != find(partyHead))
					cnt++;
			}

			cout << cnt;
		}
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mHead.resize(mN + 1, -1);

		int t;
		cin >> t;
		vi groupT(t);
		for (auto& i : groupT)
			cin >> i;
		if (!groupT.empty())
		{
			mHeadT = groupT[0];
			for (int i = 1; i < groupT.size(); i++)
			{
				merge(mHeadT, groupT[i]);
			}
		}

		for (int i = 0; i < mM; i++)
		{
			int n, head, tmp;
			cin >> n >> head;
			mParty.push_back(head);
			for (int i = 1; i < n; i++)
			{
				cin >> tmp;
				merge(head, tmp);
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
	vi mHead, mParty;
	int mN, mM, mHeadT = -1;

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