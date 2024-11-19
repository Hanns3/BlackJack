#include "CardWidget.h"
#include "constants.h"

CardWidget::CardWidget(const QPixmap &pixmap, QWidget *parent)
    : QWidget(parent), pixmap(pixmap)
{
    setFixedSize(cardSizeWidth, cardSizeHeight);

    animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(animationDuration);
    animation->setEasingCurve(QEasingCurve::OutBounce);
}

void CardWidget::setPixmap(QPixmap _pixmap) {
    pixmap = _pixmap;
}

void CardWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap scaledPixmap = pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(0, 0, scaledPixmap);
}

void CardWidget::animateEntry()
{
    animation->setStartValue(QPoint(-width(), y()));
    animation->setEndValue(QPoint(x(), y()));

    animation->start();
}
