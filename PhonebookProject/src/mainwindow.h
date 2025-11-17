#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "phonebook.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QTableWidget *m_table;
    PhoneBook m_phonebook;
    void setupUi();
    void refreshTable();
};

#endif // MAINWINDOW_H
