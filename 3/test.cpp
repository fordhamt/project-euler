#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

bool * generatePrimes( long long PRIME_NUMBER );
void segmented_sieve(int64_t range, int segment_size = 32768);

int main() {

	//int64_t PRIME_NUMBER = 13195; 
	int64_t PRIME_NUMBER = 600851475143; 
	segmented_sieve( PRIME_NUMBER );

/*
	long long PRIME_NUMBER = 600851475143;
  //long long PRIME_NUMBER = 13195; 
	//long long PRIME_NUMBER = 101; 
	//std::vector<bool> primesList;
	bool * primesList = nullptr;
	long long result = 0;

	primesList = generatePrimes( PRIME_NUMBER );


	for(long long i = 2; i != PRIME_NUMBER; ++i) { 
		if( !primesList[ i ] ) { 
			if( PRIME_NUMBER % i == 0 ) {
				result = i;
			}
		}
	}
	
  //std::cout << factorList[ factorList.size() - 1] << std::endl;
  std::cout << result << std::endl;
*/
	return 0;
}

bool * generatePrimes( long long range ) { 

	long long rangeSqrt = (long long)sqrt((double)range);
  bool * primesList = new bool[ range + 1 ];

	for(long long i = 2; i != rangeSqrt; ++i) { 
		if( !primesList[ i ] ) { 				
				for(long long j = i * i; j <= range; j += i)
				  primesList[ j ] = true;
		}
	}
				
/*
	for(long long i = 2; i != range; ++i) {
		if( !primesList[ i ] )
			std::cout << i << ' ';
	}
*/			
	return primesList;
}

void segmented_sieve(int64_t range, int segment_size)
{
  int rangeSqrt = (int)sqrt((double) range);
  int64_t count = (range < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;
  int64_t result = 0;

  // vector used for sieving
  std::vector<char> sieve( segment_size );

  // generate small primes <= sqrt
  std::vector<char> is_prime( rangeSqrt + 1, 1 );

  for (int i = 2; i * i <= rangeSqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= rangeSqrt; j += i)
        is_prime[j] = 0;

  std::vector<int> primes;
  std::vector<int> next;

  for (int64_t low = 0; low <= range; low += segment_size)
  {
    std::fill( sieve.begin(), sieve.end(), 1 );

    // current segment = interval [low, high]
    int64_t high = std::min(low + segment_size - 1, range);

    // store small primes needed to cross off multiples
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    // sieve the current segment
    for (std::size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

		for (; n <= high; n += 2)
			      if (sieve[n - low]) // n is a prime
							        count++;
		
		/*
    for (; n <= high; n += 2) {
      if ( sieve[ n - low] ) {	// n is a prime
        //std::cout <<  n - low  << ' ';
				if( range % ( n - low ) == 0 && n - low != 1){ 
					result = ( n - low );
					std::cout <<  n - low  << ' ' << std::endl;				}
			}
		}	

		*/
  }

	std::cout << count << std::endl;
}
