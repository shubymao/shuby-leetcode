#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> richerList(quiet.size());
        for(auto rich : richer){
            richerList[rich[1]].push_back(rich[0]);
        }
        vector<int> res(quiet.size(), -1);
        for(int i = 0 ; i < quiet.size() ; i++){
            dfs(richerList, res, quiet, i);
        }
        return res;
    }

    void dfs(vector<vector<int>>& richerList, vector<int>& res, vector<int>& quiet, int i){
        if(res[i]!=-1)return;
        int candidate = i;
        for(auto next : richerList[i]){
            dfs(richerList, res, quiet, next);
            if(quiet[res[next]] < quiet[candidate]){
                candidate = res[next];
            }
        }
        res[i] = candidate;
    }
};