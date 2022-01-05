#include<graphics.h>
#include<time.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")//预处理指令告诉编译器要导入winmm库以便加载声音
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")//预处理指令关闭DOS窗口
#define PI 3.14159265354

void main()
{
	char cmd[20] = "shutdown -s -t ";
	int back1;
	char levestr[5] = "0";
	int levetime = 0;
	int back2;
	int showhour = 0;//定义初始小时
	int showmin = 0;//定义初始分钟
	int levemin = 0;
	int leveour = 0;
	int hourcount = 0;//定义小时增量
	int mincount = 0;//定义分钟增量
	int lastingtime = 0;//定义持续的时间
	int lastinghour = 0;
	int lastingminute = 0;
	int lastingsecond = 0;
	char hour[][24] = {"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23"};//将要输出的小时存入二维数组
	char minute[][12] = {"00", "05","10","15","20","25","30","35","40","45","50","55"};//将要输出的分钟存入二维数组
	char str3[2];//定义存放输出小时的字符串
	char str4[2];//定义存放输出分钟的字符串
	char str5[2];//定义存放电脑运行小时
	char str6[2];//定义存放电脑运行分钟
//	char str7[2];//定义存放电脑运行秒
	char s[] = "你要几点几分关机？";//设置要输出的提示
	char s1[] = "距离关机：";//设置提示文字
	char s2[] = "开始";//设置要输出的提示
	char s3[] = "取消";//设置要输出的提示
	char s4[] = "小时";//将要输出的提示装入字符串
	char s5[] = "分钟";//将要输出的提示装入字符串
	char s6[] = "电脑已运行：";//设置提示文字
	char s7[] = "关屏";
	char closeLCDatten[] = "电脑屏幕将在30秒后关闭！请不要关闭该应用，否则将导致关屏不成功！";
	//char s7[] = "秒";//将要输出的提示装入字符串
	int sysour;//定义系统小时
	int sysmin;//定义系统分钟
	LOGFONT f;//定义字体样式的一个结构体f
	
	//绘图窗口
	initgraph(360, 254);//初始化绘图窗口

	BeginBatchDraw();// 开启批量绘图模式
	mciSendString(_T("play open.wav from 0"), NULL, 0, NULL);//载入提示音
	setbkcolor(RGB(254, 254, 254));//设置背景颜色
	cleardevice();//清除屏幕内容
	//绘制小时的显示框
	setcolor(RGB(56,189,25));//设置线条颜色
	setfillcolor(RGB(56,188,25));//设置填充颜色
	rectangle(63, 69, 164, 128);//绘制外部矩形
	line(142, 69, 142, 128);//绘制内部线条
	line(142, 98, 164, 98);//绘制内部线条
	POINT pts1[] = { {153, 79}, {148, 84}, {158, 84} };//设置三角形三顶点
	polygon(pts1, 3);//绘制三角形
	floodfill(153, 82, RGB(56,189,25));//填充三角形
	POINT pts2[] = { {153, 117}, {148, 112}, {158, 112} };//设置三角形三顶点
	polygon(pts2, 3);//绘制三角形
	floodfill(153, 115, RGB(56,189,25));//填充三角形
	//绘制分钟显示框
	rectangle(196, 69, 297, 128);//绘制外部矩形
	line(275, 69, 275, 128);//绘制内部线条
	line(275, 98, 297, 98);//绘制内部线条
	POINT pts3[] = { {286, 79}, {281, 84}, {291, 84} };//设置三角形三顶点
	polygon(pts3, 3);//绘制三角形
	floodfill(286, 82, RGB(56,189,25));//填充三角形
	POINT pts4[] = { {286, 117}, {281, 112}, {291, 112} };//设置三角形三顶点
	polygon(pts4, 3);//绘制三角形
	floodfill(286, 115, RGB(56,189,25));//填充三角形
	//绘制开始和关闭按钮
	//开始
	setfillcolor(RGB(56,188,25));//设置填充颜色
	line(81,195,148,195);//绘制开始按钮
	line(81,223,148,223);//绘制开始按钮
	arc(71,195,91,223,PI/2,PI*3/2);//绘制开始按钮
	arc(138,195,158,223,-PI/2,PI/2);//绘制开始按钮
	floodfill(100, 200, RGB(56,189,25));//填充开始按钮
	//关闭
	line(210,195,277,195);//绘制关闭按钮
	line(210,223, 277,223);//绘制关闭按钮
	arc(200, 195, 220, 223, PI/2,PI*3/2);//绘制关闭按钮
	arc(267, 195,287,223, -PI/2, PI/2);//绘制关闭按钮
	floodfill(250, 200, RGB(56,189,25));//填充关闭按钮
	//绘制中间两点
	//上点
	setcolor(RGB(255, 161, 64));//设置当前绘图前景色
	circle(180, 91, 2);//上面的圆
	circle(180, 105, 2);//下面的圆
	//下点
	setfillcolor(RGB(255, 161, 64));//设置填充颜色
	floodfill(180,91,RGB(255, 161, 64));//填充上面的圆
	floodfill(180,105,RGB(255, 161, 64));//填充下面的圆
	//输出提示文字
	settextstyle(16, 0, _T("宋体"));//设置字体样式
	settextcolor(BLACK);//设置文字颜色
	outtextxy(111, 25, s);//输出提示
	settextstyle(12, 0, _T("宋体"));//设置字体样式
	outtextxy(105, 156, s1);//输出提示
	//启动按钮提示
	setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
	gettextstyle(&f);  //获取当前字体样式                   
	f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
	f.lfHeight = 13;//设置字高为13
	f.lfWidth = 0;
	settextstyle(&f);//设置字体样式为f
	settextcolor(WHITE);//设置文字颜色
	outtextxy(101, 202, s2);//输出提示
	outtextxy(228, 202, s3);//输出提示
	//输出倒计时单位
	settextcolor(RGB(255, 160, 64));//设置当前字体颜色
	f.lfWeight = 0;//令笔画粗细等于0 默认粗细（0 ~ 1000）
	settextstyle(&f);//设置字体样式为f
	outtextxy(184, 156, s4);//输出提示
	outtextxy(230, 156, s5);//输出提示

	//输出系统运行时间提示

	settextcolor(BLACK);//设置文字颜色
	settextstyle(12, 0, _T("宋体"));//设置字体样式
	outtextxy(85, 240, s6);//输出提示
	settextcolor(RGB(255, 160, 64));//设置当前字体颜色
	f.lfWeight = 0;//令笔画粗细等于0 默认粗细（0 ~ 1000）
	settextstyle(&f);//设置字体样式为f
	outtextxy(174, 240, s4);//输出提示
	outtextxy(220, 240, s5);//输出提示
	//outtextxy(266, 240, s7);//输出秒


	//绘制箭头体现变化and检测鼠标动作
	MOUSEMSG m;	//定义鼠标动作结构体
	time_t rawtime;//定义一个时间内型
	tm * t;//定义一个结构体指针
	//获取系统小时和分钟
	time(&rawtime);//获取时间
	t = localtime(&rawtime);//转化为本地时间
	sysour = t->tm_hour;//系统小时
	sysmin = t->tm_min;//系统分钟
	//输出初始时间
	settextcolor(RGB(255, 160, 64));//设置文字颜色
	settextstyle(50, 0, _T("宋体"));//设置文字样式
	gettextstyle(&f);  //获取当前字体样式   
	f.lfWeight = 1;//设置笔画粗细
	f.lfWidth = 30;//设置字宽
	f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
	settextstyle(&f);//用f的结构体设置字体样式
	hourcount = sysour + 2;//设置默认倒计时
	showhour = sysour + 2;//设置初始小时
	if (hourcount >= 24)
	{
		hourcount -= 24;
	}
	//输出初始小时
	outtextxy(73, 73, hour[hourcount]);
	//输出初始分钟
	outtextxy(207, 73, minute[mincount]);

	//绘制关闭屏幕按钮
	setcolor(RGB(56,189,25));//设置线条颜色
	setfillcolor(RGB(0, 100, 0));
	rectangle(7, 3, 40, 21);//绘制矩形框
	floodfill(20, 20, RGB(56,189,25));
	setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
	gettextstyle(&f);  //获取当前字体样式                   
	f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
	f.lfHeight = 12;//设置字高为12
	f.lfWidth = 0;
	settextstyle(&f);//设置字体样式为f
	settextcolor(WHITE);//设置文字颜色
	outtextxy(11, 6, s7);//输出提示


	EndBatchDraw();// 关闭批量绘图模式
	while (true)
	{
		BeginBatchDraw();// 开启批量绘图模式
		//获取系统小时和分钟
		time(&rawtime);//获取时间
		t = localtime(&rawtime);//转化为本地时间
		sysour = t->tm_hour;//系统小时
		sysmin = t->tm_min;//系统分钟
		//输出剩余时间
		setcolor(RGB(254,255,255));//设置当前绘图前景色
		rectangle(164,155,184,168);//绘制小矩形
		rectangle(211, 154, 228, 168);//绘制小矩形
		setfillcolor(WHITE);//设置填充颜色
		settextcolor(RGB(255, 160, 64));//设置当前字体颜色
		settextstyle(14, 0, _T("宋体"));//设置文字样式
		gettextstyle(&f);//获取当前字体样式 
		f.lfWeight = 700;//设置笔画粗细
		f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
		settextstyle(&f);//用f的结构体设置字体样式	
		floodfill(170, 160, RGB(254,255,255));//填充小矩形
		floodfill(215,160,RGB(254,255,255));//填充小矩形
		if (showmin < 0)
		{
			showmin += 60;
		}
		else if (showmin >= 60)
		{
			showmin -= 60;
		}
		if (showhour > 23)
		{
			showhour -= 24;
		}
		else if (showhour < 0)
		{
			showhour += 24;
		}
		leveour = showhour - sysour - 1;
		levemin = 60-sysmin+showmin;
		if (levemin >= 60)
		{
			leveour++;
			levemin -= 60;
		}
		if (leveour < 0)
		{
			leveour += 24;
		}
		else if (leveour == 0 && levemin == 0)
		{
			leveour = 24;
		}
		_itoa(leveour, str3, 10);//将剩余小时数转换为字符串
		_itoa(levemin, str4, 10);//将剩余分钟数转换为字符串
		outtextxy(167,155,str3);//输出剩余小时
		outtextxy(212,155,str4);//输出剩余分钟

		//输出电脑运行时间
		lastingtime=GetTickCount();
    	lastinghour=(lastingtime/1000)/3600;
	    lastingminute=(lastingtime/1000)/60-lastinghour*60;
		//lastingsecond=(lastingtime/1000)-lastinghour*3600-lastingminute*60;

		setcolor(RGB(254,255,255));//设置当前绘图前景色
		rectangle(154,239,174,252);//绘制小矩形
		rectangle(201, 238, 218, 252);//绘制小矩形
		//rectangle(247,238,264,252);
		setfillcolor(WHITE);//设置填充颜色
		settextcolor(RGB(255, 160, 64));//设置当前字体颜色
		settextstyle(14, 0, _T("宋体"));//设置文字样式
		gettextstyle(&f);//获取当前字体样式 
		f.lfWeight = 700;//设置笔画粗细
		f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
		settextstyle(&f);//用f的结构体设置字体样式	
		floodfill(160, 245, RGB(254,255,255));//填充小矩形
		floodfill(210,245,RGB(254,255,255));//填充小矩形
		//floodfill(255,245,RGB(254,255,255));
		_itoa(lastinghour, str5, 10);//将运行小时数转换为字符串
		_itoa(lastingminute, str6, 10);//将运行分钟数转换为字符串
		//_itoa(lastingsecond, str7, 10);
		outtextxy(157,239,str5);//输出运行小时
		outtextxy(202,239,str6);//输出运行分钟
		//outtextxy(248,239,str7);//输出剩余分钟
		EndBatchDraw();// 关闭批量绘图模式

		BeginBatchDraw();// 开启批量绘图模式

		m = GetMouseMsg();//获取鼠标信息
		setcolor(RGB(56,189,25));//设置绘图颜色
		polygon(pts1, 3);//绘制三角形
		polygon(pts2, 3);//绘制三角形
		polygon(pts3, 3);//绘制三角形
		polygon(pts4, 3);//绘制三角形
		HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("stand.cur"), IMAGE_CURSOR, 33, 32, LR_LOADFROMFILE);
		HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
		SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式


		//关闭屏幕
		if (m.x >7 && m.x<40 && m.y >3 && m.y<21)//关闭屏幕框
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式
		}
		if (m.x >7 && m.x<40 && m.y >3 && m.y<21 && m.uMsg == WM_LBUTTONUP)
		{
			HWND wnd = GetHWnd();
			MessageBox(wnd, closeLCDatten , "提示", MB_OK | MB_ICONINFORMATION);
			Sleep(30000);//延时ms
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); //关闭显示器
		}

		if (m.x < 164 && m.x > 142 && m.y > 69 && m.y < 98)//左上框
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式
			setfillcolor(RGB(105,212,80));//设置填充颜色
			floodfill(153, 70, RGB(56,189,25));//填充矩形
			setfillcolor(WHITE);//设置填充颜色
			floodfill(153, 82, RGB(56,189,25));//填充三角形
			setcolor(WHITE);//设置绘图颜色
			polygon(pts1, 3);//绘制三角形
			settextcolor(RGB(255, 160, 64));
			if (m.uMsg == WM_LBUTTONDOWN)         
			{
				setcolor(RGB(56,189,25));
				polygon(pts1, 3);
				setfillcolor(RGB(56, 188, 25));//设置填充颜色
				floodfill(153, 70, RGB(56,189,25));//填充矩形
				setfillcolor(WHITE);//设置填充颜色
				floodfill(153, 82, RGB(56,189,25));//填充三角形
				setcolor(WHITE);//设置绘图颜色
				polygon(pts1, 3);//绘制三角形
			}
			if (m.uMsg == WM_LBUTTONUP)//判断左键是否弹起
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//载入提示音
				showhour++;
				settextcolor(RGB(255, 160, 64));//设置文字颜色
				settextstyle(50, 0, _T("宋体"));//设置文字样式
				gettextstyle(&f);  //获取当前字体样式   
				f.lfWeight = 1;//设置笔画粗细
				f.lfWidth = 30;//设置字宽
				f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
				settextstyle(&f);//用f的结构体设置字体样式
				setfillcolor(WHITE);
				floodfill(100,100,RGB(56,189,25));
				hourcount++;
				if (hourcount > 23)
				{
					hourcount -= 24;
				}
				outtextxy(73, 73, hour[hourcount]);
			}
		}
		else
		{
			setfillcolor(RGB(56,188,25));
			floodfill(153, 82, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(153, 70, RGB(56,189,25));	
		}
		if (m.x < 164 && m.x > 142 && m.y > 98 && m.y < 128)//左下框
		{
			
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式
			setfillcolor(RGB(105, 212, 80));
			floodfill(153, 120, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(153, 115, RGB(56,189,25));
			setcolor(WHITE);
			polygon(pts2, 3);//绘制三角形	
			if (m.uMsg == WM_LBUTTONDOWN)             
			{
				setcolor(RGB(56,189,25));
				polygon(pts2, 3);
				setfillcolor(RGB(56, 188, 25));
				floodfill(153, 120, RGB(56,189,25));
				setfillcolor(WHITE);
				floodfill(153, 115, RGB(56,189,25));
				setcolor(WHITE);
				polygon(pts2, 3);//绘制三角形
			}
			if (m.uMsg == WM_LBUTTONUP)//判断左键是否弹起
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//载入提示音
				showhour--;
				settextcolor(RGB(255, 160, 64));//设置文字颜色
				settextstyle(50, 0, _T("宋体"));//设置文字样式
				gettextstyle(&f);  //获取当前字体样式   
				f.lfWeight = 1;//设置笔画粗细
				f.lfWidth = 30;//设置字宽
				f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
				settextstyle(&f);//用f的结构体设置字体样式
				setfillcolor(WHITE);
				floodfill(100,100,RGB(56,189,25));
				hourcount--;
				if (hourcount < 0)
				{
					hourcount += 24;
				}
				outtextxy(73, 73, hour[hourcount]);
			}
		}
		else
		{
			setfillcolor(WHITE);
			floodfill(153, 120, RGB(56,189,25));
			setfillcolor(RGB(56, 188, 25));
			floodfill(153, 115, RGB(56,189,25));
		}
		if (m.x < 297 && m.x > 275 && m.y > 69 && m.y < 98)//右上框
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式
			setfillcolor(RGB(105,212,80));
			floodfill(286, 75, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(286, 82, RGB(56,189,25));
			setcolor(WHITE);
			polygon(pts3, 3);//绘制三角形
			if (m.uMsg == WM_LBUTTONDOWN)        
			{
				setcolor(RGB(56,189,25));
				polygon(pts3, 3);
				setfillcolor(RGB(56,188,25));
				floodfill(286, 75, RGB(56,189,25));
				setfillcolor(WHITE);
				floodfill(286, 82, RGB(56,189,25));
				setcolor(WHITE);
				polygon(pts3, 3);//绘制三角形
			}
			if (m.uMsg == WM_LBUTTONUP)//判断左键是否弹起
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//载入提示音
				showmin+=5;
				settextcolor(RGB(255, 160, 64));//设置文字颜色
				settextstyle(50, 0, _T("宋体"));//设置文字样式
				gettextstyle(&f);  //获取当前字体样式   
				f.lfWeight = 1;//设置笔画粗细
				f.lfWidth = 30;//设置字宽
				f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
				settextstyle(&f);//用f的结构体设置字体样式
				setfillcolor(WHITE);
				floodfill(200,100,RGB(56,189,25));
				mincount++;
				if (mincount > 12)
				{
					mincount -= 12;
				}
				outtextxy(207, 73, minute[mincount]);
			}
		}
		else
		{
			setfillcolor(RGB(56,188,25));
			floodfill(286, 82, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(286, 75, RGB(56,189,25));
		}
		if (m.x < 297 && m.x > 275 && m.y > 98 && m.y < 128)//右下框
		{
			
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式
			setfillcolor(RGB(105,212,80));
			floodfill(286, 120, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(286, 115, RGB(56,189,25));
			setcolor(WHITE);
			polygon(pts4, 3);//绘制三角形
			if (m.uMsg == WM_LBUTTONDOWN)               
			{
				setcolor(RGB(56,189,25));
				polygon(pts4, 3);
				setfillcolor(RGB(56,188,25));
				floodfill(286, 120, RGB(56,189,25));
				setfillcolor(WHITE);
				floodfill(286, 115, RGB(56,189,25));
				setcolor(WHITE);
				polygon(pts4, 3);//绘制三角形
			}
			if (m.uMsg == WM_LBUTTONUP)//判断左键是否弹起
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//载入提示音
				showmin-=5;
				settextcolor(RGB(255, 160, 64));//设置文字颜色
				settextstyle(50, 0, _T("宋体"));//设置文字样式
				gettextstyle(&f);  //获取当前字体样式   
				f.lfWeight = 1;//设置笔画粗细
				f.lfWidth = 30;//设置字宽
				f.lfQuality = ANTIALIASED_QUALITY;//指定输出质量是抗锯齿的（如果字体支持）
				settextstyle(&f);//用f的结构体设置字体样式
				setfillcolor(WHITE);
				floodfill(200,100,RGB(56,189,25));
				mincount--;
				if (mincount < 0)
				{
					mincount += 12;
				}
				outtextxy(207, 73, minute[mincount]);
			}
		}
		else
		{
			setfillcolor(RGB(56,188,25));
			floodfill(286, 115, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(286, 120, RGB(56,189,25));	
		}
		if (m.x < 158 && m.x > 71 && m.y > 195 && m.y < 223)//开始框
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式
		}
		if (m.x < 158 && m.x > 71 && m.y > 195 && m.y < 223)
		{
			setfillcolor(RGB(105,212,80));//设置填充颜色
			floodfill(100, 200, RGB(56,189,25));//填充开始按钮
			setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
			gettextstyle(&f);  //获取当前字体样式                   
			f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
			f.lfHeight = 13;//设置字高为13
			f.lfWidth = 0;
			settextstyle(&f);//设置字体样式为f
			settextcolor(WHITE);//设置文字颜色
			outtextxy(101, 202, s2);//输出提示
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				setfillcolor(RGB(56,188,25));//设置填充颜色
				floodfill(100, 200, RGB(56,189,25));//填充开始按钮
				setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
				gettextstyle(&f);  //获取当前字体样式                   
				f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
				f.lfHeight = 13;//设置字高为13
				f.lfWidth = 0;
				settextstyle(&f);//设置字体样式为f
				settextcolor(WHITE);//设置文字颜色
				outtextxy(101, 202, s2);//输出提示
			}
		}
		else
		{	
			setfillcolor(RGB(56,188,25));//设置填充颜色
			floodfill(100, 200, RGB(56,189,25));//填充开始按钮
			setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
			gettextstyle(&f);  //获取当前字体样式                   
			f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
			f.lfHeight = 13;//设置字高为13
			f.lfWidth = 0;
			settextstyle(&f);//设置字体样式为f
			settextcolor(WHITE);//设置文字颜色
			outtextxy(101, 202, s2);//输出提示
		}
		if (m.x < 158 && m.x > 71 && m.y > 195 && m.y < 223 && m.uMsg == WM_LBUTTONUP)
		{
			//HWND wnd = GetHWnd();
			//MessageBox(wnd, "请点击确认！设置中......" , "提示", MB_OK | MB_ICONINFORMATION);	
			levetime = leveour*3600+levemin*60;
			_itoa(levetime, levestr, 10);
			back1 = system(strcat(cmd, levestr));
			if (back1 == 0)
			{
				int Thour, Tmin;
				char atten[50];
				char thour[5],tmin[5];
				char zero[2] = "0";
				
				Thour = leveour + sysour;
				Tmin = levemin + sysmin;
				if (Tmin >= 60)
				{
					Thour += 1;
					Tmin -= 60;
				}
				if (Thour >= 24)
				{
					Thour -= 24;
				}
				
				_itoa(Thour, thour, 10);
				_itoa(Tmin, tmin, 10);
				if (Tmin < 10)
				{
					strcat(tmin, "0");
				}
				
				if (Thour < 10)
				{
					strcat(zero, thour);
					strcpy(thour, zero);
				}
				strcpy(atten, "电脑将在");
				strcat(atten, thour);
				strcat(atten, ":");
				strcat(atten, tmin);
				strcat(atten, "关机！");
				strcat(atten,"目前距离关机还有");
				strcat(atten, str3);
				strcat(atten, "小时");
				strcat(atten, str4);
				strcat(atten, "分钟。");
				HWND wnd = GetHWnd();
				MessageBox(wnd, atten , "提示", MB_OK | MB_ICONINFORMATION);
			}
			else if (back1 != 0 && back1 != 1)
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "您已设置关机时间！如想更改设置请点取消。" , "警告", MB_OK | MB_ICONWARNING);
			}
			else if (back1 == 1)
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "设置关机失败！请重新启动程序。" , "警告", MB_OK | MB_ICONWARNING);
			}
		}
		if (m.x < 287 && m.x > 200 && m.y > 195 && m.y < 223)//取消框
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // 获取绘图窗口句柄
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // 设置绘图窗口内的鼠标样式	
		}
		if (m.x < 287 && m.x > 200 && m.y > 195 && m.y < 223)
		{	
			setfillcolor(RGB(105,212,80));//设置填充颜色
			floodfill(250, 200, RGB(56,189,25));//填充关闭按钮
			setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
			gettextstyle(&f);  //获取当前字体样式                   
			f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
			f.lfHeight = 13;//设置字高为13
			settextstyle(&f);//设置字体样式为f
			settextcolor(WHITE);//设置文字颜色
			outtextxy(228, 202, s3);//输出提示
			if (m.uMsg == WM_LBUTTONDOWN)
			{	
				setfillcolor(RGB(56,188,25));//设置填充颜色
				floodfill(250, 200, RGB(56,189,25));//填充关闭按钮
				setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
				gettextstyle(&f);  //获取当前字体样式                   
				f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
				f.lfHeight = 13;//设置字高为13
				settextstyle(&f);//设置字体样式为f
				settextcolor(WHITE);//设置文字颜色
				outtextxy(228, 202, s3);//输出提示
			}
		}
		else
		{
			setfillcolor(RGB(56,188,25));//设置填充颜色
			floodfill(250, 200, RGB(56,189,25));//填充关闭按钮
			setbkmode(TRANSPARENT);//设置文字输出的背景模式为透明	
			gettextstyle(&f);  //获取当前字体样式                   
			f.lfWeight = 900;//令笔画粗细等于900（0 ~ 1000）
			f.lfHeight = 13;//设置字高为13
			settextstyle(&f);//设置字体样式为f
			settextcolor(WHITE);//设置文字颜色
			outtextxy(228, 202, s3);//输出提示
		}
		if (m.x < 287 && m.x > 200 && m.y > 195 && m.y < 223 && m.uMsg == WM_LBUTTONUP)
		{
			//HWND wnd = GetHWnd();
			//MessageBox(wnd, "请点击确认！取消中......" , "提示", MB_OK | MB_ICONINFORMATION);			
			back2 = system("shutdown -a");
			if (back2 == 0)
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "您已成功取消关机设置时间！" , "提示", MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "您还没有设置关机时间！" , "警告", MB_OK | MB_ICONWARNING);
			}
		}
		EndBatchDraw();// 关闭批量绘图模式
			
	}
	return ;
}

