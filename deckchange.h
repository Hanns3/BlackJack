#ifndef DECKCHANGE_H
#define DECKCHANGE_H

#include <QDialog>
#include <QDir>
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>

namespace Ui {
class deckChange;
}

class deckChange : public QDialog
{
    Q_OBJECT

public:
    explicit deckChange(QWidget *parent = nullptr);
    ~deckChange();
    QString getCurrentDirectory() const;

private slots:
    void on_treeView_activated(const QModelIndex &index);

    void on_listView_activated(const QModelIndex &index);

    void on_confirmButton_clicked();

private:
    Ui::deckChange *ui;
    QDir dir;
    QFileSystemModel model;
    QString currentDirectory;
    void init();
};

#endif // DECKCHANGE_H
