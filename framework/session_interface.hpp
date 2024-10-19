#pragma once
#include <iostream>

class IGraphServer
{
public:

    virtual void init();
    virtual void make_screenshot();
    virtual char* get_scrn_data();
    virtual int* get_scrn_bytes_per_line();
    virtual unsigned short* get_display_width() { return nullptr; };
    virtual unsigned short* get_display_height() { return nullptr; };
};