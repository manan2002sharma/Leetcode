class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<num.length();i++){
            while(!st.empty()&&st.top()>num[i]&&k!=0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k!=0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        stack<int> rst;
        while(!st.empty()){
            rst.push(st.top());
            st.pop();
        }
        string ans="";
        while(!rst.empty()&&rst.top()=='0'){
            rst.pop();
        }
        if(rst.empty()) return "0";
        while(!rst.empty()){
            ans+=rst.top();
            rst.pop();
        }
        return ans;
    }
};