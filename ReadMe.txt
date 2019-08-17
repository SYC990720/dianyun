主要参考来自：https://download.csdn.net/download/lcy9819/7696131

此项目实现的功能：读取点云文件（.txt文件格式，文件中只包含所有点的坐标数据），并绘制三维点云图形

此项目运行环境：win10+vs2017+MFC+OpenGL
运行前需要下载MFC框架相关组件以及OpenGL环境配置
MFC框架下OpenGL的环境配置教程：https://blog.csdn.net/zhouhangjay/article/details/7678855

此项目主要文件结构为：资源文件、主框架运行文件以及其他一些MFC自带的文件。
以下介绍各个文件的用途：

CPointCloud.dsp
    此文件包含项目级别的信息和

用于构建单个项目或子项目。其他用户可以共享

项目（.dsp）文件，但应在本地导出生成文件。

CPointCloud.h
    这是应用程序的主头文件，包括其他

项目特定的标题（包括resource.h）并声明

CCpointCloudApp应用程序类。

CPointCloud.cpp
    这是包含应用程序的主应用程序源文件

类ccpointcloudapp。

CPointCloud.rc
    这是所有Microsoft Windows资源的列表，

程序使用。它包括存储的图标、位图和光标

在res子 目录中。此文件可以在Microsoft中直接编辑

Visual C++。

CPointCloud.clw
    此文件包含类向导用于编辑现有文件的信息

类或添加新类。Classwizard还使用此文件存储

创建和编辑消息映射和对话框数据所需的信息

映射并创建原型成员函数。

res\CPointCloud.ico
    这是一个图标文件，用作应用程序的图标。这个

图标包含在主资源文件cpointcloud.rc中。

res\CPointCloud.rc2
    此文件包含Microsoft未编辑的资源

Visual C++。放置了所有不可被资源编辑器编辑的资源。



/////////////////////////////////////////////////////////////////////////////

对于主框架窗口:

MainFrm.h, MainFrm.cpp
    这些文件包含框架类cmainframe，它是从

cframewnd和控制所有SDI帧功能。

res\Toolbar.bmp
    此位图文件用于为工具栏创建平铺图像。

初始工具栏和状态栏构建在CMainFrame中。

类。使用资源编辑器编辑此工具栏位图，以及

更新cpointcloud.rc中的idr_Mainframe工具栏数组以添加

工具栏按钮
/////////////////////////////////////////////////////////////////////////////

应用程序向导创建一个文档类型和一个视图:

CPointCloudDoc.h, CPointCloudDoc.cpp - the document
    这些文件包含CCpointCloudDoc类。这些文件实现了点云文件保存和加载

（通过ccpointclouddoc:：serialize）。

CPointCloudView.h, CPointCloudView.cpp - the view of the document
   这些文件包含CCpointCloudView类。

CCpointCloudView对象用于查看CCpointCloudDoc对象。这些文件用于实现点云的绘制以及摄像头类的操作实现（包括平移、缩放等）。



/////////////////////////////////////////////////////////////////////////////
其他标准文件:

StdAfx.h, StdAfx.cpp
    这些文件用于生成预编译头（PCH）文件

名为cpointcloud.pch和名为stdafx.obj的预编译类型文件。

Resource.h
    这是标准头文件，它定义了新的资源ID。

微软Visual C++读取并更新此文件。

/////////////////////////////////////////////////////////////////////////////
其他事项:

Appwizard使用“todo：”来指示源代码的某些部分

应该添加到或自定义。





如果应用程序在共享DLL中使用MFC，并且应用程序

在操作系统当前语言之外的其他语言中，

将需要复制相应的本地化资源mfc42xx.dll

从微软Visual C++CD-ROM到系统或Stase32目录，

并将其重命名为mfcloc.dll。“XXX”代表语言缩写。

例如，mfc42deu.dll包含翻译为德语的资源。）如果

不要这样做，应用程序的某些UI元素将保留在

操作系统的语言。

/////////////////////////////////////////////////////////////////////////////
