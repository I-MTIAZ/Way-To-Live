#include "quicktest.h"
#include "ui_quicktest.h"
#include"WOT.h"
#include"ui_WOT.h"

WotWindow *pt;
int tob_scor;


QuickTest::QuickTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuickTest)
{
    ui->setupUi(this);
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(0);
    tob_scor = 0;
}

QuickTest::~QuickTest()
{
    delete ui;
}

void QuickTest::on_A_Button_1_S_3_clicked()
{
    tob_scor += 3;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(1);
}


void QuickTest::on_B_Button_1_S_2_clicked()
{
    tob_scor += 2;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(1);
}


void QuickTest::on_C_Button_1_S_1_clicked()
{
    tob_scor += 1;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(1);
}


void QuickTest::on_D_Button_1_S_0_clicked()
{
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(1);
}


void QuickTest::on_A_Button_2_S_1_clicked()
{
    tob_scor += 1;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(2);

}


void QuickTest::on_B_Button_2_S_0_clicked()
{
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(2);
}


void QuickTest::on_A_Button_3_S_0_clicked()
{
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(3);
}


void QuickTest::on_B_Button_3_S_1_clicked()
{
    tob_scor += 1;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(3);
}


void QuickTest::on_C_Button_3_S_2_clicked()
{
    tob_scor += 2;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(3);
}


void QuickTest::on_D_Button_3_S_3_clicked()
{
    tob_scor += 3;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(3);
}


void QuickTest::on_A_Button_4_S_1_clicked()
{
    tob_scor += 1;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(4);
}


void QuickTest::on_B_Button_4_S_0_clicked()
{
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(4);
}


void QuickTest::on_A_Button_5_S_1_clicked()
{
    tob_scor += 1;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(5);

}


void QuickTest::on_B_Button_5_S_0_clicked()
{
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(5);


}


void QuickTest::on_A_Button_6_S_1_clicked()
{
    tob_scor += 1;
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(6);

    if(tob_scor == 10){ tob_scor--; }

    ui->l_Show_Score->setText(QString::number(tob_scor));
    if(tob_scor < 4)
    {
        ui->l_Situation->setText("Less Dependent on Nicotine.");
    }
    else if(tob_scor >= 4 && tob_scor <= 6)
    {
         ui->l_Situation->setText("Moderately Dependent on Nicotine.");
    }
    else
    {
        ui->l_Situation->setText("Highly Dependent on Nicotine.");
    }
}


void QuickTest::on_B_Button_6_S_0_clicked()
{
    ui->stackedWidget_Free_quiz_test->setCurrentIndex(6);

    if(tob_scor == 10){ tob_scor--; }

    ui->l_Show_Score->setText(QString::number(tob_scor));
    if(tob_scor < 4)
    {
        ui->l_Situation->setText("Less Dependent on Nicotine.");
    }
    else if(tob_scor >= 4 && tob_scor <= 6)
    {
         ui->l_Situation->setText("Moderately Dependent on Nicotine.");
    }
    else
    {
        ui->l_Situation->setText("Highly Dependent on Nicotine.");
    }
}


void QuickTest::on_Home_Button_from_Quiz_clicked()
{
    hide();
    qDebug() << total;
    pt = new WotWindow(this);
    pt->show();
}


void QuickTest::on_pushButton_clicked()
{
    hide();
    qDebug() << total;
    pt = new WotWindow(this);
    pt->show();
}

