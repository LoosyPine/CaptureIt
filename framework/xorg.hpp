#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <X11/Xlib.h>
#include "session_interface.hpp"



class Xorg : public IGraphServer
{
public:
    /*IGraphServer virtual functions*/
    void            init();
    void            make_screenshot();
    //getters:
    char*           get_scrn_data(); // get screenshot data(bytes)
    int*            get_scrn_bytes_per_line(); // get count of bytes of one row of the screenshot
    unsigned short* get_display_width() { return &this->display_width; }; // get X11 display width
    unsigned short* get_display_height() { return &this->display_height; }; // get x11 display heigt

private:
    /*Functions*/
    void check_img_ptr();

    /*Variables*/
    Display         *display = nullptr;
    int             screen;
    XImage          *image = nullptr;
    unsigned short  display_height = 0;
    unsigned short  display_width = 0;
};