class Solution {
public:
    int maxArea(vector<int>& arr) {
          int n = arr.size();
        if (n == 2) {
            return min(arr[0], arr[1]);
        }
        int i = 0;
        int j = n - 1;
        int maxwater = INT_MIN;
        while (i < j) {
            int height = min(arr[i], arr[j]);
            int width = j - i;
            int currIdx = height * width;
            maxwater = max(maxwater, currIdx);

            if (arr[i] < arr[j])
                i++;
            else
                j--;
        }
        return maxwater;
    }
};
