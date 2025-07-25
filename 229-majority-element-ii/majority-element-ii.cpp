class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() < 2 ) return nums;

        int potential1 = nums[0], potential2 = nums[0];
        int count1 =1, count2 = 0;

        for (int i=1; i<nums.size(); i++){
            if (nums[i]== potential1){
                count1++;
            }
            else if(nums[i]== potential2){
                count2++;
            }else{
                if (count1 == 0){
                    potential1 = nums[i];
                    count1++;
                }else if(count2 == 0){
                    potential2 = nums[i];
                    count2++;
                }
                else{
                    count1--, count2--;
                }
            }
        }

        count1 = 0, count2 =0;
        for (int i:nums){
            if (i == potential1) count1++;
            else if (i == potential2) count2++;
        }

        vector<int>ans;
        if (count1 > nums.size()/3) ans.push_back(potential1);
        if (count2 > nums.size()/3) ans.push_back(potential2);

        return ans;
        
    }
};