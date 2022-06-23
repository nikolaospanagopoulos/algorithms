#include <iostream>

int findSmallestMissingNum(int nums[], int &size);

int partition(int nums[], int &size);

int main() {

  int myArr[]{4, 5, 1, 2};

  int myArrSize = 4;

  std::cout << "for the array, the smallest missing number is "
            << findSmallestMissingNum(myArr, myArrSize) << std::endl;

  return 0;
}

int partition(int nums[], int &size) {

  int index = 0;

  for (int i{}; i < size; i++) {
    if (nums[i] > 0) {
      std::swap(nums[i], nums[index]);
      index++;
    }
  }
  return index;
}

int findSmallestMissingNum(int nums[], int &size) {

  // find the end index of positive numbers
  int positiveNumberLimitIndex = partition(nums, size);

  for (int i{}; i < positiveNumberLimitIndex; i++) {
    int val = std::abs(nums[i]);

    if (val - 1 < positiveNumberLimitIndex && nums[val - 1] >= 0) {
      // make numbers negative
      nums[val - 1] = -nums[val - 1];
    }
  }

  for (int i{}; i < positiveNumberLimitIndex; i++) {
    if (nums[i] > 0) {
      // if number is missing return it
      return i + 1;
    }
  }
  // if not return the one next to the last
  return positiveNumberLimitIndex + 1;
}
