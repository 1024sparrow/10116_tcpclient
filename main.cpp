#include <QCoreApplication>
#include <QString>

#include "gameplay.h"

#include <iostream>
#include <string.h>

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);

	QString targetIp;
	int targetPort = -1;
	const char *targetEncoding = "cp1251";
	enum
	{
		Initial,
		TargetIp,
		TargetPort,
		Encoding
	} state {Initial};
	for (int i = 1 ; i < argc ; ++i)
	{
		if (!strcmp(argv[i], "--help"))
		{
			std::cout << R"(TCP-клиент.
Использование:
	./XXX --ip 1.2.3.4 --port 1234 [--encoding "some encoding"] [--help]
Ключи:
	--ip <IP> - указание, к какому IP коннектиться
	--port <port> - указание, по какому порту коннектиться
	--encoding <encoding> - указание кодировки (например, "utf8"). По умолчанию, "cp1251".
	--help - показать справку по использованию (и тут же выйти)
)" << std::endl;
			return 0;
		}
		else if (!strcmp(argv[i], "--ip"))
		{
			state = TargetIp;
		}
		else if (!strcmp(argv[i], "--port"))
		{
			state = TargetPort;
		}
		else if (!strcmp(argv[i], "--encoding"))
		{
			state = Encoding;
		}
		else if (*argv[i] == '-')
		{
			std::cerr << "неподдерживаемый ключ: " << argv[i] << std::endl;
			return 1;
		}
		else
		{
			if (state == Initial)
			{
				std::cerr << "неправильные параметры. См. справку." << std::endl;
				return 1;
			}
			else
			{
				if (state == TargetIp)
				{
					targetIp = argv[i];
				}
				else if (state == TargetPort)
				{
					targetPort = QString(argv[i]).toInt();
				}
				else if (state == Encoding)
				{
					targetEncoding = argv[i];
				}
				else
				{
					std::cerr << "epic fail" << std::endl;
					return 1;
				}
				state = Initial;
			}
		}
	}
	if (state != Initial)
	{
		std::cerr << "указанный ключ требует указания значения. См. справку." << std::endl;
		return 1;
	}
	if (targetIp.isEmpty())
	{
		std::cerr << "Не указан IP. См. справку." << std::endl;
		return 1;
	}
	if (targetPort == -1)
	{
		std::cerr << "Не указан порт. См. справку." << std::endl;
		return 1;
	}
	if (targetPort == 0)
	{
		std::cerr << "Порт должен быть представлен числом! См. справку." << std::endl;
		return 1;
	}

	Gameplay gp;
	if (!gp.start(targetIp, targetPort, targetEncoding))
	{
		std::cerr << "Не удалось запустить" << std::endl;
		return 1;
	}

	return app.exec();
}
