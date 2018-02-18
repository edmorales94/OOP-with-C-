#include <iostream>

using namespace std;

class Car{
//---------- Variables -----------------------------------------------------------------------------------------------------------
    private:
        int fuelEfficiency;//miles per gallon
        int fuelLevel;//gallons in the tank

    public:
//---------- Constructor ---------------------------------------------------------------------------------------------------------
        Car(int fuelEfficiency){
            setEfficiency(fuelEfficiency);
            setFuelLevel(0);
        }

//---------- Setters -------------------------------------------------------------------------------------------------------------
        void setEfficiency(int efficiency){
            fuelEfficiency = efficiency;
        }

        void setFuelLevel(int fuel){
            fuelLevel = fuel;
        }

//---------- Getters -------------------------------------------------------------------------------------------------------------
        int getFuelEfficiency(){
            return fuelEfficiency;
        }

        int getGas(){
            return fuelLevel;
        }

//---------- addGas method -------------------------------------------------------------------------------------------------------
        void addGas(int gallonsToAdd){
            setFuelLevel(getGas()+gallonsToAdd);
        }

//---------- drive method --------------------------------------------------------------------------------------------------------
        void drive(int milesTravelled){
            int gallonsToRemove = (int)(milesTravelled/getFuelEfficiency());//get how many gallons were used to travel that distance
            setFuelLevel(getGas()-gallonsToRemove);//update the level of gallons remaining
            if(getGas()< 0){//make sure we don't get less than 0 gallons
                setFuelLevel(0);
            }
        }

};

//---------- main method ---------------------------------------------------------------------------------------------------------

int main(){
    Car ToyotaPrius(52);
    cout << "You have : " << ToyotaPrius.getGas() << " gallons remaining" << endl;
    ToyotaPrius.addGas(20);
    cout << "You have : " << ToyotaPrius.getGas() << " gallons remaining" << endl;
    ToyotaPrius.drive(120);
    cout << "You have : " << ToyotaPrius.getGas() << " gallons remaining" << endl;
    ToyotaPrius.drive(839);
    cout << "You have : " << ToyotaPrius.getGas() << " gallons remaining" << endl;
    ToyotaPrius.drive(156);
    cout << "You have : " << ToyotaPrius.getGas() << " gallons remaining" << endl;
    ToyotaPrius.addGas(28);
    cout << "You have : " << ToyotaPrius.getGas() << " gallons remaining" << endl;

    return 0;
}
