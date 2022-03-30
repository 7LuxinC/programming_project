#ifndef WORDLEDIALOG_H
#define WORDLEDIALOG_H

#include <QDialog>
#include <string>
#include "wordle.h"

namespace Ui {
class WordleDialog;
}

class WordleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WordleDialog(QWidget *parent = nullptr);
    ~WordleDialog();

private slots:
    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();

private:
    Ui::WordleDialog *ui;
    const int max = 6;

    wordle *wordleGame;
    void wordWithColor(string word);
};

#endif // WORDLEDIALOG_H
