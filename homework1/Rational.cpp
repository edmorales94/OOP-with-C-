#include <iostream>
#include <typeinfo>

using namespace std;

class Rational{
    private:
        int numerator;
        int denominator;
    public:
        Rational(int numerator, int denominator){
            setNumerator(numerator);
            if(denominator > 0){
                setDenominator(denominator);
            }
            else{
                cout << "Denominator can't be zero or less" <<endl;
            }

        }
        void setNumerator(int numerator){
            this -> numerator = numerator;
        }
        void setDenominator(int denominator){
            this -> denominator = denominator;
        }

        int getNumerator(){
            return this -> numerator;
        }

        int getDenominator(){
            return this ->denominator;
        }

        int GCD(int firstNumber, int secondNumber){
            int divided = 0;
            int gcd = 1;
            int remaining = 0;
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
            cout<<gcd<<endl;
            return gcd;
        }
        void add(int otherNumerator, int otherDenominator){
            if( getDenominator() == otherDenominator){
                cout << getNumerator()+otherNumerator << "/" << getDenominator()<< endl;
            }
            else{
                int newNumerator = getNumerator()*otherDenominator + otherNumerator*getDenominator();
                int newDenominator = getDenominator()*otherDenominator;
                cout << newNumerator << "/" << newDenominator<< endl;
            }
        }

        void substract(int otherNumerator, int otherDenominator){
            if( getDenominator() == otherDenominator){
                cout << getNumerator()+otherNumerator << "/" << getDenominator()<< endl;
            }
            else{
                int newNumerator = getNumerator()*otherDenominator - otherNumerator*getDenominator();
                int newDenominator = getDenominator()*otherDenominator;
                cout << newNumerator << "/" << newDenominator<< endl;
            }
        }

        void multiply(int otherNumerator, int otherDenominator){
            int newNumerator = getNumerator()*otherNumerator;
            int newDenominator = getDenominator()*otherDenominator;
            cout << newNumerator << "/" << newDenominator<< endl;
        }

        void divide(int otherNumerator, int otherDenominator){
            int newNumerator = getNumerator()*otherDenominator;
            int newDenominator = getDenominator()*otherNumerator;
            cout << newNumerator << "/" << newDenominator<< endl;
        }

};

int main()
{
    Rational myFraction(1,4);
    myFraction.add(6,8);
    myFraction.substract(1,8);
    myFraction.multiply(3,4);
    myFraction.divide(2,3);
    myFraction.GCD(10,45);
    myFraction.GCD(10,12);
    myFraction.GCD(31,15);
    myFraction.GCD(30,6);
    myFraction.GCD(11,22);
    myFraction.GCD(100,28);
    return 0;
}
