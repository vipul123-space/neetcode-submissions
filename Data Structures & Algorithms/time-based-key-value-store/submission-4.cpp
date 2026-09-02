class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> tp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        tp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& arr= tp[key];
        int left=0;
        int right=arr.size()-1;

        string ans="";

        while(left<=right){
            int mid=left+(right-left)/2;

            if(arr[mid].first<=timestamp){
                ans=arr[mid].second;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }


        return ans;

    }
};
