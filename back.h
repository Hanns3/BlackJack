#ifndef BACK_H
#define BACK_H

#include <QPixmap>

class Back {
public:
    // todo: implement setter
    Back(const QString& basePath);
    void InitializeSkin(const QString& basePath);
    QPixmap getBack() const;
private:
    QPixmap back;
};

#endif // BACK_H
