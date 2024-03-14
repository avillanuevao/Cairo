#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();

protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

private:
    void drawCompass(const Cairo::RefPtr<Cairo::Context>& cr);
    void drawInnerCircle(const Cairo::RefPtr<Cairo::Context>& cr, double centerX, double centerY, double radius);
    void drawCardinalPoints(const Cairo::RefPtr<Cairo::Context>& cr, double centerX, double centerY, double scaleFactor);
    void drawNeedle(const Cairo::RefPtr<Cairo::Context>& cr, double centerX, double centerY, double needleLength, double scaleFactor);
    void drawCenterCircle(const Cairo::RefPtr<Cairo::Context>& cr, double centerX, double centerY, double radius);
    void drawInnerLines(const Cairo::RefPtr<Cairo::Context>& cr, double centerX, double centerY, double circleRadius, double innerCircleRadius, double scaleFactor);
    void drawOuterCircle(const Cairo::RefPtr<Cairo::Context>& cr, double centerX, double centerY, double outerCircleRadius);
};

#endif // GTKMM_EXAMPLE_MYAREA_H