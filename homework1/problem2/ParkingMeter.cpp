#include <iostream>

using namespace std;

class ParkingMeter{
    private:
        int maxTime;
        int rate;//minutes per quarter
        int remainingTime;
    public:
        ParkingMeter(int maximumParkingMinutes, int rate){
            maxTime = maximumParkingMinutes;
            this ->rate = rate;
            remainingTime = 0;
        }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
