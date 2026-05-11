//Approach: Easy Simulation
//T.C: O(NlogM) , N = nums.size() & logM is the number of digits in numbers
//SC: O(NlogM)
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (auto& num : nums) {
            vector<int> digits;
            
            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }

            for (int i = digits.size() - 1; i >= 0; i--) {
                result.push_back(digits[i]);
            }
        }

        return result;
    }
};