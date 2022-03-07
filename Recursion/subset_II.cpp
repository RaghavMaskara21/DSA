void subset(int index, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums){
        ans.push_back(v);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            subset(i+1,v,ans,nums);
            v.pop_back();
        }
        
    }