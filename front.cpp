#include "front.h"

Front::Front(const QString& rank, const QString& suit,const QString& basePath)
{
    QString frontPath = basePath + "/front/" + rank + "_of_" + suit;
    front = QPixmap(frontPath);
}
 void Front::InitializeSkin(const QString& basePath) {

}

 QPixmap Front::getFront() const { return front; }

