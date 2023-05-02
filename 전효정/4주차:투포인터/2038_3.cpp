#include <iostream>
#include <vector>
using namespace std; 

int main()
{
	unsigned int n; 
	cin >> n; 

	if (n == 1) {
		cout << "1";
		return 0; 
	} else if (n == 2 || n == 3) {
		cout << "2";
		return 0; 
	} else if (n == 4 || n == 5) {
		cout << "3";
		return 0; 
	}

	vector<unsigned int> f;

	f.push_back(0); // f(0) = 0
	f.push_back(1); // f(1) = 1
	f.push_back(3); // f(2) = 3
	f.push_back(5);	// f(3) = 5

	unsigned int count = 2; 

	unsigned int lastIndex = 3;
	unsigned int result;
	while (1) {	

		for (int i = lastIndex + 1; i <= lastIndex + count; i++){
			f.push_back(f[i-1] + (count+1));
			if (f[f.size()-1] >= n) {
				result = f.size()-1; 
				break;
			}
		}
		if (f[f.size()-1] >= n) {
			break;
		}
		lastIndex += count; 
		count++;
	}

	cout << result;
}