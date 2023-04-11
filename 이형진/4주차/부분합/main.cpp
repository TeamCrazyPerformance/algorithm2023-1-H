#include<bits/stdc++.h>

#define INF 987654321

using namespace std;

class Solve{
private:
  int N, M;
  vector<int> data;
  int result;

  void solving() {
    int sum = 0;
    int start = 0, end=0;
    int len = INF;
    while(start < N) {
      if(sum >= M && len > end-start) {
        len = end-start;
      }
      if(sum > M || end == N) {
        sum -= data[start];
        start += 1;
      } else {
        sum += data[end];
        end += 1;
      }
    }
    result = len;
  }

public:
  Solve() {
    cin >> N >> M;
    data.resize(N);
    for(int i=0; i<N; i++) {
      cin >> data[i];
    }
  }

  void print_result() {
    solving();
    if(result == INF) cout << 0;
    else cout << result;
  }
};

int main() {
  Solve solve;
  solve.print_result();
  return 0;
}
