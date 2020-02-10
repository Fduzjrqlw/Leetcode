class WordFilter {
public:

    struct TrieNode {
        TrieNode *ch[26] ;
        int weight ;
    } ;
    unordered_map<string,TrieNode*> rootMap ;

    void update(string s , int w , string word) {
        if (rootMap.find(s) == rootMap.end()) {
            rootMap[s] = new TrieNode() ;
            rootMap[s]->weight = -1 ;
        }
        
        TrieNode *root = rootMap[s] ;
        root->weight = max(root->weight , w) ;
        for (int i = word.length() - 1 ; i >= 0 ; --i) {
            if (root->ch[word[i] - 'a'] == NULL) {
                root->ch[word[i] - 'a'] = new TrieNode() ;
                root->ch[word[i] - 'a']->weight = -1 ;
            }
            root = root->ch[word[i] - 'a'] ;
            root->weight = max(root->weight , w) ;
        }
        return ;
    }

    WordFilter(vector<string>& words) {
        rootMap.clear() ;
        for (int i = 0 ; i < words.size() ; ++i) {
            string temp = "" ;
            update("$" , i , words[i]) ;
            for (int j = 0 ; j < words[i].length() ; ++j) {
                temp += words[i][j] ;
                update(temp , i , words[i]) ;
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if (prefix.length() == 0) {
            prefix = "$" ;
        }
        if (rootMap.find(prefix) == rootMap.end()) {
            return -1 ;
        }
        TrieNode *root = rootMap[prefix] ;
        for (int i = suffix.length() - 1 ; i >= 0 ; --i) {
            if (root->ch[suffix[i] - 'a'] == NULL) {
                return -1 ;
            }
            root = root->ch[suffix[i] - 'a'] ;
        }
        return root->weight ;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */