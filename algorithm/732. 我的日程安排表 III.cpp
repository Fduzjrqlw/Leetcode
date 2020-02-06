class MyCalendarThree {
public:
    map<int,int> delta ;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        delta[start]++ ;
        delta[end]-- ;
        int cnt = 0 , res = 0 ;
        for (auto it = delta.begin() ; it != delta.end() ; ++it) {
            cnt += it->second ;
            res = max(res , cnt) ;
        }
        return res ;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */