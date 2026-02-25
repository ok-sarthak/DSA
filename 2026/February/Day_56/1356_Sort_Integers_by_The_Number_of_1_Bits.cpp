//Approach 1 - Using a custom function countOneBits to count the number of 1 bits in each number. The function uses bitwise operations to count the set bits efficiently. The sorting is done using a lambda function that compares the count of 1 bits and the values of the numbers when the counts are equal.
//T.C: O(n*logn * log(num)) // nlog(n) for sorting and log₂(num) for counting the number of 1 bits in each number
//S.C: O(1) // No extra space is used for sorting, and the countOneBits function uses O(1) space.
class Solution {
public:

    int countOneBits(int num) {
        int count = 0;

        while(num) {
            count += num & 1;

            num >>= 1;
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        auto lambda = [&](int &a, int &b) {
            int count_a = countOneBits(a);
            int count_b = countOneBits(b);

            if(count_a == count_b) {
                return a < b;
            }

            return count_a < count_b;
        };

        sort(begin(arr), end(arr), lambda);

        return arr;
    }
};


//Approach 2 - Using __builtin_popcount function to count the number of 1 bits in each number, which is a built-in function in C++ that counts the number of set bits (1s) in an integer. This function is optimized and runs in O(1) time complexity for counting the bits, making the overall sorting process more efficient.
//T.C: O(n*logn) // nlog(n) for sorting and O(1) for counting the number of 1 bits in each number using __builtin_popcount
//S.C: O(1) // No extra space is used for sorting, and the __builtin_popcount function uses O(1) space.
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        auto lambda = [&](int &a, int &b) {
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);

            if(count_a == count_b) {
                return a < b;
            }

            return count_a < count_b;
        };

        sort(begin(arr), end(arr), lambda);

        return arr;
    }
};