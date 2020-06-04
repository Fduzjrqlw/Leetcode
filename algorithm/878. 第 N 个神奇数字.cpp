class Solution {
public:

    typedef long long ll ;
    const ll module = 1e9 + 7ll ;

    ll gcd(ll x , ll y) {
        if (x % y == 0)
            return y ;
        return gcd(y , x % y) ;
    }

    int nthMagicalNumber(int N, int A, int B) {
        ll d = gcd(1ll * A , 1ll * B) ;
        ll lcm = (ll)A / d * (ll)B  ;
        ll x = lcm / A , y = lcm / B ;
        if (A == B) {
            ll res = (ll) A * (ll) N % module ;
            return res ;
        }

        ll res = 0ll ;
        ll n = x + y - 1 ;
        ll t = (ll) N / n  ;

        lcm %= module ;
        
        if (N % n == 0) {
            res = (ll) t * (ll) lcm % module ;
            return res ;
        }
        res = (ll) t * (ll) lcm % module ;
        vector<ll> nums ;
        for (ll i = 1 ; i <= x ; ++i) {
            nums.push_back(i * A) ;
        }
        for (ll i = 1 ; i <= y ; ++i) {
            nums.push_back(i * B) ;
        }
        sort(nums.begin() , nums.end()) ;
        res = (res + nums[N % n - 1] % module) % module ;
        return res ; 
    }
};