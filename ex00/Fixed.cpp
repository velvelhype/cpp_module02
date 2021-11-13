#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
  // fixed_point_value_ = src.getRawBits();
  *this = src;
}

Fixed &Fixed::operator=(const Fixed &tmp) {
  std::cout << "Assignation operator called" << std::endl;
  setRawBits(tmp.getRawBits());
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_value_;
}

void Fixed::setRawBits(int const raw) { fixed_point_value_ = raw; }
