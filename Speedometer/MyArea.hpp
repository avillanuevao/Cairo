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
  void drawSemicircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius);
  void drawLinesAndNumbers(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius);
  void drawText(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY);
  void drawCenterCircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY);
  void drawNeedle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius, double resizePercentage);
};

#endif // GTKMM_EXAMPLE_MYAREA_H