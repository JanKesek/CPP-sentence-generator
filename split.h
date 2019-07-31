#include <vector>
#include <iostream>
#include <map>
using std::vector;
using std::string;
using std::map;
using std::cin;
using std::cout;

void countDistinctWords() {
    string s;
    map<string,int> counters;
    while(cin>>s && cin.get()!='\n') ++counters[s];
    for(map<string,int>::const_iterator iter=counters.begin();
        iter!=counters.end();iter++) {
            cout<<iter->first<<"\t"<<iter->second<<"\n";
        }
}
vector<string> split(string& s) {
    vector<string> ret;
    typedef string::size_type strSize;
    strSize i =0;
    while(i!=s.size()) {
        while (i!=s.size() && isspace(s[i])) ++i;
        strSize j = i;
        while (j!=s.size() && !isspace(s[j])) j++;
        if(i!=j) {
            ret.push_back(s.substr(i,j-i));
            i=j;
        }
    }
    return ret;
}
