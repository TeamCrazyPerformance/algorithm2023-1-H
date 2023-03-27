#include <iostream>
#include <algorithm>
using namespace std; 

int main()
{
	int arr[100001] = {0}; 
	int n, x;
	cin >> n; 

	int num; 
	for (int i = 0; i < n; i++) {
		cin >> num; 
		arr[i] = num;
	}

	cin >> x; 

	sort(arr, arr+n); 

	int start = 0, end = n-1; 

	int count = 0;
	while (start < end) {
		if (arr[start] + arr[end] == x) {
			count++;
			start++; 
			end--;
		} else {
			while (arr[start] + arr[end] > x) end--;
			while (arr[start] + arr[end] < x) start++;
		}
	}

	cout << count; 
}