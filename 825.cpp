#include <iostream>
#include <queue>
#include <iterator> 
#include <unordered_map>
using namespace std;

int main() {
	queue<int> q1;
	queue<int> q2;
	queue<int> q3;
	queue<int> q4;
	unordered_map<int, int> nation_n;



	int N;
	int n, m, nation;
	int temp;
	int E = 0;
	cin >> N;
	int Size = N;
	while (N--) {
		cin >> n >> m;
		q1.push(n);
		q2.push(m);
		while (m--) {
			cin >> nation;
			q3.push(nation);
			if (nation_n.find(nation) == nation_n.end()) {
				nation_n[nation] = 1;
			}
			else {
				auto itr = nation_n.find(nation);
				temp = itr->second + 1;
				nation_n[nation] = temp;
			}
		}

		while (((q1.back()) - (q1.front())) >= 86400) {
			q1.pop();
			for (int i = 0; i < q2.front(); i++) {
				auto itr = nation_n.find(q3.front());
				temp = itr->second - 1;
				if (temp > 0) {
					nation_n[q3.front()] = temp;
				}
				else { nation_n.erase(q3.front()); }
				q3.pop();
			}
			q2.pop();
		}
		q4.push(nation_n.size());
		
	}
	for (int i = 0; i < Size; i++) {
		cout << q4.front() << endl;
		q4.pop();
	}
	return 0;

}