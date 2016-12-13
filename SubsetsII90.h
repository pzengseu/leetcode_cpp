//
// Created by zp on 12/13/16.
//

#ifndef LEETCODE_CPP_SUBSETSII90_H
#define LEETCODE_CPP_SUBSETSII90_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<vector<int>> subsetsWithDup(vector<int>& nums);
};

vector<vector<int>> Solution::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> totalset = {{}};
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size();){
        int count = 0;
        while(count+i<nums.size() && nums[count+i]==nums[i]) count++;
        int previousN = totalset.size();
        for(int k=0; k<previousN; k++){
            vector<int> instance = totalset[k];
            for(int j=0; j<count; j++){
                instance.push_back(nums[i]);
                totalset.push_back(instance);
            }
        }
        i += count;
    }
    return totalset;
}
#endif //LEETCODE_CPP_SUBSETSII90_H
