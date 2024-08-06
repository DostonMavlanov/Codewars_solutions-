#include <string>
#include <vector>
#include <set>

std::string range_extraction(std::vector<int> args){
    using Range = std::pair<int, int>;
    std::vector<Range> ranges;
    for (int i: args){
        if (ranges.empty() || ranges.back().second + 1 != i){
            ranges.push_back({i, i});
        }else{
            ++ranges.back().second;
        }
    }
  
    std::string result;
    for (auto& r: ranges){
    if (r.first == r.second){
        result.append(std::to_string(r.first) + ",");
    }else {
        result.append(std::to_string(r.first) +
                ((r.first + 1 == r.second) ? ',' : '-') +
                std::to_string(r.second) +
                ",");
        }
    }
    result.pop_back();
    return result;
}