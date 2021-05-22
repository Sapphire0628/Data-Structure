#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
 
int main()
{   unordered_map<std::string, int> acad_word;
    unordered_map<std::string, int> mark_word;
    unordered_map<std::string, int>::iterator itr;
    std::set<int, greater<int> > index;
    int N;
    string key;
    while(cin>>N){
        while(N--){
            cin>>key;
            acad_word[key]=0;}
        
        int number, temp;
        int len = 0; int size = 0; int rr = 1;
        string list;
        cin>> number;
        
        while(number--){
            cin>>list;
            if (acad_word.find(list)!=acad_word.end()){
                if(mark_word.find(list)==mark_word.end()){
                    mark_word[list]=rr;
                    index.insert(rr);
                    size = mark_word.size();
                    auto max = *index.begin();
			        auto min = *index.rbegin();
			        int distance = max - min +  1;
			        if (distance > len) {len = distance ;}
                }
                else{
                    temp = mark_word.find(list)->second;
                    index.erase(temp);
                    mark_word[list]=rr;
                    index.insert(rr);
                    auto max = *index.begin();
			        auto min = *index.rbegin();
			        int distance = max - min +  1;
                    if (distance < len) {len = distance ;}
                }
            }
            rr++;
        }
    cout <<  size<<endl;
	cout << len << endl;
	acad_word.clear();
	mark_word.clear();
	index.clear();
	
    }
}