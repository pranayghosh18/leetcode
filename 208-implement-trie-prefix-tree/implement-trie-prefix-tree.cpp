class Trie {
private:
    struct node{
        char value;
        vector<node*> children;
        bool isEnd;

        node(char value){
            this->value = value;
            this->children = vector<node*>(26, nullptr);
            this->isEnd = false;
        }
    };

public:
    node *root;
    Trie() {
        root = new node('*');        
    }
    
    void insert(string word) {
        node *t = root;
        for(char c : word){
            if(t->children[c-'a'] == nullptr){
                t->children[c-'a'] = new node(c);
            }
            t = t->children[c-'a'];
        }
        t->isEnd = true;
    }
    
    bool search(string word) {
        node *t = root;
        for(char c : word){
            if(t->children[c-'a'] == nullptr) return false;
            t = t->children[c-'a'];
        }
        return t->isEnd;
    }
    
    bool startsWith(string prefix) {
        node *t = root;
        for(char c : prefix){
            if(t->children[c-'a'] == nullptr) return false;
            t = t->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */