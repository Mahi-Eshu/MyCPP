#include <iostream>
#include <string>
#include <vector>

using namespace std;



class MobileConnection{
    private:
        string number;
        double bill;
    public:
        MobileConnection(string n, double b): number(n), bill(b) {}

        string getNumber(){
            return number;
        }
        double getBill(){
            return bill;
        }
        void payBill(){
            bill = 0.0;
        }
        void setBill(double amount){
            bill += amount;
        }
};
class LandlineConnection{
    private:
        string stdCode;
        string number;
        double bill;
    public:
        LandlineConnection(string s, string n, double b): stdCode(s), number(n), bill(b) {}
        string getSTDCode(){
            return stdCode;
        }
        string getNumber(){
            return number;
        }
        double getBill(){
            return bill;
        }
        void payBill(){
            bill = 0.0;
        }
        void setBill(double amount){
            bill += amount;
        }
};


template <typename T>
class ZohoBillingSystem;

template<>
class ZohoBillingSystem<MobileConnection>{
    private:
        vector<MobileConnection> connections;
    public:
        void addConnection(string m, double b){
            //lambda expression
            auto it = find_if(connections.begin(), connections.end(), [&](MobileConnection conn){
                return conn.getNumber() == m;
            });
            if (it != connections.end()){
                cout << "This mobile connection already exists." << endl;
                return;
            }
            if (m.length() != 10 || !all_of(m.begin(), m.end(), ::isdigit)){
                cout << "Invalid mobile number. It should be a 10-digit number." << endl;
                return;
            }
            connections.emplace_back(m, b);
            cout << "New mobile connection added!" << endl;
        }
        void payingBill(string m){
            if (connections.empty()){
                cout << "Zero mobile connections" << endl;
                return;
            }

            bool found = false;
            for(MobileConnection& conn : connections){ // Iterate by reference
                if(conn.getNumber() == m){
                    found = true;
                    if(conn.getBill() == 0.0){
                        cout << "Bill already paid for this mobile number." << endl;
                    }else{
                        conn.payBill();
                        cout << "Bill amount paid!" << endl;
                    }
                    break;
                }
            }
            if (!found){
                cout << "Check your mobile number." << endl;
            }
        }
        void updateBill(string m, double amount){
            if(connections.empty()){
                cout << "Zero mobile connections" << endl;
                return;
            }
            bool found = false;
            for(MobileConnection& connection : connections){
                if(connection.getNumber() == m){
                    found = true;
                    if(amount < 0){
                        cout << "Amound cannot be negative" << endl;
                    }
                    else{
                        connection.setBill(amount);
                        cout << "Bill amount set newly" << endl;
                    }
                    break;
                }
                if(!found){
                    cout << "Check your mobile number again" << endl;
                }
            }
        }
        void displayConnections(){
            if(connections.empty()){
                cout << "Zero mobile connections" << endl;
                return;
            }
            for(MobileConnection& connection : connections){
                cout << "\n\nMobile Number: " << connection.getNumber() << endl
                     << "Pending Bill Amount: " << connection.getBill() << endl
                     << "-----------------------------------------" << endl;
            }
        }
};

template<>
class ZohoBillingSystem<LandlineConnection>{
    private: 
        vector<LandlineConnection> connections;
    public: 
        void addConnection(string s, string m, double b){
            if(connections.empty()){
                LandlineConnection landline(s, m, b);
                connections.push_back(landline);
                cout << "New landline connection added!" << endl;
                return;
            }  
            for(LandlineConnection connection : connections){
                if(connection.getSTDCode() == s && connection.getNumber() == m){
                    cout << "This landline connection already exists" << endl;
                }
                else{
                    LandlineConnection landline(s, m, b);
                    connections.push_back(landline);
                    cout << "New landline connection added!" << endl;
                }  
            }

        }
        void payBill(string s, string m){
            if(connections.empty()){
                cout << "Zero landline numbers" << endl;
                return;
            }
            for(LandlineConnection& connection : connections){
                if(connection.getSTDCode() == s && connection.getNumber() == m){
                    if(connection.getBill() == 0.0){
                        cout << "Bill already paid for this landline number" << endl;
                    }
                    else{
                        connection.payBill();
                        cout << "Bill amount paid!" << endl;
                    }
                }
                else{
                    cout << "Check your landline number again" << endl;
                }
            }
        }
        void updateBill(string s, string m, double amount){
            if(connections.empty()){
                cout << "Zero landline numbers" << endl;
                return;
            }
            for(LandlineConnection& connection : connections){
                if(connection.getSTDCode() == s && connection.getNumber() == m){
                    connection.setBill(amount);
                    cout << "Bill amount set newly" << endl;
                }
                else{
                    cout << "Check your landline number again" << endl;
                }
            }
        }
        void displayConnections(){
            if(connections.empty()){
                cout << "Zero landline connections" << endl;
                return;
            }
            for(LandlineConnection& connection : connections){
                cout << "\n\nSTD Code: " << connection.getSTDCode() << endl
                     << "Landline Number: " << connection.getNumber() << endl
                     << "Pending Bill Amount: " << connection.getBill() << endl
                     << "-----------------------------------------" << endl;
            }
        }
};

int main(){
    ZohoBillingSystem<MobileConnection> mobile;
    ZohoBillingSystem<LandlineConnection> landline;

    int choice;
    while(true){
        cout << "----Welcome to Zoho Billing System----" << endl;
        cout << "1. Add Mobile Connection" << endl;
        cout << "2. Add Landline Connection" << endl;
        cout << "3. Pay your bill" << endl;
        cout << "4. Update your bill" << endl;
        cout << "5. Display all Mobile Numbers" << endl;
        cout << "6. Display all Landline Numbers" << endl;
        cin >> choice;
        cout << endl;
        switch (choice){
            case 1: {
                string m;
                double b;
                cout << "Enter your Mobile number (10 digits): ";
                cin >> m;
                cout << "Enter your bill amount: ";
                cin >> b;
                mobile.addConnection(m, b);
                break;
            }
            case 2: {
                string s, m;
                double b;
                cout << "Enter your Landline STD Code (1 symbol and 3 digits): ";
                cin >> s;
                cout << "Enter your Landline Number (6 digits): ";
                cin >> m;
                cout << "Enter your bill amount: ";
                cin >> b;
                landline.addConnection(s, m, b);
                break;
            }
            case 3: {
                int option;
                cout << "---1. For Mobile Number" << endl;
                cout << "---2. For Landline Number" << endl;
                cin >> option;
                if (option == 1) {
                    string m;
                    cout << "Enter the mobile number to pay your bill: ";
                    cin >> m;
                    mobile.payingBill(m);
                } else if (option == 2) {
                    string s, m;
                    cout << "Enter your landline STD Code: ";
                    cin >> s;
                    cout << "Enter your landline number to pay your bill: ";
                    cin >> m;
                    landline.payBill(s, m);
                }
                break;
            }
            case 4: {
                int option;
                cout << "---1. For Mobile Number" << endl;
                cout << "---2. For Landline Number" << endl;
                cin >> option;
                if(option == 1){
                    string m;
                    double a;
                    cout << "Enter the mobile number to update your bill: ";
                    cin >> m;
                    cout << "Enter the amount to add: ";
                    cin >> a;
                    mobile.updateBill(m, a);
                }
                else if(option == 2){
                    string s, m;
                    double a;
                    cout << "Enter your landline STD Code: ";
                    cin >> s;
                    cout << "Enter your landline number: ";
                    cin >> m;
                    cout << "Enter the amount to add: ";
                    cin >> a;
                    landline.updateBill(s, m, a);
                }
                break;
            }
            case 5: {
                mobile.displayConnections();
                break;
            }
            case 6: {
                landline.displayConnections();
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }
}




