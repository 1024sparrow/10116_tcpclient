#include "stdinreader.h"

#include <QTextStream>

StdinReader::StdinReader(const char *p_encoding, QObject *p_parent)
	: QThread(p_parent)
	, _encoding(p_encoding)
{

}

void StdinReader::run()
{
	QTextStream ts(stdin);
	ts.setCodec(_encoding);
	while (true)
	{
		QString line = ts.readLine();
		emit stdinReceived(line);
	}
}
