# MFC-Draw-Line
MFC-Draw-Line
如果想在窗口上绘制直线的话，我们需要捕捉两个点<br>
线段的起点和终点二者可以分别通过WM_LBUTTONDOWN和WM_LBUTTONUP来实现。<br>
类似于上节课讲述的添加消息函数的方法，在类视图的CDrawView右键属性<br>
选择“消息”菜单，找到对应的消息即可,进入二者的消息函数的实现之前，需要定义一个变量表示线段的起点CPoint m_ptOrigin同样是右键View类添加变量即可
