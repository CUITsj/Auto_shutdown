#include<graphics.h>
#include<time.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")//Ԥ����ָ����߱�����Ҫ����winmm���Ա��������
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")//Ԥ����ָ��ر�DOS����
#define PI 3.14159265354

void main()
{
	char cmd[20] = "shutdown -s -t ";
	int back1;
	char levestr[5] = "0";
	int levetime = 0;
	int back2;
	int showhour = 0;//�����ʼСʱ
	int showmin = 0;//�����ʼ����
	int levemin = 0;
	int leveour = 0;
	int hourcount = 0;//����Сʱ����
	int mincount = 0;//�����������
	int lastingtime = 0;//���������ʱ��
	int lastinghour = 0;
	int lastingminute = 0;
	int lastingsecond = 0;
	char hour[][24] = {"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23"};//��Ҫ�����Сʱ�����ά����
	char minute[][12] = {"00", "05","10","15","20","25","30","35","40","45","50","55"};//��Ҫ����ķ��Ӵ����ά����
	char str3[2];//���������Сʱ���ַ���
	char str4[2];//������������ӵ��ַ���
	char str5[2];//�����ŵ�������Сʱ
	char str6[2];//�����ŵ������з���
//	char str7[2];//�����ŵ���������
	char s[] = "��Ҫ���㼸�ֹػ���";//����Ҫ�������ʾ
	char s1[] = "����ػ���";//������ʾ����
	char s2[] = "��ʼ";//����Ҫ�������ʾ
	char s3[] = "ȡ��";//����Ҫ�������ʾ
	char s4[] = "Сʱ";//��Ҫ�������ʾװ���ַ���
	char s5[] = "����";//��Ҫ�������ʾװ���ַ���
	char s6[] = "���������У�";//������ʾ����
	char s7[] = "����";
	char closeLCDatten[] = "������Ļ����30���رգ��벻Ҫ�رո�Ӧ�ã����򽫵��¹������ɹ���";
	//char s7[] = "��";//��Ҫ�������ʾװ���ַ���
	int sysour;//����ϵͳСʱ
	int sysmin;//����ϵͳ����
	LOGFONT f;//����������ʽ��һ���ṹ��f
	
	//��ͼ����
	initgraph(360, 254);//��ʼ����ͼ����

	BeginBatchDraw();// ����������ͼģʽ
	mciSendString(_T("play open.wav from 0"), NULL, 0, NULL);//������ʾ��
	setbkcolor(RGB(254, 254, 254));//���ñ�����ɫ
	cleardevice();//�����Ļ����
	//����Сʱ����ʾ��
	setcolor(RGB(56,189,25));//����������ɫ
	setfillcolor(RGB(56,188,25));//���������ɫ
	rectangle(63, 69, 164, 128);//�����ⲿ����
	line(142, 69, 142, 128);//�����ڲ�����
	line(142, 98, 164, 98);//�����ڲ�����
	POINT pts1[] = { {153, 79}, {148, 84}, {158, 84} };//����������������
	polygon(pts1, 3);//����������
	floodfill(153, 82, RGB(56,189,25));//���������
	POINT pts2[] = { {153, 117}, {148, 112}, {158, 112} };//����������������
	polygon(pts2, 3);//����������
	floodfill(153, 115, RGB(56,189,25));//���������
	//���Ʒ�����ʾ��
	rectangle(196, 69, 297, 128);//�����ⲿ����
	line(275, 69, 275, 128);//�����ڲ�����
	line(275, 98, 297, 98);//�����ڲ�����
	POINT pts3[] = { {286, 79}, {281, 84}, {291, 84} };//����������������
	polygon(pts3, 3);//����������
	floodfill(286, 82, RGB(56,189,25));//���������
	POINT pts4[] = { {286, 117}, {281, 112}, {291, 112} };//����������������
	polygon(pts4, 3);//����������
	floodfill(286, 115, RGB(56,189,25));//���������
	//���ƿ�ʼ�͹رհ�ť
	//��ʼ
	setfillcolor(RGB(56,188,25));//���������ɫ
	line(81,195,148,195);//���ƿ�ʼ��ť
	line(81,223,148,223);//���ƿ�ʼ��ť
	arc(71,195,91,223,PI/2,PI*3/2);//���ƿ�ʼ��ť
	arc(138,195,158,223,-PI/2,PI/2);//���ƿ�ʼ��ť
	floodfill(100, 200, RGB(56,189,25));//��俪ʼ��ť
	//�ر�
	line(210,195,277,195);//���ƹرհ�ť
	line(210,223, 277,223);//���ƹرհ�ť
	arc(200, 195, 220, 223, PI/2,PI*3/2);//���ƹرհ�ť
	arc(267, 195,287,223, -PI/2, PI/2);//���ƹرհ�ť
	floodfill(250, 200, RGB(56,189,25));//���رհ�ť
	//�����м�����
	//�ϵ�
	setcolor(RGB(255, 161, 64));//���õ�ǰ��ͼǰ��ɫ
	circle(180, 91, 2);//�����Բ
	circle(180, 105, 2);//�����Բ
	//�µ�
	setfillcolor(RGB(255, 161, 64));//���������ɫ
	floodfill(180,91,RGB(255, 161, 64));//��������Բ
	floodfill(180,105,RGB(255, 161, 64));//��������Բ
	//�����ʾ����
	settextstyle(16, 0, _T("����"));//����������ʽ
	settextcolor(BLACK);//����������ɫ
	outtextxy(111, 25, s);//�����ʾ
	settextstyle(12, 0, _T("����"));//����������ʽ
	outtextxy(105, 156, s1);//�����ʾ
	//������ť��ʾ
	setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
	gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
	f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
	f.lfHeight = 13;//�����ָ�Ϊ13
	f.lfWidth = 0;
	settextstyle(&f);//����������ʽΪf
	settextcolor(WHITE);//����������ɫ
	outtextxy(101, 202, s2);//�����ʾ
	outtextxy(228, 202, s3);//�����ʾ
	//�������ʱ��λ
	settextcolor(RGB(255, 160, 64));//���õ�ǰ������ɫ
	f.lfWeight = 0;//��ʻ���ϸ����0 Ĭ�ϴ�ϸ��0 ~ 1000��
	settextstyle(&f);//����������ʽΪf
	outtextxy(184, 156, s4);//�����ʾ
	outtextxy(230, 156, s5);//�����ʾ

	//���ϵͳ����ʱ����ʾ

	settextcolor(BLACK);//����������ɫ
	settextstyle(12, 0, _T("����"));//����������ʽ
	outtextxy(85, 240, s6);//�����ʾ
	settextcolor(RGB(255, 160, 64));//���õ�ǰ������ɫ
	f.lfWeight = 0;//��ʻ���ϸ����0 Ĭ�ϴ�ϸ��0 ~ 1000��
	settextstyle(&f);//����������ʽΪf
	outtextxy(174, 240, s4);//�����ʾ
	outtextxy(220, 240, s5);//�����ʾ
	//outtextxy(266, 240, s7);//�����


	//���Ƽ�ͷ���ֱ仯and�����궯��
	MOUSEMSG m;	//������궯���ṹ��
	time_t rawtime;//����һ��ʱ������
	tm * t;//����һ���ṹ��ָ��
	//��ȡϵͳСʱ�ͷ���
	time(&rawtime);//��ȡʱ��
	t = localtime(&rawtime);//ת��Ϊ����ʱ��
	sysour = t->tm_hour;//ϵͳСʱ
	sysmin = t->tm_min;//ϵͳ����
	//�����ʼʱ��
	settextcolor(RGB(255, 160, 64));//����������ɫ
	settextstyle(50, 0, _T("����"));//����������ʽ
	gettextstyle(&f);  //��ȡ��ǰ������ʽ   
	f.lfWeight = 1;//���ñʻ���ϸ
	f.lfWidth = 30;//�����ֿ�
	f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
	settextstyle(&f);//��f�Ľṹ������������ʽ
	hourcount = sysour + 2;//����Ĭ�ϵ���ʱ
	showhour = sysour + 2;//���ó�ʼСʱ
	if (hourcount >= 24)
	{
		hourcount -= 24;
	}
	//�����ʼСʱ
	outtextxy(73, 73, hour[hourcount]);
	//�����ʼ����
	outtextxy(207, 73, minute[mincount]);

	//���ƹر���Ļ��ť
	setcolor(RGB(56,189,25));//����������ɫ
	setfillcolor(RGB(0, 100, 0));
	rectangle(7, 3, 40, 21);//���ƾ��ο�
	floodfill(20, 20, RGB(56,189,25));
	setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
	gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
	f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
	f.lfHeight = 12;//�����ָ�Ϊ12
	f.lfWidth = 0;
	settextstyle(&f);//����������ʽΪf
	settextcolor(WHITE);//����������ɫ
	outtextxy(11, 6, s7);//�����ʾ


	EndBatchDraw();// �ر�������ͼģʽ
	while (true)
	{
		BeginBatchDraw();// ����������ͼģʽ
		//��ȡϵͳСʱ�ͷ���
		time(&rawtime);//��ȡʱ��
		t = localtime(&rawtime);//ת��Ϊ����ʱ��
		sysour = t->tm_hour;//ϵͳСʱ
		sysmin = t->tm_min;//ϵͳ����
		//���ʣ��ʱ��
		setcolor(RGB(254,255,255));//���õ�ǰ��ͼǰ��ɫ
		rectangle(164,155,184,168);//����С����
		rectangle(211, 154, 228, 168);//����С����
		setfillcolor(WHITE);//���������ɫ
		settextcolor(RGB(255, 160, 64));//���õ�ǰ������ɫ
		settextstyle(14, 0, _T("����"));//����������ʽ
		gettextstyle(&f);//��ȡ��ǰ������ʽ 
		f.lfWeight = 700;//���ñʻ���ϸ
		f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
		settextstyle(&f);//��f�Ľṹ������������ʽ	
		floodfill(170, 160, RGB(254,255,255));//���С����
		floodfill(215,160,RGB(254,255,255));//���С����
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
		_itoa(leveour, str3, 10);//��ʣ��Сʱ��ת��Ϊ�ַ���
		_itoa(levemin, str4, 10);//��ʣ�������ת��Ϊ�ַ���
		outtextxy(167,155,str3);//���ʣ��Сʱ
		outtextxy(212,155,str4);//���ʣ�����

		//�����������ʱ��
		lastingtime=GetTickCount();
    	lastinghour=(lastingtime/1000)/3600;
	    lastingminute=(lastingtime/1000)/60-lastinghour*60;
		//lastingsecond=(lastingtime/1000)-lastinghour*3600-lastingminute*60;

		setcolor(RGB(254,255,255));//���õ�ǰ��ͼǰ��ɫ
		rectangle(154,239,174,252);//����С����
		rectangle(201, 238, 218, 252);//����С����
		//rectangle(247,238,264,252);
		setfillcolor(WHITE);//���������ɫ
		settextcolor(RGB(255, 160, 64));//���õ�ǰ������ɫ
		settextstyle(14, 0, _T("����"));//����������ʽ
		gettextstyle(&f);//��ȡ��ǰ������ʽ 
		f.lfWeight = 700;//���ñʻ���ϸ
		f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
		settextstyle(&f);//��f�Ľṹ������������ʽ	
		floodfill(160, 245, RGB(254,255,255));//���С����
		floodfill(210,245,RGB(254,255,255));//���С����
		//floodfill(255,245,RGB(254,255,255));
		_itoa(lastinghour, str5, 10);//������Сʱ��ת��Ϊ�ַ���
		_itoa(lastingminute, str6, 10);//�����з�����ת��Ϊ�ַ���
		//_itoa(lastingsecond, str7, 10);
		outtextxy(157,239,str5);//�������Сʱ
		outtextxy(202,239,str6);//������з���
		//outtextxy(248,239,str7);//���ʣ�����
		EndBatchDraw();// �ر�������ͼģʽ

		BeginBatchDraw();// ����������ͼģʽ

		m = GetMouseMsg();//��ȡ�����Ϣ
		setcolor(RGB(56,189,25));//���û�ͼ��ɫ
		polygon(pts1, 3);//����������
		polygon(pts2, 3);//����������
		polygon(pts3, 3);//����������
		polygon(pts4, 3);//����������
		HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("stand.cur"), IMAGE_CURSOR, 33, 32, LR_LOADFROMFILE);
		HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
		SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ


		//�ر���Ļ
		if (m.x >7 && m.x<40 && m.y >3 && m.y<21)//�ر���Ļ��
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ
		}
		if (m.x >7 && m.x<40 && m.y >3 && m.y<21 && m.uMsg == WM_LBUTTONUP)
		{
			HWND wnd = GetHWnd();
			MessageBox(wnd, closeLCDatten , "��ʾ", MB_OK | MB_ICONINFORMATION);
			Sleep(30000);//��ʱms
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); //�ر���ʾ��
		}

		if (m.x < 164 && m.x > 142 && m.y > 69 && m.y < 98)//���Ͽ�
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ
			setfillcolor(RGB(105,212,80));//���������ɫ
			floodfill(153, 70, RGB(56,189,25));//������
			setfillcolor(WHITE);//���������ɫ
			floodfill(153, 82, RGB(56,189,25));//���������
			setcolor(WHITE);//���û�ͼ��ɫ
			polygon(pts1, 3);//����������
			settextcolor(RGB(255, 160, 64));
			if (m.uMsg == WM_LBUTTONDOWN)         
			{
				setcolor(RGB(56,189,25));
				polygon(pts1, 3);
				setfillcolor(RGB(56, 188, 25));//���������ɫ
				floodfill(153, 70, RGB(56,189,25));//������
				setfillcolor(WHITE);//���������ɫ
				floodfill(153, 82, RGB(56,189,25));//���������
				setcolor(WHITE);//���û�ͼ��ɫ
				polygon(pts1, 3);//����������
			}
			if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//������ʾ��
				showhour++;
				settextcolor(RGB(255, 160, 64));//����������ɫ
				settextstyle(50, 0, _T("����"));//����������ʽ
				gettextstyle(&f);  //��ȡ��ǰ������ʽ   
				f.lfWeight = 1;//���ñʻ���ϸ
				f.lfWidth = 30;//�����ֿ�
				f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
				settextstyle(&f);//��f�Ľṹ������������ʽ
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
		if (m.x < 164 && m.x > 142 && m.y > 98 && m.y < 128)//���¿�
		{
			
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ
			setfillcolor(RGB(105, 212, 80));
			floodfill(153, 120, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(153, 115, RGB(56,189,25));
			setcolor(WHITE);
			polygon(pts2, 3);//����������	
			if (m.uMsg == WM_LBUTTONDOWN)             
			{
				setcolor(RGB(56,189,25));
				polygon(pts2, 3);
				setfillcolor(RGB(56, 188, 25));
				floodfill(153, 120, RGB(56,189,25));
				setfillcolor(WHITE);
				floodfill(153, 115, RGB(56,189,25));
				setcolor(WHITE);
				polygon(pts2, 3);//����������
			}
			if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//������ʾ��
				showhour--;
				settextcolor(RGB(255, 160, 64));//����������ɫ
				settextstyle(50, 0, _T("����"));//����������ʽ
				gettextstyle(&f);  //��ȡ��ǰ������ʽ   
				f.lfWeight = 1;//���ñʻ���ϸ
				f.lfWidth = 30;//�����ֿ�
				f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
				settextstyle(&f);//��f�Ľṹ������������ʽ
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
		if (m.x < 297 && m.x > 275 && m.y > 69 && m.y < 98)//���Ͽ�
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ
			setfillcolor(RGB(105,212,80));
			floodfill(286, 75, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(286, 82, RGB(56,189,25));
			setcolor(WHITE);
			polygon(pts3, 3);//����������
			if (m.uMsg == WM_LBUTTONDOWN)        
			{
				setcolor(RGB(56,189,25));
				polygon(pts3, 3);
				setfillcolor(RGB(56,188,25));
				floodfill(286, 75, RGB(56,189,25));
				setfillcolor(WHITE);
				floodfill(286, 82, RGB(56,189,25));
				setcolor(WHITE);
				polygon(pts3, 3);//����������
			}
			if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//������ʾ��
				showmin+=5;
				settextcolor(RGB(255, 160, 64));//����������ɫ
				settextstyle(50, 0, _T("����"));//����������ʽ
				gettextstyle(&f);  //��ȡ��ǰ������ʽ   
				f.lfWeight = 1;//���ñʻ���ϸ
				f.lfWidth = 30;//�����ֿ�
				f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
				settextstyle(&f);//��f�Ľṹ������������ʽ
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
		if (m.x < 297 && m.x > 275 && m.y > 98 && m.y < 128)//���¿�
		{
			
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ
			setfillcolor(RGB(105,212,80));
			floodfill(286, 120, RGB(56,189,25));
			setfillcolor(WHITE);
			floodfill(286, 115, RGB(56,189,25));
			setcolor(WHITE);
			polygon(pts4, 3);//����������
			if (m.uMsg == WM_LBUTTONDOWN)               
			{
				setcolor(RGB(56,189,25));
				polygon(pts4, 3);
				setfillcolor(RGB(56,188,25));
				floodfill(286, 120, RGB(56,189,25));
				setfillcolor(WHITE);
				floodfill(286, 115, RGB(56,189,25));
				setcolor(WHITE);
				polygon(pts4, 3);//����������
			}
			if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
			{
				mciSendString(_T("play click.wav from 0"), NULL, 0, NULL);//������ʾ��
				showmin-=5;
				settextcolor(RGB(255, 160, 64));//����������ɫ
				settextstyle(50, 0, _T("����"));//����������ʽ
				gettextstyle(&f);  //��ȡ��ǰ������ʽ   
				f.lfWeight = 1;//���ñʻ���ϸ
				f.lfWidth = 30;//�����ֿ�
				f.lfQuality = ANTIALIASED_QUALITY;//ָ����������ǿ���ݵģ��������֧�֣�
				settextstyle(&f);//��f�Ľṹ������������ʽ
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
		if (m.x < 158 && m.x > 71 && m.y > 195 && m.y < 223)//��ʼ��
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ
		}
		if (m.x < 158 && m.x > 71 && m.y > 195 && m.y < 223)
		{
			setfillcolor(RGB(105,212,80));//���������ɫ
			floodfill(100, 200, RGB(56,189,25));//��俪ʼ��ť
			setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
			gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
			f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
			f.lfHeight = 13;//�����ָ�Ϊ13
			f.lfWidth = 0;
			settextstyle(&f);//����������ʽΪf
			settextcolor(WHITE);//����������ɫ
			outtextxy(101, 202, s2);//�����ʾ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				setfillcolor(RGB(56,188,25));//���������ɫ
				floodfill(100, 200, RGB(56,189,25));//��俪ʼ��ť
				setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
				gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
				f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
				f.lfHeight = 13;//�����ָ�Ϊ13
				f.lfWidth = 0;
				settextstyle(&f);//����������ʽΪf
				settextcolor(WHITE);//����������ɫ
				outtextxy(101, 202, s2);//�����ʾ
			}
		}
		else
		{	
			setfillcolor(RGB(56,188,25));//���������ɫ
			floodfill(100, 200, RGB(56,189,25));//��俪ʼ��ť
			setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
			gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
			f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
			f.lfHeight = 13;//�����ָ�Ϊ13
			f.lfWidth = 0;
			settextstyle(&f);//����������ʽΪf
			settextcolor(WHITE);//����������ɫ
			outtextxy(101, 202, s2);//�����ʾ
		}
		if (m.x < 158 && m.x > 71 && m.y > 195 && m.y < 223 && m.uMsg == WM_LBUTTONUP)
		{
			//HWND wnd = GetHWnd();
			//MessageBox(wnd, "����ȷ�ϣ�������......" , "��ʾ", MB_OK | MB_ICONINFORMATION);	
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
				strcpy(atten, "���Խ���");
				strcat(atten, thour);
				strcat(atten, ":");
				strcat(atten, tmin);
				strcat(atten, "�ػ���");
				strcat(atten,"Ŀǰ����ػ�����");
				strcat(atten, str3);
				strcat(atten, "Сʱ");
				strcat(atten, str4);
				strcat(atten, "���ӡ�");
				HWND wnd = GetHWnd();
				MessageBox(wnd, atten , "��ʾ", MB_OK | MB_ICONINFORMATION);
			}
			else if (back1 != 0 && back1 != 1)
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "�������ùػ�ʱ�䣡��������������ȡ����" , "����", MB_OK | MB_ICONWARNING);
			}
			else if (back1 == 1)
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "���ùػ�ʧ�ܣ���������������" , "����", MB_OK | MB_ICONWARNING);
			}
		}
		if (m.x < 287 && m.x > 200 && m.y > 195 && m.y < 223)//ȡ����
		{
			HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("hand.cur"), IMAGE_CURSOR, 32, 35, LR_LOADFROMFILE);
			HWND hwnd = GetHWnd();    // ��ȡ��ͼ���ھ��
			SetClassLong(hwnd, GCL_HCURSOR, (long)hcur); // ���û�ͼ�����ڵ������ʽ	
		}
		if (m.x < 287 && m.x > 200 && m.y > 195 && m.y < 223)
		{	
			setfillcolor(RGB(105,212,80));//���������ɫ
			floodfill(250, 200, RGB(56,189,25));//���رհ�ť
			setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
			gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
			f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
			f.lfHeight = 13;//�����ָ�Ϊ13
			settextstyle(&f);//����������ʽΪf
			settextcolor(WHITE);//����������ɫ
			outtextxy(228, 202, s3);//�����ʾ
			if (m.uMsg == WM_LBUTTONDOWN)
			{	
				setfillcolor(RGB(56,188,25));//���������ɫ
				floodfill(250, 200, RGB(56,189,25));//���رհ�ť
				setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
				gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
				f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
				f.lfHeight = 13;//�����ָ�Ϊ13
				settextstyle(&f);//����������ʽΪf
				settextcolor(WHITE);//����������ɫ
				outtextxy(228, 202, s3);//�����ʾ
			}
		}
		else
		{
			setfillcolor(RGB(56,188,25));//���������ɫ
			floodfill(250, 200, RGB(56,189,25));//���رհ�ť
			setbkmode(TRANSPARENT);//������������ı���ģʽΪ͸��	
			gettextstyle(&f);  //��ȡ��ǰ������ʽ                   
			f.lfWeight = 900;//��ʻ���ϸ����900��0 ~ 1000��
			f.lfHeight = 13;//�����ָ�Ϊ13
			settextstyle(&f);//����������ʽΪf
			settextcolor(WHITE);//����������ɫ
			outtextxy(228, 202, s3);//�����ʾ
		}
		if (m.x < 287 && m.x > 200 && m.y > 195 && m.y < 223 && m.uMsg == WM_LBUTTONUP)
		{
			//HWND wnd = GetHWnd();
			//MessageBox(wnd, "����ȷ�ϣ�ȡ����......" , "��ʾ", MB_OK | MB_ICONINFORMATION);			
			back2 = system("shutdown -a");
			if (back2 == 0)
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "���ѳɹ�ȡ���ػ�����ʱ�䣡" , "��ʾ", MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "����û�����ùػ�ʱ�䣡" , "����", MB_OK | MB_ICONWARNING);
			}
		}
		EndBatchDraw();// �ر�������ͼģʽ
			
	}
	return ;
}

