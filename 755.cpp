#include<iostream>
#include<stack>
using namespace std;

long long int stock_market(int histogram_area[], int n)
{
	stack<int> stack;
	long long int maxArea = 0, small;
	int Top;
	int i = 0;

	while (i < n)
	{
		if (stack.empty() || histogram_area[stack.top()] <= histogram_area[i]) {
			stack.push(i++);
		}
		else
		{
			Top = stack.top();
			stack.pop();

			if (stack.empty())
			{
				small = (long long int)histogram_area[Top] * i;
			}
			else
			{
				small = (long long int)histogram_area[Top] * (i - stack.top() - 1);
			}
			if (maxArea < small)
				maxArea = small;
		}
	}

	while (stack.empty() == false)
	{
		Top = stack.top();
		stack.pop();
		if (stack.empty())
		{
			small = (long long int)histogram_area[Top] * i;
		}
		else
		{
			small = (long long int)histogram_area[Top] * (i - stack.top() - 1);
		}

		if (maxArea < small)
			maxArea = small;
	}

	return maxArea;
}

int main()
{
	long long int c;
	int t;
	int t_2;
	long long int result[100000];
	int j = 0;

	cin >> t;
	t_2 = t;
	if (t < 1 && t>10) {
		return 0;
	}
	while (t--)
	{
		int size;
		cin >> size;
		int data[100000];
		if (size < 1 && size>100000) {
			return 0;
		}
		for (int i = 0; i < size; i++)
		{
			cin >> data[i];
		}
		c = stock_market(data, size);
		result[j] = c;
		j++;
	}

	for (int x = 0; x < t_2; x++) {
		cout << (long long int)result[x] <<endl;
	}
	return 0;
}