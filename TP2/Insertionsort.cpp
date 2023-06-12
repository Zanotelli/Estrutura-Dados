#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& nums) {
  int n = nums.size();
  
  for (int i = 1; i < n; ++i) {
    int key = nums[i];
    int j = i - 1;
    
    while (j >= 0 && nums[j] > key) {
      nums[j + 1] = nums[j];
      --j;
    }
    
    nums[j + 1] = key;
  }
}

void printArray(const std::vector<int>& nums) {
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> nums = {5, 2, 8, 6, 1, 3};
  
  std::cout << "Original array: ";
  printArray(nums);
  
  insertionSort(nums);
  
  std::cout << "Sorted array: ";
  printArray(nums);
  
  return 0;
}
