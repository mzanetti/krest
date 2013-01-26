#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QSettings>
#include <QModelIndex>

class RequestItemModel;
class BookmarkModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void networkReplyFinished(QNetworkReply *reply);

    void bookmarkClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_tvBookmarks_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *m_nam;

    QStringList m_dataHistory;
    QStringList m_urlHistory;

    QSettings *m_settings;

    BookmarkModel *m_bookmarkModel;
};

#endif // MAINWINDOW_H
