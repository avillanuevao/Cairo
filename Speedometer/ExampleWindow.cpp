#include "ExampleWindow.hpp"

ExampleWindow::ExampleWindow()
{
  maximize();
  set_title("DrawingArea");
  set_child(m_area);
}
