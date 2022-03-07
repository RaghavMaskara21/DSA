void subset(int index, vector<int>&v,vector<vector<int>> &ans, vector<int>&candidates, int target, int sum){        
        if(sum>target) return;   
        if(sum==target)
              ans.push_back(v);          
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            sum=sum+candidates[i];
            subset(i+1,v,ans,candidates,target,sum);
            v.pop_back();
            sum=sum-candidates[i];
        }
        
    }