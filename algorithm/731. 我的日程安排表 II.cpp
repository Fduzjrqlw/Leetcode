class MyCalendarTwo {
public:
    vector<pair<int,int>> calendars ;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (int i = 0 ; i < calendars.size() ; ++i) {
            if (calendars[i].second > start) {
                if (calendars[i].first < end) {
                    int s = max(start , calendars[i].first) ;
                    int e = min(end , calendars[i].second) ;
                    for (int j = 0 ; j < i ; ++j) {
                        if (calendars[j].second > s) {
                            if (calendars[j].first < e) {
                                return false ;
                            }
                        }
                    }
                }
            }
        }
        calendars.push_back(make_pair(start , end)) ;
        return true ;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */