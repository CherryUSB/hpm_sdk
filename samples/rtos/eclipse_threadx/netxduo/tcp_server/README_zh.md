# Netx Duo Tcp服务端

## 概述

这个例程演示了netx的tcp服务端功能。

## 硬件设置

用网线连接开发板和电脑/路由器/交换机

## 工程配置
- 以太网端口配置：参考 [以太网通用工程设置](../../../../lwip/doc/Ethernet_Common_Project_Settings_zh.md)
- 可以通过将`CONFIG_NETX_ENABLE_DHCP`设置为0或者注释掉定义`CONFIG_NETX_ENABLE_DHCP`宏的语句来禁止DHCP功能。
- 禁用DHCP时，可以注释掉`set(CONFIG_ECLIPSE_THREADX_NETXDUO_ADDONS_DHCP 1)`语句，从而减少工程的源文件数量

## 运行现象

当工程正确运行后,程序会监听端口**ECHO_SERVER_PORT**(7777)。一旦有一个客户端连接到了服务端，程序会等待客户端发送数据直到收到数据、10秒没收到数据或者客户端关闭了链接。如果收到了客户端的数据，程序会将同样的数据返回给客户端，随后关闭链接。物理链接状态会被周期性的打印到终端上,直到链接状态为 **Up**。以下消息会被打印到终端上:
```console
Reference Clock: Internal Clock
Enet phy init passed !
Link Status: Down
NetXDuo is running

IP address: 192.168.1.223

Mask: 255.255.255.0

Link Status: Up
Link Speed:  100Mbps
Link Duplex: Full duplex
A client is connected to the server.
Receive data from client.
Send data back to client success.
Close the connection
A client is connected to the server.
Receive data from client.
Send data back to client success.
Close the connection
A client is connected to the server.
Failed to receive from the socket, reason 1.
Close the connection
```
