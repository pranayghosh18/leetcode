class Solution {
public:
template <typename T>
void printVec(vector<T> arr){
    for(auto it: arr) cout << it << "\t";
    cout << endl;
}

vector<int> getSentWordCount(vector<string>& words, int maxWidth){
    int i(0), currLen(0), count(0);
    vector<int> lengths;
    while(i < words.size()){
        int nextLen = currLen + words[i].size();

        // cout << "i " << i << " curLen " <<  currLen << " nextLen " << nextLen << endl;

        // fits perfectly, consume current word
        if(nextLen == maxWidth) {
            count++;
            lengths.push_back(count);
            count = 0;
            currLen = 0;
        }
        // start of a new row
        else if(nextLen > maxWidth){
            lengths.push_back(count);
            count = 1;
            currLen = words[i].size() + 1;
        }
        else{
            currLen += (words[i].size() + 1);
            count++;
        }

        i++;
    }
    if(count > 0) lengths.push_back(count);
    return lengths;
}

string makeSent(vector<string>& words, int start, int count, int maxWidth){
    string res;
    if(count == 1) {
        res = words[start];
        res += string(maxWidth-words[start].size(), ' ');
        return res;
    }
    int wordCount(0);
    for(int i=0; i<count; i++) wordCount += words[start + i].size();
    int spaces = maxWidth - wordCount;
    int divider = count - 1;
    int equalSpaces = spaces / divider;
    int extraSpaces = spaces % divider;

    for(int i=0; i<count-1; i++){
        res += words[start + i];
        res += string(equalSpaces, ' ');
        if(extraSpaces > 0) {
            res += " ";
            extraSpaces--;
        }
    }
    res += words[start + count - 1];

    return res;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<int> sentWords = getSentWordCount(words, maxWidth);
    // printVec(sentWords);
    vector<string> doc;
    int start(0);
    for(int i=0; i<sentWords.size()-1; i++){
        int len = sentWords[i];
        doc.push_back(makeSent(words, start, len, maxWidth));
        start += len;
    }
    // the last row
    string lastRow;
    for(int i=0; i<sentWords.back()-1; i++) {
        lastRow += words[start + i] + " ";
    }
    lastRow += words.back();
    while (lastRow.size() < maxWidth) lastRow.push_back(' ');
    doc.push_back(lastRow);
    
    return doc;
}
};