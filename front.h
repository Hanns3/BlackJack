#ifndef FRONT_H
#define FRONT_H
#include <QPixmap>
#include <QString>

class Front {
public:
    Front(const QString& rank, const QString& suit, const QString& basePath);
    void InitializeSkin(const QString& basePath);
    QPixmap getFront() const;
private:
    QPixmap front;
};

#endif // FRONT_H
