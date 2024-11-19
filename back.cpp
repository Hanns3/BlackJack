#include "back.h"

Back::Back(const QString& basePath)
{
    QString backPath = basePath + "/back/back.png";
    this->back = QPixmap(backPath);
}

void Back::InitializeSkin(const QString& basePath) {

}

QPixmap Back::getBack() const { return back; }
