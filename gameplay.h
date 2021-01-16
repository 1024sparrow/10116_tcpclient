#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QObject>
#include <QTcpSocket>
#include <QString>


class StdinReader;
class Gameplay : public QObject
{
	Q_OBJECT
public:
	Gameplay();
	bool start(const QString &p_ip, int p_port, const char *p_encoding);
private slots:
	void onConnected();
	void onReadyRead();
	void onDisconnected();
	void onStdinReceived(const QString &line);
private:
	QTcpSocket *_socket {nullptr};
	const char *_encoding {nullptr};
	StdinReader *_stdinreader {nullptr};
};

#endif // GAMEPLAY_H
