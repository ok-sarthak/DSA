//T.C: O(length) = O(n)
//S.C: O(1)
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(begin(n), end(n)) - '0';
    }
};