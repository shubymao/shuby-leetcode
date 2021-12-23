#include <bits/stdc++.h>
using namespace std;

class Compare {
    public:
        bool operator() (vector<int>& a, vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0] * b[0] + b[1] * b[1];
        }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        for(auto& point : points){
            pq.push(point);
            if(pq.size()> k)pq.pop();
        }
        vector<vector<int>> res;
        while(pq.size()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};