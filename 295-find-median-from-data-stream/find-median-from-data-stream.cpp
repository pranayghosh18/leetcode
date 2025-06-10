class MedianFinder {
public:
    multiset<int> minHeapOfMaxElemets;
    multiset<int, greater<int>> maxHeapOfSmallerElements;
    MedianFinder() {
        
    }

    void adjust(){
        if(minHeapOfMaxElemets.empty() || maxHeapOfSmallerElements.empty()) return;
        int minLargeValue = *minHeapOfMaxElemets.begin();
        int maxSmallValue = *maxHeapOfSmallerElements.begin();
        if(minLargeValue < maxSmallValue){
            minHeapOfMaxElemets.erase(minHeapOfMaxElemets.begin());
            maxHeapOfSmallerElements.erase(maxHeapOfSmallerElements.begin());

            minHeapOfMaxElemets.insert(maxSmallValue);
            maxHeapOfSmallerElements.insert(minLargeValue);
        }
    }

    void addNum(int num) {
        if(minHeapOfMaxElemets.size() == maxHeapOfSmallerElements.size()){
            minHeapOfMaxElemets.insert(num);
            adjust();
        }
        else{
            maxHeapOfSmallerElements.insert(num);
            adjust();
        }
    }
    
    double findMedian() {
        int minLargeValue = minHeapOfMaxElemets.empty() ? 0 : *minHeapOfMaxElemets.begin();
        int maxSmallValue = maxHeapOfSmallerElements.empty() ? 0 : *maxHeapOfSmallerElements.begin();
        if(minHeapOfMaxElemets.size() == maxHeapOfSmallerElements.size()){
            return double(minLargeValue + maxSmallValue)/2;
        }
        return double(minLargeValue);
    }
};