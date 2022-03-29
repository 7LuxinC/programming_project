#include "wordledialog.h"
#include "ui_wordledialog.h"

WordleDialog::WordleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WordleDialog)
{
    ui->setupUi(this);
}

WordleDialog::~WordleDialog()
{
    delete ui;
}
