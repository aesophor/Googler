#include <iostream>
#include <string>

class Fraction {
 public:
  Fraction() : numerator(1), denominator(1) {}

  Fraction(int n, int d) {
    numerator = n;
    if ( d == 0) {
      std::cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << std::endl;
      exit(0); // will terminate the program if division by 0 is attempted
    } else {
      denominator = d;
    }
  }

  /*In the following functions I am dividing both numerator and denominator by the gcd function.
    GCD function accepts both numerator and denominator values. If we had 2 fractions, 1/2 and 1/4
    and we passed it into the Sum, the result would be n=6 and d=8. These are the values that GCD
    function will accept, find greatest common divisor and return the integer value of 2. In my case 
    am diving both numerator and denominator on the same line by the greatest common divisor. Although 
    it probably would be more efficient to create a local int variable and store GCD value in it, but
    for such small program it shouldn't make any difference.*/
  Fraction Sum(Fraction otherFraction) {
    int n = numerator*otherFraction.denominator+otherFraction.numerator*denominator;
    int d = denominator*otherFraction.denominator;
    return Fraction(n/gcd(n,d),d/gcd(n,d));
  }

  Fraction Difference(Fraction otherFraction) {
    int n = numerator*otherFraction.denominator-otherFraction.numerator*denominator;
    int d = denominator*otherFraction.denominator;
    return Fraction(n/gcd(n,d),d/gcd(n,d));
  }

  Fraction Product(Fraction otherFraction) {
    int n = numerator*otherFraction.numerator;
    int d = denominator*otherFraction.denominator;
    return Fraction(n/gcd(n,d),d/gcd(n,d));
  }

  Fraction Division(Fraction otherFraction) {
    int n = numerator*otherFraction.denominator;
    int d = denominator*otherFraction.numerator;
    return Fraction(n/gcd(n,d),d/gcd(n,d));
  }

  void Simplify() {
    int this_gcd = gcd(numerator, denominator);
    if (numerator >= this_gcd && denominator >= this_gcd) {
      numerator /= this_gcd;
      denominator /= this_gcd;
    }
  }

  int gcd(int n, int d) {
    int remainder;
    while (d != 0)
    {
      remainder = n % d;
      n = d;
      d = remainder;
    }
    return n;
  }

  void show() {
    std::cout << numerator << "/" << denominator << std::endl;
  }

 private:
  int numerator;
  int denominator; 
};


int main() {
  std::string line;
  std::getline(std::cin, line);
  int count = std::stoi(line);

  for (int i = 0; i < count; i++) {
    std::getline(std::cin, line);
    std::string first = line.substr(0, line.find(','));
    std::string second = line.substr(line.find(',') + 1);

    int n1 = std::stoi( first.substr(0, first.find('/')) );
    int d1 = std::stoi( first.substr(first.find('/') + 1) );

    int n2 = std::stoi( second.substr(0, second.find('/')) );
    int d2 = std::stoi( second.substr(second.find('/') + 1) );

    Fraction a(n1, d1);
    Fraction b(n2, d2);
    Fraction c;

    c = a.Sum(b); // Result: 3/4
    c.Simplify();
    c.show();

    c = a.Difference(b); // Result: 1/4
    c.Simplify();
    c.show();

    c = a.Product(b); // Result: 1/8
    c.Simplify();
    c.show();

    c = a.Division(b); // Result: 2
    c.Simplify();
    c.show();
  }

  return 0;
}
