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
 // Obtener el tamaño de la ventana
  width = get_allocated_width();
  height = get_allocated_height();

  double centerX = width / 2; 
  double centerY = height / 2; 

  // Definir el porcentaje de cambio de tamaño
  double resizePercentage = 5; 

  drawCarBody(cr, centerX, centerY, resizePercentage);
  drawLine(cr, centerX, centerY, resizePercentage);
  drawCarRoof(cr, centerX, centerY, resizePercentage);
  drawCarWheels(cr, centerX, centerY, resizePercentage);
  drawCarHeadlight(cr, centerX, centerY, resizePercentage);

}

void MyArea::drawCarBody(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage)
{
  double bodyX = centerX / 2 - 50 * resizePercentage;
  double bodyY = centerY / 2;
  double bodyWidth = 100 * resizePercentage;
  double bodyHeight = 50 * resizePercentage;

  cr->rectangle(bodyX, bodyY, bodyWidth, bodyHeight);
  cr->set_source_rgb(1.0, 1.0, 1.0); 
  cr->fill_preserve();               
  cr->set_source_rgb(0, 0, 0);       
  cr->stroke();
}

void MyArea::drawLine(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage)
{
  double lineX = centerX / 2 - 20 * resizePercentage;       
  double lineY = centerY / 2 + 10 * resizePercentage;       
  double lineLength = 10 * resizePercentage;         

  cr->move_to(lineX, lineY);              
  cr->line_to(lineX + lineLength, lineY); 
  cr->set_source_rgb(0, 0, 0);            
  cr->stroke();  
}

void MyArea::drawCarRoof(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage)
{
  double roofX = centerX / 2 - 30 * resizePercentage;
  double roofY = centerY / 2 - 30 * resizePercentage;
  double roofWidth = 40 * resizePercentage;
  double roofHeight = 30 * resizePercentage;

  cr->rectangle(roofX, roofY, roofWidth, roofHeight); // Ajustar la posición del rectángulo del techo
  cr->set_source_rgb(1.0, 1.0, 1.0);                      
  cr->fill_preserve();                                     
  cr->set_source_rgb(0, 0, 0);                             
  cr->stroke();
}

void MyArea::drawCarWheels(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage)
{
  double wheelRadius = 15 * resizePercentage;
  double wheel1X = centerX / 2 - 30 * resizePercentage;
  double wheel2X = centerX / 2 + 30 * resizePercentage;
  double wheelY = centerY / 2 + 50 * resizePercentage;
  double innerWheelRadius = 10 * resizePercentage;

  cr->arc(wheel1X, wheelY, wheelRadius, 0, 2 * M_PI);
  cr->set_source_rgb(1.0, 1.0, 1.0); 
  cr->fill_preserve();     
  cr->set_source_rgb(0, 0, 0);       
  cr->stroke(); 

  cr->arc(wheel2X, wheelY, wheelRadius, 0, 2 * M_PI);
  cr->set_source_rgb(1.0, 1.0, 1.0); 
  cr->fill_preserve();                
  cr->set_source_rgb(0, 0, 0);       
  cr->stroke();                      

  cr->set_source_rgb(0, 0, 0); 
  cr->arc(wheel1X, wheelY, innerWheelRadius, 0, 2 * M_PI);
  cr->fill();
  cr->arc(wheel2X, wheelY, innerWheelRadius, 0, 2 * M_PI);
  cr->fill();
}

void MyArea::drawCarHeadlight(const Cairo::RefPtr<Cairo::Context> &cr, double centerX, double centerY, double resizePercentage)
{
  double headlightRadius = 5 * resizePercentage;
  double headlight1X = centerX / 2 - 40 * resizePercentage;
  double headlight1Y = centerY / 2 + 10 * resizePercentage;

  cr->set_source_rgb(0.0, 0.0, 0.0);                        // Color negro para el faro
  cr->arc(headlight1X, headlight1Y, headlightRadius, 0, 2 * M_PI); // Faro izquierdo
  cr->stroke();
}
