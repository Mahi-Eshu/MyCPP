#include <iostream>
using namespace std;

void outer(){
    int a, b;
    try
    {
        cout << "Enter integers for division: ";
        cin >> a >> b;
        if( b==0 ){
            throw invalid_argument("Invalid Argument");
        }
        try
        {

            cout << "Enter integers for positive check: ";
            cin >> a >> b;
            if( a==0 ){
                throw invalid_argument("Invalid Argument");
            }
        }
        catch(const std::exception& e)
        {
            cout << e.what() << endl;
        }
        
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    
}

int main(){
    try
    {
        outer();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}