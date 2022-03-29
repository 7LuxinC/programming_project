#ifndef WORDLEDIALOG_H
#define WORDLEDIALOG_H

#include <QDialog>

namespace Ui {
class WordleDialog;
}

class WordleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WordleDialog(QWidget *parent = nullptr);
    ~WordleDialog();

private:
    Ui::WordleDialog *ui;
};

#endif // WORDLEDIALOG_H
