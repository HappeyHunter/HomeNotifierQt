#include "notificationarea.h"
#include "ui_notificationarea.h"

NotificationArea::NotificationArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationArea)
{
    ui->setupUi(this);
    ui->notificationLayout->setAlignment(ui->notificationLayout, Qt::AlignTop);
}

NotificationArea::~NotificationArea()
{
    delete ui;
}

void NotificationArea::addWidget(QWidget *item) {
    ui->notificationLayout->addWidget(item);
    ui->notificationLayout->setAlignment(item, Qt::AlignTop);
}

void NotificationArea::removeWidget(QWidget *item) {
    ui->notificationLayout->removeWidget(item);
}
