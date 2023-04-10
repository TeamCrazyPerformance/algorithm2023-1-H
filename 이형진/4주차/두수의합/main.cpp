#include<bits/stdc++.h>

using namespace std;

class Solve {
private:
  int n, x;
  vector<int> arr;

  int solving() {
    int right = n-1;
    int left = 0;
    int sum;
    int count = 0;
    while(left < right && left < n) {
      sum = arr[left] + arr[right];
      if(sum == x) {
        left++;
        count++;
      }
      else if(sum < x) left++;
      else right--;
    }
    return count;
  }

public:
  Solve() {
    int input;
    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> input;
      arr.push_back(input);
    }
    cin >> x;
  }
  
  void printResult() {
    sort(arr.begin(), arr.end());
    int res = solving();
    cout << res;
  }

};

int main() {
  Solve solve;
  solve.printResult();
  return 0;
}
