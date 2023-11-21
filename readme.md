基于 Qt 6.6.0(Community) + MinGW + CMake + Visual Studio Code

使用纯代码构建界面，主要实现一个基础的主界面窗口

已封装成一个动态库文件供主程序调用

已实现
1、生成一个800*600 MainWindow
2、自定义的圆角边框及配色，自带实现缩放、窗口移动等
3、自定义的最小化、关闭按钮
4、生成一个关联大小的Widget用于承载各类工具

窗口相关工具类请承载在 QWidget *m_Main 中
这是一个圆角的QWidget对象，父类为MainWindow对象