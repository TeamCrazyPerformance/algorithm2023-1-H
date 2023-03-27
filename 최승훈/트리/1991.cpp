#include <iostream>
using namespace std;
pair<char, char> arr[26];
int N;
void preorder(char x)
{
	// 전위 부모 -> 왼쪽 -> 오른쪽
	if (x != '.')
	{
		cout << x;
		preorder(arr[x - 'A'].first);
		preorder(arr[x - 'A'].second);
	}
}

void inorder(char x)
{
	// 중위 왼쪽 -> 부모 -> 오른쪽
	if (x != '.')
	{
		inorder(arr[x - 'A'].first);
		cout << x;
		inorder(arr[x - 'A'].second);
	}
}
void postorder(char x)
{
	// 후위 왼쪽 -> 오른쪽 -> 부모
	if (x != '.')
	{
		postorder(arr[x - 'A'].first);
		postorder(arr[x - 'A'].second);
		cout << x;
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		// 부모, 왼쪽 자식 노드, 오른쪽 자식 노드
		char parent, left, right;
		cin >> parent >> left >> right;

		arr[(parent - 'A')].first = left;
		arr[(parent - 'A')].second = right;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}
