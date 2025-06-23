class Solution {
public:
bool checkValidString(string s) {
    stack<int> brackets, stars;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') brackets.push(i);
        else if(s[i] == '*') stars.push(i);
        else{
            if(!brackets.empty()) brackets.pop();
            else if(!stars.empty()) stars.pop();
            else return false;
        }
    }

    while(brackets.size() > 0 
            && stars.size() > 0){
        int bracket = brackets.top();
        brackets.pop();
        int star = stars.top();
        stars.pop();
        
        if(star < bracket) return false;
    }

    return brackets.empty();
}
};