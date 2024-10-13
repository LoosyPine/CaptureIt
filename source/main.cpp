#include <iostream>
#include <fstream>
#include <cstdio>

#include <X11/Xlib.h>
#include <png.h>
#include <errno.h>

#define X 0
#define Y 0
#define WIDTH 1720
#define HEIGHT 720
#define DISPLAY_WIDTH 1366
#define DISPLAY_HEIGHT 768

int main()
{
    Display     *display;
    Window      window;
    int         screen;
    XImage      *image;
    GC          gpraph_ctx;
    XGCValues   *gc_values;

    //Xorg part
    if((display = XOpenDisplay(getenv("DISPLAY"))) == NULL) {
        //printf("Can't connect X server: %s\n", strerror(errno));
        exit(1);
    }
    screen = XDefaultScreen(display);
    image = XGetImage(display, DefaultRootWindow(display), 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, AllPlanes, ZPixmap);
    
    //PNG part
    FILE *fp = fopen("outputPNG.png", "wb");
    if (!fp)
        return (-1);

    png_structp  write_ptr = png_create_write_struct(
        PNG_LIBPNG_VER_STRING,
        nullptr, nullptr, nullptr );
    if (!write_ptr)
        return (-1);

    png_infop info_ptr = png_create_info_struct(write_ptr);
    if(!info_ptr) {
        //png_destroy_write_struct(&write_ptr, (png_infop)NULL);
        return (-1);
    }

    //set up error handling
    if(setjmp(png_jmpbuf(write_ptr))) {
        png_destroy_write_struct(&write_ptr, &info_ptr);
        fclose(fp);
        return (-1);
    }

    png_init_io(write_ptr, fp);

    png_set_IHDR(write_ptr, info_ptr,
                DISPLAY_WIDTH, DISPLAY_HEIGHT,
                8,
                PNG_COLOR_TYPE_RGB_ALPHA,
                PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT,
                PNG_FILTER_TYPE_DEFAULT
                );
    
    png_bytep *row_pointers = new png_bytep[DISPLAY_HEIGHT];
    for(int i = 0; i < DISPLAY_HEIGHT; i++)
    {
        //пройдись по каждому индексу в image->data и преобразуй в png_bytep
        row_pointers[i] = (png_bytep)((image->data) + i * (image->bytes_per_line));
    }
    png_set_rows(write_ptr, info_ptr, row_pointers);
    png_init_io(write_ptr, fp);
    png_write_png(write_ptr, info_ptr, PNG_TRANSFORM_BGR, nullptr);
    png_write_end(write_ptr, info_ptr);

    std::cout << image->data[0] << std::endl;

    return 0;
}