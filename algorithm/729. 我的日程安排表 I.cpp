class MyCalendar {
public:

    map<int,int> tree ;

    MyCalendar() {
        ;
    }
    
    bool book(int start, int end) {
        auto it = tree.upper_bound(start) ;
        if (it == tree.end()) {
            tree[end] = start ;
            return true ;
        }
        if (end <= it->second) {
            tree[end] = start ;
            return true ;
        }
        return false ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */