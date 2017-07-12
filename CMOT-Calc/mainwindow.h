#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QStringList a_array;
    QStringList b_array;
protected slots:
    void onCB_AChanged();
public slots:
    void clear();
    void updateFormula();
    void initA();
    void setDefaultValues();
    void calcMass();
};

#endif // MAINWINDOW_H
