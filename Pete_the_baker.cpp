#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available) {
  int result = std::numeric_limits<int>::max();
  for (auto& [word, num] : recipe) {
    if (auto iter = available.find(word); iter != available.end()) {
      result = std::min((iter->second / num), result);
    } else {
      return 0;
    }
  }
  return result;
}