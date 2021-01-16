#ifndef STDINREADER_H
#define STDINREADER_H

#include <QThread>


class StdinReader : public QThread
{
	Q_OBJECT
public:
	StdinReader(const char *p_encoding, QObject *p_parent = nullptr);
	void run() override;
signals:
	void stdinReceived(const QString &line);
private:
	const char *_encoding;
};

#endif // STDINREADER_H
