#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/ioctl.h>
#include "session_interface.hpp"
#include "abstract_lib_png.hpp"

class Controller
{
public:
    /*Session(Xorg/Wayland) funstions*/
    void session_definition();
    void session_init(IGraphServer *igs_ptr);
    void session_make_screenshot();
    bool is_wayland() { return this->session_type; }
    bool is_xorg()    { return !this->session_type; }
    
    /*Export funstions*/
    void save_screenshot_png();

    //getters:
    unsigned short* get_dis_width()  { return this->display_width; }
    unsigned short* get_dis_height() { return this->display_height; }


private:
    /*Variables*/
    bool            session_type = 0; //0->Xorg/1->Wayland
    IGraphServer    *igs_ptr = nullptr;
    unsigned short  *display_width = nullptr;
    unsigned short  *display_height = nullptr;
};