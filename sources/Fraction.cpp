#include "Fraction.hpp"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;

using namespace ariel;
void MUL_overflow(int num1 , int num2){
  if(num1 == 0 || num2 == 0){
    return;
  }
  int num3 = num1* num2;
  if(num3 /num1 != num2)
    throw std::overflow_error("");
}
void Add_overflow(int num1 , int num2){
  int num3 = num1 + num2;
  if(num1>0 && num2 >0 && num3<0){
    throw std::overflow_error("");
  }
  if(num1<0 && num2 < 0 && num3 > 0){
    throw std::overflow_error("");
  }
}
void Fraction::reduce() { // 2/4 -> 1/2
  int gcd = __gcd(numrator, denominator);
  numrator /= gcd;
  denominator /= gcd;
  if(denominator <0){
    this->numrator *=-1;
    this->denominator *=-1;
  }
}

/* NOTES in the hpp class */

Fraction::Fraction(int numrator, int denominator)
    : numrator(numrator), denominator(denominator) {
      if(denominator == 0)
      {
        throw invalid_argument("");
      }
      
      this->reduce();
}

Fraction::Fraction()
    : numrator(0), denominator(1) {}


Fraction::Fraction(float f_num) {
  numrator = std::floor(f_num * 1000);
  denominator = 1000;
}

Fraction::Fraction(const Fraction &fraction): numrator(fraction.numrator), denominator(fraction.denominator) {
}

/* Operators :*/
const Fraction Fraction::operator+(const Fraction &other) const {
  MUL_overflow(denominator ,other.denominator);
  int new_denominator = denominator * other.denominator;
  Add_overflow(numrator * other.denominator,other.numrator * denominator);
  MUL_overflow(numrator , other.denominator);
  MUL_overflow( other.numrator , denominator);
  int new_numerator =
      numrator * other.denominator + other.numrator * denominator;
  return Fraction(new_numerator, new_denominator);
}
const Fraction Fraction::operator-(const Fraction &other) const {
  int min_int = std::numeric_limits<int>::min();
  if(other.numrator == min_int){
    throw std::overflow_error("");
  }
  return *this +  Fraction(-other.numrator,other.denominator);
}
const Fraction Fraction::operator/(const Fraction &other) const {
  if(other.numrator == 0)
  {
    throw std::runtime_error("");
  }
  return *this * Fraction(other.denominator,other.numrator);
}
const Fraction Fraction::operator*(const Fraction &other) const {
  MUL_overflow(numrator ,other.numrator);
  MUL_overflow(denominator ,other.denominator);
  int new_numerator = numrator * other.numrator;
  int new_denominator = denominator * other.denominator;
  return Fraction(new_numerator, new_denominator);
}

/* Bool :*/
bool Fraction::operator>=(const Fraction &other) const {
  return (numrator * other.denominator) >= (other.numrator * denominator);
}
bool Fraction::operator<=(const Fraction &other) const {
  return (numrator * other.denominator) <= (other.numrator * denominator);
}
bool Fraction::operator>(const Fraction &other) const {
  return (numrator * other.denominator) > (other.numrator * denominator);
}
bool Fraction::operator<(const Fraction &other) const {
  return (numrator * other.denominator) < (other.numrator * denominator);
}
bool Fraction::operator==(const Fraction &other) const {
  int num1 = ((float)this->numrator * 1000)/ this->denominator;
  int num2 = ((float)other.numrator * 1000)/ other.denominator;
  return num1 == num2;
}


/* Float op' fraction :*/
Fraction Fraction::operator+(const float &other) const {
  // Convert the float to a fraction and add it to this fraction
  return *this + Fraction(other);
}
Fraction Fraction::operator-(const float &other) const {
  // Convert the float to a fraction and subtract it from this fraction
  return *this - Fraction(other);
}
Fraction Fraction::operator/(const float &other) const {
  // Convert the float to a fraction and divide this fraction by it
  if (other == 0){
    throw std::runtime_error("");
  }
  return *this / Fraction(other);
}
Fraction Fraction::operator*(const float &other) const {
  // Convert the float to a fraction and multiply it by this fraction
  return *this * Fraction(other);
  ;
}

/* Bool fraction :*/
bool Fraction::operator>=(const float &other) const {
  // Convert the float to a fraction and compare it with this fraction
  return *this >= Fraction(other);
}
bool Fraction::operator<=(const float &other) const {
  // Convert the float to a fraction and compare it with this fraction
  return *this <= Fraction(other);
}
bool Fraction::operator>(const float &other) const {
  // Convert the float to a fraction and compare it with this fraction
  return *this > Fraction(other);
}
bool Fraction::operator<(const float &other) const {
  // Convert the float to a fraction and compare it with this fraction
  return *this < Fraction(other);
}

bool Fraction::operator==(const float &other) const {
  // Convert the float to a fraction and compare it with this fraction
  return *this == Fraction(other);
}

/* Op' :*/
Fraction operator+(const float n, const Fraction &fraction) {
  // Convert the float to a fraction and add it to the given fraction
  return Fraction(n) + fraction;
}
Fraction operator-(const float n, const Fraction &fraction) {
  // Convert the float to a fraction and subtract the given fraction from it
  return Fraction(n) - fraction;
}
Fraction operator/(const float n, const Fraction &fraction) {
  // Convert the float to a fraction and divide it by the given fraction
  if(fraction.numrator == 0)
  {
    throw invalid_argument("");
  }
  return Fraction(n) / fraction;
}
Fraction operator*(const float n, const Fraction &fraction) {
  // Convert the float to a fraction and multiply it by the given fraction
  return Fraction(n) * fraction;
}

/* Bool Op' :*/
bool operator==(const float n, const Fraction &fraction) {
  // Compare the fraction to the float converted to a fraction
  return fraction == Fraction(n);
}
bool operator>=(const float n, const Fraction &fraction) {
  // Compare the fraction to the float converted to a fraction
  return fraction <= Fraction(n);
}
bool operator<=(const float n, const Fraction &fraction) {
  // Compare the fraction to the float converted to a fraction
  return fraction >= Fraction(n);
}
bool operator>(const float n, const Fraction &fraction) {
  // Compare the fraction to the float converted to a fraction
  return fraction < Fraction(n);
}
bool operator<(const float n, const Fraction &fraction) {
  // Compare the fraction to the float converted to a fraction
  return fraction > Fraction(n);
}

/* pre inc' : */
Fraction &Fraction::operator++() {
  numrator += denominator;
  return *this;
}
/* pre dec' : */
Fraction &Fraction::operator--() {
  numrator -= denominator;
  return *this;
}
/* post inc' : */
Fraction Fraction::operator++(int n) {
  Fraction result(*this);
  numrator += denominator;
  return result;
}
/* post dec' : */
Fraction Fraction::operator--(int n) {
  Fraction result(*this);
  numrator -= denominator;
  return result;
}
std::ostream &operator<<(std::ostream &os_Stream, const Fraction &fraction) {
  
  os_Stream << fraction.numrator << "/" << fraction.denominator;
  return os_Stream;
}

std::istream &operator>>(std::istream &is_Stream, Fraction &fraction) {
  int a, b;
  if (!(is_Stream >> a >> b)){
    throw std::runtime_error("");
  }
  if (b == 0){
    throw std::runtime_error("");
  }
  fraction = Fraction(a,b);
  // is_Stream >> fraction.numrator >> fraction.denominator;
  return is_Stream;
}
