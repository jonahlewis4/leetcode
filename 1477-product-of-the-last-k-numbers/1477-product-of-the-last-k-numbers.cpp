class ProductOfNumbers {
    vector<int> nums;
    int latest0;
public:
    ProductOfNumbers() {
        latest0 = -1;
        nums.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            nums.push_back(1);
            latest0 = nums.size() - 1;
        } else {
            nums.push_back(nums.back() * num);
        }
    }
    
    int getProduct(int k) {
        auto test = latest0;
        auto size = nums.size();
        if(int(nums.size()) - k <= latest0){
            return 0;
        }
        return nums.back() / nums[nums.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */