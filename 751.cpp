#include<iostream>
#include<string>
#include <locale>
#include <algorithm>
using namespace std;
int stack[1000];
static int top = -1;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	return stack[top--];
}


int main()
{
	char input[1000];
	int result[1000];
	int i = 0;
	int j = 0;
	int a, b, c, d;
	string s;
	
	getline(cin, s);
	while (s!="") {

		*std::remove_copy(s.begin(), s.end(), input, ' ') = 0;



		for (int i = 0; input[i] != '\0'; i++)
		{

			if (input[i] >= '0' && input[i] <= '9')
			{
				d = input[i] - 48;
				push(d);
			}
			else
			{
				a = pop();
				b = pop();
				switch (input[i])
				{
				case '+':
				{
					c = a + b;
					break;
				}
				case '-':
				{
					c = b - a;
					break;
				}
				case '*':
				{
					c = a * b;
					break;
				}
				case '/':
				{
					c = b / a;
					break;
				}
				}
				push(c);
			}

		}

		result[i]= pop();
		i++;
		getline(cin, s);
		
	}
	for (int j = 0; j < i; j++) {
		cout << result[j] << endl;
	}
	return 0;

}