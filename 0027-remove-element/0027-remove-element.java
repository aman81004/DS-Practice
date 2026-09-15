class Solution {
    public int removeElement(int[] nums, int val) {
        
        int n = nums.length ;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        int k = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;

    }
}