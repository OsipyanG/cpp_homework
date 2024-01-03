#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums, int k, int start, int target, vector<bool>& visited, int currentSum) {
    if (k == 1) {
        return true;
    }
    if (currentSum == target) {
        return canPartition(nums, k - 1, 0, target, visited, 0);
    }
    for (int i = start; i < nums.size(); i++) {
        if (!visited[i] && currentSum + nums[i] <= target) {
            visited[i] = true;
            if (canPartition(nums, k, i + 1, target, visited, currentSum + nums[i])) {
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    if (sum % k != 0) {
        return false;
    }
    vector<bool> visited(nums.size(), false);
    return canPartition(nums, k, 0, sum / k, visited, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    if (canPartitionKSubsets(values, 3)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}