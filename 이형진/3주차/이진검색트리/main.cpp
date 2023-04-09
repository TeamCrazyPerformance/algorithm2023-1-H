#include<bits/stdc++.h>

using namespace std;

vector<int> bstPre;

void postOrderTraversal(int start, int end) {
  if(start >= end) return;
  if(start == end-1) {
    cout << bstPre[start] << "\n";
    return;
  }

  int idx = start+1;
  while(idx<end) {
    if(bstPre[start] < bstPre[idx]) break;
    idx++;
  }

  postOrderTraversal(start+1, idx);
  postOrderTraversal(idx, end);
  cout << bstPre[start] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  int n;
  while(cin >> n) {
    bstPre.push_back(n);
  }
  
  postOrderTraversal(0, bstPre.size());
  return 0;
}
