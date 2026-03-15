//T.C: O(log(M)) , for Binary Exponentiation power(mult, M-2)
//S.C: O(1)
class Fancy {
public:

    typedef long long ll;

    ll M = 1e9+7;

    vector<ll> seq;

    ll add = 0;

    ll mult = -1;

    ll power(ll a, ll b) {
        if(b == 0) return 1;

        ll half = power(a, b/2);

        ll result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    Fancy() {
        
    }
    
    void append(int val) {
        ll x = ((val - add) % M + M) * power(mult, M-2) % M;
        
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        mult = (mult * m) % M;

        add = (add * m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size()) return -1;

        return (seq[idx] * mult + add) % M;
    }
};