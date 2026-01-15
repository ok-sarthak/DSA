// T.C: O(n log n + n + m log m + m) = O(n log n + m log m)
// S.C: O(1)
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutiveWidth = 1;
        int maxConsecutiveHeight = 1;

        int consecutiveWidth = 1;
        int consecutiveHeight = 1;

        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                consecutiveWidth++;
            } else {
                consecutiveWidth = 1;
            }
            maxConsecutiveWidth = max(maxConsecutiveWidth, consecutiveWidth);
        }

        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                consecutiveHeight++;
            }
            else {
                consecutiveHeight = 1;
            }
            maxConsecutiveHeight = max(maxConsecutiveHeight, consecutiveHeight);
        }

        int length = min(maxConsecutiveHeight, maxConsecutiveWidth) + 1;
        return length * length;
    }
};