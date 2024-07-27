class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.empty()||matrix[0].empty())return v;
        int minc=0,minr=0,maxc=matrix[0].size()-1,maxr=matrix.size()-1;
        int count=0;
        int total=matrix.size()*matrix[0].size();
        while(count<total)
        {
            for(int j=minc;j<=maxc&&count<total;j++)
            {
                v.push_back(matrix[minr][j]);
                count++;
            }
            minr++;
            for(int i=minr;i<=maxr&&count<total;i++)
            {
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            for(int j=maxc;j>=minc&&count<total;j--)
            {
                v.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;
            for(int i=maxr;i>=minr&&count<total;i--)
            {
                v.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return v;
    }
};