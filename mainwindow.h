#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "notificationentity.h"
#include "notificationarea.h"
#include "notificationmanager.h"
#include "soundmanager.h"

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
    void visibilityCheck();
    void playNewNotification(QString message);

private:
    QTimer timer;
    Ui::MainWindow *ui;
    NotificationArea notificationArea;
    QVector<NotificationEntity*> notificationEntities;
    NotificationManager notificationManager;
    SoundManager soundManager;

public slots:
    void addNotification(NotificationEntity* newNotification);
    void deleteNotification(NotificationEntity* notification);
    void playTopNotification();
};

#endif // MAINWINDOW_H
