#include "gameplay.h"
#include "stdinreader.h"

#include <QTextStream>
#include <QCoreApplication>

#include <iostream>

Gameplay::Gameplay()
	: QObject(nullptr)
{
}

bool Gameplay::start(const QString &p_ip, int p_port, const char *p_encoding)
{
	_socket = new QTcpSocket(this);
	_encoding = p_encoding;
	_stdinreader = new StdinReader(p_encoding, this);
	connect(_stdinreader, SIGNAL(stdinReceived(QString)), SLOT(onStdinReceived(QString)));

	connect(_socket, SIGNAL(connected()), SLOT(onConnected()));
	connect(_socket, SIGNAL(readyRead()), SLOT(onReadyRead()));
	connect(_socket, SIGNAL(disconnected()), SLOT(onDisconnected()));

	_socket->connectToHost(p_ip, p_port);
	_stdinreader->start();

	return true;
}

void Gameplay::onConnected()
{
	std::cout << std::endl << "<connected>" << std::endl;
}

void Gameplay::onReadyRead()
{
	QTextStream ts(_socket);
	ts.setCodec(_encoding);
	std::cout << ts.readAll().toStdString();
}

void Gameplay::onDisconnected()
{
	std::cout << std::endl << "<disconnected>" << std::endl;
	qApp->exit(0);
}

void Gameplay::onStdinReceived(const QString &line)
{
	//std::cout << line.toStdString();
	QTextStream ts(_socket);
	ts.setCodec(_encoding);
	ts << line;
}
