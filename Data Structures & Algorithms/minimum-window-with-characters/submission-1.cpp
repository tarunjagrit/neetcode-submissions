class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        if(s.size()<t.size()){
            return ans;
        }
        //t freq1 creation
        int freq1[128]={0};

        int required=0;
        for(int i=0; i<t.size(); i++){
            if(freq1[t[i]] == 0){
                required++;
            }
            freq1[t[i]]++;
        }
        int r=0, l=0, len=INT_MAX, count=0, start=0;

        //s freq2 creation
        int freq2[128]={0};
        while(r<s.size()){
            freq2[s[r]]++;

            if(freq2[s[r]]==freq1[s[r]]){
                count++;
            }

            if(count==required){
                while(count==required){
                    if(r-l+1< len){
                        len= r-l+1;
                        start= l;
                    }

                    if(freq2[s[l]]==freq1[s[l]]){
                        count--;
                    }
                    freq2[s[l]]--;
                    l++;
                }
            }
            r++;
        }
        if(len==INT_MAX){
            return "";
        }
        return s.substr(start, len);
    }
};