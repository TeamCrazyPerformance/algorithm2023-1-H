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
		int left = 0, right = mN - 1;
		int minSum = 0x7FFFFFFF;
		pii ans;
		while (left < right)
		{
			int sum = mArr[left] + mArr[right];
			if (minSum > abs(sum))
			{
				minSum = abs(sum);
				ans = { left, right };
			}

			if (sum < 0)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		cout << mArr[ans.first] << " " << mArr[ans.second];
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
	}

private:
	vi mArr;
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