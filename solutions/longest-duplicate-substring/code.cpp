#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

class Solution {
   public:
    int check(string& s, int len) {
        if (len >= s.size()) return -1;
        unordered_set<ULL> seen;
        ULL hashcode = 0;
        for (int i = 0; i < s.size(); i++) {
            hashcode = hashcode * PRIME_BASE + s[i];
            if (i >= len) {
                hashcode -= power[len] * s[i - len];
            }
            if (i >= len - 1) {
                if (seen.find(hashcode) != seen.end()) return i - len + 1;
                seen.insert(hashcode);
            }
        }
        return -1;
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        power.resize(n, 1);
        for (int i = 1; i < n; i++) {
            // ULL overflow will simply disgard result exceeding nums
            power[i] = power[i - 1] * PRIME_BASE;
        }
        int l = 0, r = n - 1, bestInd = 0;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            int ind = check(s, mid);
            if (ind != -1) {
                l = mid;
                bestInd = ind;
            } else {
                r = mid - 1;
            }
        }
        return s.substr(bestInd, l);
    }

   private:
    vector<ULL> power;
    int PRIME_BASE = 131;
};