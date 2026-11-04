class Solution {
public:
    int square(int num){
        return num*num;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<double,int>> pq;

        for(int i=0; i<points.size(); i++){
            double dist= sqrt(square(points[i][0])+ square(points[i][1]));
            pq.push({dist, i});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(pq.size()>0){
            int idx= pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }

        return ans;
    }
};