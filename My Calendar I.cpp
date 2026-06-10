class MyCalendar {
    map<int, int> mp;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        auto it = mp.lower_bound(startTime);
        if (it != mp.end() && it->first < endTime)   return false;
        if (it != mp.begin() && prev(it)->second > startTime)    return false;
        mp[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */