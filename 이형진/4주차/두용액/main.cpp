#include<bits/stdc++.h>

#define INF 987654321

using namespace std;

class Solve {
private:
  int n;
  vector<int> data;
  pair<int, int> result;

  void solving() {
    int pl=0, pr=n-1;
    int sum;
    pair<int, int> m = make_pair(data[pl], data[pr]);
    while(pl < pr) {
      sum = data[pl] + data[pr];
      if(abs(m.first + m.second) > abs(sum)) m = make_pair(data[pl], data[pr]);
      
      if(sum > 0) pr--;
      else pl ++;


    }
    result = m;
  }

public:
  Solve() {
    cin >> n;
    data.resize(n);
    for(int i=0;i<n;i++) {
      cin >> data[i];
    }
    sort(data.begin(), data.end());
  }

  void print_result() {
    solving();
    cout << result.first << " " << result.second;
  }
};

int main() {
  Solve solve;
  solve.print_result();
  return 0;
}
