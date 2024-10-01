#include <iostream>
#include <cmath>
using namespace std;

class Rectangle{
    private:
        int* left;
        int* top;
        int* width;
        int* height;
        int* area;
    public:
        Rectangle(){
            this->left = new int(0);
            this->top = new int(0);
            this->width = new int(0);
            this->height = new int(0);
        }
        Rectangle(int width, int height){
            this->left = new int(0);
            this->top = new int(0);
            this->width = new int(width);
            this->height = new int(height);
        }
        Rectangle(int left, int top, int width, int height){
            this->left = new int(left);
            this->top = new int(top);
            this->width = new int(width);
            this->height = new int(height);
        }
        Rectangle(float left, float top, float width, float height){
            this->left = new int(static_cast<int>(round(left)));
            this->top = new int(static_cast<int>(round(top)));
            this->width = new int(static_cast<int>(round(width)));
            this->height = new int(static_cast<int>(round(height)));
        }
        Rectangle(Rectangle &rect){
            left = new int(*rect.left); //new memory is allocated for pointer variables to avoid shallow copying
            top = new int(*rect.top);
            width = new int(*rect.width);
            height = new int(*rect.height);
            area = new int( (*width) * (*height) );
        }

        //destructor
        ~Rectangle(){
            delete left;
            delete top;
            delete width;
            delete height;
            delete area;
        }

        void printValues(){
            cout << "Left: " << *left << endl
                 << "Top: " << *top << endl
                 << "Width: " << *width << endl
                 << "Height: " << *height << endl
                 << "Area of the given Rectangle: " << *area << endl << endl << endl;
        }
};

int main(){
    Rectangle rect1(10, 20, 4, 15);
    rect1.printValues(); //will return some negative value because we have initialized the area with (width * height) only in the copy constructor,

    Rectangle rectCopy = rect1; //initializing object to call the copy constructor
    rectCopy.printValues(); //haan ipo idhoda value varum paru
}


//g++ 4_Rectangle.cpp
//./a.out