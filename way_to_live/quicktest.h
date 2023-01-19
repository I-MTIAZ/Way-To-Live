#ifndef QUICKTEST_H
#define QUICKTEST_H

#include <QDialog>

namespace Ui {
class QuickTest;
}

class QuickTest : public QDialog
{
    Q_OBJECT

public:
    explicit QuickTest(QWidget *parent = nullptr);
    ~QuickTest();

private slots:
    void on_A_Button_1_S_3_clicked();

    void on_B_Button_1_S_2_clicked();

    void on_C_Button_1_S_1_clicked();

    void on_D_Button_1_S_0_clicked();

    void on_A_Button_2_S_1_clicked();

    void on_B_Button_2_S_0_clicked();

    void on_A_Button_3_S_0_clicked();

    void on_B_Button_3_S_1_clicked();

    void on_C_Button_3_S_2_clicked();

    void on_D_Button_3_S_3_clicked();

    void on_A_Button_4_S_1_clicked();

    void on_B_Button_4_S_0_clicked();

    void on_A_Button_5_S_1_clicked();

    void on_B_Button_5_S_0_clicked();

    void on_A_Button_6_S_1_clicked();

    void on_B_Button_6_S_0_clicked();

    void on_Home_Button_from_Quiz_clicked();

    void on_pushButton_clicked();

private:
    Ui::QuickTest *ui;
};

#endif // QUICKTEST_H
