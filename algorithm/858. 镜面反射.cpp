class Solution {
public:

    int gcd(int p , int q) {
        if (p % q == 0)
            return q ;
        return gcd(q , p % q) ;
    }

    int mirrorReflection(int p, int q) {
        if (q == 0) {
            return 0 ;
        }
        int d = gcd(p , q) , lcm = p * q / d ;
        int m = lcm / p , n = lcm / q ;
        if (m % 2 == 1) {
            return (2 - n % 2) ;
        }
        return 0 ;
    }
};