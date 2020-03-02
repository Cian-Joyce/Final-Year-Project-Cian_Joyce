#ifndef SCANMAPAREA_H
#define SCANMAPAREA_H

#include <QtWidgets>  //include the base widget class
#include <QColor>   //include class for dealing with RGB colouring in the GUI
#include <QImage>   //include class for dealing with images on the GUI
#include <QPoint>   //include a class that helps when dealing with x & y based coordanates
#include <QWidget>

class scanMapArea : public QWidget
{
    Q_OBJECT
    //this macro tell the moc(Meta object compiler) that this file contains GUI elements that may need signals and slots
public:
    scanMapArea(QWidget *parent = nullptr);
    bool openBackgroundImage(const QString &filePath);
    void setPointColour(const QColor &newColor);
    void setPointWidth(int newWidth);
    void paintPoint(int distanceMm, int theta);
    void paintMaxRangeCircle();


    QColor getPointColor() const { return currentPointColor; }
    int getPointWidth() const { return currentPointWidth; }

public slots:
    void clearScanMap();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);
    bool openImage(const QString &fileName);

    bool drawing;
    int currentPointWidth;
    QColor currentPointColor;
    QImage image;
    QPoint lastPoint;
    QString imageFileName;
};

#endif // SCANMAPAREA_H
