#ifndef SKETCHFCOMPANION_H
#define SKETCHFCOMPANION_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QPixmap>

class SketchFCompanion : public QWidget
{
    Q_OBJECT

public:
    SketchFCompanion(QWidget *parent = nullptr);

    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    void addImage(const QPixmap &image, const QPoint &position);

    void addText(const QString &text, const QPoint &position);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool scribbling;
    int myPenWidth;

    QPixmap sketch; // Declare sketch as a member variable

    QColor myPenColor;
    QImage image;
    QPoint lastPoint;

};

#endif
