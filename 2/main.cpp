#include <iostream>

int main() {

  const int FOUR_MILLION = 4000000;  
  
	int prev = 1;
	int next	= 2;
  int temp = 0;

	int result = 0;   

	while( next < FOUR_MILLION ) {

		if( next % 2 == 0)
			result += next;

		temp = next;

		next += prev;
    prev = temp;
	}

	std::cout << result << std::endl;

	return 0;
}

