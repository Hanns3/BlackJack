#include "deckchange.h"
#include "ui_deckchange.h"
#include <QFileDialog>
#include <QMessageBox>
#include "constants.h"

deckChange::deckChange(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deckChange)
{
    ui->setupUi(this);
    init();
}

deckChange::~deckChange()
{
    delete ui;
}

QString deckChange::getCurrentDirectory() const { return currentDirectory; }

void deckChange::init()
{
    dir.cdUp(); dir.cdUp();
    QString imagesPath = dir.absolutePath() + pathToCardDirectory;
    model.setRootPath(imagesPath);
    ui->treeView->setModel(&model);
    ui->listView->setModel(&model);

    QModelIndex rootIndex = model.index(imagesPath);
    ui->treeView->setRootIndex(rootIndex);
    ui->listView->setRootIndex(rootIndex);

    for (int i = 1; i < model.columnCount(); i++) {
        ui->treeView->hideColumn(i);
    }

    ui->listView->setViewMode(QListView::ViewMode::ListMode);
}

void deckChange::on_treeView_activated(const QModelIndex &index)
{
}


void deckChange::on_listView_activated(const QModelIndex &index)
{
}

void deckChange::on_confirmButton_clicked()
{
    QModelIndex selectedIndex = ui->listView->currentIndex();

    if (!selectedIndex.isValid()) {
        QMessageBox::warning(this, tr("Warning"), tr("No directory selected."));
        return;
    }

    QString selectedPath = model.filePath(selectedIndex);

    QFileInfo fileInfo(selectedPath);
    if (fileInfo.isDir()) {

        QString relativePath = dir.relativeFilePath(selectedPath);

        currentDirectory = relativePath;
        QMessageBox::information(this, tr("Success"), tr("Directory was successfully chosen"));
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("Selected item is not a directory."));
    }
    this->close();
}


