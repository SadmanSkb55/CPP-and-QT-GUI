#include <QtWidgets>

#include "sketchfcompanion.h"

SketchFCompanion::SketchFCompanion(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);

    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
}

void SketchFCompanion::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void SketchFCompanion::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void SketchFCompanion::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

void SketchFCompanion::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}

void SketchFCompanion::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}

void SketchFCompanion::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

void SketchFCompanion::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QRect dirtyRect = event->rect();

    painter.drawImage(dirtyRect, image, dirtyRect);
}

void SketchFCompanion::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void SketchFCompanion::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);

    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawLine(lastPoint, endPoint);

    modified = true;

    int rad = (myPenWidth / 2) + 2;

    update(QRect(lastPoint, endPoint).normalized()
               .adjusted(-rad, -rad, +rad, +rad));

    lastPoint = endPoint;
}

void SketchFCompanion::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void SketchFCompanion::addText(const QString &text, const QPoint &position) {
    QPainter painter(&image); // Assuming you want to draw text on the image
    painter.setPen(QPen(myPenColor, myPenWidth)); // Set the pen color and width
    painter.drawText(position, text);
}


void SketchFCompanion::addImage(const QPixmap &image, const QPoint &position)
{
    QPainter painter(&this->image);
    painter.drawPixmap(position, image);
}





