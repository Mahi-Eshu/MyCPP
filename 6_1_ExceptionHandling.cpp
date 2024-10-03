#include <iostream>
#include <string>
#include <regex>
#include <exception>
using namespace std;



//user-defined exception bro
class MyException : public exception{ //inheritance for user-definability

    string param;
    string message;

    public:
        MyException(string p) : param(p){
            message = "MyException[" + param + "]";
        } //initializer list
        const char* what() const noexcept override{
            return message.c_str();
        }
};


void handleException(){
    int a, b;
    string s;
    int index;
    try{
        //invalid division
        cout << "Enter two numbers for division : ";
        cin >> a >> b;
        if(b==0){
            throw runtime_error("Invalid Division");
        }
        cout << "Result: " << a/b << endl << endl;



        //memory allocation compromised
        int* ptr = new(nothrow) int[1000000091910]; //assigning ptr to the integer array of size 1000000000
        if(!ptr){ //if the ptr has a value, it means the integer array has gotten its memory
            throw runtime_error("Memory is compromised!");
        }



        //format mismatching
        cout << "Enter an array to convert to integer: ";
        cin >> s;
        cout << endl;
        for(int i=0;i<s.length();i++){
            if(!isdigit(s[i])){
                throw invalid_argument("Format Mismatch");
            }
        }
        int number = stoi(s);
        cout << "Converted into Integer: " << number << endl << endl;



        //index validity checking
        cout << "Enter a string & index: ";
        cin >> s >> index;
        cout << endl;
        if(index < 0 || index >= s.length()){
            throw out_of_range("Array Index is Invalid");
        }
        cout << "Popped out: " << s[index] << endl << endl;


        //chumma one user-defined exception
        throw MyException("Mahesh");

    }
    catch(const runtime_error e){
        cout << e.what() << endl;
    }
    catch(const invalid_argument e){
        cout << e.what() << endl;
    }
    catch(const out_of_range e){
        cout << e.what() << endl;
    }
    catch( const MyException e){
        cout << e.what() << endl;
    }
    catch(...){
        cout << "Exception encountered bro!" << endl;
    }

    //finally
    cout << endl;
    cout << "Exception Handling Accomplished." << endl;
}


int main(){
    handleException();
    return 0;
}