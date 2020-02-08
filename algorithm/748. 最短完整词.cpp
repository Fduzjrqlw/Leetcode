class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<int,int> mp ;
        int n = words.size() ;
        for (int i = 0 ; i < licensePlate.length() ; ++i) {
            if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') {
                mp[licensePlate[i] - 'A']++ ;
            }
            if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
                mp[licensePlate[i] - 'a']++ ;
            }
        }
        int res = -1 ;
        for (int i = 0 ; i < words.size() ; ++i) {
            unordered_map<int,int> newmp ;
            for (int j = 0 ; j < words[i].length() ; ++j) {
                if (words[i][j] >= 'A' && words[i][j] <= 'Z') {
                    newmp[words[i][j] - 'A']++ ;
                }
                if (words[i][j] >= 'a' && words[i][j] <= 'z') {
                    newmp[words[i][j] - 'a']++ ;
                }
            }
            bool less = true ;
            for (auto key : mp) {
                if (key.second > newmp[key.first]) {
                    less = false ;
                    break ;
                }
            }
            if (less) {
                if (res == -1) {
                    res = i ;
                } else if (words[i].length() < words[res].length()) {
                    res = i ;
                }
            }
        }
        return words[res] ;
    }
};