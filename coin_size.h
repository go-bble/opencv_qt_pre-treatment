#ifndef OPENCV1_H
#define OPENCV1_H

#include <QMainWindow>
#include <QpMatView>



namespace Ui {
class opencv1;
}

class opencv1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit opencv1(QWidget *parent = 0);
    ~opencv1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::opencv1 *ui;
    QpMatView *mview;
    Mat image,imagemid;

    QString result;
    int yiyuan = 0 ;
    int wumao = 0 ;
    int yimao =0;


    std::vector<std::vector<Point> > contours;
};

#endif // OPENCV1_H
