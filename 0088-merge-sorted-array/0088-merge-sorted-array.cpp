class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        for (int i = 0; i < n; i++) {
            nums1.push_back(nums2[i]);
        }
        int size = nums1.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (nums1[j] > nums1[j + 1]) {
                    swap(nums1[j], nums1[j + 1]);
                }
            }
        }
    }
};