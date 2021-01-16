# 10116_tcpclient
> Tcp-клиент
## Сборка
qmake && make

Qt версии 5.

## Использование

TCP-клиент.
Использование:
	./10116_tcpclient --ip 1.2.3.4 --port 1234 [--encoding "some encoding"] [--help]
Ключи:
	--ip <IP> - указание, к какому IP коннектиться
	--port <port> - указание, по какому порту коннектиться
	--encoding <encoding> - указание кодировки (например, "utf8"). По умолчанию, "cp1251".
	--help - показать справку по использованию (и тут же выйти)

