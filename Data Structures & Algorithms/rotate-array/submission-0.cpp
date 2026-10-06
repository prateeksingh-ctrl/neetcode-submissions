class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return;
        
        int count = 0; // Tracks total elements successfully placed
        
        // The outer loop handles cases where the jumps form smaller disconnected cycles
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev_val = nums[start];
            
            // Keep jumping by k until we circle back to the start index
            do {
                int next_idx = (current + k) % n;
                
                // Swap the value we are holding with the one at the target index
                swap(nums[next_idx], prev_val);
                
                current = next_idx;
                count++;
                
            } while (start != current);
        }
    }
};