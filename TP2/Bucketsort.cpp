#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<float>& nums) {
  int n = nums.size();

  // Create empty buckets
  std::vector<std::vector<float>> buckets(n);

  // Put elements into respective buckets
  for (int i = 0; i < n; ++i) {
    int bucketIndex = n * nums[i];
    buckets[bucketIndex].push_back(nums[i]);
  }

  // Sort elements within each bucket
  for (int i = 0; i < n; ++i) {
    std::sort(buckets[i].begin(), buckets[i].end());
  }

  // Concatenate sorted buckets
  int index = 0;
  for (int i = 0; i < n; ++i) {
    for (float num : buckets[i]) {
      nums[index++] = num;
    }
  }
}

void printArray(const std::vector<float>& nums) {
  for (float num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<float> nums = {0.8, 0.2, 0.4, 0.6, 0.1, 0.3};

  std::cout << "Original array: ";
  printArray(nums);

  bucketSort(nums);

  std::cout << "Sorted array: ";
  printArray(nums);

  return 0;
}
