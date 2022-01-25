#ifndef MAINWINDOW_HXX_
#define MAINWINDOW_HXX_

#include <iostream>
#include <fstream>

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QLabel>
#include <QString>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
      MainWindow(QWidget *parent =0);
      ~MainWindow();

      void Login();
      void LoginCheck();
      void LoginSuceed();
      void SearchingWindow();
      void FlushTable();

private:
      QWidget *Login_Widget;
      QWidget *Searching_Widget;
      QLineEdit *EditUser;
      QLineEdit *EditPass;
      QPushButton *submit;
      QPushButton *cancel;
      QHBoxLayout *HBoxLayout;
      QGroupBox *Left_Table_Box;
      QGroupBox *Right_Table_Box;
      QTableWidget *Time_Table;
};

#endif
