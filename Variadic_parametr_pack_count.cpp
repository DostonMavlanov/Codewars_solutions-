#include <cstddef>

template <typename... Ts>
constexpr std::size_t arg_length(Ts... xs) noexcept {
  constexpr auto counter = [](auto const& k) { (void)k; return 1; };
  return (counter(xs) + ...);
}