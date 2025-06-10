class WordDictionary {
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
    WordDictionary() {
        root = new node('*'); 
    }
    
    void addWord(string word) {
        node *t = root;
        for(char c : word){
            if(t->children[c-'a'] == nullptr){
                t->children[c-'a'] = new node(c);
            }
            t = t->children[c-'a'];
        }
        t->isEnd = true;
    }
    
    // check if root has a child with word[c]
    bool dfsSearch(node* root, string& word, int index, bool isEndOfAWord_){
        if(index == word.size()) return isEndOfAWord_;
        // check all children
        if(word[index] == '.'){
            for(node *child : root->children){
                if(child != nullptr){
                    bool isEndOfAWord = child->isEnd;
                    if(dfsSearch(child, word, index+1, isEndOfAWord)) return true;
                }
            }
            return false;
        }
        if(root->children[word[index] - 'a'] == nullptr) return false;
        bool isEndOfAWord = root->children[word[index] - 'a']->isEnd;
        return dfsSearch(root->children[word[index] - 'a'], word, index+1, isEndOfAWord);
    }

    bool search(string word) {
        node *t = root;
        return dfsSearch(t, word, 0, false);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */