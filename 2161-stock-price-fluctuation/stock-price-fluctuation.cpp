
class StockPrice {
    set<pair<int,int>> priceOnTime;
    unordered_map<int,int> timeToPrice;
    int currentPrice;
    int currentTime;
public:
    StockPrice() {
        currentTime = -1;
        currentPrice = -1;
    }
    
    void update(int timestamp, int price) {
        // if exists then need to remove first
        if(timeToPrice.find(timestamp) != timeToPrice.end()){
            pair<int,int> entry = {timeToPrice[timestamp], timestamp};
            auto pos = priceOnTime.find(entry);
            priceOnTime.erase(pos);
        }
        timeToPrice[timestamp] = price;
        priceOnTime.insert({price, timestamp});
        if(timestamp >= currentTime){
            currentTime = timestamp;
            currentPrice = price;
        }
    }
    
    int current() {
        return currentPrice;
    }
    
    int maximum() {
        return priceOnTime.rbegin()->first;
    }
    
    int minimum() {
        return priceOnTime.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */