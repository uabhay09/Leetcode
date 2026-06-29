class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;

        for(int i = 0; i < nums.size(); i++) {
            
            int need = target - nums[i];

            if(visited.count(need)) {
                return {visited[need], i};
            }

           visited[nums[i]] = i;
        }

        return {};
    }
};
