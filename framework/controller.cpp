#include "controller.hpp"

void Controller::session_definition()
{
    // definition graphics server (Xorg/Wayland)
    /* if Xorg => this->session_type = 0 */
    /* if Wayland => this->session_type = 1 */
    char *session = std::getenv("XDG_SESSION_TYPE");
    if(session == "wayland") { this->session_type = 1; };
    session = std::getenv("XDG_SESSION_DESKTOP");
    if(session[strlen(session) - 1] == 'd') { this-> session_type = 1; };
}

void Controller::session_init(IGraphServer *igs_ptr)
{
    // init graphics server through the input pointer
    this->igs_ptr = igs_ptr;
    this->igs_ptr->init();
    // save resolution in local variable
    this->display_width = this->igs_ptr->get_display_width();
    this->display_height = this->igs_ptr->get_display_height();
}

void Controller::session_make_screenshot()
{
    if(this->igs_ptr == nullptr)
    {
        std::cerr << "ERROR::CAPIT::CONTROLLER::IGS_PTR_NO_INIT\n";
        exit(EXIT_FAILURE);
    }
    this->igs_ptr->make_screenshot();
}

void Controller::save_screenshot_png()
{
    libPNG png;
    png.init(display_width, display_height);
    png.set_img_data(this->igs_ptr->get_scrn_data());
    png.set_img_bytes_per_line(this->igs_ptr->get_scrn_bytes_per_line());
    png.save_png();
}

