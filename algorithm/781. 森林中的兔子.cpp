class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> color ;
        if (answers.size() == 0) {
            return 0 ;
        }
        for (int i = 0 ; i < answers.size() ; ++i) {
            color[answers[i] + 1]++ ;
        }
        int res = 0 ;
        for (auto it = color.begin() ; it != color.end() ; ++it) {
            res += it->first * ((it->second - 1)  / it->first + 1) ;
        }
        return res ;
    }
};