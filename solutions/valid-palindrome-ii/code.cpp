#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validPalindrome(string s) { return check(s, 0, s.size() - 1, 1); }

    bool check(string& s, int left, int right, int remainDeletion) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (remainDeletion > 0) {
                    remainDeletion--;
                    bool delLeft = check(s, left + 1, right, remainDeletion);
                    bool delRight = check(s, left, right - 1, remainDeletion);
                    return delLeft || delRight;
                } else {
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
};