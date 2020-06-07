class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size() ;
        sort(people.begin() , people.end()) ;
        int res = 0 , p = 0 ;
        for (int i = n - 1 ; i >= p ; --i) {
            if (i == p) {
                ++res ;
                break ;
            }
            if (people[i] + people[p] <= limit) {
                ++p ;
                ++res ;
            } else {
                ++res ;
            }
        }
        return res ;
    }
};