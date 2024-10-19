#include "session_interface.hpp"

void IGraphServer::init() {
    std::cerr << "\nERROR::CAPTIT::INTERFACE_GRAPHICS_SERVER::INIT\n";
    exit(EXIT_FAILURE);
}

void IGraphServer::make_screenshot() {
    std::cerr << "\nERROR::CAPTIT::INTERFACE_GRAPHICS_SERVER::MAKE_SCREENSHOT()\n";
    exit(EXIT_FAILURE);
}

char* IGraphServer::get_scrn_data() {
    std::cerr << "\nERROR::CAPTIT::INTERFACE_GRAPHICS_SERVER::GET_SCRN_DATA()\n";
    exit(EXIT_FAILURE);
}

int* IGraphServer::get_scrn_bytes_per_line() {
    std::cerr << "\nERROR::CAPTIT::INTERFACE_GRAPHICS_SERVER::GET_SCRN_BYTES_PER_LINE()\n";
    exit(EXIT_FAILURE);
}