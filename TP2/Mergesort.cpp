#include <iostream>
#include <vector>

void merge(std::vector<int>& nums, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> leftArray(n1);
  std::vector<int> rightArray(n2);

  for (int i = 0; i < n1; ++i) {
    leftArray[i] = nums[left + i];
  }

  for (int j = 0; j < n2; ++j) {
    rightArray[j] = nums[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      nums[k] = leftArray[i];
      ++i;
    } else {
      nums[k] = rightArray[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    nums[k] = leftArray[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    nums[k] = rightArray[j];
    ++j;
    ++k;
  }
}

void mergeSort(std::vector<int>& nums, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums, left, mid, right);
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

  mergeSort(nums, 0, nums.size() - 1);

  std::cout << "Sorted array: ";
  printArray(nums);

  return 0;
}
