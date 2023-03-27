// C++20
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
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
		int ans = 0, tot = mArr[0];
		int left = 0, right = 0;
		while (right < mN)
		{
			if (mM > tot)
			{
				right++;
				if (right == mN)
					break;
				tot += mArr[right];
			}
			else if (mM < tot)
			{
				tot -= mArr[left];
				left++;
			}
			else
			{
				ans++;
				tot -= mArr[left];
				left++;
			}
		}

		cout << ans;
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mArr.resize(mN);
		for (auto& i : mArr)
		{
			cin >> i;
		}
	}


private:
	vi mArr;
	int mN, mM;

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