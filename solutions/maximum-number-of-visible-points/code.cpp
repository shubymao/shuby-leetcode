#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    double PI = 3.141592653589793238463;

   public:
    int visiblePoints(vector<vector<int>>& points, int angle,
                      vector<int>& loc) {
        vector<double> angles = getPointsAngles(points, loc);
        int atOrigin = points.size() - angles.size(), n = angles.size();
        if (n == 0) return atOrigin;
        int view = 1;
        for (int i = n - 1; i > 0; i--) {
            if (diff(angles[0], angles[i]) <= angle)
                view++;
            else
                break;
        }
        int res = view;
        for (int i = 1; i < n; i++) {
            if (view == n) break;
            while (diff(angles[i], angles[(i - view + n) % n]) > angle) view--;
            view++;
            res = max(res, view);
        }
        return res + atOrigin;
    }

    double diff(double a1, double a2) {
        if (a1 >= a2) return a1 - a2;
        return a1 + 360 - a2;
    }

    vector<double> getPointsAngles(vector<vector<int>>& points,
                                   vector<int> loc) {
        vector<double> angles;
        for (auto pLoc : points) {
            if (pLoc[0] != loc[0] || pLoc[1] != loc[1]) {
                double radian = atan2(pLoc[1] - loc[1], pLoc[0] - loc[0]);
                double angle = radian * 180.0 / PI;
                if (angle < 0) angle += 360.0;
                angles.push_back(angle);
            }
        }
        sort(angles.begin(), angles.end());
        return angles;
    }
};