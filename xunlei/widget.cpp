#include "widget.h"
#include "ui_widget.h"
#include <string>
#include  <QScrollBar>
#include <QFrame>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    setFixedSize(150+1000+30+25,900);
    //设置为黑色背景
    this->setStyleSheet("background-color:rgb(26,26,26)");
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint);
    //listwidget(150)+scorllArea(1000+30)

    ui->setupUi(this);


    listWidget=new QListWidget(this);
    listWidget->setFocusPolicy(Qt::NoFocus);


    listWidget->setFrameShape(QFrame::NoFrame);
    listWidget->setFixedWidth(150);
    scrollArea=new QScrollArea(this);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //scorllBar(30)
    scrollArea->setFixedWidth(1000+30);

    QHBoxLayout *HLayout=new QHBoxLayout(this);
    HLayout->addWidget(listWidget);
    HLayout->addWidget(scrollArea);

    strList<<"基本设置"<<"云盘设置"<<"下载设置"<<"接管设置"<<"任务管理"<<"提醒";
    listWidget->addItems(strList);

    //写Json文件方便
    std::string lw_qss=R"(
    QListWidget
        {
            /*border:1px solid gray;   �߽���:���ȡ���ɫ*/
            background:rgb(26, 26, 26);   /*���񱳾�ɫ*/
            color:rgb(200, 200, 200);     /*ǰ��ɫ��������ɫ*/
            font-size:15px;
            border-radius:1px;
        }

        QListWidget::item
        {
            height:40px;
            padding-left:10px; /*�����ı���left��ߵľ���*/
        }

        QListWidget::item:!active
        {
            background:rgb(26, 26, 26);
            margin:5px 20px 1px 20px;   /*��������, ����item��ListWidget�ľ���*/
        }

        QListWidget::item:hover
        {
            background:rgb(56, 56, 56);
            /*padding-left:30px;*/
        }

        QListWidget::item:selected
        {
            border-radius:15px;
            background:lightblue;
        }

        /*�ϴ�ѡ�������״̬������뿪����ʾ*/
        QListWidget::item:selected:!active
        {
            background:rgb(51,51,51);
            color:#3F85FF;
        })";
    listWidget->setStyleSheet(QString::fromStdString(lw_qss));

    std::string verticalbar_qss = R"(
        QScrollBar{width:16px;background:rgb(26, 26, 26);margin:0px, 0px, 0px, 0px;}
        QScrollBar::handle:vertical{width:8px;background:rgba(162, 163, 165, 100%);border-radius:4px;min-height:40;}
              QScrollBar::handle:vertical:hover{width:8px;background:rgba(115,118,118, 100%);border-radius:4px;min-height:40;}
              QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgb(26, 26, 26);border-radius:4px;}
              QScrollBar::top-arrow:vertical,QScrollBar::bottom-arrow:vertical{border: none;background: none;color: none;}
              QScrollBar::add-line:vertical{border:none;background:none;}
              QScrollBar::sub-line:vertical{border:none;background:none;}
        )";
    scrollArea->verticalScrollBar()->setStyleSheet(QString::fromStdString(verticalbar_qss));

    baseSetWidget=new TBaseSetWidget(this);
    widges.push_back(baseSetWidget);

    YunpanSet=new QWidget(this);
    YunpanSet->setFixedSize(1000,478);
    YunpanSet->setStyleSheet("background-image:url(:/resources/YunPanSet.png);background-repeat: no-repeat;background-color:rgb(51, 51, 51)");
    widges.push_back(YunpanSet);

    DownlodSet=new QWidget(this);
    DownlodSet->setFixedSize(1000,337);
    DownlodSet->setStyleSheet("background-image:url(:/resources/XiaZai.png);background-repeat: no-repeat;background-color:rgb(51, 51, 51)");
    widges.push_back(DownlodSet);

    jieguanSet=new QWidget(this);
    jieguanSet->setFixedSize(1000,400);
    jieguanSet->setStyleSheet("background-image:url(:/resources/JieGuanSet.png);background-repeat: no-repeat;background-color:rgb(51, 51, 51)");
    widges.push_back(jieguanSet);
    RenwuWidget=new QWidget(this);
    RenwuWidget->setStyleSheet("background-image:url(:/resources/RenwuGuanli.png);background-repeat: no-repeat;background-color:rgb(51, 51, 51)");
    RenwuWidget->setFixedSize(1000,413);
    widges.push_back(RenwuWidget);
    TixingWidget=new QWidget(this);
    TixingWidget->setStyleSheet("background-image:url(:/resources/TiXing.png);background-repeat: no-repeat;background-color:rgb(51, 51, 51)");
    TixingWidget->setFixedSize(1000,728);
    widges.push_back(TixingWidget);

    QWidget *mainSetWidget=new QWidget(this);
    QVBoxLayout *vlayout=new QVBoxLayout(mainSetWidget);
    for(auto wd:widges)
    {
        vlayout->addWidget(wd);
        vlayout->addSpacing(5);
    }
    vlayout->setContentsMargins(5,5,5,5);
    scrollArea->setWidget(mainSetWidget);

    QHBoxLayout * hlayout=new QHBoxLayout(this);
    HLayout->addWidget(listWidget);
    HLayout->addWidget(scrollArea);

    connect(listWidget,&QListWidget::itemClicked,this,&Widget::on_itemClicked);

  connect(scrollArea->verticalScrollBar(),&QScrollBar::valueChanged,this,&Widget::on_valueChanged);

}

Widget::~Widget()
{

    delete ui;
}

void Widget::on_itemClicked(QListWidgetItem *item)
{
    signFlag=true;
    QString itemtext=item->text();
    QPoint widgetPos;
    int sz=strList.size();
    for(int i=0;i<sz;i++)
    {
        if(itemtext==strList[i])
        {
            widgetPos=widges[i]->pos();
        }
    }
    scrollArea->verticalScrollBar()->setValue(widgetPos.y());
}

void Widget::on_valueChanged(int value)
{
    if(!signFlag)
    {
        int itemSz=widges.size();
        for(int i=0;i<itemSz;i++)
        {
            if(!widges[i]->visibleRegion().isEmpty())
            {
                listWidget->item(i)->setSelected(true);
                return ;
            }
            else
            {
                listWidget->item(i)->setSelected(false);
            }

        }
    }
    signFlag=false;
}

