#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(const int& a, const int& b) const { return a < b; }
};

class Solution {
   public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int, Compare> appleTable;
        int cnt = 0;
        for (int i = 0; i < apples.size(); i++) {
            appleTable[i + days[i]] += apples[i];
            if (eat(appleTable, i)) cnt++;
        }
        int day = apples.size();
        while (!appleTable.empty()) {
            if (appleTable.begin()->first > day) {
                int eat = min(appleTable.begin()->first - day,
                              appleTable.begin()->second);
                cnt += eat;
                day += eat;
            }
            appleTable.erase(appleTable.begin()->first);
        }
        return cnt;
    }

    bool eat(map<int, int, Compare>& appleTable, int day) {
        while (!appleTable.empty() && (appleTable.begin()->first <= day ||
                                       appleTable.begin()->second <= 0)) {
            appleTable.erase(appleTable.begin()->first);
        }
        if (appleTable.empty()) return false;
        appleTable[appleTable.begin()->first]--;
        return true;
    }
};