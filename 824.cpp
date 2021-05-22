#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
long int C;

int round =1;


while(cin >> n >> C) {
long int count = 0;
long int arr[n];
for(int i = 0; i < n; i++)
cin >> arr[i];
  

unordered_map<long int, int> mp;
for (int i = 0; i < n; i++)
mp[arr[i]]++;
  

for(int i = 0; i < n; i++) {
int num = arr[i] - C;
if(mp.find(num) != mp.end())
count += mp.at(num);
}
cout<<count<<endl;
round++;
}



return 0;
}