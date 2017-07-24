#ifndef NOTIFICATIONAREA_H
#define NOTIFICATIONAREA_H

#include <QWidget>

namespace Ui {
class NotificationArea;
}

class NotificationArea : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationArea(QWidget *parent = 0);
    ~NotificationArea();
    void addWidget(QWidget *item);
    void removeWidget(QWidget *item);

private:
    Ui::NotificationArea *ui;
};

#endif // NOTIFICATIONAREA_H
