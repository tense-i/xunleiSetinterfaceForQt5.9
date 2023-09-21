#ifndef TBASESETWIDGET_H
#define TBASESETWIDGET_H

#include <QWidget>

namespace Ui {
class TBaseSetWidget;
}

class TBaseSetWidget : public QWidget
{
    Q_OBJECT
public:

public:
    explicit TBaseSetWidget(QWidget *parent = nullptr);
    ~TBaseSetWidget();

private:
    Ui::TBaseSetWidget *ui;
};

#endif // TBASESETWIDGET_H
