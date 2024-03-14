#include <memory>
#include <iostream>

#include <gtkmm-4.0/gtkmm.h>

#include "ExampleWindow.hpp"

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}