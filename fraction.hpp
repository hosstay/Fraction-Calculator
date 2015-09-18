/***************************************************************************** 
   Taylor Hoss
   X432Z869 
   Program #3

   This program implements the Fraction class which allows the user to make
   instances of fractions and then do certain manipulations to them:
   returning decimal value, returning reduced fraction, adding, subtracting,
   multiplying, and dividing the fractions using operator overloading.
    

   Psuedo Code
      Class Name: Fraction
      Data:
         num
         den
      Mutator Functions:
         Fraction()
         Fraction(input, input)
      Accessor Functions:
         get_num
         get_den
         get_decimalValue
         reduce
         operator+
         operator-
         operator*
         operator/

*/

class Fraction
{

   //data
   int num, den;

 public:
   //mutator functions
   //constructors
   Fraction();
   Fraction(int n, int d);

   //accessor functions
   int get_num();
   int get_den();
   double get_decimalValue();
   Fraction reduce();
   Fraction operator+(Fraction f);
   Fraction operator-(Fraction f);
   Fraction operator*(Fraction f);
   Fraction operator/(Fraction f);

};
