#include <iostream>
using namespace std;

//simulation check
//automation pending

class Devices{
    public:
        virtual void onConnect(){}
        virtual void onDisconnect(){}
        virtual ~Devices(){}
};
class TemperatureSensor : public Devices{
    private:
        float temperature;
        bool isConnected;
    public:
        TemperatureSensor() : temperature(33.0), isConnected(false) {}
        void onTempChange(float temp){
            temperature = temp;
            cout << "Temperature changed to: " << temperature << endl;
        }
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        float getTemperature(){
            return temperature;
        }
        bool getConnection(){
            return isConnected;
        }
};
class MotionSensor : public Devices{
    private:
        bool isOn;
        bool isConnected;
    public:
        MotionSensor() : isOn(false), isConnected(false){}
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        void turnOn(){
            isOn = true;
            cout << "Motion sensor is turned on!" << endl;
        }
        void turnOff(){
            isOn = false;
            cout << "Motion sensor is turned off!" << endl;
        }
    void getStatus(){
        if(isOn) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    bool getConnection(){
        return isConnected;
    }
};
class WaterSensor : public Devices{
    private:
        bool isOn;
        bool isConnected;
    public:
        WaterSensor() : isOn(false), isConnected(false){}
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        void turnOn(){
            isOn = true;
            cout << "Water level sensor is turned on!" << endl;
        }
        void turnOff(){
            isOn = false;
            cout << "Water level sensor is turned off!" << endl;
        }
    void getStatus(){
        if(isOn) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    bool getConnection(){
        return isConnected;
    }
};
class GasSensor : public Devices{
    private:
        bool isOn;
        bool isConnected;
    public:
        GasSensor() : isOn(false), isConnected(false){}
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        void turnOn(){
            isOn = true;
            cout << "Gas detection sensor is turned on!" << endl;
        }
        void turnOff(){
            isOn = false;
            cout << "Gas detection sensor is turned off!" << endl;
        }
    void getStatus(){
        if(isOn) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    bool getConnection(){
        return isConnected;
    }
};
class Fan : public Devices{
    private:
        bool isOn;
        bool isConnected;
    public:
        Fan() : isOn(false), isConnected(false){}
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        void turnOn(){
            isOn = true;
            cout << "Fan is turned on!" << endl;
        }
        void turnOff(){
            isOn = false;
            cout << "Fan is turned off!" << endl;
        }
    void getStatus(){
        if(isOn) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    bool getConnection(){
        return isConnected;
    }
};
class Light : public Devices{
    private:
        bool isOn;
        bool isConnected;
    public:
        Light() : isOn(false){}
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        void turnOn(){
            isOn = true;
            cout << "Light is turned on!" << endl;
        }
        void turnOff(){
            isOn = false;
            cout << "Light is turned off!" << endl;
        }
    void getStatus(){
        if(isOn) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    bool getConnection(){
        return isConnected;
    }
};
class Door : public Devices{
    private:
        bool isOpen;
        bool isConnected;
    public:
        Door() : isOpen(false){}
        void onConnect() override {
            isConnected = true;
            cout << "(Device is connected!)" << endl << endl;
        }
        void onDisconnect() override {
            isConnected = false;
            cout << "(Device is disconnected!)" << endl << endl;
        }
        void openDoor(){
            isOpen = true;
            cout << "Door opened!" << endl;
        }
        void closeDoor(){
            isOpen = false;
            cout << "Door closed!" << endl;
        }
    void getStatus(){
        if(isOpen) cout << "OPEN" << endl;
        else cout << "CLOSED" << endl;
    }
    bool getConnection(){
        return isConnected;
    }
};


void simulateInput(unordered_map<string, Devices*>& devices){
    string s;
    string action;
    int points;
    cout << "Choose sensor(temperature, motion, water, gas, fan, light, door): ";
    cin >> s;

    if (s == "temperature"){
        TemperatureSensor* tempSensor = dynamic_cast<TemperatureSensor*>(devices["TemperatureSensor"]);
        if(!tempSensor->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            cout << endl;
            if(action == "yes"){
                tempSensor->onConnect();
            }
            else{
                return;
            }
        }
        if(tempSensor->getConnection()){
            cout << "Choose action(increase, decrease, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "increase"){
                cout << "Enter points: ";
                cin >> points;
                cout << endl;
                tempSensor->onTempChange(tempSensor->getTemperature() + (float)points);
            }
            if(action == "decrease"){
                cout << "Enter points: ";
                cin >> points;
                cout << endl;
                tempSensor->onTempChange(tempSensor->getTemperature() - (float)points);
            }
            if(action == "disconnect"){
                tempSensor->onDisconnect();
            }
        }
    }
    else if (s == "motion"){

        MotionSensor* motionSensor = dynamic_cast<MotionSensor*>(devices["MotionSensor"]);
        if(!motionSensor->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            cout << endl;
            if(action == "yes"){
                motionSensor->onConnect();
            }
            else{
                return;
            }
        }
        if(motionSensor->getConnection()){
            cout << "Choose action(on, off, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "on"){
                motionSensor->turnOn();
            }
            if(action == "off"){
                motionSensor->turnOff();
            }
            if(action == "disconnect"){
                motionSensor->onDisconnect();
            }
        }
    }
    else if (s == "water"){
        WaterSensor* waterSensor = dynamic_cast<WaterSensor*>(devices["WaterSensor"]);
        if(!waterSensor->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            cout << endl;
            if(action == "yes"){
                waterSensor->onConnect();
            }
            else{
                return;
            }
        }
        if(waterSensor->getConnection()){
            cout << "Choose action(on, off, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "on"){
                waterSensor->turnOn();
            }
            if(action == "off"){
                waterSensor->turnOff();
            }
            if(action == "disconnect"){
                waterSensor->onDisconnect();
            }
        }
    }
    else if (s == "gas"){
        GasSensor* gasSensor = dynamic_cast<GasSensor*>(devices["GasSensor"]);
        if(!gasSensor->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            if (action == "yes"){
                gasSensor->onConnect();
            }
            else{
                return;
            }
        }
        if(gasSensor->getConnection()){
            cout << "Choose action(on, off, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "on"){
                gasSensor->turnOn();
            }
            if(action == "off"){
                gasSensor->turnOff();
            }
            if(action == "disconnect"){
                gasSensor->onDisconnect();
            }
        }
    }
    else if (s == "fan"){
        Fan* fan = dynamic_cast<Fan*>(devices["Fan"]);
        if(!fan->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            if (action == "yes"){
                fan->onConnect();
            }
            else{
                return;
            }
        }
        if(fan->getConnection()){
            cout << "Choose action(on, off, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "on"){
                fan->turnOn();
            }
            if(action == "off"){
                fan->turnOff();
            }
            if(action == "connect"){
                fan->onConnect();
            }
            if(action == "disconnect"){
                fan->onDisconnect();
            }
        }
    }
    else if (s == "light"){
        Light* light = dynamic_cast<Light*>(devices["Light"]);
        if(!light->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            if (action == "yes"){
                light->onConnect();
            }
            else{
                return;
            }
        }
        if(light->getConnection()){
            cout << "Choose action(on, off, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "on"){
                light->turnOn();
            }
            if(action == "off"){
                light->turnOff();
            }
            if(action == "connect"){
                light->onConnect();
            }
            if(action == "disconnect"){
                light->onDisconnect();
            }
        }
    }
    else if (s == "door"){
        Door* door = dynamic_cast<Door*>(devices["Door"]);
        if(!door->getConnection()){
            cout << "Wanna connect the device first (yes/no) : ";
            cin >> action;
            if (action == "yes"){
                door->onConnect();
            }
            else{
                return;
            }
        }
        if(door->getConnection()){
            cout << "Choose action(open, close, disconnect): ";
            cin >> action;
            cout << endl;
            if(action == "open"){
                door->openDoor();
            }
            if(action == "close"){
                door->closeDoor();
            }
            if(action == "disconnect"){
                door->onDisconnect();
            }
        }
    }
    else{
        cout << "Enter a valid Device";
    }
    cout << endl << endl;
}


void setupAutomations(const unordered_map<string, Devices*>& devices, vector<function<void()>>& automations){

    //turning off light and closing door when temp is < 20
    automations.emplace_back([devices](){
        TemperatureSensor* temp = dynamic_cast<TemperatureSensor*>(devices.at("TemperatureSensor"));
        Fan* fan = dynamic_cast<Fan*>(devices.at("Fan"));
        Door* door = dynamic_cast<Door*>(devices.at("Door"));

        if(temp && fan && door){
            float currTemp = temp->getTemperature();
            if(currTemp < 20.0 && fan->getConnection() && door->getConnection()){
                cout << "[Automation] Temperature less than 20 detected. Turning off the fan and closing the door.\n";
                fan->turnOff();
                door->closeDoor();
            }
            else if(currTemp > 40.0 && fan->getConnection() && door->getConnection()){
                cout << "[Automation] Temperature greater than 40 detected. Turning on the fan and opening the door.\n";
                fan->turnOn();
                door->openDoor();
            }
        }
    });


    //turning on light when there is motion
    automations.emplace_back([devices](){
        MotionSensor* motion = dynamic_cast<MotionSensor*>(devices.at("MotionSensor"));
        Light* light = dynamic_cast<Light*>(devices.at("Light"));

        if (motion && light){ 
            if (motion->getConnection() && light->getConnection()) {
                cout << "[Automation] Motion detected. Turning on the light.\n";
                light->turnOn();
            }
        }
    });
}

void executeAutomations(vector<function<void()>>& automations) {
    for(auto& automation : automations){
        automation();
    }
}

int main(){
    unordered_map<string, Devices*> devices; //initializing classes - it is always safe to denote it as a pointer
    devices["TemperatureSensor"] = new TemperatureSensor();
    devices["MotionSensor"] = new MotionSensor();
    devices["WaterSensor"] = new WaterSensor();
    devices["GasSensor"] = new GasSensor();
    devices["Fan"] = new Fan();
    devices["Light"] = new Light();
    devices["Door"] = new Door();

    vector<function<void()>> automations;
    setupAutomations(devices, automations);

    int choice;
    while(true){
        cout << "1. Simulate Input \n2. Device Automation \n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                simulateInput(devices);
                executeAutomations(automations);
                break;
            case 2: 
                executeAutomations(automations);
                break;
            case 3:
                for(auto& pair: devices){
                    delete pair.second;
                }
                cout << "Exiting the program.";
                break;
            default:
                break;
        }
    }
}
