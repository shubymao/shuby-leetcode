#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start); visited[start]=true;
        while(q.size()){
            int pos = q.front(); q.pop();
            if(arr[pos] == 0)return true;
            int left = pos + arr[pos];
            if(left < visited.size() && !visited[left]){
                visited[left] = true;
                q.push(left);
            }
            int right = pos - arr[pos];
            if(right >= 0 && !visited[right]){
                visited[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};