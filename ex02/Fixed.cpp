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

Fixed::Fixed(int const val) {
  // std::cout << "Int constructor called" << std::endl;
  fixed_point_value_ = val << fractional_bits_;
}

Fixed::Fixed(float const val) {
  // std::cout << "Float constructor called" << std::endl;
  fixed_point_value_ = roundf(val * (float)(1 << fractional_bits_));
}
 //assign

Fixed &Fixed::operator=(const Fixed &tmp) {
  // std::cout << "Assignation operator called" << std::endl;
  setRawBits(tmp.getRawBits());
  return *this;
}

//comparisons >, >=, <=, <, ==,!=.
// bool  Fixed::operator>(const Fixed &tmp)
// { return (getRawBits() > tmp.getRawBits());}

bool	Fixed::operator>(const Fixed &tmp) const
{return (this->getRawBits() > tmp.getRawBits());}

bool  Fixed::operator>=(const Fixed &tmp)const
{ return (getRawBits() >= tmp.getRawBits());}

bool  Fixed::operator<(const Fixed &tmp) const
{ return (getRawBits() < tmp.getRawBits());}

bool  Fixed::operator<=(const Fixed &tmp)const
{ return (getRawBits() <= tmp.getRawBits());}

bool  Fixed::operator==(const Fixed &tmp)const
{ return (getRawBits() == tmp.getRawBits());}

bool  Fixed::operator!=(const Fixed &tmp)const
{ return (getRawBits() != tmp.getRawBits());}

// in/de crements
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

Fixed &Fixed::operator--() {
  // std::cout << "++a" << std::endl;
  fixed_point_value_ -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  // std::cout << "a++" << std::endl;
  Fixed prev = *this;
  --*this;
  return prev;
}

// four srithmetricts
Fixed Fixed::operator+(const Fixed &tmp)
{ return (Fixed(this->toFloat() + tmp.toFloat()));}

Fixed Fixed::operator-(const Fixed &tmp)
{ return (Fixed(this->toFloat() - tmp.toFloat()));}

Fixed Fixed::operator*(const Fixed &tmp)
{ return (Fixed(this->toFloat() * tmp.toFloat()));}

Fixed Fixed::operator/(const Fixed &tmp)
{ return (Fixed(this->toFloat() / tmp.toFloat()));}


//max min

// Fixed	&Fixed::max(Fixed &a, Fixed &b)
// {
//     return (a > b ? a : b);
// }

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

//min

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

//getters
int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_value_;
}

float Fixed::toFloat() const {
  return fixed_point_value_ / (float)(1 << fractional_bits_);
}

int Fixed::toInt(void) const { return fixed_point_value_ >> fractional_bits_; }

//setter
void Fixed::setRawBits(int const raw) { fixed_point_value_ = raw; }

std::ostream &operator<<(std::ostream &stream, const Fixed &value) {
  return stream << value.toFloat();
}
