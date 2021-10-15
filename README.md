# somethingreallyshitty
用C++实现上位机接受下位机发送的数据，并plot

严格按照步骤来做。

1.单片机烧录的程序以115200波特率中断发送0-255的ASCII码。将单片机与电脑用RS232接口相连。

2.电脑端：1）编译两个.cpp文件
         2）运行comRecieve.exe，创建file.txt
         3）运行forPlot.exe。
