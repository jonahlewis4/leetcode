class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        for(int i = 0; i < nums.length;) {
            if(nums[i] == i + 1) {
                i++;
            } else {
                int currentValue = nums[i];
                int otherIndex = currentValue - 1;
                if(nums[otherIndex] == currentValue) {
                    i++;
                    continue;
                } else {
                    //swap
                    int temp = currentValue;
                    nums[i] = nums[otherIndex];
                    nums[otherIndex] = temp;
                }
            }
        }

        ArrayList<Integer> res = new ArrayList<>();

        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != i + 1) {
                res.add(nums[i]);
            }
        }


        return res;
    }
}