#include <algorithm>
#include <set>
#include <vector>

namespace DoubleLinear
{
   int dblLinear(const int n)
   {
     std::set<int> s { 1 };
     for (int i = 0; i < n; ++i) {
       auto x = *(s.begin());
       s.erase(s.begin());
       auto ins = s.insert(x + x + 1);
       s.insert(ins.first, x + x + x + 1);
     }
     return *(s.begin());
   }
}