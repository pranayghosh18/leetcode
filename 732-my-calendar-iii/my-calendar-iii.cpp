
class MyCalendarThree {
public:
map<int,int> eventsCount;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        eventsCount[startTime]++;
        eventsCount[endTime]--;
        int events(0), maxEvents(0);
        for(auto it:eventsCount) events += it.second, maxEvents=max(maxEvents, events);
        return maxEvents;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */