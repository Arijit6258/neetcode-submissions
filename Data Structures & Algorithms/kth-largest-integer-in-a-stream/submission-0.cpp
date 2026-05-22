class compare {
    public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

class KthLargest {
public:
    priority_queue<int, vector<int>, compare> largestK;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (largestK.size() == k && nums[i] > largestK.top()) {
                largestK.pop();
            }

            if (largestK.size() < k) largestK.push(nums[i]);
        }    
    }
    
    int add(int val) {
        if (largestK.size() == k && val > largestK.top()) {
            largestK.pop();
        }

        if (largestK.size() < k) largestK.push(val);

        return largestK.top();
    }
};
