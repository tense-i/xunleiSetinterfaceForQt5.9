#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <tbasesetwidget.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:
    QListWidget* listWidget=nullptr;
    QScrollArea* scrollArea=nullptr;
    QStringList strList;
    TBaseSetWidget *baseSetWidget=nullptr;
    QWidget * YunpanSet=nullptr;
    QWidget * DownlodSet=nullptr;
    QWidget *jieguanSet=nullptr;
    QWidget* RenwuWidget;
    QWidget* TixingWidget;
    QWidget* XuanfuWidget;
    std::vector<QWidget*> widges;
    bool signFlag=false;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_itemClicked(QListWidgetItem *item);
    void on_valueChanged(int value);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
