#include "mycircle.h"
#include"QPainter"


    MyCircle::MyCircle(int value, QWidget *parent) : QWidget(parent)
    {
        m_value = value;
    }

    int MyCircle::heightForWidth(int width) const
    {
     return width;
    }

    QSize MyCircle::sizeHint() const
    {
     return QSize(100, 100);
    }


    int MyCircle::value() const
    {
     return m_value;
    }

    void MyCircle::setValue(int value)
    {
     if (value < 0)
     value = 0;

     if (value > 100)
     value = 100;

     if (m_value == value)
     return;

     m_value = value;

     update();

     emit valueChanged(m_value);

    }

    void MyCircle::paintEvent(QPaintEvent *event)
    {
     drawMyFigure();
    }

    void MyCircle::drawMyFigure()
    {
     int radius = width()/2;
     double factor = value()/100.0;

     QPainter p(this);
     p.setPen(Qt::black);
     //this draws the outside circle
     p.drawEllipse(0,0,width()-1,width()-1);
     //this changes the colour of the brush
     p.setBrush(Qt::black);
     //draw the inside circle
     p.drawEllipse((int)(radius*(1.0-factor)),
     (int)(radius*(1.0-factor)),
     (int)((width()-1)*factor)+1,
     (int)((width()-1)*factor)+1);
    }
