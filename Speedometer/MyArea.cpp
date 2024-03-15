#include "MyArea.hpp"
#include <cairomm/context.h>

MyArea::MyArea()
{
  set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
}

MyArea::~MyArea()
{
}

void MyArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height)
{
  width = get_allocated_width();
  height = get_allocated_height();

  double centerX = width / 2;
  double centerY = height / 2;
  double initialRadius = 150;

  double resizePercentage = 1;

  double radius = initialRadius * resizePercentage;

  drawSemicircle(cr, centerX, centerY, radius);
  drawLinesAndNumbers(cr, centerX, centerY, radius);
  drawText(cr, centerX, centerY);
  drawCenterCircle(cr, centerX, centerY);
  drawNeedle(cr, centerX, centerY, radius, resizePercentage);
}

void MyArea::drawSemicircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius)
{
  cr->arc(centerX, centerY, radius, M_PI, 2 * M_PI);
  cr->close_path();
  cr->fill();
}

void MyArea::drawLinesAndNumbers(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius)
{
  cr->set_source_rgb(1, 1, 1);

  int numLines = 11;
  int numSubLines = numLines * 2;
  for (int i = 0; i < numSubLines; ++i)
  {
    int lineIndex = i / 2;
    double angle;
    if (i % 2 == 0)
    {
      angle = M_PI + (M_PI / (numLines + 1)) * (lineIndex + 1);
    }
    else
    {
      angle = M_PI + (M_PI / (numLines + 1)) * (lineIndex + 1) + (M_PI / (numLines + 1)) / 2.0;
    }
    double x1 = centerX + radius * cos(angle);
    double y1 = centerY + radius * sin(angle);
    double x2, y2;
    if (i % 2 == 0)
    {
      x2 = centerX + (radius - 10) * cos(angle);
      y2 = centerY + (radius - 20) * sin(angle);
    }
    else
    {
      x2 = centerX + (radius - 10) * cos(angle);
      y2 = centerY + (radius - 20) * sin(angle);
    }
    cr->move_to(x1, y1);
    cr->line_to(x2, y2);
    cr->stroke();

    if (i % 2 == 0)
    {
      cairo_text_extents_t extents;
      char number[4];
      snprintf(number, sizeof(number), "%d", (lineIndex * 20) + 20);
      cairo_text_extents(cr->cobj(), number, &extents);
      cairo_move_to(cr->cobj(), x2 - extents.width / 2.0, y2 + 10);
      cairo_show_text(cr->cobj(), number);
    }
  }
}

void MyArea::drawText(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY)
{
  cairo_text_extents_t extents_km_h;
  std::string text_km_h = "km/h";
  cairo_text_extents(cr->cobj(), text_km_h.c_str(), &extents_km_h);
  double x_text = centerX - extents_km_h.width / 2.0;
  double y_text = centerY - 100;
  cairo_move_to(cr->cobj(), x_text, y_text);
  cairo_show_text(cr->cobj(), text_km_h.c_str());
}

void MyArea::drawCenterCircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY)
{
  cr->set_source_rgb(1, 0, 0);
  double circle_radius = 10;
  cr->arc(centerX, centerY - 50, circle_radius, 0, 2 * M_PI);
  cr->fill();
}

void MyArea::drawNeedle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius, double resizePercentage)
{
  double needleLength = 145 * resizePercentage;
  cr->move_to(centerX, centerY - 50);
  cr->line_to(centerX, centerY - needleLength);
  cr->stroke();
}
