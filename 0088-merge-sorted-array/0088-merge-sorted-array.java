class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int s = m + n;
        int[] result = new int[s];

        int k = 0;
        int j = 0;

        for (int i = 0; i < s; i++) {

            if (k == m) {
                result[i] = nums2[j];
                j++;
            }

            else if (j == n) {
                result[i] = nums1[k];
                k++;
            }

            else if (nums1[k] <= nums2[j]) {
                result[i] = nums1[k];
                k++;
            }

            else {
                result[i] = nums2[j];
                j++;
            }
        }

        for (int i = 0; i < s; i++) {
            nums1[i] = result[i];
        }
    }
}