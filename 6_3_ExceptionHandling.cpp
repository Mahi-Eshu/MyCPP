#include <iostream>
#include <exception>
#include <string>
using namespace std;

class AgeNotWithinRangeException : public exception{
    public:
        const char* what() const noexcept override{
            return "Age must be b/w 15 to 21";
        };
};
class NameNotValidException : public exception{
    public:
        const char* what() const noexcept override{
            return "Name is Invalid";
        };
};
class InvalidCourseException : public exception{
    public:
        const char* what() const noexcept override{
            return "Course is Invalid";
        };
};


class Student{
    private:
        static bool singleObject;
        int rollno;
        string name;
        int age;
        string course;
    public:
        Student(int rollno, string name, int age, string course){
            if(singleObject) throw runtime_error("Object already created!");

            this->rollno = rollno;

            for(int i=0;i<name.length();i++){
                if(!isalpha(name[i])){
                    throw NameNotValidException();
                }
            } this->name = name;

            if(age<15 || age>21){
                throw AgeNotWithinRangeException();
            } this->age = age;

            string availableCourses[] = {"BCom", "BTech", "BSc", "BE"};
            bool valid = false;
            for(int i=0;i<4;i++){
                if(availableCourses[i] == course){
                    valid = true;
                    break;
                }
            }
            if(!valid){
                throw InvalidCourseException();
            } this->course = course;

            singleObject = true;
        }

        void display(){
            cout << "Roll Number: " << rollno << endl
                 << "Student Name: " << name << endl
                 << "Student Age: " << age << endl
                 << "Chosen Course: " << course << endl;
        }
};
bool Student::singleObject = false;
int main(){
    try
    {
        Student student(22496, "Mahesh", 21, "BTech");
        student.display();

    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}