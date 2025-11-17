#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "filestorage.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    QWidget *central = new QWidget(this);
    QVBoxLayout *v = new QVBoxLayout(central);
    m_table = new QTableWidget(0, 5, this);
    QStringList headers = {"Фамилия","Имя","Отчество","Телефоны","Email"};
    m_table->setHorizontalHeaderLabels(headers);
    v->addWidget(m_table);

    QPushButton *bLoad = new QPushButton("Загрузить", this);
    QPushButton *bSave = new QPushButton("Сохранить", this);
    v->addWidget(bLoad);
    v->addWidget(bSave);

    connect(bLoad, &QPushButton::clicked, [this]{
        FileStorage fs;
        m_phonebook = PhoneBook();
        fs.load(m_phonebook, "phonebook.json");
        refreshTable();
    });
    connect(bSave, &QPushButton::clicked, [this]{
        FileStorage fs;
        fs.save(m_phonebook, "phonebook.json");
    });

    setCentralWidget(central);
}

void MainWindow::refreshTable() {
    m_table->setRowCount(0);
    int row = 0;
    for (const Contact &c : m_phonebook.contacts()) {
        m_table->insertRow(row);
        m_table->setItem(row, 0, new QTableWidgetItem(c.lastName));
        m_table->setItem(row, 1, new QTableWidgetItem(c.firstName));
        m_table->setItem(row, 2, new QTableWidgetItem(c.middleName));
        QString phones;
        for (const PhoneNumber &p : c.phones) { if (!phones.isEmpty()) phones += ", "; phones += p.number; }
        m_table->setItem(row, 3, new QTableWidgetItem(phones));
        m_table->setItem(row, 4, new QTableWidgetItem(c.email));
        ++row;
    }
}
