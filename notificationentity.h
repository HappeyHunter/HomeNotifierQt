#ifndef NOTIFICATIONENTITY_H
#define NOTIFICATIONENTITY_H

#include <QWidget>
#include <QGraphicsOpacityEffect>

namespace Ui {
class NotificationEntity;
}

class NotificationEntity : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationEntity(QWidget *parent, const QString& notification, const QString& description, int id);
    ~NotificationEntity();
    int getID();
    QString getNotification();

private slots:
    void on_closeButton_released();
    void hideThisWidget();

signals:
    void acknowledged(NotificationEntity* notification);

private:
    void fadeAway();

private:
    Ui::NotificationEntity *ui;
    QGraphicsOpacityEffect *graphicsEffect;
    int id;
    QString notificationMessage;

};

#endif // NOTIFICATIONENTITY_H
