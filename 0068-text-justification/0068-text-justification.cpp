class Solution {
public:
    string createString(int i, int j, vector<string>& words, int maxWidth, int wordCount, int totalChars){

        int remChars = maxWidth - totalChars;
        int spaces = 0;
        int xFactor = 0;
        if(wordCount > 1){
            spaces = remChars / (wordCount - 1);
            xFactor = remChars % (wordCount -1);
        } else {
            spaces = remChars;
        }
        cout<<wordCount<<endl;
        cout<<spaces<<" "<<xFactor<<endl;
        
        int cnt = 0;
        string str="";

        for(int idx = i; idx <= j; idx++){
            str += words[idx];
            cnt += words[idx].size();

            for(int k = 1;cnt < maxWidth && k<= spaces; k++){
                str += ' ';
                cnt++;
            }

            if(cnt < maxWidth && xFactor > 0){
                str += ' ';
                xFactor--;
                cnt++;
            }  
        }

        return str;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n = words.size();
        int cnt = 0;
        int sum = 0;
        int start = 0;
        int i = 0;
        vector<string> res;
        string str ="";
        for(i = 0; i< n; i++){
            sum += words[i].size();
            cnt++;

            if(sum + cnt - 1 > maxWidth){
                string str = createString(start, i-1, words, maxWidth, cnt -1 , sum - words[i].size());
                res.push_back(str);
                start = i;
                cnt = 1;
                sum = words[i].size();
            }
        }

        str = "";
        for(int idx = start; idx <= n-1; idx++){
            str += words[idx];
            if(idx < n-1){
                str += ' ';
                sum++;
            }
        }
        int val = maxWidth - sum;
        for(int i = 1; i<=val; i++){
            str += ' ';
        }
        res.push_back(str);
        return res;
    }
};