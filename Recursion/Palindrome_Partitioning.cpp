class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    void partition(int index, string s, vector<vector<string>> &ans, vector<string> &v){
        if(index==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                partition(i+1,s,ans,v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        partition(0,s,ans,v);
        return ans;
    }
};