class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        int ans=1;

        while (low<=high){

            int mid=low+(high-low)/2;

            if(canEat(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;

    }

    bool canEat(vector<int>& piles, int mid, int h){

        int totalHours=0;

        for(int pile:piles){
            totalHours+=(pile+mid-1)/mid;
        }

        return totalHours<=h;
    }
};
