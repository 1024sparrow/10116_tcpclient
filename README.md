# 10116_tcpclient
> Tcp-клиент. Тот же telnet, только корректно работающий с нелатинскими символами в явно указываемой при запуске кодировке.
## Сборка
qmake && make

Qt версии 5.

## Использование
```
TCP-клиент.
Использование:
	./10116_tcpclient --ip 1.2.3.4 --port 1234 [--encoding "some encoding"] [--help]
Ключи:
	--ip <IP> - указание, к какому IP коннектиться
	--port <port> - указание, по какому порту коннектиться
	--encoding <encoding> - указание кодировки (например, "utf8"). По умолчанию, "cp1251".
	--help - показать справку по использованию (и тут же выйти)
```

Например,
```
$ ./10116_tcpclient --ip example.com --port 80 --encoding utf-8

<connected>
GET / HTTP/1.1      <-- это мы руками вводим (и ENTER наживаем)
Host: example.com   <-- это мы руками вводим (и ENTER наживаем)
HTTP/1.1 400 Bad Request
Server: nginx/1.14.1
Date: Sat, 16 Jan 2021 22:01:07 GMT
Content-Type: text/html
Content-Length: 173
Connection: close

<html>
<head><title>400 Bad Request</title></head>
<body bgcolor="white">
<center><h1>400 Bad Request</h1></center>
<hr><center>nginx/1.14.1</center>
</body>
</html>

<disconnected>

```
