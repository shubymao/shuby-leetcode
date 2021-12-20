#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dayOfYear(string date) {
        vector<int> dayCnt = {0,  31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            // leap year
            dayCnt[2] = 29;
        }
        return calculateDay(dayCnt, month, day);
    }

    int calculateDay(vector<int>& dayCnt, int month, int day) {
        int days = 0;
        for (int i = 1; i < month; i++) {
            days += dayCnt[i];
        }
        days += day;
        return days;
    }
};