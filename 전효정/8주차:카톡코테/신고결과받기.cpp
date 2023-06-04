// https://word.tistory.com/24

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1. 
    const int n = id_list.size();
    map<string, int> Conv;
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i; 

    // 2.
    vector<pair<int, int> > v; 
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (const auto& s: report) {
        stringstream in(s); 
        string a, b; in >> a >> b; 
        v.push_back({ Conv[a], Coㅅnv[b] });
    }

    // 3.
    vector<int> cnt(n), ret(n);
    for (const auto& [a,b] : v) cnt[b]++;
    for (const auto& [a,b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}