class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> found(26,false);
        for(auto i:s){
            freq[i-'a']++;
        }
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(found[s[i]-'a']){
                freq[s[i]-'a']--;
                continue;
            }
                while(!st.empty()&&st.top()>s[i]&&freq[st.top()-'a']>0){
                    found[st.top()-'a']=false;
                    st.pop();
                    
                }
                st.push(s[i]);
                found[s[i]-'a']=true;
                freq[s[i]-'a']--;
            
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};