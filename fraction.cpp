/***************************************************************************** 
   Taylor Hoss
   X432Z869
   Program #3 
   
*/

#include "fraction.hpp" 

//mutator functions
//constructors
Fraction::Fraction(void)
{
   num = 1;
   den = 1;
}

Fraction::Fraction(int n, int d)
{
   num = n;
   den = d;
}

//accessor functions
int Fraction::get_num()
{
   return num;
}

int Fraction::get_den()
{
   return den;
}

double Fraction::get_decimalValue()
{
   return (double(num) / double(den));
}

Fraction Fraction::reduce()
{
   Fraction f;
   int wholePart = 0;
   int remainder;

   //setting up temp to be used for mathmatical operations
   f.num = num;
   f.den = den;

   //if the numerator is greater than the denominator then pull out
   //whole parts until the numerator is smaller, allowing for
   //GCD calculation to take place.
   while(f.num > f.den)
   {
      f.num -= f.den;
      wholePart++;
   }
   
   //loops through the GCD calculation until the remainder is 0
   //which tells us that the last number divided by is the GCD
   do
   {
      while(f.den >= f.num)
      {
         f.den -= f.num;
      }

      remainder = f.den;
      f.den = f.num;

      if (remainder != 0)
      {
         f.num = remainder;
      }
   }
   while(remainder != 0);

   //finally using the GCD to simplify the input fraction
   f.num = num / f.num;
   f.den = den / f.den;

   //adding back in the whole part to the numerator since the
   //fraction class has no way to send back data on whole parts
   if (wholePart > 0)
   {
      f.num += ( wholePart * f.den );
   }

   return f;
}

Fraction Fraction::operator+(Fraction f)
{
   Fraction f3;

   //if the denominators are equal you just have to add the numerators
   if (den == f.den)
   {
      f3.num = num + f.num;
   }
   //otherwise multiply the denominators and multiply the numerators by the
   //others denominator
   else
   {
      f3.den = den * f.den;
      f3.num = (num * f.den)+(f.num * den);
   }

   return f3;
}

Fraction Fraction::operator-(Fraction f)
{
   Fraction f3;

   //same as operator+ implementation just wish subtraction
   if (den == f.den)
   {
      f3.num = num - f.num;
   }
   else
   {
      f3.den = den * f.den;
      f3.num = (num * f.den)-(f.num * den);
   }

   return f3;
}

Fraction Fraction::operator*(Fraction f)
{
   Fraction f3;

   f3.num = num * f.num;
   f3.den = den * f.den;

   return f3;
}

Fraction Fraction::operator/(Fraction f)
{
   Fraction f3;
   
   //flip the numerator and denominator of the second fraction so 
   //you can just multiply them together.
   f3.num = f.num;
   f.num = f.den;
   f.den = f3.num;

   f3.num = num * f.num;
   f3.den = den * f.den;

   return f3;
}
