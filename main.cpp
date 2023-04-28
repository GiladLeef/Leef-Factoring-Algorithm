#include <iostream>
#include <math.h>

typedef unsigned long long int BigNumber;

int main() {

  // Input big product of primes (like RSA public SemiPrime for example)
  BigNumber SemiPrime;
  std::cout << "Please enter a product of two prime numbers: ";
  std::cin >> SemiPrime;

  // Check if even, return 2 * (SemiPrime / 2)
  if (SemiPrime % 2 == 0) {

    // Found SemiPrime, print output and exit
    std::cout << (SemiPrime / 2) << " * 2 = " << SemiPrime << "\n";
    return 0;
  }

  // Find square root
  BigNumber one = sqrt(SemiPrime);

  // If one is even, make it odd
  if (one % 2 == 0) {
    one += 1;
  }

  // Start with one = two
  BigNumber two = one;
  BigNumber prod = one * one;

  // Run until all relevant primes tested
  while (two > 2 && one < SemiPrime) {
    if (prod > SemiPrime) {
      prod = prod - one - one;
      two -= 2;
    } else if (prod < SemiPrime) {
      prod = prod + two + two;
      one += 2;
    } else {

      // Found SemiPrime, print output and exit the program.
      std::cout << one << " * " << two << " = " << SemiPrime << "\n";
      return 0;
    }
  }

  // Found SemiPrime, print output and exit the program.
  std::cout << SemiPrime << " * 1 = " << SemiPrime << "\n";
  return 0;
}
