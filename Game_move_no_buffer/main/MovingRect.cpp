/*! \brief Implementation for MovingRect
 *
 *  
 */

#include "MovingRect.hpp"
#include <cmath>

void MovingRect::update(float dt, int screenW, int screenH) {
    // Integrate position with velocity using Euler method: pos = pos + velocity * dt https://en.wikipedia.org/wiki/Euler_method
    x_ = x_ + vx_ * dt;
    y_ = y_ + vy_ * dt;
    if (x_ < 0 || x_ + w_ > screenW)
    {
        vx_ = -vx_;
    }
    if (y_ < 0 || y_ + h_ > screenH)
    {
        vy_ = -vy_;
    }
}
 
void MovingRect::draw(Ili9341Display& d) const {
    // Convert float position to integer pixel coordinates at draw time
    d.drawRectangle(static_cast<int>(x_), static_cast<int>(y_), w_, h_, color_, true);
}