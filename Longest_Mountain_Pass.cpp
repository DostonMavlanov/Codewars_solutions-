#include <vector>
#include <utility>


std::pair<int, int> longest_mountain_pass(const std::vector<int>& mountains, int e) {
  int current_energy = 0;
  int max_length = 0;
  int start_index = 0;
  int iend=0;
  for (int istart=0; istart<(int)mountains.size()-1; istart++)
  {
    while (current_energy > e)
    {
      current_energy -= std::max(0, (mountains[iend] - mountains[iend-1]));
      iend--;
    }
    while (current_energy <= e && iend < (int)mountains.size()-1)
    {
      iend++;
      current_energy += std::max(0, (mountains[iend] - mountains[iend-1]));
    }
    if (current_energy > e)
    {
      current_energy -= std::max(0, (mountains[iend] - mountains[iend-1]));
      iend--;
    }
    if (iend - istart + 1 > max_length)
    {
      max_length = iend - istart + 1;
      start_index = istart;
    }
    current_energy -= std::max(0, (mountains[istart+1] - mountains[istart]));
  }
  return {max_length, start_index};
}