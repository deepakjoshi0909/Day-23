class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int requiredStores = 0;

            for (int qty : quantities) {
                requiredStores += (qty + mid - 1) / mid;  // ceil(qty / mid)
            }

            if (requiredStores <= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
