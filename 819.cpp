#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class joseph_ring
{
private:
	int n;
	int m;
	Node *head;
public:
	joseph_ring(int nn, int mm);
	~joseph_ring();
	void show();
};

joseph_ring::joseph_ring(int nn, int mm)
{
	n = nn;
	m = mm;
	Node *p1 = NULL;
	Node *p2 = NULL;
	for (int i = 1; i <= n; i++)
	{
		p1 = new Node;
		p1->data = i;
		if (i == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p2->next = head;
	}


}

joseph_ring::~joseph_ring()
{
	delete head;
	head = NULL;
}

void joseph_ring::show()
{
	if (n <= 0 || m > 10000) {
		return;
	}

	Node *p1 = NULL;
	Node *p2 = NULL;
	Node *p = NULL;
	int count;
	p1 = head;
	for (int i = 1; i <= n-1; i++)
	{
		count = 1;
		while (count < m)
		{
			p2 = p1;
			p1 = p1->next;
			count++;
		}
		cout << p1->data << " ";
		p = p1;
		p2->next = p1->next;
		p1 = p1->next;

	}
	cout << p1->data << endl;

	head = p1;
}

int main()
{

	int n, m;
	while (cin >> n >> m) {
		joseph_ring j(n, m);
		j.show();

	}


}