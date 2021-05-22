#include <iostream> 
#include <iterator> 
#include <set> 

using namespace std;

int main(void)
{
	set<int, greater<int> > s1;
	set<int> s2;
	int k, n;
	int i = 1;

	cin >> k;
	s1.insert(0);
	s1.insert(k + 1);
	s2.insert(0);
	s2.insert(k + 1);
	while (i <= k) {
		cin >> n;
		s1.insert(n);
		s2.insert(n);
		cout<<*s1.upper_bound(n)<<" ";
		cout<<*s2.upper_bound(n)<<endl;
		i++;
	}
	

	return 0;
}