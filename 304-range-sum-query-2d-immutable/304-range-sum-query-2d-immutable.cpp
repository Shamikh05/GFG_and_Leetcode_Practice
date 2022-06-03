class NumMatrix {
private:
    vector<vector<int> > preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        preSum = vector<vector<int> >(matrix.begin(), matrix.end());
        
        for(int i=0;i<m;++i) {
            
            for(int j=0;j<n;++j) {
                
                int upperSum = 0;
                int upperRemSum = 0;
                    
                int leftSum = 0;
                
                if(i)
                    upperSum = preSum[i-1][j];
                
                if(i and j)
                    upperRemSum = preSum[i-1][j-1];
                    
                int netUpperSum = upperSum - upperRemSum;
                
                if(j) 
                    leftSum = preSum[i][j-1];
                
                
                preSum[i][j] += leftSum + netUpperSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int upperSum = 0;
        int upperRemSum = 0;
        
        if(row1) 
            upperSum = preSum[row1-1][col2];
        
        if(row1 and col1)
            upperRemSum = preSum[row1-1][col1-1];
        
        
        int upperDiff = upperSum - upperRemSum;
        
        int leftSum = 0;
        
        if(col1)
            leftSum = preSum[row2][col1-1];
        
        
        int sumRegion = preSum[row2][col2] - upperDiff - leftSum;
        
        return sumRegion;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */