#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minAddToMakeValid(string s) {
        int cnt = 0, res = 0;
        for (char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')' && cnt == 0)
                res++;
            else if (c == ')')
                cnt--;
        }
        return res + cnt;
    }
};