#include<string>
#include<map>
#include<iostream>
#include<bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;


// need to look at every i window of elements
int sherlockAndAnagrams(string s) {
    map<string, int> counts;
    bool finished = false;
    int matches = 0;
    
    for (int i = 0; i < s.size(); i++)
            for (int j = 1; i+j <= s.size(); j++) {
                string s2 = s.substr(i, j);
                cout << "Substring: " << s2 << endl;
                sort(s2.begin(), s2.end());
                counts[s2]++;
            }

    for (map<string, int>::iterator it = counts.begin(); it != counts.end(); it++){
        cout << "It second: " << it->second << " Weird division: " << (it->second - 1)/2 << " total: "<< it->second * (it->second - 1)/2 << endl;  
        matches += it->second * (it->second - 1)/2;
    }
            
    cout << "Found matches: " << matches << endl;
} 

int toNum(char c){
    return (c - 'a');
}

int sherlockAnagrams(string s){
    int N = s.length();

    map<vector<int>, int> mp;

    for(int i = 0; i < N; i++){
        vector<int> freq(MAX_CHAR, 0);

        for(int j = i; j< N; j++){
            freq[toNum(s[j])]++;

            cout << "Frequency: " << freq[toNum(s[j])] << "For char: " << s[j] << endl;

            mp[freq]++;
        }
    }

    int matches = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        int freq = it->second;
        matches += ((freq) * (freq-1))/2;
    }

    cout << "Matches: " << matches << endl;
    return matches;
}
// c, c
// d, d
// cd, dc
// dc, cd

int main(){

    sherlockAnagrams("cdcd");
    return 0;
}