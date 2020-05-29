class Solution {
public:

    struct Cars {
        int p , s ;
    } ;

    static bool cmp(const Cars &A ,  const Cars &B) {
        return A.p > B.p ;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size() , res = 0 ;

        vector<Cars> cars(n) ;

        for (int i = 0 ; i < n ; ++i) {
            cars[i].p = position[i] ;
            cars[i].s = speed[i] ;
        }

        sort(cars.begin() , cars.end() , cmp) ;

        double tmin = target + 100 , tmax = -1.00 ;

        for (int i = 0 ; i < n ; ++i) {
            int d = target - cars[i].p ;
            double t = (d * 1.0) / (1.0 * cars[i].s) ;
            if (t > tmax) {
                ++res ;
                tmax = max(t , tmax) ;
            }
        }
        return res ;

    }
};