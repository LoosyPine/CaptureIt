#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <png.h>

class libPNG
{
public:
    /*Functions*/
    void init(unsigned short *width, unsigned short *height);
    void set_img_data(char *data);
    void check_img_data();
    void set_img_bytes_per_line(int *bytes_per_line);
    void check_img_bytes_per_line();
    void save_png();

private:
    //setters:
    void set_dis_width(unsigned short* width);
    void set_dis_height(unsigned short* width);

    /*Variables*/
    FILE            *fp = NULL;
    png_structp     write_ptr = NULL;
    png_infop       info_ptr = NULL;
    png_bytep       *row_pointers = NULL;
    char            *data = nullptr;
    int             *bytes_per_line = nullptr;
    unsigned short  *width = nullptr;
    unsigned short  *height = nullptr;
};