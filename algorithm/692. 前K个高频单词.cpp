struct W {
    string word ;
    int time ;
} ;

bool operator < (const  W& A , const  W& B) {
    if (A.time != B.time) {
        return A.time > B.time ;
    }
    return A.word < B.word ;
}
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hashWords ;
        for (int i = 0 ; i < words.size() ; ++i) {
            hashWords[words[i]]++ ;
        }
        unordered_map<string,int>::iterator it ;
        vector<W> newWords ;
        for (it = hashWords.begin() ; it != hashWords.end() ; ++it) {
            newWords.push_back({it->first , it->second}) ;
        }
        priority_queue<W> heap ;
        for (int i = 0 ; i < k ; ++i) {
            heap.push(newWords[i]) ;
        }
        for (int i = k ; i < newWords.size() ; ++i) {
            W tmp = heap.top() ;
            heap.pop() ;
            //cout << tmp << ""
            if (newWords[i] < tmp) {
                heap.push(newWords[i]) ;
            } else heap.push(tmp) ;
        }
        vector<string> res(k) ;
        for (int i = k - 1 ; i >= 0 ; --i) {
            res[i] = heap.top().word ;
            heap.pop() ;
        }
        return res ;
    }
};