#include <iostream>

int main() {

		const long PRIME_NUMBER = 600851475143;
		long largestPrime = 0;

				for( long i = 0; i < PRIME_NUMBER; i++) 
							if( i % 2 != 0 && i % 3 != 0 ) largestPrime = i;

				  std::cout << largestPrime << std::endl;

						return 0;
}

