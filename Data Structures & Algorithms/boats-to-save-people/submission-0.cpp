class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
           if ((people.size() == 1) && people[0] <= limit) {
        return 1;
    }

    int left = 0, right = people.size() - 1;

    int ans = 0;
    sort(people.begin(), people.end());
    while (left <= right)
    {
        if (people[left] + people[right] <= limit) {
            ans++;
            right--;
            left++;
        }
        else if (people[right] <= limit) {
            ans++;
            right--;
        }
    }

    return ans;
    }
};