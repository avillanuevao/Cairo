#include "MyArea.hpp"
#include <cairomm/context.h>

MyArea::MyArea()
{
  set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
}

MyArea::~MyArea()
{
}

void MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  drawCompass(cr);
}

void MyArea::drawCompass(const Cairo::RefPtr<Cairo::Context> &cr)
{
  int width = get_allocated_width();
  int height = get_allocated_height();
  double scaleFactor = 1.0; // Ajustar según el porcentaje de escala deseado

  double centerX = width / 10; // Otra ubicación x
  double centerY = height / 2; // Otra ubicación y

  // Ajustar el tamaño de los elementos de la brújula según el factor de escala
  double circleRadius = 100 * scaleFactor;
  double needleLength = 100 * scaleFactor;
  double centerCircleRadius = 5 * scaleFactor;
  double innerCircleRadius = 90 * scaleFactor;
  double outerCircleRadius = 120 * scaleFactor;

  // Llamar a las funciones para dibujar cada parte de la brújula
  drawInnerCircle(cr, centerX, centerY, circleRadius);
  drawCardinalPoints(cr, centerX, centerY, scaleFactor);
  drawNeedle(cr, centerX, centerY, needleLength, scaleFactor);
  drawCenterCircle(cr, centerX, centerY, centerCircleRadius);
  drawInnerLines(cr, centerX, centerY, circleRadius, innerCircleRadius, scaleFactor);
  drawOuterCircle(cr, centerX, centerY, outerCircleRadius);
}

void MyArea::drawInnerCircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius)
{
  cr->set_source_rgb(0, 0, 0);
  cr->arc(centerX, centerY, radius, 0, 2 * M_PI);
  cr->fill();
}

void MyArea::drawCardinalPoints(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double scaleFactor)
{
  double cardinalTextSize = 15 * scaleFactor;
  cr->set_font_size(cardinalTextSize);
  cr->move_to(centerX - 5 * scaleFactor, centerY - 105 * scaleFactor);
  cr->show_text("N");
  cr->move_to(centerX + 105 * scaleFactor, centerY + 5 * scaleFactor);
  cr->show_text("E");
  cr->move_to(centerX - 10 * scaleFactor, centerY + 115 * scaleFactor);
  cr->show_text("S");
  cr->move_to(centerX - 116 * scaleFactor, centerY + 5 * scaleFactor);
  cr->show_text("W");
}

void MyArea::drawNeedle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double needleLength, double scaleFactor)
{
  cr->save();
  cr->set_source_rgba(1, 0, 0, 1);
  cr->set_line_width(2 * scaleFactor);
  cr->move_to(centerX, centerY);
  cr->line_to(centerX, centerY - needleLength);
  cr->stroke();
  cr->restore();
}

void MyArea::drawCenterCircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double radius)
{
  cr->arc(centerX, centerY, radius, 0, 2 * M_PI);
  cr->fill();
}

void MyArea::drawInnerLines(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double circleRadius, double innerCircleRadius, double scaleFactor)
{
  cr->set_source_rgb(1, 1, 1); 
  cr->set_line_width(1 * scaleFactor);
  for (int i = 0; i < 36; ++i) 
  {
      double angle = 2 * M_PI * i / 36;
      cr->move_to(centerX + circleRadius * cos(angle), centerY + circleRadius * sin(angle));
      cr->line_to(centerX + innerCircleRadius * cos(angle), centerY + innerCircleRadius * sin(angle));
      cr->stroke();
  }
}

void MyArea::drawOuterCircle(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double outerCircleRadius)
{
  cr->set_source_rgb(0, 0, 0);
  cr->arc(centerX, centerY, outerCircleRadius, 0, 2 * M_PI); // Aumentar el radio para incluir el texto
  cr->stroke();
}
