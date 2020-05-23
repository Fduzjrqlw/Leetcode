class Solution {
public:

    int res = 0 , op = 0 ;

    struct TrieNode {
        TrieNode *ch[26] ;
        int tag ;
    } ;

    void insert(TrieNode *root , string& word) {
        TrieNode *pt = root ;
        int l = 0 ;
        for (int i = word.length() - 1 ; i >= 0 ; --i) {
            ++l ;
            if (pt->ch[word[i] - 'a'] == NULL) {
                pt->ch[word[i] - 'a'] = new TrieNode() ;
            }
            pt = pt->ch[word[i] - 'a'] ;
            if (pt->tag == 1) {
                res -= l ;
                pt->tag = 0 ;
                --op ;
            }
        }
        pt->tag = 1 ;
        res += l ;
        ++op ;
        return ;
    }

    static bool cmp(const string &a , const string &b) {
        return a.length() < b.length() ;
    }

    int minimumLengthEncoding(vector<string>& words) {

        TrieNode *root = new TrieNode() ;

        sort(words.begin() , words.end() , cmp) ;

        for (int i = 0 ; i < words.size() ; ++i) {
            insert(root , words[i]) ;
        }
        
        return res + op ;
    }
};