#include<bits/stdc++.h>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n,m;
    unordered_map<int,int> map1;
    
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>m;
        map1[m]++;
    }
    for(int i =0;i<n;i++){
        if(map1.find(i)==map1.end()){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0 ;
}