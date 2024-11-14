class Solution {
public:
    int distribute(vector<int>& quntities, int max_val)
    {
        int stores = 0;
        for(auto qunatity: quntities)
        {
            stores += qunatity / max_val;
            stores += (qunatity % max_val) > 0 ? 1 : 0;
        }
        return stores;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int stores = distribute(quantities, mid);  
            if(stores <= n)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};