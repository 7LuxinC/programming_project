#ifndef WORDLEDIALOG_H
#define WORDLEDIALOG_H

#include <QDialog>
#include <string>
#include "wordle.h"

using namespace std;

namespace Ui {
class WordleDialog;
}

class WordleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WordleDialog(QWidget *parent = nullptr);
    ~WordleDialog();
    bool winGame();

private slots:
    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();


private:
    Ui::WordleDialog *ui;
    wordle *wordleGame;
    void wordWithColor(string word);
    bool wonOrLost;
    const int max = 6;                                                          //constant variable
};

#endif // WORDLEDIALOG_H
