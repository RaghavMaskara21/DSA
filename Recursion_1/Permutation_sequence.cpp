class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> v;
        for(int i=1;i<=n;i++){
            fact*=i;
            v.push_back(i);
        }
        k=k-1;
        string ans="";
        while(v.size()>0){
            fact=fact/v.size();
            ans+=to_string(v[k/fact]);
            v.erase(v.begin()+k/fact);
            k=k%fact;
        }
        return ans;
    }
};