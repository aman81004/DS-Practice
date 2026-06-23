class Solution {
public:
    void colors(vector<int> &a,vector<int> &b,vector<int> &v){
        int i=0;
        int j=0;
        int k=0;
        int n1=a.size();
        int n2=b.size();
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                v[k++]=a[i++];
            }
            else{
                v[k++]=b[j++];
            }
        }
        while(i<n1){
            v[k++]=a[i++];
        }
        while(j<n2){
            v[k++]=b[j++];
        }
    }
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return;

        int n1=n / 2;
        int n2=n - n1;

        vector<int> a(n1);
        vector<int> b(n2);
        for(int i=0;i<n1;i++){
            a[i]=nums[i];
        }
        for(int i=0;i<n2;i++){
            b[i]=nums[i + n1];
        }

        sortColors(a);
        sortColors(b);
        colors(a,b,nums);
    }
};