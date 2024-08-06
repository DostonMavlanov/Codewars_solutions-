#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod) 
  {
    static std::vector<ull> result;
    ull a = 0;
    ull b = 1;
    ull c = 1;
    while (a * b <= prod) {
      a = b;
      b = c;
      c = a + b;
      
      if (a * b == prod) {
        return {a, b, 1};
      }
      
      if (b * c == prod) {
        return {b, c, 1};
      }
    }
    return {a, b, 0};
  }
};