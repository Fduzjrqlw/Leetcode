class Solution {
public:

    struct sticker {
        unordered_map<char,int> count ;
    } ;

    //由于target的长度更小，因此考虑对于target str进行搜索，注意加上记忆化
    int dfs(string target , unordered_map<string,int>& memo , vector<sticker>& st) {
        if (memo.find(target) != memo.end()) {
            return memo[target] ;
        }
        unordered_map<char,int> cnt ;
        for (int i = 0 ; i < target.length() ; ++i) {
            cnt[target[i]]++ ;
        }
        int res = INT_MAX ;
        for (int i = 0 ; i < st.size() ; ++i) {
            //一个略有效的剪枝
            if (st[i].count[target[0]] == 0) {
                continue ;
            }
            string newTarget = "" ;
            for (auto v : cnt) {
                if (v.second - st[i].count[v.first] > 0) {
                    newTarget += string(v.second - st[i].count[v.first] , v.first) ;
                }
            }
            int temp = dfs(newTarget , memo , st) ;
            if (temp != -1) {
                res = min(res , temp + 1) ;
            }
        }
        memo[target] = (res == INT_MAX ? -1 : res) ;
        return memo[target] ;
    }

    int minStickers(vector<string>& stickers, string target) {
        vector<sticker> st , tempSt , finalSt;
        unordered_map<char,int> cnt ;
        for (int i = 0 ; i < target.size() ; ++i) {
            cnt[target[i]]++ ;
        }
        for (int i = 0 ; i < stickers.size() ; ++i) {
            sticker temp ;
            for (int j = 0 ; j < stickers[i].length() ; ++j) {
                if (cnt.find(stickers[i][j]) != cnt.end())
                    temp.count[stickers[i][j]]++ ;
            }
            st.push_back(temp) ;
        }
        //在偏序下只保留最优的
        for (int i = 0 ; i < st.size() ; ++i) {
            bool save = true ;
            for (int j = 0 ; j < st.size() ; ++j) {
                if (i != j) {
                    bool equal = true ;
                    for (auto v : cnt) {
                        if (st[i].count[v.first] >= st[j].count[v.first]) {
                            equal = false ;
                            break ;
                        }
                    }
                    if (equal) {
                        save = false ;
                        break ;
                    }
                }
            }
            if (save) {
                tempSt.push_back(st[i]) ;
            }
        }
        //去掉相同的部分
        for (int i = 0 ; i < tempSt.size() ; ++i) {
            bool save = true ;
            for (int j = 0 ; j < i ; ++j) {
                bool equal = true ;
                for (auto v : cnt) {
                    if (tempSt[i].count[v.first] != tempSt[j].count[v.first]) {
                        equal = false ;
                        break ;
                    }
                }
                if (equal) {
                    save = false ;
                    break ;
                }
            }
            if (save) {
                finalSt.push_back(tempSt[i]) ;
            }
        }
        for (auto v : cnt) {
            int t = 0 ;
            for (int i = 0 ; i < st.size() ; ++i) {
                t += st[i].count[v.first] ;
            }
            if (t == 0) {
                return -1 ;
            }
        }
        unordered_map<string,int> memo ;
        memo[""] = 0 ;
        return dfs(target , memo , finalSt) ;
    }
};