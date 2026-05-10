class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
                int low=*max_element(weights.begin(),weights.end());
                int high=accumulate(weights.begin(),weights.end(),0);

        int ans=1;

        while (low<=high){

            int mid=low+(high-low)/2;

            if(canShip(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
    
    bool canShip(vector<int>& weights, int mid, int days){

        int totalDays=1;
        int currCapicity=0;
        for(int weight:weights){

            if(currCapicity+weight<=mid){
                currCapicity+=weight;
            }else{
                currCapicity=weight;
                totalDays++;
            }

        }

        return totalDays<=days;
    }
};