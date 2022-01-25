#include <QApplication>

#include "MainWindow.hxx"

int main(int argc, char** argv){
	QApplication GUI(argc, argv);
	MainWindow window;
	window.show();

	return GUI.exec();
}
