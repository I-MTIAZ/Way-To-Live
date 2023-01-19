#include "WOT.h"
#include "ui_WOT.h"




QVector<user>arr;
user obj;
admin admin_obj;
int current_user_index;
int admin_f = 0;



void admin_read_file() //read file
{
    QString username, password;

    int ad_flag;
    QString tem;

    QFile file("C:/Users/Imtiaz/Desktop/qt/WOT/way_to_live/admin.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "ADMIN READ FILE NOT OPEN";
            return;
        }
     QTextStream in(&file);
     //brr.clear();
     while (!in.atEnd())
     {
         username = in.readLine();
         password = in.readLine();
         //mail = in.readLine();
         //name = in.readLine();
         tem = in.readLine();
         ad_flag = tem.split(" ")[0].toInt();

         admin_obj.set_all_admin_info(ad_flag, password,username);
         //brr.push_back(admin_obj);
     }
}


void admin_write_file()  //write file
{
    qDebug() << "File Writing ";
    QFile file("C:/Users/Imtiaz/Desktop/qt/WOT/way_to_live/admin.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            qDebug() << "FILE NOT WRITTING";
            return;
        }
     QTextStream out(&file);
     //for (int i = 0; i < brr.size(); i++)
     //{
         QString tem;
         out << admin_obj.get_admin_u_name() << "\n";
         //out << admin_obj.get_admin_name() << "\n";
         out << admin_obj.get_admin_pass() << "\n";
         //out << admin_obj.get_admin_mail() << "\n";

         tem = QString::number(admin_obj.get_admin_Flag());
         out << tem << "\n";
     //}
}







void read_file() //read file
{
    QString username;
    QString password;
    QString piority;
    int AGE, total_cigar,total_cost;

    QString tem;

    QFile file("C:/Users/Imtiaz/Desktop/qt/WOT/way_to_live/dot.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "READ FILE NOT OPEN";
            return;
        }
     QTextStream in(&file);
     arr.clear();
     while (!in.atEnd())
     {
         username = in.readLine();
         password = in.readLine();
         tem = in.readLine();
         AGE = tem.split(" ")[0].toInt();
         piority = in.readLine();
         tem = in.readLine();
         total_cigar = tem.split(" ")[0].toInt();
         tem = in.readLine();
         total_cost = tem.split(" ")[0].toInt();

         obj.set_all_user_info(username,password,AGE,piority,total_cigar,total_cost);
         arr.push_back(obj);
     }
}


void write_file()  //write file
{
    qDebug() << "File Writing ";
    QFile file("C:/Users/Imtiaz/Desktop/qt/WOT/way_to_live/dot.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            qDebug() << "FILE NOT WRITTING";
            return;
        }
     QTextStream out(&file);
     for (int i = 0; i < arr.size(); i++)
     {
         QString tem;
         out << arr[i].get_username() << "\n";
         out << arr[i].get_password() << "\n";
         tem = QString::number(arr[i].get_AGE());
         out << tem << "\n";
         out << arr[i].get_purpose() << "\n";
         tem = QString::number(arr[i].get_Total_Cigar());
         out << tem << "\n";
         tem = QString::number(arr[i].get_Total_Cost());
         out << tem << "\n";
     }
}







WotWindow::WotWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WotWindow)
{
    ui->setupUi(this);
    read_file();
    admin_read_file();
    ui->stackedWidget_main->setCurrentIndex(0);

    QMovie* movie=  new QMovie(":/img/Vanilla-2.9s-280pxExtra.gif");
    if (!movie->isValid())
    {
        qDebug() << "Something went wrong";
    }
    ui->label_animated->setMovie(movie);
    movie->start();

}

WotWindow::~WotWindow()
{
    delete ui;
}


void WotWindow::on_Main_Button_Quick_Test_clicked()
{
    hide();
    quick_tob_test = new QuickTest(this);
    quick_tob_test->show();
}


void WotWindow::on_Main_Button_signin_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
    ui->login_frame->show();
    ui->login_icon->show();
    ui->graphicsView_login->show();
    ui->graphicsView_registration->hide();
    ui->registration_frame->hide();
}


void WotWindow::on_log_in_Button_clicked()
{
    QString tem;
    int f = 0;
    int A = 0;

    qDebug() << "hey\n" ;

    if(admin_obj.get_admin_u_name() == ui->Login_u_name->text() && admin_obj.get_admin_pass() == ui->login_pass->text())
    {
        A = 1;
        ui->Login_u_name->clear();
        ui->login_pass->clear();

        ui->stackedWidget_main->setCurrentIndex(3);
        ui->admin_update_frame->hide();
        qDebug() << "not ok in loop\n" ;
    }
    else
    {

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i].get_username() == ui->Login_u_name->text() && arr[i].get_password()==ui->login_pass->text())
        {
            f = 1;
            current_user_index = i;

            ui->Login_u_name->clear();
            ui->login_pass->clear();

            ui->stackedWidget_main->setCurrentIndex(2);
            ui->update_frame->hide();
            ui->calculator_frame->hide();
            QMovie* movie=  new QMovie(":/img/ezgif.com-gif-maker.gif");
            if (!movie->isValid())
            {
                qDebug() << "Something went wrong in profile animation";
            }
            ui->profile_animation->setMovie(movie);
            movie->start();
            qDebug() << "ok in loop\n" ;
        }
    }
    }
    if(f != 1 && A != 1)
    {
        qDebug() << "something wrong\n" ;
        ui->Login_u_name->clear();
        ui->login_pass->clear();
        QMessageBox::critical(this, tr("WTL"), tr("Wrong Username or Password\t\n Try again?"), QMessageBox::Ok);
    }
    else if(f == 1)
    {
    ui->S_username->setText(arr[current_user_index].get_username());
    ui->Show_Totl_cigar->setText(QString::number(arr[current_user_index].get_Total_Cigar()));
    ui->shoe_Totl_cost->setText(QString::number(arr[current_user_index].get_Total_Cost()));
    ui->board_frame->show();
    ui->board_icon->show();
    }
    else if(A == 1)
    {
        ui->admin_u_name_s->setText(admin_obj.get_admin_u_name());
        ui->admin_pass_s->setText(admin_obj.get_admin_pass());
    }


    qDebug() << "i am in end stage\n" ;
}


void WotWindow::on_DEEp_Qz_Button_main_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("WTL"), tr("When Deep Quiz Start You will be Sign Out Automatically\nAre You Ready to Start?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {

        ui->logout_button->click();
    hide();
    deep_test = new DeepQuiz(this);
    deep_test->show();
    }
}

void WotWindow::on_Register_Button_main_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
    ui->login_frame->hide();
    ui->login_icon->hide();
    ui->graphicsView_login->hide();
    ui->graphicsView_registration->show();
    ui->registration_frame->show();
    admin_f = admin_obj.get_admin_Flag();
    if(admin_f == 0)
    {
        ui->panel_lavel->setText("Admin Panel");
        ui->L_age->hide();
        ui->comboBox->hide();
    }
    else
    {
        ui->panel_lavel->setText("User Registration");
        ui->L_age->show();
        ui->comboBox->show();
    }


}


void WotWindow::on_registre_submit_buttn_clicked()
{
    qDebug() << "start\n" ;
    QString tem;
    QString u_name;
    QString pass;
    QString pior;
    int f = 0;
    int Age;
    qDebug() << "take variable\n" ;
    admin_f = admin_obj.get_admin_Flag();
    if(admin_f == 0)
    {
        u_name = ui->L_username->text();
        pass = ui->L_pass->text();
        admin_obj.set_admin_u_name(u_name);
        admin_obj.set_admin_pass(pass);
        admin_obj.set_admin_Flag(1);
        f = 1;
        if(f == 1)
        {
            QMessageBox::information(this, tr("WTL"), tr("Successfully registered\nNow Login for continue"), QMessageBox::Ok);
            ui->L_username->clear();
            ui->L_pass->clear();
            qDebug() << "everything is ok\n" ;
            ui->stackedWidget_main->setCurrentIndex(1);
            ui->graphicsView_registration->hide();
            ui->login_frame->show();
            ui->graphicsView_login->show();            ui->login_icon->show();
            ui->registration_frame->hide();
            admin_write_file();
        }
        else
           QMessageBox::warning(this, tr("WTL"), tr("Try again !\nUse unique name\nFillup all information"), QMessageBox::Ok);


    }
    else
    {
        u_name = ui->L_username->text();
        pass = ui->L_pass->text();
        tem = ui->L_age->text();
        Age = tem.split(" ")[0].toInt();
        pior = ui->comboBox->currentText();
        qDebug() << "take input\n" ;

        for (int i = 0; i < arr.size(); i++)
        {
          if (u_name == arr[i].get_username() || u_name == admin_obj.get_admin_u_name())
          {
            ui->L_username->clear();
            ui->L_pass->clear();
            ui->L_age->clear();
            QMessageBox::warning(this, tr("Way to Live"), tr("Try again !\nUse unique name\nFillup all information"), QMessageBox::Ok);
            u_name = "";
            //ui->stackedWidget_main->setCurrentIndex(1);
            break;
            }
          }

            if(u_name != ""){
            obj.registration(u_name,pass,Age,pior);
            arr.push_back(obj);
            qDebug() << "input set in class\n" ;
            QMessageBox::information(this, tr("WTL"), tr("Successfully registered\nNow Login for continue"), QMessageBox::Ok);
            ui->L_username->clear();
            ui->L_pass->clear();
            ui->L_age->clear();
            qDebug() << "everything is ok\n" ;
            ui->stackedWidget_main->setCurrentIndex(1);
            ui->graphicsView_registration->hide();
            ui->graphicsView_login->show();
            ui->login_frame->show();
            ui->login_icon->show();
            ui->registration_frame->hide();
            write_file();
        }

    }

}


void WotWindow::on_Calulattor_button_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(2);
    ui->calculator_frame->show();
    ui->board_frame->hide();
    ui->board_icon->hide();
}


void WotWindow::on_Calculator_submit_button_clicked()
{
    QString tem;
    int cigar,cost;
    int f = 0;

    tem = ui->enter_totL_cigar->text();
    cigar = tem.split(" ")[0].toInt();
    tem = ui->enter_totL_cost->text();
    cost = tem.split(" ")[0].toInt();
    //for(int i = current_user_index; i <= current_user_index; i++)
    //{
        arr[current_user_index].set_total(cigar,cost);
        f = 1;
    //}
    if(f == 1)
    {
        QMessageBox::information(this, tr("WTL"), tr("Successfully Submitted"), QMessageBox::Ok);
        ui->enter_totL_cigar->clear();
        ui->enter_totL_cost->clear();
        qDebug() << "everything is ok\n" ;

    }
        else
           QMessageBox::warning(this, tr("WTL"), tr("Try again !\nSomething is wrong"), QMessageBox::Ok);

    //profile
    ui->calculator_frame->hide();
    ui->board_frame->show();
    ui->board_icon->show();

    ui->stackedWidget_main->setCurrentIndex(2);
    ui->Show_Totl_cigar->setText(QString::number(arr[current_user_index].get_Total_Cigar()));
    ui->shoe_Totl_cost->setText(QString::number(arr[current_user_index].get_Total_Cost()));
}


void WotWindow::on_reset_board_buuton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("WTL"), tr("Reset?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {

        //for(int i = current_user_index; i <= current_user_index; i++)
        //{
            arr[current_user_index].set_Total_Cigar(0);
            arr[current_user_index].set_Total_Cost(0);
        //}
        ui->Show_Totl_cigar->clear();
        ui->shoe_Totl_cost->clear();
    }



}


void WotWindow::on_logout_button_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
    ui->Show_Totl_cigar->clear();
    ui->shoe_Totl_cost->clear();
    write_file();

}


void WotWindow::on_admin_logout_button_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
    admin_write_file();
}


void WotWindow::on_user_info_button_clicked()
{
    for (int i = 0; i < arr.size(); i++)
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        QFont f;

        f.setPointSize(14);
        newItem->setText(arr[i].get_username());
        ui->listWidget->addItem(newItem);
    }
    ui->stackedWidget_main->setCurrentIndex(4);
}

QString flagName;
void WotWindow::on_listWidget_clicked(const QModelIndex &index)
{
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i].get_username() == ui->listWidget->currentItem()->text())
      {
        QString tem;
        flagName = arr[i].get_username();
        ui->list_u_name->setText(arr[i].get_username());
        ui->list_purpose->setText(arr[i].get_purpose());
        tem = QString::number(arr[i].get_AGE());
        ui->list_age->setText(tem);
        tem = QString::number(arr[i].get_Total_Cigar());
        ui->list_total_cigar->setText(tem);
        tem = QString::number(arr[i].get_Total_Cost());
        ui->list_total_cost->setText(tem);
        ui->stackedWidget_main->setCurrentIndex(4);
        break;
      }
    }
}


void WotWindow::on_back_from_list_to_admin_button_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(3);
    ui->listWidget->clear();
}

// support key setup;


void WotWindow::on_pushButton_55_clicked()
{
    ui->profile_animation->hide();
    ui->update_frame->show();
}


void WotWindow::on_update_confirm_button_clicked()
{
    ui->update_frame->hide();

    QString name,pass,con_pass;
    int u = 0, p = 0,t = 0;

    name = ui->edit_u_name->text();
    pass = ui->edit_u_pass->text();
    con_pass = ui->edit_u_pass_confirm->text();
    qDebug() << "Name size" << name.size();
    qDebug() <<"Pass size" << pass.size();
    if(name.size() != 0) {u = 1;}
    if(pass.size() != 0) {p = 1;}


    if(p == 1 && pass == con_pass && u == 1)
    {
        arr[current_user_index].set_username(name);
        arr[current_user_index].set_password(pass);
        QMessageBox::information(this, tr("WTL"), tr("Your Information Updated\n"), QMessageBox::Ok);
        t = 1;
        ui->edit_u_name->clear();
        ui->edit_u_pass->clear();
        ui->edit_u_pass_confirm->clear();
    }
    else if(p == 1 && pass == con_pass)
    {
        arr[current_user_index].set_password(pass);
        QMessageBox::information(this, tr("WTL"), tr("Your Information Updated\n"), QMessageBox::Ok);
        t = 1;
        ui->edit_u_name->clear();
        ui->edit_u_pass->clear();
        ui->edit_u_pass_confirm->clear();
    }

    else if(u == 1)
    {
        arr[current_user_index].set_username(name);
        QMessageBox::information(this, tr("WTL"), tr("Your Information Updated\n"), QMessageBox::Ok);
        t = 1;
        ui->edit_u_name->clear();
        ui->edit_u_pass->clear();
        ui->edit_u_pass_confirm->clear();
    }
    if(t == 1)
    {
        if(u == 1)
        ui->S_username->setText(name);

    }
    else
    {
     QMessageBox::critical(this, tr("WTL"), tr("Somethin Wrong\nTry Again"), QMessageBox::Ok);
     ui->edit_u_name->clear();
     ui->edit_u_pass->clear();
     ui->edit_u_pass_confirm->clear();
    }

    ui->profile_animation->show();
}


void WotWindow::on_update_close_button_clicked()
{
    ui->update_frame->hide();
    ui->profile_animation->show();
}





void WotWindow::on_update_admin_button_clicked()
{
    ui->admin_update_frame->show();
    ui->admin_frame->hide();
}


void WotWindow::on_admin_update_close_button_clicked()
{
    ui->admin_update_frame->hide();
    ui->admin_frame->show();
}


void WotWindow::on_admin_update_confirm_button_clicked()
{

    QString name,pass,con_pass;
    ui->admin_update_frame->hide();
    ui->admin_frame->show();
    int u = 0, p = 0,t = 0;

    name = ui->edit_admin_name->text();
    pass = ui->edit_admin_pass->text();
    con_pass = ui->edit_admin_pass_confirm->text();
    qDebug() << "Name size" << name.size();
    qDebug() <<"Pass size" << pass.size();
    if(name.size() != 0) {u = 1;}
    if(pass.size() != 0) {p = 1;}


    if(p == 1 && pass == con_pass && u == 1)
    {
        admin_obj.set_admin_u_name(name);
        admin_obj.set_admin_pass(pass);
        QMessageBox::information(this, tr("WTL"), tr("Your Information Updated\n"), QMessageBox::Ok);
        t = 1;
        ui->edit_admin_name->clear();
        ui->edit_admin_pass->clear();
        ui->edit_admin_pass_confirm->clear();
    }
    else if(p == 1 && pass == con_pass)
    {
        admin_obj.set_admin_pass(pass);
        QMessageBox::information(this, tr("WTL"), tr("Your Information Updated\n"), QMessageBox::Ok);
        t = 1;
        ui->edit_admin_name->clear();
        ui->edit_admin_pass->clear();
        ui->edit_admin_pass_confirm->clear();
    }

    else if(u == 1)
    {
        admin_obj.set_admin_u_name(name);
        QMessageBox::information(this, tr("WTL"), tr("Your Information Updated\n"), QMessageBox::Ok);
        t = 1;
        ui->edit_admin_name->clear();
        ui->edit_admin_pass->clear();
        ui->edit_admin_pass_confirm->clear();
    }
    if(t == 1)
    {
        if(u == 1)
        ui->admin_u_name_s->setText(name);
        if(p == 1)
        ui->admin_pass_s->setText(pass);
    }
    else
    {
     QMessageBox::critical(this, tr("WTL"), tr("Somethin Wrong\nTry Again"), QMessageBox::Ok);
     ui->edit_admin_name->clear();
     ui->edit_admin_pass->clear();
     ui->edit_admin_pass_confirm->clear();
    }


}
// main_Button && sub_button managment



// main_button registration && sign in button define before;
void WotWindow::on_Home_main_clicked()
{

    ui->stackedWidget_main->setCurrentIndex(0);
}
void WotWindow::on_About_main_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(5);
    ui->about_frame->show();
    ui->about_text->show();
    ui->developer_frame->hide();
    ui->developer_frame->hide();
    ui->develope_icon->hide();
}


void WotWindow::on_Topic_main_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(7);
    QMovie* movie=  new QMovie(":/img/quit-smoking.gif");
    if (!movie->isValid())
    {
        qDebug() << "Something went wrong";
    }
    ui->topic_animation->setMovie(movie);
    movie->start();
}


void WotWindow::on_refer_main_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(6);
}

void WotWindow::on_developer_button_main_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(5);
    ui->about_frame->hide();
    ui->about_text->hide();
    ui->developer_frame->show();
    ui->developer_frame->show();
    ui->developer_frame->show();
    ui->develope_icon->show();
}

// Sub_button


//Sub_home_button



void WotWindow::on_home_copy_clicked()   {ui->Home_main->click();}
void WotWindow::on_home_copy_8_clicked() {ui->Home_main->click();}
void WotWindow::on_home_copy_2_clicked() {ui->Home_main->click();}
void WotWindow::on_home_copy_7_clicked() {ui->Home_main->click();}
void WotWindow::on_home_copy_3_clicked() {ui->Home_main->click();}
void WotWindow::on_home_copy_4_clicked() {ui->Home_main->click();}
void WotWindow::on_home_copy_6_clicked() {ui->Home_main->click();}
void WotWindow::on_home_copy_5_clicked() {ui->Home_main->click();}

//Sub_Quick_test_button

void WotWindow::on_coppy_Button_Quick_Test_clicked() {ui->Main_Button_Quick_Test->click();}
void WotWindow::on_coppy_Button_Quick_Test2_clicked() {ui->Main_Button_Quick_Test->click();}
void WotWindow::on_coppy_Button_Quick_Test3_clicked() {ui->Main_Button_Quick_Test->click();}
void WotWindow::on_coppy_Button_Quick_Test4_clicked() {ui->Main_Button_Quick_Test->click();}
void WotWindow::on_Main_Button_Quick_Test_2_clicked() {ui->Main_Button_Quick_Test->click();}

//Sub_Registration_button

void WotWindow::on_registration_copy_button6_clicked() {ui->Register_Button_main->click();}
void WotWindow::on_registration_copy_button5_clicked() {ui->Register_Button_main->click();}
void WotWindow::on_registration_copy_button4_clicked() {ui->Register_Button_main->click();}
void WotWindow::on_registration_copy_button3_clicked() {ui->Register_Button_main->click();}
void WotWindow::on_registration_copy_button_clicked() {ui->Register_Button_main->click();}
void WotWindow::on_Register_Button_main_2_clicked() {ui->Register_Button_main->click();}
void WotWindow::on_Register_Button_main_3_clicked() {ui->Register_Button_main->click();}

//Sub_sign_In_button

void WotWindow::on_signin_copy_clicked() {ui->Main_Button_signin->click();}
void WotWindow::on_Main_Button_signin_2_clicked() {ui->Main_Button_signin->click();}
void WotWindow::on_Main_Button_signin_3_clicked() {ui->Main_Button_signin->click();}
void WotWindow::on_Main_Button_signin_4_clicked() {ui->Main_Button_signin->click();}
void WotWindow::on_Main_Button_signin_5_clicked() {ui->Main_Button_signin->click();}

//Sub_sign_In_button

void WotWindow::on_Topic_copy_clicked() {ui->Topic_main->click();}
void WotWindow::on_Topic_main_2_clicked() {ui->Topic_main->click();}
void WotWindow::on_Topic_main_3_clicked() {ui->Topic_main->click();}

//Sub_Developer_button

void WotWindow::on_developer_button_main_2_clicked() {ui->developer_button_main->click();}

//Sub_about_us_button

void WotWindow::on_About_copy_clicked() {ui->About_main->click();}
void WotWindow::on_About_main_2_clicked() {ui->About_main->click();}

//Sub_Reference_button

void WotWindow::on_refer_copy_clicked() {ui->refer_main->click();}
void WotWindow::on_refer_main_2_clicked()  {ui->refer_main->click();}




void WotWindow::on_Calculator_close_button_clicked()
{
        ui->enter_totL_cigar->clear();
        ui->enter_totL_cost->clear();
        ui->calculator_frame->hide();
        ui->board_frame->show();
        ui->board_icon->show();
        ui->stackedWidget_main->setCurrentIndex(2);
}

