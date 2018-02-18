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
            maxTime = maximumParkingMinutes;//user will define the max amount of time
            this ->rate = rate;//user will define the number of minutes per quarter
            remainingTime = 0;//since no quarters have been added, initial remaining time is 0
        }
//---------- InsertQuarters method -----------------------------------------------------------------------------------------------
    void insertQuarters(int numberOfQuarters){
        if(remainingTime == maxTime){//can't exceed the maximum amount of minutes
            return;//do nothing and end method
        }
        int additionalTime = numberOfQuarters*rate;
        remainingTime += additionalTime;//add the additional time to the remaining time
        if(maxTime <= remainingTime){//check again we haven't exceeded the maximum amount
            remainingTime = maxTime;//if we have, then set the remaining time equal to max
        }
    }
//---------- CheckRemainingTime method -------------------------------------------------------------------------------------------
    int checkRemainingTime(){
        return this -> remainingTime;//return remainingTime
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
