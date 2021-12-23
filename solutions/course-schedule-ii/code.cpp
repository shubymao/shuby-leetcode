#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> requirements(numCourses);
        for (auto prereq : prerequisites) {
            requirements[prereq[0]].push_back(prereq[1]);
        }
        // 0 mean unvisited, 1 within traverse path, 2 completed
        vector<int> res, state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            bool valid = dfs(requirements, state, res, i);
            if (!valid) return vector<int>();
        }
        return res;
    }

    bool dfs(vector<vector<int>>& reqs, vector<int>& state, vector<int>& res,
             int course) {
        if (state[course] == 2) return true;
        if (state[course] == 1) return false;  // loops, indicate invalid
        state[course] = 1;
        for (auto req : reqs[course]) {
            bool valid = dfs(reqs, state, res, req);
            if (!valid) return false;
        }
        state[course] = 2;
        res.push_back(course);
        return true;
    }
};