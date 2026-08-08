class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int[] rightHandSideMatchLength = new int[n];
        int rightMatched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0) {
            if(j >= 0 && word1.charAt(i) == word2.charAt(j)) {
                rightMatched++;
                j--;
            }
            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }
        int[] seq = new int[m];
        int idx = 0;              //fill pointer for seq
        boolean changePower = true; //can change only one character
        i = 0;
        j = 0;
        while(i < n && j < m) {
            if(word1.charAt(i) == word2.charAt(j)) {
                seq[idx++] = i;
                j++;
            } else if(changePower == true && i+1 < n && rightHandSideMatchLength[i+1] >= m-j-1) {
                seq[idx++] = i;
                j++;
                changePower = false;
            }
            i++;
        }
        return j == m ? seq : new int[0];
    }
}