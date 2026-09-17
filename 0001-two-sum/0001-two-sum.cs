public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        
        int n = nums.Length ;
        Dictionary<int,int> map = new Dictionary<int, int>() ; 

        for( int i = 0 ; i < n ; i++ ){
            int sub = target - nums[i];

            if ( map.ContainsKey( sub ) ) {
                return new int[] { map[ sub ], i };
            }

            map[nums[i]] = i;
        }

        return new int[0] ;
        

    }
}