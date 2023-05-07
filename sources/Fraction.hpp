#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <math.h>

namespace ariel{}


    class Fraction 
    {
    private:
        int numrator;
        int denominator;

    public:
    /* conversion constructor */
        Fraction(int numrator, int denominator);
        Fraction(float fl_number);
        Fraction();
        Fraction(const Fraction & f);
    
    // reduce
    void reduce(); // 2/4 -> 1/2
    //GET:
        int getNumerator() const
        {
            return this->numrator;
        }
        int getDenominator() const
        {
            return this->denominator;
        }
        
        // void setNumerator(int num) 
        // {
        //     numrator = num;
        // }

        // void setDenominator(int den) 
        // {
        //     denominator = den;
        // }
        /*
        const: the const keyword at the end of the function signature
        indicates that this function is a const member function and
        does not modify the state of the object on which it is called.
        */

        /* Operators For Conversion with one and another :*/
        const Fraction operator+(const Fraction& other) const;
        const Fraction operator/(const Fraction& other) const;
        const Fraction operator-(const Fraction& other) const;
        const Fraction operator*(const Fraction& other) const;

        
        Fraction operator+(const float& other) const;
        Fraction operator-(const float& other) const;
        Fraction operator/(const float& other) const;
        Fraction operator*(const float& other) const;
        

        /* Bool Of the Op' that return T/F:
        (of the other floating-point number,
        that is passed as an argument to the function.)*/

        bool operator>=(const float& other) const;
        bool operator<=(const float& other) const;
        bool operator>(const float& other) const;
        bool operator<(const float& other) const;
        bool operator==(const float& other) const;
        
        

        /* Bool Of the Op' that return T/F:
        (of the other floating-point number,
        that is passed as an argument to the function.)*/

    
        bool operator==(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;

        /* 
        friend: A friend function is allowed to access
        the private and protected members
        of the class as if it were a member of the class.
        used here to allow this function to access the private and
        protected members of the Fraction class,
        specifically the floating-point representation of the Fraction object.
        */

        /* Friend, op' the other side : */
        //function that overloads of the +,*,-,/, operator's to allow Op' between
        //a Fraction object and a floating-point number.
        friend Fraction operator+(const float fl_number, const Fraction& fraction);
        friend Fraction operator/(const float fl_number, const Fraction& fraction);
        friend Fraction operator*(const float fl_number, const Fraction& fraction);
        friend Fraction operator-(const float fl_number, const Fraction& fraction);

        /* Friend, bool op' the other side : */
        friend bool operator==(const float fl_number, const Fraction& fraction);
        friend bool operator==(const float fl_number, const Fraction& fraction);
        friend bool operator<(const float fl_number, const Fraction& fraction);
        friend bool operator>(const float fl_number, const Fraction& fraction);
        friend bool operator<=(const float fl_number, const Fraction& fraction);
        friend bool operator>=(const float fl_number, const Fraction& fraction);

        
        /* Prefix (before inc' and dec') && Postfix (after inc' and dec') : */
        Fraction& operator++();
        Fraction& operator--();
        Fraction operator--(int);
        Fraction operator++(int);
        /*
        operator<< and operator>> are the stream insertion and extraction operators, respectively.
        They are used for input and output operations with stream objects
        such as std::cout, std::cin, and file streams. 
        */
       
        friend std::ostream& operator<<(std::ostream& os_Stream, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& is_Stream, Fraction& fraction);

    };

