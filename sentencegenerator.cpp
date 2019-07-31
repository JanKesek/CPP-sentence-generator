#include <vector>
#include <string>
#include <map> 
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string,RuleCollection> Grammar;

Grammar readGrammar(ifstream& in) {
    Grammar ret;
    string line;
    
    while (getline(in,line))
    {
        vector<string> entry = split(line);
        if(!entry.empty()) {
            ret[entry[0]].push_back(Rule(entry.begin()+1,entry.end()));
        }
    }
    
    //vector<string> entry=split(line);
    //if(!entry.empty()) ret[entry[0]].push_back(Rule(entry.begin()+1,entry.end()));
    return ret;
    
}
bool isBracketed(const string& s) {
    return s.size() >1 && s[0] =='<' && s[s.size()-1]=='>';
}
int nrand(int n) {
    return rand()%n;
}
void generateFromCategory(const Grammar& g, const string& word, vector<string>& ret) {
    if(!isBracketed(word)) {
        ret.push_back(word);
    }
    else
    {
        Grammar::const_iterator iter = g.find(word);
        if(iter==g.end()) throw logic_error("empty rule");
        const RuleCollection& c = iter->second;
        int randNumb=nrand(c.size());
        //cout<<randNumb<<"\n";
        const Rule& r = c[randNumb];
        for(Rule::const_iterator i=r.begin();i!=r.end();++i) {
            generateFromCategory(g,*i,ret);
        }
    }
    
}

vector<string> generateSentence(const Grammar& g) {
    vector<string> ret;
    generateFromCategory(g,"<sentence>", ret);
    return ret;
}
int main(int argc, char** argv) {
    srand(time(0));
    ifstream infile("testtext3");
    vector<string> sentence = generateSentence(readGrammar(infile));
    vector<string>::const_iterator iter=sentence.begin();
    if(!sentence.empty()) {
        cout<<*iter;
        ++iter;
    }
    while(iter!=sentence.end()) {
        cout<<" "<<*iter;
        ++iter;
    }
    cout<<"\n";
    return 0;
}
