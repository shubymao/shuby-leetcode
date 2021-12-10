#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int lCount[26] = {0};
        for(auto c: licensePlate){
            if(c<='Z' && c>='A')
               lCount[c-'A']++; 
            else if(c<='z' && c>='a')
               lCount[c-'a']++;
        }
        string res = "\t";
        for(auto word : words){
            int wordCount[26] = {0};
            for(auto c: word){
                wordCount[c-'a']++;
            }
            bool valid = true;
            for(auto i = 0 ; i < 26 ; i++){
                if(wordCount[i] < lCount[i]){
                    valid = false;
                    break;
                }
            }
            if(valid && (res == "\t" || word.size() < res.size())){
                res = word;
            }
        }
        return res;
    }
};