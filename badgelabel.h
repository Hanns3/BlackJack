#ifndef BADGELABEL_H
#define BADGELABEL_H

#include <QLabel>
#include <QFont>
#include <QFontMetrics>
#include <QPainter>
#include <QVBoxLayout>

template <typename T>
class BadgeLabel : public QLabel
{
public:
    BadgeLabel(T value, QWidget *parent = nullptr, const QString& textColor = "white", int fontSize = 14);
};

template <typename T>
BadgeLabel<T>::BadgeLabel(T value, QWidget *parent, const QString& textColor, int fontSize)
    : QLabel(parent)
{
    if constexpr (std::is_arithmetic_v<T>) {
        setText(QString::number(value));
    } else if constexpr (std::is_same_v<T, QString>) {
        setText(value);
    }
    setAlignment(Qt::AlignCenter);
    this->setAutoFillBackground(true);
    this->raise();

    // Apply custom text color
    setStyleSheet(QString("background-color: #999999; color: %1; border-radius: 10px;").arg(textColor));
    // Set custom font size
    QFont font = this->font();
    font.setPointSize(fontSize);
    setFont(font);

    // Adjust size based on font metrics
    QFontMetrics fm(font);
    int width = fm.horizontalAdvance(text()) + 20;
    int height = fm.height() + 10;
    setFixedSize(width, height);
}

#endif // BADGELABEL_H

