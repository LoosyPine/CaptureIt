#include <iostream>
#include <X11/Xlib.h>
#include "../include/test.hpp"

int main()
{
    Prog obj;
    //std::cout << "Hello World!" << std::endl;
    Display* dis = XOpenDisplay(NULL);
    return 0;
}

