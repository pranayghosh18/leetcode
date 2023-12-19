class Solution {
public:
    
vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    vector<vector<int>> opImg(img.size(), vector<int>(img[0].size(), 0));
    int gs(0), count(0);
    for(int i=0; i<img.size(); i++){
        for(int j=0; j<img[0].size(); j++){
            // load initail 2/3 width col
            if(j==0){
                gs = img[i][j];
                count = 1;
                if(i>0) gs += img[i-1][j], count++;
                if(i<img.size()-1) gs += img[i+1][j], count++; 
            }

            int x1,x2,x3,y1,y2,y3;
            x1=x2=x3=y1=y2=y3=0;

            if(j-2 >= 0){
                x1 = img[i][j-2];
                count--;
                if(i>0) x2 = img[i-1][j-2], count--; 
                if(i<img.size()-1) x3 = img[i+1][j-2], count--;  
            }

            if(j+1 < img[0].size()){
                y1 = img[i][j+1];
                count++; 
                if(i>0) y2 = img[i-1][j+1], count++; 
                if(i<img.size()-1) y3 = img[i+1][j+1], count++; 
            }
            gs = gs - (x1+x2+x3) + (y1+y2+y3);
            opImg[i][j] = gs/count;
        }
    }
    return opImg;
}
};