#include <iostream>

using namespace std;

class ParkingMeter{
//---------- variables -----------------------------------------------------------------------------------------------------------
    private:
        int maxTime;
        int rate;//minutes per quarter
        int remainingTime;

    public:
//---------- Constructor ---------------------------------------------------------------------------------------------------------
        ParkingMeter(int maximumParkingMinutes, int rate){
            setMaxTime(maximumParkingMinutes);//user will define the max amount of time
            setRate(rate);//user will define the number of minutes per quarter
            setRemainingTime(0);//since no quarters have been added, initial remaining time is 0
        }

//---------- Setters -------------------------------------------------------------------------------------------------------------
        void setMaxTime(int maximumTime){
            maxTime = maximumTime;
        }

        void setRate(int rate){
            this ->rate = rate;
        }

        void setRemainingTime(int time){
            remainingTime = time;
        }

//---------- Getters -------------------------------------------------------------------------------------------------------------
        int getMaxTime(){
            return this ->maxTime;
        }

        int getRate(){
            return this ->rate;
        }

        int getRemainingTime(){
            return this ->remainingTime;
        }
//---------- InsertQuarters method -----------------------------------------------------------------------------------------------
        void insertQuarters(int numberOfQuarters){
            if(getRemainingTime() == getMaxTime()){//can't exceed the maximum amount of minutes
                return;//do nothing and end method
            }
            int additionalTime = numberOfQuarters*rate;
            remainingTime += additionalTime;//add the additional time to the remaining time
            if(getMaxTime() <= getRemainingTime()){//check again we haven't exceeded the maximum amount
                setRemainingTime(getMaxTime());//if we have, then set the remaining time equal to max
            }
        }
//---------- CheckRemainingTime method -------------------------------------------------------------------------------------------
        int checkRemainingTime(){
            return getRemainingTime();//return remainingTime
            }

};
//---------- main method ---------------------------------------------------------------------------------------------------------
int main(){
    ParkingMeter pm1(50, 5);//50 minutes max, 5 minutes per quarter
    cout << "Remaining time: " << pm1.checkRemainingTime()<<endl;//no quarters added, no remaining time
    pm1.insertQuarters(4);
    cout << "Remaining time: " << pm1.checkRemainingTime()<<endl;
    pm1.insertQuarters(5);
    cout << "Remaining time: " << pm1.checkRemainingTime()<<endl;
    pm1.insertQuarters(8);
    cout << "Remaining time: " << pm1.checkRemainingTime()<<endl;
    pm1.insertQuarters(3);
    cout << "Remaining time: " << pm1.checkRemainingTime()<<endl;
    pm1.insertQuarters(9);
    cout << "Remaining time: " << pm1.checkRemainingTime()<<endl;
}
