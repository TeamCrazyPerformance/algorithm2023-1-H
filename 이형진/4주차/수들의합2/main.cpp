#include<bits/stdc++.h>

using namespace std;

class Solve {
private:
  int N, M;
  vector<int> A;

  int solving(int M) {
    int count = 0;
    int sum = 0;
    int end = 0;
    for(int i=0; i<N; i++) {
      while(sum < M && end < N) {
        sum += A[end];
        end++;
      }
      if(sum == M) count++;
      sum -= A[i];
    }
    return count;
  } 

public:
  Solve() {
    int input;
    cin >> this->N >> this->M;
    for(int i=0; i<N; i++) {
      cin >> input;
      this->A.push_back(input);
    }
  }

  void printResult() {
    int res = solving(M);
    cout << res;
  }
};

int main() {
  Solve solve;
  solve.printResult();
  return 0;
}
