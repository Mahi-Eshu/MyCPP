#include <iostream>

namespace ns {
    class Rectangle {
        public :
            double length, width;
            Rectangle(double l, double w) : length(l), width(w) {}

            double findArea(){
                return length * width;
            }
    };
}

int main(){
    ns::Rectangle rectangle(10.0, 11.0);
    std::cout << rectangle.findArea();
}