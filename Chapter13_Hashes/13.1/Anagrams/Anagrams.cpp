#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void Anagrams(const vector<string>& words, vector<vector<string> >& groups){
  //Create hash on sorted strings.
  unordered_map<string,vector<string> > sorted_string_to_anagrams;
  //Insert string to hash.
  for (int i = 0; i < words.size(); i++){
    string sorted_string(words[i]);
    sort(sorted_string.begin(),sorted_string.end());
    sorted_string_to_anagrams[sorted_string].emplace_back(words[i]);
  }
  //Insert hash content into results.
  for (const pair<string, vector<string> >& p : sorted_string_to_anagrams){    
    //emplace the string groups (instead of strings 1 by 1) to result
    groups.emplace_back(p.second);
  }
}

int main(){
  vector<string> words = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis", "money"};
  vector<vector<string> > groups;
  Anagrams(words, groups);
  for (int i = 0; i < groups.size(); i++){
    for (int j = 0; j < groups[i].size(); j++){
      cout<<groups[i][j]<<"\t";
    }
    cout<<endl;
  }
}
