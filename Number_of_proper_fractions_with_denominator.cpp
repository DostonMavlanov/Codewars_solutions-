#include <iostream>

long long properFractions(long long n)
{
  if (n == 1) return 0;
  long long phi = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      phi = phi / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  
  if (n > 1) phi = phi / n * (n - 1);
  return phi;
}