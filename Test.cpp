#include <stdio.h>
#include "sources/Fraction.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace ariel;


TEST_CASE("Negative Fraction: ")
{
    /*any frac' here equal to 1/3 || (-1/3)*/
    Fraction frac_1(1, 3);
    Fraction frac_2(1, -3);
    Fraction frac_3(-1, 3);
    Fraction frac_4(-1, -3);
    CHECK_EQ(frac_1, frac_2);
    CHECK_EQ(frac_1, frac_3);
    CHECK_EQ(frac_1, frac_4);
    CHECK_EQ(frac_2, frac_3);
    CHECK_EQ(frac_2, frac_4);
    CHECK_EQ(frac_3, frac_4);
}

TEST_CASE("Positive Fraction: ")
{
    /*any frac' here equal to 3*/
    Fraction frac_1(6, 2);
    Fraction frac_2(21, 7);
    Fraction frac_3(99, 33);
    Fraction frac_4(18, 6);
    CHECK_EQ(frac_1, frac_2);
    CHECK_EQ(frac_1, frac_3);
    CHECK_EQ(frac_1, frac_4);
    CHECK_EQ(frac_2, frac_3);
    CHECK_EQ(frac_2, frac_4);
    CHECK_EQ(frac_3, frac_4);
}

TEST_CASE("Init: ")
{
    CHECK_THROWS(Fraction(2, 0));
    CHECK_NOTHROW(Fraction(0, 2));
    CHECK_NOTHROW(Fraction(1, 3));
}

TEST_CASE("Operators+: ")
{
    Fraction fr_1(1, 3);
    Fraction fr_2(2, 3);
    Fraction fr_3(2, 2);
    CHECK_EQ(fr_1 + fr_2 , Fraction(1, 1));
    CHECK_EQ(fr_1 + fr_2 , fr_3);
    CHECK_EQ(fr_1+fr_2, fr_2+fr_1);
    CHECK_EQ(fr_2+fr_3, fr_3+fr_2);
}

TEST_CASE("Operator-: ")
{
    Fraction fra_1(1, 2);
    Fraction fra_2(1, 2); 
    Fraction fra_3(2, 2);
    CHECK_EQ(fra_1 - fra_2, Fraction(0, 1));
    CHECK_EQ(fra_3 - fra_1 , fra_2);
    CHECK_EQ(fra_1-fra_2, fra_2-fra_1);
    CHECK_EQ(fra_2-fra_3, fra_3-fra_2);
}

TEST_CASE("Operator*: ")
{
    Fraction frac__1(1, 2);
    Fraction frac__2(1, 2); 
    Fraction frac__3(1, 4);
    Fraction f11(1, 8);
    Fraction f22(1, 32);
    CHECK((frac__1 * frac__2) == frac__3);
    CHECK((frac__1 * frac__3) == f11);
    CHECK((frac__3 * f11) == f22);
}

TEST_CASE("Operator/: ")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2); 
    Fraction f3(2, 2);
    Fraction f__11(12, 4);
    Fraction f__12(24, 4);
    Fraction fr(2, 1);
    CHECK((f1 / f2) == f3);
    CHECK((f__11 / f2) == f__12);
    CHECK((f__11 / f__12) == fr);
}

TEST_CASE("Operator ++, --: ")
{
    Fraction _f(-1, 2);
    Fraction ff(-1, 2);
    Fraction fff(2, 4);
    CHECK_NOTHROW(_f++);
    CHECK_NOTHROW(--_f);
    CHECK_NOTHROW(fff++);
    CHECK_NOTHROW(--fff);
    CHECK(++ff == fff);
    CHECK(--fff == _f);    
}

Fraction f_01(1, 2);
Fraction f_02(1, 1);
Fraction f_03(2, 2);
Fraction f_04(2, 1);
Fraction f_05(8, 16);
Fraction f_06(8, 4);
Fraction f_07(10, 5);


TEST_CASE("Bool operators < : ")
{
    CHECK((f_01 < f_02) == true);
    CHECK((f_01 < f_04) == true); 
    CHECK((f_01 < f_03) == true); 
    CHECK((f_05 < f_04) == true); 
    CHECK((f_05 < f_01) == true); 
}

TEST_CASE("Bool operator > : ")
{
    CHECK((f_02 > f_01) == true);
    CHECK((f_03 > f_01) == true); 
    CHECK((f_04 > f_05) == true); 
    CHECK((f_01 > f_05) == true);
}
TEST_CASE("Bool operator >= : ")
{
    CHECK((f_03 >= f_02) == true);
    CHECK((f_02 >= f_01) == true);
    CHECK((f_03 >= f_01) == true); 
    CHECK((f_04 >= f_05) == true); 
    CHECK((f_01 >= f_05) == true);
}
TEST_CASE("Bool operator <= : ")
{
    CHECK((f_01 <= f_02) == true);
    CHECK((f_01 <= f_02) == true);
    CHECK((f_01 <= f_04) == true); 
    CHECK((f_01 <= f_03) == true); 
    CHECK((f_05 <= f_04) == true); 
    CHECK((f_05 <= f_01) == true); 
    CHECK((f_02 <= f_04) == true);
}

TEST_CASE("Bool operator == : ")
{
    CHECK((f_02 == f_03) == true);
    CHECK((f_04 == f_06) == true);
    CHECK((f_07 == f_06) == true);
    CHECK((f_07 == f_04) == true);
}

TEST_CASE("Bool operator != : ")
{
    CHECK((f_01 != f_02) == true);
    CHECK((f_04 != f_03) == true);
    CHECK((f_05 != f_07) == true);
    CHECK((f_03 != f_05) == true);
    CHECK((f_03 != f_07) == true);
}
