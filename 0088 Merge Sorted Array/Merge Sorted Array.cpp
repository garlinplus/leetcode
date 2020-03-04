class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = 0; i < n; i++){
            int j = 0;
            while(j < m && nums1[j] <= nums2[i]){
                j++;
            }
            
            if(j < m){
                for(int k = nums1.size() - 2; k >= j; k--) nums1[k+1]= nums1[k];
            }
            
            nums1[j] = nums2[i];
            m++;
        }
    }
};