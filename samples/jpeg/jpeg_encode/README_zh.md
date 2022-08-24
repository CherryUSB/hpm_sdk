# JPEG_ENCODE编码
## 概述
***
**jpeg_encode**编码示例工程展示了如何将摄像头采集的RGB565数据通过libjpeg_turbo库或硬件JPEG模块，转换为JPG数据并保存在存储介质中。
- 通过**摄像头**获取RGB565数据，通过代码库将RGB565数据转换为YUV图像数据，并压缩成JPG图像文件，并将JPG图片存储于**USB**或**SD卡**内。

## 硬件设置
***
- **USB盘**连接到开发板``USB0``，或**SD内存卡**插入到开发板``sd card``
- **CAM摄像头**连接到开发板``CAM``

## 工程配置
***
- 文件[CMakeLists.txt](./CmakeLists.txt)中配置``set(CONFIG_SDFATFS_MODE 1)``，则默认将JPG图片存储在**SD卡**内；配置
``set(CONFIG_TINYUSBHOST_MODE 1)``，则默认将JPG图片存储在**USB**内

## 存储图片大小
***
- 本例程中存储的图片格式为JPG，分辨率大小为800*480
- 如果支持更高分辨率的编码，可采用支持高分辨率的摄像头作为RGB数据源，通过编码功能存储JPG文件

## 运行现象
***
- SD卡方式：
当工程正确运行后，摄像头捕获的图片，存储在SD卡中，命名为Camera.jpg，而串口终端会输出如下信息：
```
> storage picture data by SD card
> File Name: Camera.jpg
> Libjpeg-turbo encode completed
```

- USB方式：
当工程正确运行后，摄像头捕获的图片，存储在USB中，命名为Camera.jpg，而串口终端会输出如下信息：
```
> storage picture data by tinyusb mode
> File Name: Camera.jpg
> Libjpeg-turbo encode completed
```

