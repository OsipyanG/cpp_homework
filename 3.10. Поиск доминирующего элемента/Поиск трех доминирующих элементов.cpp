#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    return (count > nums.size() / 2) ? 1 : 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = majorityElement(nums);
    cout << result << endl;
    return 0;
}
