#ifndef DEEPQUIZ_H
#define DEEPQUIZ_H

#include <QDialog>
#include <QtDebug>

namespace
{
    int total;
}

namespace Ui {
class DeepQuiz;
}

class DeepQuiz : public QDialog
{
    Q_OBJECT
public:
    explicit DeepQuiz(QWidget *parent = nullptr);


    ~DeepQuiz();

private slots:
    void on_flag_T_Button_clicked();

    void on_flag_C_Button_clicked();

    void on_flag_B_Button_clicked();

    void on_Button_1_S_0_clicked();

    void on_Button_1_S_2_clicked();

    void on_Button_1_S_3_clicked();

    void on_Button_1_S_4_clicked();

    void on_Button_1_S_6_clicked();

    void on_Button_2_S_0_clicked();

    void on_Button_2_S_2_clicked();

    void on_Button_2_S_3_clicked();

    void on_Button_2_S_4_clicked();

    void on_Button_2_S_6_clicked();

    void on_Button_3_S_0_clicked();

    void on_Button_3_S_2_clicked();

    void on_Button_3_S_3_clicked();

    void on_Button_3_S_4_clicked();

    void on_Button_3_S_6_clicked();

    void on_Button_4_S_0_clicked();

    void on_Button_4_S_2_clicked();

    void on_Button_4_S_3_clicked();

    void on_Button_4_S_4_clicked();

    void on_Button_4_S_6_clicked();

    void on_Button_5_S_0_clicked();

    void on_Button_5_S_2_clicked();

    void on_Button_5_S_3_clicked();

    void on_Button_5_S_4_clicked();

    void on_Button_5_S_6_clicked();

    void on_Button_6_S_0_clicked();

    void on_Button_6_S_2_clicked();

    void on_Button_6_S_3_clicked();

    void on_Button_6_S_4_clicked();

    void on_Button_6_S_6_clicked();

    void on_pushButton_clicked();




    void on_Home_button_clicked();

    void on_result_button_clicked();

private:
    Ui::DeepQuiz *ui;



};


#endif // DEEPQUIZ_H

