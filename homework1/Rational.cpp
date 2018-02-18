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

};

int main()
{
    Rational myFraction(1,4);
    myFraction.add(6,8);
    myFraction.substract(1,8);
    myFraction.multiply(3,4);
    return 0;
}
