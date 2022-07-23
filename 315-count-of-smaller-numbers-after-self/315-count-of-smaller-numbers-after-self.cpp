class Solution {
public:
    using Item = pair<int, int>;
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<Item> items(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            items[i] = {nums[i], i};
        }
        temp.assign(nums.size(), {0, 0});
        inversionCount.assign(nums.size(), 0);
        
        mergeSort(items, 0, nums.size() - 1);
        
        return inversionCount;
    }
    
    void mergeSort(vector<Item> &items, const int leftStart, const int rightEnd) {
        if (rightEnd - leftStart + 1 <= 1) return;
        const int leftEnd = leftStart + (rightEnd - leftStart) / 2;
        const int rightStart = leftEnd + 1;
        mergeSort(items, leftStart, leftEnd);
        mergeSort(items, rightStart, rightEnd);
        mergeParts(items, leftStart, leftEnd, rightStart, rightEnd);
    }
    
    void mergeParts(vector<Item> &items, const int leftStart, const int leftEnd, const int rightStart, const int rightEnd) {
        std::copy(items.begin() + leftStart, items.begin() + rightEnd + 1, temp.begin() + leftStart);
      
        int left = leftStart;
        int right = rightStart;
        int outputIndex = leftStart;
        int rightSmallerCount = 0;
        while (left <= leftEnd || right <= rightEnd) {
            if (left <= leftEnd && right <= rightEnd) {
                if (temp[left] > temp[right]) {
                    items[outputIndex] = temp[right++];
                    
                    rightSmallerCount++;
                } else {
                    items[outputIndex] = temp[left++];
                    
                    addInversionCount(items[outputIndex], rightSmallerCount);
                }
            } else if (left <= leftEnd) {
                items[outputIndex] = temp[left++];
                
                addInversionCount(items[outputIndex], rightSmallerCount);
            } else { 
                items[outputIndex] = temp[right++];
            }
            
            outputIndex++;
        }
    }
    
    void addInversionCount(const Item &item, const int rightSmallerCount) {
        const int origIndex = item.second;
        inversionCount[origIndex] += rightSmallerCount;
    }
    
    vector<Item> temp;
    vector<int> inversionCount;
};