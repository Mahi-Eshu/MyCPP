#include <iostream>
#include <string>
using namespace std;


//1_creating a class for Vehicle
class Vehicle{
    private:
        string vehicleType;
        string brand;
        string model;
        string color;
        double mileage;
        double price;
    public:
        Vehicle(string vehicleType, string brand, string model, string color, double mileage, double price){
            this->vehicleType = vehicleType;
            this->brand = brand;
            this->model = model;
            this->color = color;
            this->mileage = mileage;
            this->price = price;
        }

        //3_an abstract method for getting number of wheels
        virtual int getNoOfWheels() const = 0;


        //4_overloading the << operator to display vehicle details
        friend ostream& operator<<(ostream& os, const Vehicle& vehicle){
            os << " Brand: " << vehicle.brand << "/ Model: " << vehicle.model
               << "/ Color: " << vehicle.color << "/ Mileage: " << vehicle.mileage
               << "/ Price: " << vehicle.price;
            return os;
        }   

        //5_overloading < and > to compare the vehicles based on their price
        bool operator<(const Vehicle& vehicle) const {
            return this->price < vehicle.price;
        }
        bool operator>(const Vehicle& vehicle) const {
            return this->price > vehicle.price;
        }
    public:
        void getDetails(){
            cout << "Vehicle Type -> " << vehicleType << endl;
            cout << "Brand -> " << brand << endl;
            cout << "Model -> " << model << endl;
            cout << "Color -> " << color << endl;
            cout << "Mileage -> " << mileage << endl;
            cout << "Price -> " << price << endl;
        }
};

//2_inheriting Bike and Car from Vehicle
class Bike : public Vehicle{
    private:
        int weight;
        string bikeType;
    public:
        Bike(string brand, string model, string color, double mileage, double price, int weight, string bikeType) : Vehicle("Bike", brand, model, color, mileage, price){
        }
        int getNoOfWheels() const{
            return 2;
        }
};
class Car : public Vehicle{
    private:
        int seats;
        string carType;
    public:
        Car(string brand, string model, string color, double mileage, double price, int seats, string carType) : Vehicle("Car", brand, model, color, mileage, price){
        }
        int getNoOfWheels() const{
            return 4;
        }
};


int main(){
    Car car1("Hyundai", "i20", "Grey", 21.02, 605400.00, 5, "Sedan");
    Car car2("Toyota", "Camry", "White", 23.60, 750000.00, 5, "Sedan");

    Bike bike1("Yamaha", "FZ", "Black", 45.1, 145000.00, 150, "Motorbike");
    Bike bike2("Honda", "Activa", "Red", 35.04, 105000.00, 110, "Scooter");

    //since operator << is overloaded, it will print the details in the format in line 30
    cout << "Car 1 ->" << car1 << endl;
    cout << "Car 2 ->" << car2 << endl;
    cout << "Bike 1 ->" << bike1 << endl;
    cout << "Bike 2 ->" << bike2 << endl;
    cout << endl;

    //getting number of wheels
    cout << "Car has " << car1.getNoOfWheels() << " wheels" << endl;
    cout << "Bike has " << bike1.getNoOfWheels() << " wheels" << endl;

    //comparing the price
    cout << "\nComparing the prices of Cars" << endl;
    if(car1 < car2){
        cout << "Car 1 is cheaper than car 2";
    }
    else{
        cout << "Car 2 is cheaper than car 1";
    }

    cout << "\n\nComparing the prices of Bikes" << endl;
    if(bike1 < bike2){
        cout << "Bike 1 is cheaper than bike 2";
    }
    else{
        cout << "Bike 2 is cheaper than bike 1";
    }
    return 0;
}

//to execute

//  g++ VehicleTask.cpp
//  ./a.out