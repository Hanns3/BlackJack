#ifndef FRONT_H
#define FRONT_H
#include <QPixmap>
#include <QString>

class Front {
public:
    // todo: How use virtual InitializeSkin same for back and front, front needs rank and suit
    // todo: implement setter
    Front(const QString& rank, const QString& suit, const QString& basePath);
    void InitializeSkin(const QString& basePath);
    QPixmap getFront() const;
private:
    QPixmap front;
};

#endif // FRONT_H
