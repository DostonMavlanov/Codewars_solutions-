#include <math.h>
#include <vector>



class KPrimes
{
public:
    static std::vector<long long> countKprimes(int k, long long start, long long end);
    static int puzzle(int s);
private:
    static int countPrimeFactors(long long n);
};

int KPrimes::countPrimeFactors(long long n)
{
    if (n == 0)
        return 0;
    int factors = 0;
    long long fac = 2;
    while (n != 1)
    {
        while ( (n % fac) != 0)
        {  
            if ( fac > sqrt(n))
                fac = n; 
            else if (fac == 2)
                fac = 3;  
            else
                fac += 2; 
        factors++;
        n = n / fac;
    }
    return factors;
}

std::vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
    std::vector<long long> kPrimes;
    for (long long i = start; i <= end; i++)
    {
        if (countPrimeFactors(i) == k)
            kPrimes.push_back(i);  
    }
    return kPrimes;
}

int KPrimes::puzzle(int s)
{
    int sums = 0;
   
    for (int i = 128; i <= s - 10; i++) 
    {
        if (countPrimeFactors(i) == 7)
        {
            int b = s-i; 
            for (int j = 8; j <= b-2; j++) 
            {
                if (countPrimeFactors(j) == 3)
                {
                    int a = b - j; 
                    if (countPrimeFactors(a) == 1)
                        sums++; 
                }
            }
        }
    }
    return sums;
} 