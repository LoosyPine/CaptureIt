#include "abstract_lib_png.hpp"

void libPNG::init(unsigned short *width, unsigned short *height)
{
    // setup img resolution
    set_dis_width(width);
    set_dis_height(height);

    /*Setup libPNG(png.h) structs*/
    this->fp = fopen("outputPNG.png", "wb");
    if(!this->fp) {
        std::cerr << "\nERROR::CAPIT::ABSTRACT_LIB_PNG::FSTREAM::NOT_OPEN\n";
        exit(EXIT_FAILURE);
    }
    this->write_ptr = png_create_write_struct(
        PNG_LIBPNG_VER_STRING,
        nullptr,
        nullptr,
        nullptr
    );
    if(!this->write_ptr) {
        std::cerr << "\nERROR::CAPIT::ABSTRACT_LIB_PNG::PNG_STRUCTP_NOT_CREATE\n";
        exit(EXIT_FAILURE);
    }
    this->info_ptr = png_create_info_struct(this->write_ptr);
    if(!this->info_ptr) {
        std::cerr << "\nERROR::CAPIT::ABSTRACT_LIB_PNG::PNG_INFOP_NOT_CREATE\n";
        exit(EXIT_FAILURE);
    }

    // set up error handling to jmpbuff
    if(setjmp(png_jmpbuf(this->write_ptr))) {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::SETJMP_ERROR\n";
        png_destroy_write_struct(&write_ptr, &info_ptr);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // init input/output stream
    png_init_io(this->write_ptr, this->fp);

    // setup export img settings
    png_set_IHDR(this->write_ptr, this->info_ptr,
                *this->width, *this->height,
                8,
                PNG_COLOR_TYPE_RGB_ALPHA,
                PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT,
                PNG_FILTER_TYPE_DEFAULT
                );
}

void libPNG::save_png()
{
    check_img_data();
    check_img_bytes_per_line();

    // record img data to row_pointers(dinamic array)
    this->row_pointers = new png_bytep[*this->height];
    for(int i = 0; i < *this->height; ++i)
    {
        this->row_pointers[i] = (png_bytep)((this->data) + i * (*this->bytes_per_line));
    }
    png_set_rows(this->write_ptr, this->info_ptr, this->row_pointers);
    png_write_png(this->write_ptr, this->info_ptr, PNG_TRANSFORM_BGR, nullptr);
    png_write_end(this->write_ptr, this->info_ptr);
}

void libPNG::set_img_data(char *data)
{
    if(data == nullptr)
    {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::SET_IMG_DATA::DATA_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
    this->data = data;
}

void libPNG::set_img_bytes_per_line(int *bytes_per_line)
{
    if(bytes_per_line == nullptr)
    {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::SET_IMG_BYTES_PER_LINE::BYTES_PER_LINE_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
    this->bytes_per_line = bytes_per_line;
}

void libPNG::check_img_data()
{
    if(this->data == nullptr)
    {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::CHECK_IMG_DATA::DATA_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
}

void libPNG::check_img_bytes_per_line()
{
    if(this->bytes_per_line == nullptr)
    {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::CHECK_IMG_BYTES_PER_LINE::BYTES_PER_LINE_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
}

void libPNG::set_dis_width(unsigned short *width)
{
    if(width == nullptr)
    {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::DIS_WIDTH_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
    this->width = width;
}

void libPNG::set_dis_height(unsigned short *height)
{
    if(height == nullptr)
    {
        std::cerr << "\nERROR::CAPTIT::ABSTRACT_LIB_PNG::DIS_HEIGHT_NULLPTR\n";
        exit(EXIT_FAILURE);
    }
    this->height = height;
}