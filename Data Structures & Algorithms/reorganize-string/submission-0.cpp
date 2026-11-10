class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> map;
        for(int i=0; i<s.size(); i++){
            map[s[i]]++;
        }

        //Map se Heap mein daalo
        priority_queue<pair<int, char>> pq;

        

        for(auto& it: map){
            pq.push({it.second, it.first});
        }

        // feasability check
        int n=s.size();
        int maxFreq=pq.top().first;
        if(maxFreq> (n+1)/2){
            return "";
        }

        //string mein append krte raho till heap khaali na hojaye
        string str="";

        while(pq.size()>1){
            char hi= pq.top().second;
            int hifi= pq.top().first;
            pq.pop();
            str+=hi;
            hifi--;

            char sec= pq.top().second;
            int sifi= pq.top().first;
            pq.pop();
            str+=sec;
            sifi--;
            
            if(hifi>0){
                pq.push({hifi, hi});
            }
            if(sifi>0){
                pq.push({sifi, sec});
            }
        }

        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }
            str+=pq.top().second;
            pq.pop();
        }
        return str;
    }
};