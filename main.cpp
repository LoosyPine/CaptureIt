

#include <iostream>
#include <fstream>
#include <cstdio>

#include <pthread.h>
#include <png.h>
#include <errno.h>

#include "framework/xorg.hpp"
#include "framework/controller.hpp"


int main()
{

    Controller core;
    Xorg x11;
    core.session_definition();
    core.session_init(&x11);
    core.session_make_screenshot();
    core.save_screenshot_png();

    return 0;
}