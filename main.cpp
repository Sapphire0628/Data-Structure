#include <iostream>
using namespace std;

int search(int s[], int x, int m)
{
	for (int i = 0; i < m; i++)
		if (s[i] == x)
			return i;
	return -1;
}

void postOrder(int inorder[], int preorder[], int n,int N)
{
	int root = search(inorder, preorder[0], n);
	if (root != 0) {
		postOrder(inorder, preorder + 1, root,N);
	}
	if (root != n - 1)
		postOrder(inorder + root + 1, preorder + root + 1, n - root - 1,N);
	cout << preorder[0];
	if (n != N) { cout << " "; }
}

int main()
{
	int *inorder, *preorder, n, N;
	int i = 0, num;
	cin >> num;

	while (num > 0) {
		cin >> n;
		N = n;
		inorder = new int[n];
		preorder = new int[n];

		for (i = 0; i < n; i++)
		{
			cin >> preorder[i];
		}
		for (i = 0; i < n; i++)
		{
			cin >> inorder[i];
		}
		postOrder(inorder, preorder, n, N); 
		cout << endl;
		num--;
	}
	return 0;
}