#include "rect.h"
#include <QPainter>

Rect::Rect()
    :Rect(0, 0, 0, 0)

{

}

Rect::Rect(int x1, int y1, int x2, int y2)
{
    if(x1 < x2){
        x = x1;
        w = x2 - x1;
    }
    else{
        x = x2;
        w = x1 - x2;
    }
    if(y1 < y2){
        y = y1;
        h = y2 - y1;
    }
    else{
        y = y2;
        h = y1 - y2;
    }
}

bool Rect::contains(int x, int y)
{
    return(x >= this->x && x<= (this->x+w) && y>= this->y && y<= (this->y+h));
}

void Rect::draw(QPainter *painter)
{
    painter->drawRect(x, y, w, h);
}

