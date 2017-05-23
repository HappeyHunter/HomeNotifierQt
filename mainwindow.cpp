#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QMutex>
#include <QDesktopWidget>

QMutex notificationLock;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    timer(this),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Make it borderless and move it to the top left/origin
    setWindowFlags(Qt::FramelessWindowHint);

    // Position it
    moveToTopLeft();

    setCentralWidget(&notificationArea);

    connect(&timer, SIGNAL(timeout()), this, SLOT(playTopNotification()));
    timer.start(30000); //time specified in ms

    visibilityCheck();

    connect(&notificationManager, SIGNAL(newNotification(NotificationEntity*)), this, SLOT(addNotification(NotificationEntity*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Moves the notification are to the top left corner of the primary screen
void MainWindow::moveToTopLeft()
{
    QDesktopWidget* desktop = QApplication::desktop();

    QWidget* primaryScreen = desktop->screen(desktop->primaryScreen());

    move(primaryScreen->pos());
}

// Adds a notification object to show
void MainWindow::addNotification(NotificationEntity* newNotification)
{
    notificationLock.lock();

    connect(newNotification, SIGNAL(acknowledged(NotificationEntity*)), this, SLOT(deleteNotification(NotificationEntity*)));

    notificationEntities.append(newNotification);

    notificationArea.addWidget(notificationEntities.last());

    playNewNotification(newNotification->getNotification());

    visibilityCheck();

    notificationLock.unlock();
}

// Delete a notification (and send an acknowledgement (WIP))
void MainWindow::deleteNotification(NotificationEntity* notification) {
    // Acknowlege it first
    // this is not done yet

    notificationLock.lock();
    // Remove from the layout
    notificationArea.removeWidget(notification);

    // Delete the actual object
    int index = notificationEntities.indexOf(notification);
    delete notificationEntities.at(index);
    notificationEntities.remove(index);

    // Check if I need to still be visible
    visibilityCheck();

    notificationLock.unlock();
}

// Check if there is a notification to be shown
// Make the window visible if there is, otherwise make it invisible
void MainWindow::visibilityCheck() {
    if(isVisible() && notificationEntities.length() == 0) {
        setVisible(false);
    } else if(!isVisible() && notificationEntities.length() > 0) {
        setVisible(true);
    }
}

// Repeat the sound for the top notification
void MainWindow::playTopNotification() {
    notificationLock.lock();

    if(notificationEntities.size() > 0) {
        soundManager.playSound(notificationEntities.first()->getNotification());
    }

    notificationLock.unlock();
}

//Play the sound file associated with the new notification
void MainWindow::playNewNotification(QString message) {
    timer.start();
    soundManager.playSound(message);
}
