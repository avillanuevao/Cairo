#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "MyArea.hpp"

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();

protected:
  MyArea m_area;
};