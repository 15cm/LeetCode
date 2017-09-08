class Solution {
public:
    // Radix Sort
    // int maximumGap(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n < 2) return 0;
    //     // LSD Radix Sort
    //     int maxVal = *max_element(nums.begin(), nums.end());
    //     int R = 10;
    //     int exp = 1;
    //     vector<int> aux(n);
    //     while(maxVal / exp > 0) {
    //         vector<int> cnt(R + 1);
    //         for(auto v: nums)
    //             cnt[v / exp % 10 + 1]++;
    //         for(int i = 0; i < R; i++)
    //             cnt[i + 1] += cnt[i];
    //         for(auto v: nums)
    //             aux[cnt[v / exp % 10]++] = v;
    //         nums = aux;
    //         exp *= 10;
    //     }

    //     int ans = 0;
    //     for(int i = 1; i < n; i++)
    //         ans = max(ans, nums[i] - nums[i - 1]);
    //     return ans;
    // }

    // Solution 3
    struct Bucket {
        bool used;
        int minVal = numeric_limits<int>::max();
        int maxVal = numeric_limits<int>::min();
    };

    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int minV = *min_element(nums.begin(), nums.end());
        int maxV = *max_element(nums.begin(), nums.end());
        int bucketSize = max(1, (maxV - minV) / ((int)nums.size() - 1));
        int bucketNum = (maxV - minV) / bucketSize + 1;
        vector<Bucket> buckets(bucketNum);

        for(auto&& num: nums) {
            int bucketIndex = (num - minV) / bucketSize;
            auto& bucket = buckets[bucketIndex];
            bucket.used = true;
            bucket.minVal = min(bucket.minVal, num);
            bucket.maxVal = max(bucket.maxVal, num);
        }

        int prevBucketMax = minV, maxGap = 0;
        for(auto&& bucket: buckets) {
            if(!bucket.used)
                continue;
            maxGap = max(maxGap, bucket.minVal - prevBucketMax);
            prevBucketMax = bucket.maxVal;
        }
        return maxGap;
    }
};
