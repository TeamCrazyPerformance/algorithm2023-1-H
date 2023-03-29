// C++20
	// C++20
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef unsigned int u_int;
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
		unordered_map<int, int> sushiInRange;
		for (int i = 0; i < mK; i++)
		{
			if (!sushiInRange.insert({ mBelt[i], 1 }).second)
			{
				sushiInRange[mBelt[i]]++;
			}
		}

		pair<int, int> max = { 0, 0 }; // { 범위내 최대 초밥 종류, 쿠폰 초밥 포함 여부 }
		if (sushiInRange.find(mC) == sushiInRange.end())
			max = { int(sushiInRange.size()), 0 };
		else
			max = { int(sushiInRange.size()), 1 };

		for (int left = 0; left < mN; left++)
		{
			int right = (left + mK) % mN;
			if (!sushiInRange.insert({ mBelt[right], 1 }).second)
			{
				sushiInRange[mBelt[right]]++;
			}

			if (--sushiInRange[mBelt[left]] == 0)
			{
				sushiInRange.erase(mBelt[left]);
			}


			if (max.first == int(sushiInRange.size()))
			{
				if (sushiInRange.find(mC) == sushiInRange.end())
				{
					max.second = 0;
				}
			}
			else if (max.first < int(sushiInRange.size()))
			{
				if (sushiInRange.find(mC) == sushiInRange.end())
				{
					max = { int(sushiInRange.size()), 0 };
				}
				else
				{
					max = { int(sushiInRange.size()), 1 };
				}
			}

		}

		int ans;
		if (max.second == 0)
			ans = max.first + 1;
		else
			ans = max.first;

		cout << ans;
	}


private:
	void init()
	{
		cin >> mN >> mD >> mK >> mC;
		mBelt.resize(mN);
		for (auto& i : mBelt)
		{
			cin >> i;
		}
	}

private:
	vector<int> mBelt;
	int mN, mD, mK, mC;

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