// C++20
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;


struct Tri
{
	int a, b, cost;

	bool operator<(auto& other)
	{
		return cost < other.cost;
	}
};

class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		int totalCost = 0,
			totalN = mN + 1; // 0번 노드를 총 노드 개수에 포함

		for (auto [a, b, cost] : mEdges)
		{
			if (merge(a, b))
			{
				totalCost += cost;
			}
		}

		cout << totalCost;
	}


private:
	void init()
	{
		cin >> mN;
		mEdges.resize(mN + 1);
		mHead.resize(mN + 1, -1);

		int cost;
		for (int i = 1; i <= mN; i++)
		{
			cin >> cost;
			mEdges.push_back({ 0, i, cost });	// 물을 길어올 수 있는 가상의 0번 정점을 생성, 0번을 포함하여 모두 연결되어야 모든 논에 물이 흐른다고 볼 수 있음
		}
		for (int i = 1; i <= mN; i++)
		{
			int j = 1;
			for (; j <= i; j++)
				cin >> cost; // i, i는 무시, 주어진 행렬이 대칭행렬이므로 효율을 위해 반은 입력만 받아주기
			for (; j <= mN; j++)
			{
				cin >> cost;
				mEdges.push_back({ i, j, cost });
			}
		}
		sort(mEdges.begin(), mEdges.end());
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
		int A = find(a),
			B = find(b);
		if (A == B)
			return false;

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
		return true;
	}


private:
	vector<Tri> mEdges;
	vi mHead;
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