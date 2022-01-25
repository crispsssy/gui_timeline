#include<iostream>

#include "MainWindow.hxx"

MainWindow::MainWindow(QWidget *Main) 
     : QMainWindow(Main)
{
	setWindowTitle("Timeline Searching system");
	this->resize(500,300);
	this->setFont(QFont("SimSun",16));
	this->Login();

}

MainWindow::~MainWindow()
{

}

void MainWindow::Login(){
	Login_Widget = new QWidget;
	QVBoxLayout *LoginBox = new QVBoxLayout(Login_Widget);

	QLabel *Login_Message = new QLabel;
	Login_Message->setAlignment(Qt::AlignCenter);
	Login_Message->setText("时间线查询系统\n请登录");

	QFormLayout *Login_Form = new QFormLayout;
	EditUser = new QLineEdit;
	EditUser->setPlaceholderText("请输入账号。。。");

        EditPass = new QLineEdit;
	EditPass->setPlaceholderText("请输入密码。。。");
	EditPass->setEchoMode(QLineEdit::Password);

	Login_Form->addRow("user name", EditUser);
	Login_Form->addRow("password", EditPass);

	QHBoxLayout *Login_Button = new QHBoxLayout;
	submit = new QPushButton("确定");
	cancel = new QPushButton("取消");
	Login_Button->addStretch(1);
	Login_Button->addWidget(submit);
	Login_Button->addStretch(1);
	Login_Button->addWidget(cancel);
	Login_Button->addStretch(1);

        LoginBox->addWidget(Login_Message,2);
	LoginBox->addLayout(Login_Form,2);
	LoginBox->addLayout(Login_Button,1);
	this->setCentralWidget(Login_Widget);

	QObject::connect(submit,&QPushButton::clicked,this,&MainWindow::LoginCheck);
	QObject::connect(cancel,&QPushButton::clicked,this,&QMainWindow::close);
}

void MainWindow::LoginCheck(){
	
	std::ifstream Login_File("../doc/Login_File.txt");
	if(EditUser->text().trimmed() == "crisps" && EditPass->text().trimmed() == "749826SSYsy_"){
		this->LoginSuceed();
	}
	else{
		std::string User;
		std::string Pass;
		while(Login_File){
			Login_File>>User>>Pass;
			if(EditUser->text().trimmed().toStdString() == User && 
				    EditPass->text().trimmed().toStdString() == Pass){
				this->LoginSuceed();
				return;
			}
			while(Login_File.get() == ' ' || Login_File.get() == '\n') continue;
		}
		QMessageBox::warning(this,"Warning!","User name or password incorrect",QMessageBox::Yes);
		EditUser->clear();
		EditPass->clear();

		EditUser->setFocus();
	}

}

void MainWindow::LoginSuceed(){
	this->resize(1000,600);
	delete Login_Widget;
	this->SearchingWindow();
}

void MainWindow::SearchingWindow(){
	Searching_Widget = new QWidget;
	QHBoxLayout *SearchingWindow = new QHBoxLayout(Searching_Widget);
	Left_Table_Box = new QGroupBox("Time");
	Time_Table = new QTableWidget;
	Time_Table->setSelectionBehavior(QAbstractItemView::SelectRows);
	Time_Table->setColumnCount(4);
	Time_Table->setHorizontalHeaderLabels(QStringList() <<"Year"<<"Month"<<"Day"<<"Name");
	FlushTable();
	QHBoxLayout *AutoHBoxLayout = new QHBoxLayout;
	AutoHBoxLayout->addWidget(Time_Table);
	Left_Table_Box->setLayout(AutoHBoxLayout);

	//connect(Time_Table,&TableWidget::cellClicked,this,&flushListWidget);
	this->setCentralWidget(Searching_Widget);
}

void MainWindow::FlushTable(){
	disconnect(Time_Table,&QTableWidget::cellChanged,0,0);
	std::ifstream dataFile("../doc/dataFile.txt");
	std::string year, month, day, name, content;
	Time_Table->setRowCount(0);
	while(dataFile){
		dataFile>>year>>month>>day>>name;
		while(dataFile.get() == ' ') continue;   //avoid spaces
		std::getline(dataFile,content);
		Time_Table->setItem(Time_Table->rowCount(),0,new QTableWidgetItem(year));
		Time_Table->setItem(Time_Table->rowCount(),1,new QTableWidgetItem(month));
		Time_Table->setItem(Time_Table->rowCount(),2,new QTableWidgetItem(day));
		Time_Table->setItem(Time_Table->rowCount(),3,new QTableWidgetItem(name));
		if(dataFile.fail()) break;               //avoid empty lines

}
