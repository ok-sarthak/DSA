class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int result = 37;

        for(int num : nums) {
            int s = digitSum(num);

            result = min(result, s);
        }

        return result;
    }
};