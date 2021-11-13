#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : fixed_point_value_(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  // std::cout << "Copy constructor called" << std::endl;
  // fixed_point_value_ = src.getRawBits();
  *this = src;
}

Fixed &Fixed::operator=(const Fixed &tmp) {
  // std::cout << "Assignation operator called" << std::endl;
  setRawBits(tmp.getRawBits());
  return *this;
}

Fixed &Fixed::operator++() {
  // std::cout << "++a" << std::endl;
  fixed_point_value_ += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  // std::cout << "a++" << std::endl;
  Fixed prev = *this;
  ++*this;
  return prev;
}

Fixed Fixed::operator*(const Fixed &tmp) {
  // std::cout << "Fixed * Fixed" << std::endl;
  Fixed n(this->toFloat() * tmp.toFloat());
  return n;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  if (f1.getRawBits() > f2.getRawBits()) {
    return f1;
  } else {
    return f2;
  }
}

Fixed::Fixed(int const val) {
  // std::cout << "Int constructor called" << std::endl;
  fixed_point_value_ = val << fractional_bits_;
}

Fixed::Fixed(float const val) {
  // std::cout << "Float constructor called" << std::endl;
  fixed_point_value_ = roundf(val * (float)(1 << fractional_bits_));
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_value_;
}

void Fixed::setRawBits(int const raw) { fixed_point_value_ = raw; }

float Fixed::toFloat() const {
  return fixed_point_value_ / (float)(1 << fractional_bits_);
}

int Fixed::toInt(void) const { return fixed_point_value_ >> fractional_bits_; }

std::ostream &operator<<(std::ostream &stream, const Fixed &value) {
  return stream << value.toFloat();
}
