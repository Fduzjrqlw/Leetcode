class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        int res= 0 ;
        unordered_map<string,int> mp ;
        for (int i = 0 ; i < words.size() ; ++i) {
            string t = "" ;
            for (int j = 0 ; j < words[i].length() ; ++j) {
                t += dict[words[i][j] - 'a'] ;
            }
            if (mp.find(t) == mp.end()) {
                mp[t] = 1 ;
                ++res ;
            }
        }
        return res ;
    }
};