#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0, remainingEmpty = 0;
        while (numBottles != 0) {
            drink += numBottles;
            remainingEmpty = numBottles + remainingEmpty;
            numBottles = remainingEmpty / numExchange;
            remainingEmpty = remainingEmpty % numExchange;
        }
        return drink;
    }
};