#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation> // Include QPropertyAnimation

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardWidget(const QPixmap &pixmap, QWidget *parent = nullptr);
    ~CardWidget() = default;

    void setPixmap(QPixmap _pixmap);
    void animateEntry(); // Function to start the animation

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap pixmap;
    QPropertyAnimation *animation; // Animation pointer
};

#endif // CARDWIDGET_H
