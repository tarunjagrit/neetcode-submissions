class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<int> abc(3,0);

        //priotity queue
        priority_queue< pair<int, char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        string str="";

        while(!pq.empty()){
            char ch = pq.top().second;
            int fre= pq.top().first;
            pq.pop();

            if(str.size()>=2 && str.back()==ch && str[str.size()-2]==ch){
               if(pq.empty()){
                    break;
                } 
                char ch2= pq.top().second;
                int fre2= pq.top().first;
                pq.pop();
                
                str+=ch2;
                fre2--;

                if(fre2>0){
                    pq.push({fre2, ch2});
                }
                pq.push({fre, ch});
            }

            else{
                str+=ch;
                fre--;

                if(fre>0){
                    pq.push({fre, ch});
                }
            }
        }

        return str;
    }
};