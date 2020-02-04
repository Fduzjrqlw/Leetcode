class RangeModule {
public:

    map<int,int> tree ;
    queue<map<int,int>::iterator> q ;
    
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        for (auto it = tree.lower_bound(left) ; it != tree.end() && it->second <= right ; ++it) {
            q.push(it) ;
        }
        while (!q.empty()) {
            auto it = q.front() ; q.pop() ;
            left = min(left , it->second) ;
            right = max(right , it->first) ;
            tree.erase(it) ;
        }
        tree[right] = left ;
        return ;
    }
    
    bool queryRange(int left, int right) {
        auto it = tree.lower_bound(right) ;
        if (it == tree.end()) {
            return false ;
        }
        if (left >= it->second) {
            return true ;
        }
        return false ;
    }
    
    void removeRange(int left, int right) {
        for (auto it = tree.upper_bound(left) ; it != tree.end() && it->second < right ; ++it) {
            q.push(it) ;
        }
        while (!q.empty()) {
            auto it = q.front() ; q.pop() ;
            int R = it->first , L = it->second ;
            tree.erase(it) ;
            if (R > right) {
                tree[R] = right ;
            }
            if (L < left) {
                tree[left] = L ;
            }
        }
        return ;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */