#include <iostream>
#include <vector>
using namespace std; 

int main()
{
	vector<unsigned int> fx; 
  	
  	fx.push_back(0); 
  	fx.push_back(1); 
  	fx.push_back(2); 
  	fx.push_back(5); 
  	unsigned int n;
  	cin >> n;

	int result;
  	int count = 2;
  	int lastIndex = 3;

  	if (n == 1) result = 1;
  	else if (n == 2 || n == 3) result = 2;
  	else if (n == 4 || n == 5) result = 3; 
  	else {
  		for (int i = 3; i <= n; i++) {
	  		if (fx[fx.size()-1] >= n) break;
	  		
	  		for (int j = lastIndex + 1; j <= lastIndex+count; j++) {
	  			fx.push_back(fx[fx.size()-1] + (count + 1));
	  			cout << "fx: " << fx[fx.size()-1] << "\n";
	  			cout << "count: " << count + 1 << "\n";
	  			if (fx[fx.size()-1] >= n) {
	  				result = j;
	  				break;
	  			} 
	  		}
	  		lastIndex += count;
	  		count++;
	  	}
	}
  	cout << result;
}