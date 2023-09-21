#include "tbasesetwidget.h"
#include "ui_tbasesetwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

TBaseSetWidget::TBaseSetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TBaseSetWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("background-color:rgb(51, 51, 51);color:rgb(200,200,200);");
    QCheckBox *ckOpenPowerOn=new QCheckBox(this);
    ckOpenPowerOn->setText("开机启动");

    QCheckBox *ckNodisturb=new QCheckBox(this);
    ckNodisturb->setText("免打扰");
    ckNodisturb->setFixedWidth(140);

    QLabel *labTooltip1=new QLabel(this);
    //labTooltip1->setFixedWidth(5);
    labTooltip1->setText("?");

    QCheckBox *ckBosskey=new QCheckBox(this);
    ckBosskey->setText("启用老板键");
    ckBosskey->setFixedWidth(105);
    QLabel *labTooltip2=new QLabel(this);
    labTooltip2->setText("?");
    QLineEdit *edit=new QLineEdit(this);
    edit->setFixedWidth(100);
    edit->setStyleSheet("border-style:solid;border-width:1px;border-color:rgb(79,79,79);");
    QCheckBox *ckShowHomeScreen=new QCheckBox(this);
    ckShowHomeScreen->setText("新建任务时显示主页面");


    QLabel *labSet=new QLabel(this);
    labSet->setText("基本设置");

    QLabel *labSetDowModel=new QLabel(this);
    labSetDowModel->setText("下载模式");


    QRadioButton *rdBtnQuikDow=new QRadioButton(this);
    rdBtnQuikDow->setText("全速下载");

    QRadioButton *rdBtnLimitDow=new QRadioButton(this);
    rdBtnLimitDow->setText("限速下载");

    QPushButton *btnModify=new QPushButton(this);
    btnModify->setText("修改设置");
    btnModify->setStyleSheet("backgound-color:#1A1A1A;color:#5F5F5F");

    QLabel *labInfo=new QLabel(this);
    labInfo->setText("限制时间段： 00：00 - 23：59 最大下载速度：不限速");

    //主水平布局
    QVBoxLayout *MainVlatout=new QVBoxLayout(this);
    MainVlatout->addWidget(labSet);//添加间隔
    MainVlatout->addSpacing(20);

    QHBoxLayout *Hlayout=new QHBoxLayout(this);
    Hlayout->addSpacing(35);

    //主水平布局1
    QVBoxLayout* Vlayout1=new QVBoxLayout(this);
    //开机启动迅雷
    Vlayout1->addWidget(ckOpenPowerOn);//间距
    Vlayout1->addSpacing(20);

    //免打扰模式下的水平布局
    QHBoxLayout *hLayout2=new QHBoxLayout;
    hLayout2->addWidget(ckNodisturb);
    hLayout2->addWidget(labTooltip1);

    //将免打扰的布局加入主布局1
    Vlayout1->addLayout(hLayout2);
    Vlayout1->addSpacing(20);

    //启用老板键水平布局
    QHBoxLayout *hLayout3=new QHBoxLayout;
    hLayout3=new QHBoxLayout;
    hLayout3->addWidget(ckBosskey);
    hLayout3->addWidget(edit);
    hLayout3->addWidget(labTooltip2);

    //加入主布局
    Vlayout1->addLayout(hLayout3);
    Vlayout1->addSpacing(20);

    //将单个无布局的复选框加入主布局
    Vlayout1->addWidget(ckShowHomeScreen);
    Vlayout1->addSpacing(20);

    //下载模式
    Vlayout1->addWidget(labSetDowModel);
    Vlayout1->setSpacing(20);

    QHBoxLayout *hLayout4=new QHBoxLayout;
    hLayout4->addSpacing(30);
    QVBoxLayout *vLayout2=new QVBoxLayout(this);

    //下载模式下的水平布局5 全速下载
    QHBoxLayout *hLayout5=new QHBoxLayout;
    hLayout5->addWidget(rdBtnQuikDow);
    hLayout5->addWidget(labTooltip2);

    //将水平布局5加入到垂直布局2
    vLayout2->addLayout(hLayout5);
    vLayout2->addSpacing(20);

    //下载模式下的限速下载布局
    QHBoxLayout *hLayout6=new QHBoxLayout;
    hLayout6->addWidget(rdBtnLimitDow);
    hLayout6->addWidget(btnModify);
    hLayout6->addWidget(labInfo);
    hLayout6->addStretch();

    //将水平布局6加入到垂直布局2
   vLayout2->addLayout(hLayout6);

   //将垂直布局2加入到下载界面
   hLayout4->addLayout(vLayout2);

   //将下载界面加入到主垂直布局
   Vlayout1->addLayout(hLayout4);
   //将主垂直布局加入到主水平布局
    Hlayout->addLayout(Vlayout1);

   MainVlatout->addLayout(Hlayout);
    MainVlatout->setContentsMargins(20,20,20,20);

}

TBaseSetWidget::~TBaseSetWidget()
{
    delete ui;
}
