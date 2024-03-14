#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();

protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height);

private:
  void drawCarBody(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage);
  void drawLine(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage);
  void drawCarRoof(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage);
  void drawCarWheels(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage);
  void drawCarHeadlight(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage);
};

#endif // GTKMM_EXAMPLE_MYAREA_H