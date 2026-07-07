class Solution {
public:
    typedef long long ll;

    ll sumAndMultiply(int n) {
        ll x   = 0;
        ll sum = 0;

        for(char &ch : to_string(n)) {
            if(ch != '0') {
                sum += ch - '0';
                x = x*10 + (ch - '0');
            }
        }

        return x * sum;

    }
};