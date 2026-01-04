class Solution {
public:
    int findSum(int num) {
        int divisors = 0; //divisor count
        int sum = 0; //sum of divisors

        for(int fact = 1; fact*fact <= num; fact++) { //sqrt(num) = fact*fact
            if(num % fact == 0) {
                int otherFact = num/fact;

                if(otherFact == fact) { //perfect square
                    divisors += 1;
                    sum += fact;
                }
                else {
                    divisors += 2;
                    sum += (fact + otherFact);
                }
            }
            if(divisors > 4)
                return 0; //invalid case
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for(int &num: nums) {
            result += findSum(num); //O(N * sqrt(num)), O(1)
        }

        return result;
    }
};