class Solution {
public:
    vector<string> result;
    bool Valid(string curr){
        stack<char> count;
        for(int i=0; i<curr.size(); i++){
            if(curr[i]=='('){
                count.push(curr[i]);
            }
            else{
                if(count.empty()){
                    return false;
                }
                count.pop();
            }
        }
        if(count.empty()){
            return true;
        }
        return false;
    }
    void func(string &curr, int n){
        if(curr.size()==2*n ){
            if(Valid(curr)){
                result.push_back(curr);
            }
            return;
        }
        //open
        curr.push_back('(');
        func(curr, n);
        curr.pop_back();

        //close
        curr.push_back(')');
        func(curr,n);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
    
        string curr="(";
        func(curr, n);
        return result;
    }
};