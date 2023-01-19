#ifndef WOTWINDOW_H
#define WOTWINDOW_H

#include <QMainWindow>
#include"quicktest.h"
#include"deepquiz.h"
#include <QString>
#include <QtDebug>
#include <QMessageBox>
#include <iostream>
#include <QDialogButtonBox>
#include <QVector>
#include <QDialog>
#include <QInputDialog>
#include <QDir>
#include <QIcon>
#include <QListWidgetItem>
#include <QDockWidget>
#include <QFont>
#include <QSize>
#include <QPicture>
#include <QMap>
#include <QPair>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include<QFile>
#include<QMovie>
#include<QtGlobal>



QT_BEGIN_NAMESPACE
namespace Ui { class WotWindow; }
QT_END_NAMESPACE

class WotWindow : public QMainWindow
{
    Q_OBJECT

public:
    WotWindow(QWidget *parent = nullptr);

    ~WotWindow();

private slots:
    void on_Main_Button_Quick_Test_clicked();

    void on_Main_Button_signin_clicked();

    void on_log_in_Button_clicked();

    void on_DEEp_Qz_Button_main_clicked();

    void on_Register_Button_main_clicked();

    void on_registre_submit_buttn_clicked();

    void on_Calulattor_button_clicked();

    void on_Calculator_submit_button_clicked();

    void on_reset_board_buuton_clicked();

    void on_logout_button_clicked();

    void on_admin_logout_button_clicked();

    void on_user_info_button_clicked();

    void on_listWidget_clicked(const QModelIndex &index);





    void on_back_from_list_to_admin_button_clicked();

    void on_pushButton_55_clicked();

    void on_update_confirm_button_clicked();

    void on_update_close_button_clicked();

    void on_About_main_clicked();

    void on_Topic_main_clicked();

    void on_refer_main_clicked();



    void on_developer_button_main_clicked();

    void on_update_admin_button_clicked();

    void on_admin_update_close_button_clicked();

    void on_admin_update_confirm_button_clicked();

    void on_Home_main_clicked();

    void on_home_copy_clicked();

    void on_home_copy_8_clicked();

    void on_home_copy_2_clicked();

    void on_home_copy_7_clicked();

    void on_home_copy_3_clicked();

    void on_home_copy_4_clicked();

    void on_home_copy_6_clicked();

    void on_home_copy_5_clicked();

    void on_coppy_Button_Quick_Test_clicked();

    void on_coppy_Button_Quick_Test2_clicked();

    void on_coppy_Button_Quick_Test3_clicked();

    void on_coppy_Button_Quick_Test4_clicked();

    void on_Main_Button_Quick_Test_2_clicked();

    void on_registration_copy_button6_clicked();

    void on_registration_copy_button5_clicked();

    void on_registration_copy_button4_clicked();

    void on_registration_copy_button3_clicked();

    void on_registration_copy_button_clicked();

    void on_Register_Button_main_2_clicked();

    void on_Register_Button_main_3_clicked();

    void on_signin_copy_clicked();

    void on_Main_Button_signin_2_clicked();

    void on_Main_Button_signin_3_clicked();

    void on_Main_Button_signin_4_clicked();

    void on_Main_Button_signin_5_clicked();

    void on_Topic_copy_clicked();

    void on_Topic_main_2_clicked();

    void on_Topic_main_3_clicked();

    void on_developer_button_main_2_clicked();

    void on_About_copy_clicked();

    void on_About_main_2_clicked();

    void on_refer_copy_clicked();

    void on_refer_main_2_clicked();



    void on_Calculator_close_button_clicked();

private:
    Ui::WotWindow *ui;
    QuickTest *quick_tob_test;
    DeepQuiz  *deep_test;
};
#endif // WOTWINDOW_H



class user
{
private:
    QString user_name, pass_word, purpose;
    int Age, total_cigar, total_cost;
public:
    void set_all_user_info(QString user_name, QString pass_word, int Age, QString purpose,
                            int total_cigar, int total_cost)
    {
        this->user_name = user_name;
        this->pass_word = pass_word;
        this->Age = Age;
        this->purpose = purpose;                       
        this->total_cigar = total_cigar;
        this->total_cost = total_cost;
    }
    void registration(QString user_name, QString pass_word, int Age, QString purpose)
    {
        this->user_name = user_name;
        this->pass_word = pass_word;
        this->Age = Age;
        this->purpose = purpose;
    }
    void set_total(int total_cigar, int total_cost)
    {
        this->total_cigar += total_cigar;
        this->total_cost += total_cost;
    }

    void set_username(QString user_name)
    {
        this->user_name = user_name;
    }
    void set_password(QString pass_word)
    {
        this->pass_word = pass_word;
    }
    void set_AGE(int Age)
    {
        this->Age = Age;
    }
    void set_purpose(QString purpose)
    {
        this->purpose = purpose;
    }



    void set_Total_Cigar(int total_cigar)
    {
        this->total_cigar = total_cigar;
    }
    void set_Total_Cost(int total_cost)
    {
        this->total_cost = total_cost;
    }

    QString get_username()
    {
        return user_name;
    }
    QString get_password()
    {
        return pass_word;
    }
    int get_AGE()
    {
        return Age;
    }
    QString get_purpose()
    {
        return purpose;
    }
    int get_Total_Cigar()
    {
        return total_cigar;
    }
    int get_Total_Cost()
    {
        return total_cost;
    }
};

class admin
{
private:
    QString password,admin_username;
    int admin_flag;
public:

    void set_all_admin_info(int admin_flag, QString password,QString admin_username)
    {
        this->admin_flag = admin_flag;
        this->password = password;
        this->admin_username = admin_username;
    }
    void set_admin_Flag(int admin_flag)
    {
        this->admin_flag = admin_flag;
    }

    void set_admin_u_name(QString admin_username)
    {
        this->admin_username = admin_username;
    }
    void set_admin_pass(QString password)
    {
        this->password = password;
    }

    QString get_admin_u_name()
    {
        return admin_username;
    }
    QString get_admin_pass()
    {
        return password;
    }
    int get_admin_Flag()
    {
        return admin_flag;
    }
};

