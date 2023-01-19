#include "deepquiz.h"
#include "ui_deepquiz.h"
#include"WOT.h"
#include"ui_WOT.h"

WotWindow *ptt;








int T , C , B ;



DeepQuiz::DeepQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeepQuiz)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    T = 0, C = 0, B = 0;
    total = 0;
}

DeepQuiz::~DeepQuiz()
{
    delete ui;
}
void DeepQuiz::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void DeepQuiz::on_flag_T_Button_clicked()
{
    T = 1;
    ui->stackedWidget->setCurrentIndex(2);
}


void DeepQuiz::on_flag_C_Button_clicked()
{
    C = 1;
    ui->stackedWidget->setCurrentIndex(2);
}


void DeepQuiz::on_flag_B_Button_clicked()
{
    B = 1;
    ui->stackedWidget->setCurrentIndex(2);
}


void DeepQuiz::on_Button_1_S_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void DeepQuiz::on_Button_1_S_2_clicked()
{
    total += 2;
    ui->stackedWidget->setCurrentIndex(3);
}


void DeepQuiz::on_Button_1_S_3_clicked()
{
    total += 3;
    ui->stackedWidget->setCurrentIndex(3);
}


void DeepQuiz::on_Button_1_S_4_clicked()
{
    total += 4;
    ui->stackedWidget->setCurrentIndex(3);
}


void DeepQuiz::on_Button_1_S_6_clicked()
{
    total += 6;
    ui->stackedWidget->setCurrentIndex(3);
}


void DeepQuiz::on_Button_2_S_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void DeepQuiz::on_Button_2_S_2_clicked()
{
    total += 2;
    ui->stackedWidget->setCurrentIndex(4);
}


void DeepQuiz::on_Button_2_S_3_clicked()
{
    total += 3;
    ui->stackedWidget->setCurrentIndex(4);
}


void DeepQuiz::on_Button_2_S_4_clicked()
{
    total += 4;
    ui->stackedWidget->setCurrentIndex(4);
}


void DeepQuiz::on_Button_2_S_6_clicked()
{
    total += 6;
    ui->stackedWidget->setCurrentIndex(4);
}


void DeepQuiz::on_Button_3_S_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void DeepQuiz::on_Button_3_S_2_clicked()
{
    total += 2;
    ui->stackedWidget->setCurrentIndex(5);
}


void DeepQuiz::on_Button_3_S_3_clicked()
{
    total += 3;
    ui->stackedWidget->setCurrentIndex(5);
}


void DeepQuiz::on_Button_3_S_4_clicked()
{
    total += 4;
    ui->stackedWidget->setCurrentIndex(5);
}


void DeepQuiz::on_Button_3_S_6_clicked()
{
    total += 6;
    ui->stackedWidget->setCurrentIndex(5);
}


void DeepQuiz::on_Button_4_S_0_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void DeepQuiz::on_Button_4_S_2_clicked()
{
    total += 2;
    ui->stackedWidget->setCurrentIndex(6);
}


void DeepQuiz::on_Button_4_S_3_clicked()
{
    total += 3;
    ui->stackedWidget->setCurrentIndex(6);
}


void DeepQuiz::on_Button_4_S_4_clicked()
{
    total += 4;
    ui->stackedWidget->setCurrentIndex(6);
}


void DeepQuiz::on_Button_4_S_6_clicked()
{
    total += 6;
    ui->stackedWidget->setCurrentIndex(6);
}


void DeepQuiz::on_Button_5_S_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void DeepQuiz::on_Button_5_S_2_clicked()
{
    total += 2;
    ui->stackedWidget->setCurrentIndex(7);
}


void DeepQuiz::on_Button_5_S_3_clicked()
{
    total += 3;
    ui->stackedWidget->setCurrentIndex(7);
}


void DeepQuiz::on_Button_5_S_4_clicked()
{
    total += 4;
    ui->stackedWidget->setCurrentIndex(7);
}


void DeepQuiz::on_Button_5_S_6_clicked()
{
    total += 6;
    ui->stackedWidget->setCurrentIndex(7);
}


void DeepQuiz::on_Button_6_S_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}


void DeepQuiz::on_Button_6_S_2_clicked()
{
    total += 2;
    ui->stackedWidget->setCurrentIndex(8);

}


void DeepQuiz::on_Button_6_S_3_clicked()
{
    total += 3;
    ui->stackedWidget->setCurrentIndex(8);

}


void DeepQuiz::on_Button_6_S_4_clicked()
{
    total += 4;
    ui->stackedWidget->setCurrentIndex(8);

}


void DeepQuiz::on_Button_6_S_6_clicked()
{
    total += 6;

    ui->stackedWidget->setCurrentIndex(8);

}



void DeepQuiz::on_Home_button_clicked()
{
  hide();
  qDebug() << total;
  ptt = new WotWindow(this);
  ptt->show();




}


void DeepQuiz::on_result_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    if(T == 1){
        ui->Show_T->setText(QString::number(total));
        ui->Show_C->setText(QString::number(0));
    }
    else if(C == 1){
        ui->Show_T->setText(QString::number(0));
        ui->Show_C->setText(QString::number(total));
    }
    else if(B == 1){
        ui->Show_T->setText(QString::number(total));
        ui->Show_C->setText(QString::number(total));
    }
}

