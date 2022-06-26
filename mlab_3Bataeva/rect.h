#ifndef RECT_H
#define RECT_H
class QPainter;

class Rect
{
public:
    Rect();
    Rect (int x1, int y1, int x2, int y2);
    void draw(QPainter *painter);
    bool contains(int x, int y);

private:
    int x, y, h, w;
};

#endif // RECT_H
