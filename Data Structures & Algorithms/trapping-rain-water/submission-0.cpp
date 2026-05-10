class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)
         return 0;
        
        int total=0;
        int i=0,j=height.size()-1;
        int l_max=height[i],r_max=height[j];
        
        while(i<=j)
        {
            r_max=max(r_max,height[j]);
            l_max=max(l_max,height[i]);
            if(l_max<=r_max)
            {
                total+=l_max-height[i];
                i++;
            }
            if(l_max>r_max)
            {
                total+=r_max-height[j];
                j--;
            }
        }
        
        return total;
    }
};
