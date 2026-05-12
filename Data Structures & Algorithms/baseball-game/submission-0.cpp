class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;
        for(int i=0; i<operations.size(); i++){
            if(operations[i]!="C" && operations[i]!="D" && operations[i]!="+"){
                int num= stoi(operations[i]);
                st.push(num);
            }
            else{
                if(operations[i]=="D"){
                    int prev=st.top();
                    prev= 2*prev;
                    st.push(prev);
                }
                else if(operations[i]=="C"){
                    st.pop();
                }
                else{
                    int sum=0;
                    int num1= st.top();
                    st.pop();
                    int num2= st.top();
                    sum=num1+num2;
                    st.push(num1);
                    st.push(sum);
                }
            }
        }
        int sum2=0;
        while(!st.empty()){
            int j=st.top();
            sum2=sum2+j;
            st.pop();
        }
        return sum2;
    }
};