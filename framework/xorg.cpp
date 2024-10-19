#include "xorg.hpp"

void Xorg::init()
{
    // init display from enviroment variable
    if((this->display = XOpenDisplay(getenv("DISPLAY"))) == NULL) {
        std::cerr << "ERROR::CAPIT::LIB_XORG::INIT_DISPLAY\n";
        exit(EXIT_FAILURE);
    }
    // init X11 screen and resolution
    this->screen = XDefaultScreen(this->display);
    this->display_height = XDisplayHeight(this->display, this->screen);
    this->display_width = XDisplayWidth(this->display, this->screen);
}

void Xorg::make_screenshot()
{
    this->image = XGetImage(this->display, DefaultRootWindow(this->display), 0, 0, this->display_width, this->display_height, AllPlanes, ZPixmap);
}

char* Xorg::get_scrn_data()
{
    check_img_ptr();
    return this->image->data;
}

int* Xorg::get_scrn_bytes_per_line()
{
    check_img_ptr();
    return &this->image->bytes_per_line;
}

void Xorg::check_img_ptr() // private func
{
    if(this->image == nullptr)
    {
        std::cerr << "ERROR::CAPIT::LIB_XORG::IMAGE_POINTER_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
}