#include <cstdint>

template <class F>
std::int64_t calc(std::int64_t n, F f) {
  std::int64_t r = 0;
  for (std::int64_t p = 1; p * p <= n; ++p) r += f(p) * (n / p - n / (p + 1));
  for (std::int64_t p = 1; p < n / p; ++p) r += f(n / p);
  return r;
}