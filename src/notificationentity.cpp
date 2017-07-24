#include "notificationentity.h"
#include "ui_notificationentity.h"

#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTime>

NotificationEntity::NotificationEntity(QWidget *parent, const QString& notification, const QString& description, int id) :
    QWidget(parent),
    ui(new Ui::NotificationEntity),
    id(id),
    notificationMessage(notification.simplified())
{
    ui->setupUi(this);
    ui->MainNotification->setText(notification);
    ui->Description->setText(description);
    ui->timeLabel->setText(QTime::currentTime().toString());
}

NotificationEntity::~NotificationEntity()
{
    delete graphicsEffect;
    delete ui;
}

// Hides the notification fully and emits the acknowledged signal so the listeners do stuff
void NotificationEntity::hideThisWidget() {
    setHidden(true);
    emit acknowledged(this);
}

// Slowly fade out the notification because it looks fancy
void NotificationEntity::fadeAway() {
    // w is your widget
    graphicsEffect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(graphicsEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(graphicsEffect,"opacity");
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::OutBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    connect(animation,SIGNAL(finished()),this,SLOT(hideThisWidget()));
}

// Acknowledge was pressed so fade out and delete
void NotificationEntity::on_closeButton_released()
{
    fadeAway();
}

// Gets the id of this notification
int NotificationEntity::getID() {
    return id;
}

// Gets the message for this notification
QString NotificationEntity::getNotification() {
    return notificationMessage;
}
