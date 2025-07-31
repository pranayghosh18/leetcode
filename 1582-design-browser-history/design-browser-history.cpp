class BrowserHistory {
    vector<string> urls;
    int currentPage;
    int lastPage;
public:
    BrowserHistory(string homepage) {
        urls.resize(101);
        currentPage = lastPage = 0;
        urls[currentPage] = homepage;
    }
    
    void visit(string url) {
        currentPage++;
        urls[currentPage] = url;
        lastPage = currentPage;
    }
    
    string back(int steps) {
        int nextPage = max(0, currentPage - steps);
        currentPage = nextPage;
        return urls[currentPage];
    }
    
    string forward(int steps) {
        int nextPage = min(lastPage, currentPage + steps);
        currentPage = nextPage;
        return urls[currentPage];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);

arr[cap = 100], current = -1, last = -1; 

visit = arr[++current] = site
        last = current

l   g   f   ln   
c       
            l
*/