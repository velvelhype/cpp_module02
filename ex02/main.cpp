#include <iostream>

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed d( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::max( b, c ) << std::endl;
return 0;
}

// int main(void)
// {
//   Fixed a = 5.05f;
//   Fixed b = 2.05f;
//   std::cout << (a)  << std::endl;
//   std::cout << (b)  << std::endl;
//   std::cout << (Fixed( a ) + Fixed( b ))  << std::endl;
//   std::cout << (Fixed( a ) - Fixed( b ))  << std::endl;
//   std::cout << (Fixed( a ) * Fixed( b ))  << std::endl;
//   std::cout << (Fixed( a ) / Fixed( b ))  << std::endl;


//   std::cout << (Fixed( 5.05f ) > Fixed( 2 ))  << std::endl;
//   std::cout << (Fixed( 5.05f ) >= Fixed( 2 ))  << std::endl;
//   std::cout << (Fixed( 5.05f ) < Fixed( 2 ))  << std::endl;
//   std::cout << (Fixed( 5.05f ) <= Fixed( 5.05f ))  << std::endl;
//   std::cout << (Fixed( 5.05f ) == Fixed( 5.05f ))  << std::endl;
//   std::cout << (Fixed( 5.05f ) != Fixed( 5.05f ))  << std::endl;
//   return 0;
// }
