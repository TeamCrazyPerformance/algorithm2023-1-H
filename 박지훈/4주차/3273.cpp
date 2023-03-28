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
		int ans = 0;
		int left = 0, right = mN - 1;
		while (left < right)
		{
			int sum = mArr[left] + mArr[right];
			if (sum < mX)
			{
				left++;
			}
			else if (sum > mX)
			{
				right--;
			}
			else
			{
				ans++;
				right--;
			}
		}

		cout << ans;
	}


private:
	void init()
	{
		cin >> mN;
		mArr.resize(mN);
		for (auto& i : mArr)
		{
			cin >> i;
		}
		sort(mArr.begin(), mArr.end());
		cin >> mX;
	}

private:
	vi mArr;
	int mN, mX;

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