class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int start=0;
        int end=0;
        
        int ans=0;
        int currCount=0;

        while(end<customers.size()){

            currCount+=customers[end]*grumpy[end];

            if((end-start+1)==minutes){
                ans=max(currCount,ans);
                currCount-=customers[start]*grumpy[start];
                start++;
            }

            end++;
        }


        for(int i=0;i<customers.size();i++){
            ans+=customers[i]*(1-grumpy[i]);
        }

        return ans;

    
    }
};