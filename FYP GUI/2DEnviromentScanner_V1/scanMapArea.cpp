#include <QImage>
#include <QColor>
#include <QPoint>
#include <QtWidgets>
#include <QPainter>
#include <cmath>
#include <math.h>
#include "scanMapArea.h"

scanMapArea::scanMapArea(QWidget *parent):QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    drawing = false;
    currentPointColor = Qt::red;
    currentPointWidth = 1;
}

void scanMapArea::resizeImage(QImage *image, const QSize &newSize)
{
    if(image->size() == newSize)
    {
        return;
    }
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

bool scanMapArea::openBackgroundImage(const QString &fileName)
{
    QImage loadedImage;
    imageFileName = fileName;
    if(loadedImage.load(fileName) == 0)
    {
        return false;   //failed to load image
    }
    const QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    update();
    return true;    //image load successful
}

void scanMapArea::setPointColour(const QColor &newColor)
{
    currentPointColor = newColor;
}

void scanMapArea::setPointWidth(int newWidth)
{
    currentPointWidth = newWidth;
}

void scanMapArea::clearScanMap()
{
   QImage loadedImage;
   image.fill(qRgb(255, 255, 255));
   loadedImage.load(imageFileName);
   const QSize newSize = loadedImage.size().expandedTo(size());
   resizeImage(&loadedImage, newSize);
   image = loadedImage;
   paintMaxRangeCircle();
   update();
}

void scanMapArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)  //if a left mouse press triggered the event
    {
        lastPoint = event->pos();   //set last point
        drawing = true;             //set drawing to true
    }
}

void scanMapArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing) //if the user moving the mouse & holding mouse click
    {
        drawLineTo(event->pos());
    }
}

void scanMapArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing) //if the user moving the mouse & holding mouse click
    {
        drawLineTo(event->pos());   //call draw line to and pass the position the event was triggered at
        drawing = false;        //when user releases mouse set drawing to false
    }
}


void scanMapArea::paintEvent(QPaintEvent *event)  //this event is triggered when update is called
{
    QPainter painter(this); //create a painter for this object (scanMapWidget)
    QRect Rectan = event->rect();
    painter.drawImage(Rectan, image, Rectan);
}

void scanMapArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() , image.width());   //set width to image width
        int newHeight = qMax(height() , image.height());    //set height to image height
        const QSize size (newWidth, newHeight); //make QSize object
        resizeImage(&image, size);  //resize the image
        update();   //update GUI
    }
    QWidget::resizeEvent(event);    //recall
}

void scanMapArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);   //set painter on scanMapImage
    //set line thickness, colour and style
    painter.setPen(QPen(currentPointColor, currentPointWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);  //draw the line from last clicked point to the current point
    update();   //update GUI
    lastPoint = endPoint;
}

void scanMapArea::paintPoint(int distanceMm, int theta)
{
    int pointX, pointY, pointXmm, pointYmm;
    double angleRads;
    const double PI = 3.14159265;
    int widgetWidth = this->width();
    int widgetHeight = this->height();
    int maxScanRadius = 12000; //scanner range 12m = 12,000mm
    QPoint centerPoint((widgetWidth)/2, (widgetHeight)/2);  //point object for center point of QWidget
    QPainter painter(&image);                                   //object for content within the QWidget
    //set up pen with current chosen color, current chosen width, with a solid line that joins to adjecent points
    painter.setPen(QPen(Qt::blue, currentPointWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(Qt::black);
    /*Here a block of code needs to be added that maps the max range of the scanner to the size of the window
      as the window is variable in size */
    angleRads = theta*PI/180;
    pointXmm = distanceMm * std::sin(angleRads);
    pointYmm = distanceMm * std::cos(angleRads);
    /*
     Mapping read value in mm range 0 - 12000 to widget pixle size range 0 - widget width, and 0 - widget height
     then due to point (0x, 0y) being the top left corner of the widget, the true position of the point is the widget
     width minus the returned x value and widget height minus the returned y point
    */
    pointX = widgetWidth - (pointXmm / maxScanRadius * widgetWidth);
    pointY = widgetHeight - (pointYmm / maxScanRadius * widgetHeight);
    QPointF truePoint(pointX, pointY);
    painter.drawEllipse(truePoint, 10, 10);
}

void scanMapArea::paintMaxRangeCircle()
{
    //const double PI = 3.14159265;
    QPainter painter(&image);
    painter.setPen(QPen(currentPointColor, currentPointWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPointF((width()/2), (height()/2)), width()/2, height()/2);
    painter.drawEllipse(QPointF((width()/2), (height()/2)), width()/4, height()/4);
    painter.setPen(QPen(currentPointColor, currentPointWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(QPoint(width()/2,0), QPoint(width()/2, height()));
    painter.drawLine(QPoint(0, height()/2),QPoint(width(), height()/2));
    update();
}
