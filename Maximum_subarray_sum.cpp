#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>

int maxSequence(const std::vector<int>& arr){
  int n = arr.size();
  int maxSubarraySum = 0;
  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int subarraySum = 0;
      for (int k = i; k <= j; ++k){
        subarraySum = subarraySum + arr[k];
      }
      if (subarraySum > maxSubarraySum) {
        maxSubarraySum = subarraySum;
      }
    }
  }
  return maxSubarraySum;
}