#include<bits/stdc++.h>

using namespace std;

class Solve {
private:
  int N, d, k, c;
  vector<int> belt;
  vector<int> sushi;
  int result;
  
  void solving() {
    int index;
    int res;
    int m = 0;
    int coupon;
    for(int i=0; i<N; i++) {
      res = k;
      coupon = 1;
      for(int j=0; j<k; j++) {
        index = (i+j)%N;
        if(sushi[belt[index]] == 1) res-=1;
        else sushi[belt[index]] = 1;

        if(belt[index] == c) coupon=0;
      }
      m = max(m, res+coupon);
      fill(sushi.begin(), sushi.end(), 0);
    }
    result = m;
  }

public:
  Solve() {
    cin >> N >> d >> k >> c;
    belt.resize(N);
    sushi.resize(d+1);
    for(int i=0; i<N; i++) {
      cin >> belt[i];
    }
  }
  
  void print_result() {
    solving();
    cout << result;
  }
};

int main() {
  Solve solve;
  solve.print_result();
  return 0;
}
