#include <iostream>
#include <stdlib.h>

using namespace std;

class Rational{
    private:
//---------- variables -----------------------------------------------------------------------------------------------------------
        int numerator;
        int denominator;

//---------- We get the Greatest Common Divisor by using the Euclidean method ----------------------------------------------------
        int GCD(int firstNumber, int secondNumber){
            int divided = 0;
            int gcd = 1;
            int remaining = 0;
            /*Euclidean Formula:
            divided = gcd * quotient + remainder*/

            if(firstNumber > secondNumber){
                divided = firstNumber;
                gcd = secondNumber;
            }
            else if(firstNumber == secondNumber){
                divided = firstNumber;
                gcd = secondNumber;
            }
            else{
                divided = secondNumber;
                gcd = firstNumber;
            }
            remaining = divided%gcd;

            while(remaining != 0){
                divided = gcd;
                gcd = remaining;
                remaining = divided%gcd;
            }
            return gcd;
        }

//---------- This method will reduce the fraction by calling the GCD method ------------------------------------------------------
        void reduceFraction(int numerator, int denominator){
            if(numerator == 0){//no need to find a gcd
                cout << numerator << "/" << denominator <<endl;
            }
            else if(numerator < 0){//negative numerator
                int gcd = GCD(numerator*-1, denominator);//make it positive to get the gcd
                cout << numerator/gcd << "/" << denominator/gcd <<endl;//divide the original numerator between the gcd
            }
            else{//both are positive
                int gcd = GCD(numerator, denominator);
                cout << numerator/gcd << "/" << denominator/gcd <<endl;
            }
        }

    public:
//---------- Constructor ---------------------------------------------------------------------------------------------------------
        Rational(int numerator, int denominator){
            if(denominator != 0){
                if(numerator < 0 && denominator > 0){//negative denominator
                    int positiveNumerator = numerator*-1;
                    int gcd = GCD(positiveNumerator,denominator);//we changed the numerator to be positive so the GCD can work
                    setNumerator((positiveNumerator/gcd)*-1);//we set the numerator to its simplest form but back to negative
                    setDenominator(denominator/gcd);//denominator remains positive
                }
                else if(numerator > 0 && denominator < 0){//negative denominator is allowed. They're called improper fractions
                    int positiveDenominator = denominator*-1;
                    int gcd = GCD(numerator,positiveDenominator);//we changed the denominator to be positive so the GCD can work
                    setNumerator((numerator/gcd)*-1);//we change the fraction to proper where the numerator is the only negative
                    setDenominator(positiveDenominator/gcd);//denominator becomes positive
                }
                else if(numerator < 0 && denominator < 0){//both are negative
                    int positiveNumerator = numerator*-1;//we make them positive because -/- = +
                    int positiveDenominator = denominator*-1;
                    int gcd = GCD(positiveNumerator,positiveDenominator);
                    setNumerator(positiveNumerator/gcd);
                    setDenominator(positiveDenominator/gcd);
                }
                else{//both are positive, so we just reduce them
                    int gcd = GCD(numerator,denominator);
                    setNumerator(numerator/gcd);
                    setDenominator(denominator/gcd);
                }
            }
            else{//denominator is zero so the fraction is undefined
                cout << "Denominator can't be zero" <<endl;
                exit(0);
            }

        }
//---------- Setters -------------------------------------------------------------------------------------------------------------
        void setNumerator(int numerator){
            this -> numerator = numerator;
        }
        void setDenominator(int denominator){
            this -> denominator = denominator;
        }

//---------- Getters -------------------------------------------------------------------------------------------------------------
        int getNumerator(){
            return this -> numerator;
        }

        int getDenominator(){
            return this ->denominator;
        }

//---------- Add method ----------------------------------------------------------------------------------------------------------
        void add(int otherNumerator, int otherDenominator){
            if( getDenominator() == otherDenominator){//if both denominators are the same number
                cout << getNumerator()+otherNumerator << "/" << getDenominator()<< endl;//add numerators and use same denominator
            }
            else{
                //do the cross multiplying method
                int newNumerator = getNumerator()*otherDenominator + otherNumerator*getDenominator();
                int newDenominator = getDenominator()*otherDenominator;
                reduceFraction(newNumerator, newDenominator);
            }
        }

//---------- Subtract method -----------------------------------------------------------------------------------------------------
        void substract(int otherNumerator, int otherDenominator){
            if( getDenominator() == otherDenominator){//if both denominators are the same number
                cout << getNumerator()+otherNumerator << "/" << getDenominator()<< endl;//Subtract numerators and use same denominator
            }
            else{
                //do the cross multiplying method
                int newNumerator = getNumerator()*otherDenominator - otherNumerator*getDenominator();
                int newDenominator = getDenominator()*otherDenominator;
                reduceFraction(newNumerator, newDenominator);
            }
        }

//---------- Multiply method -----------------------------------------------------------------------------------------------------
        void multiply(int otherNumerator, int otherDenominator){
            int newNumerator = getNumerator()*otherNumerator;//multiply both numerators
            int newDenominator = getDenominator()*otherDenominator;//multiply both denominators
            reduceFraction(newNumerator, newDenominator);
        }

//---------- Divide method -------------------------------------------------------------------------------------------------------
        void divide(int otherNumerator, int otherDenominator){ // [a/b] / [c/d] = [a*d]/[b*c]
            int newNumerator = getNumerator()*otherDenominator;
            int newDenominator = getDenominator()*otherNumerator;
            reduceFraction(newNumerator, newDenominator);
        }

};
//---------- Main method ---------------------------------------------------------------------------------------------------------
int main()
{
    Rational myFraction(1,4);
    cout <<"myFraction numerator: "<<myFraction.getNumerator()<<endl;
    cout << "myFraction denominator: " << myFraction.getDenominator()<<endl;
    myFraction.add(6,8);
    myFraction.substract(4,8);
    myFraction.multiply(3,4);
    myFraction.divide(2,4);

    Rational fraction2(5,2);
    cout <<"\nFraction2 numerator: "<<fraction2.getNumerator()<<endl;
    cout << "Fraction2 denominator: " << fraction2.getDenominator()<<endl;

    Rational fraction3(-3,12);
    cout <<"\nFraction3 numerator: "<<fraction3.getNumerator()<<endl;
    cout << "Fraction3 denominator: " << fraction3.getDenominator()<<endl;
    fraction3.add(7,9);

    Rational fraction4(10,-5);//fraction with negative denominator is called an improper fraction. Fractions can have negative denominators but
    cout <<"\nFraction4 numerator: "<<fraction4.getNumerator()<<endl;
    cout << "Fraction4 denominator: " << fraction4.getDenominator()<<endl;
    fraction4.substract(-5,2);
    return 0;
}
