#include<iostream>
#include<cstdlib>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[101] = { 0 };

int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	if (find(a) != find(b)) {
		parent[find(b)] = find(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) parent[i] = i;
	double x, y, distance;
	double ans = 0;
	tuple<int, double, double> stars[101]; // <별번호,x좌표,y좌표>
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		stars[i] = { i,x,y };
	}
	tuple<double, int, int> edge_case[5000]; // <거리,별번호,별번호>
	int num = 0;
	for(int i=0;i < n - 1;i++){
		for (int j = i + 1; j < n; j++) {
			double a = get<1>(stars[i]) - get<1>(stars[j]);
			double b = get<2>(stars[i]) - get<2>(stars[j]);
			distance = sqrt(pow(a, 2) + pow(b, 2));
			edge_case[num] = { distance, i, j };
			num++;
		}
	}
	sort(edge_case, edge_case + n * (n - 1) / 2);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		if (find(get<1>(edge_case[i])) != find(get<2>(edge_case[i]))) {
			merge(get<1>(edge_case[i]), get<2>(edge_case[i]));
			ans += get<0>(edge_case[i]);
		}
	}
	cout << ans;
	return 0;
}
