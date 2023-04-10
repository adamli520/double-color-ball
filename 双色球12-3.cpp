#include <stdio.h>
#include <stdlib.h>
#include <time.h>                        
#include<windows.h>
#include<graphics.h>

static int result[6],rblue,jixuan[6],jblue,hand[6],hblue;
void gui(){
	IMAGE jpg;
	int isok;
	HWND hnd =GetHWnd();
	SetWindowText(hnd,"双色球");
	isok=MessageBoxA(hnd,"\t欢迎来到双色球\n\t是否需要辅助窗口!","双色球",MB_YESNO);
	
	if(isok==IDYES){
		initgraph(1000,800,NOMINIMIZE|NOCLOSE|SHOWCONSOLE);
	}
	else
		initgraph(1000,800,NOMINIMIZE|NOCLOSE);
	
	cleardevice();
	loadimage(&jpg,_T("jpg\\twoball.jpg"));
	putimage(0,0,&jpg);
	setbkcolor(WHITE);
	

	
	
}
int initdate(int result[],int rblue){
	int i,j;
	for (i = 0; i < 6;)               //随机生成6个红色球号码
	{
		int temp = rand() % 33 + 1;
		for (j = 0; j < i; j++)
		{
			//依次判断数组中的已生成红色球号码是否与新生成的号码相同
			if (result[j] == temp)       //如果相同，则重新生成新的红色球号码
			{
				break;                    //跳出内层for循环
			}
		}
		if (j == i)
		{
			result[i] = temp;             //将新生成的红色球号码保存在red数组中
			i++;                         //增加红色球的数量
		}
	}
	for(i=0;i<6;i++){
		for( j=0;j<6-i-1;j++){
			if(result[j]>result[j+1]){
				int temp=result[j];
				result[j]=result[j+1];
				result[j+1]=temp;
				
			}	
		}
	}	
	
	rblue = rand() % 16 + 1;         
	for (i = 0; i < 6; i++)
	{
		printf("%-4d", result[i]);        
	}
	printf("篮球:%d \n",rblue);   
	return rblue;
}







void iswin(int result[],int rblue,int jixuan[],int jblue){
	int red_number=0,blue_number=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(result[i]==jixuan[j]){
				red_number++;
			}
		}
	}
	if(rblue==jblue){
		blue_number++;
	}
	HWND hnd =GetHWnd();
	
	if(red_number==6&&blue_number==1){
		MessageBoxA(hnd,"恭喜你获得一等奖","双色球项目",MB_OK);
	}
	else if(red_number==6&&blue_number==0){
		MessageBoxA(hnd,"恭喜你获得二等奖","双色球项目",MB_OK);
	}
	else if(red_number==5&&blue_number==1){
		MessageBoxA(hnd,"恭喜你获得三等奖","双色球项目",MB_OK);
	}
	else if((red_number==5&&blue_number==0)||(red_number==4&&blue_number==1)){
		MessageBoxA(hnd,"恭喜你获得四等奖","双色球项目",MB_OK);
	}
	else if((red_number==4&&blue_number==0)||(red_number==3&&blue_number==1)){
		MessageBoxA(hnd,"恭喜你获得五等奖","双色球项目",MB_OK);
	}
	else if((red_number==2&&blue_number==1)||(red_number==1&&blue_number==1)||(red_number==0&&blue_number==1)){
		MessageBoxA(hnd,"恭喜你获得六等奖","双色球项目",MB_OK);
	}
	else{
		MessageBoxA(hnd,"很遗憾你没中奖","双色球项目",MB_OK);
	}


}

void button(int x,int y,int w,int h,const char* text){
	
	setbkmode(TRANSPARENT);
	setfillcolor(LIGHTBLUE);
	settextcolor(BLACK);
	fillroundrect(x,y,x+w,y+h,10,10);
	settextstyle(30,0,"黑体");
	char text1[50]="button";
	strcpy(text1,text);
	int tx=x+(w-textwidth(text))/2;
	int ty=y+(h-textheight(text))/2;
	outtextxy(tx,ty,text);
}
void styleprint(int x,int y,int num){
	
	char cnum[20]={""};
	sprintf_s(cnum,20,"%02d",num);
	settextstyle(30,0,"幼圆");
	setbkmode(TRANSPARENT);
	outtextxy(x,y,cnum);
	int nx= x+textwidth(cnum)/2;
	int ny=y+textheight(cnum)/2;
	setlinestyle(0,3);
	circle(nx,ny,30);
	
}

void printnum1(){
	rblue=initdate(result,rblue);
	HRGN rgn = CreateRectRgn(290,365,860,435);
	setcliprgn(rgn);
	clearcliprgn();
	int x,y=385;
	for(int i=0;i<6;i++){
		x=70*i+340;
		settextcolor(RED);
		setlinecolor(RED);
		
		styleprint(x,y,result[i]);
		
	}
	
	settextcolor(BLUE);
	setlinecolor(BLUE);
	
	styleprint(x+70,y,rblue);
	
}
void printnum2(){
	
	jblue=initdate(jixuan,jblue);
	HRGN rgn = CreateRectRgn(280,465,860,530);
	setcliprgn(rgn);
	clearcliprgn();
	int x,y=482;
	for(int i=0;i<6;i++){
		x=70*i+340;
		settextcolor(RED);
		setlinecolor(RED);
		styleprint(x,y,jixuan[i]);
	}
	settextcolor(BLUE);
	setlinecolor(BLUE);
	
	styleprint(x+70,y,jblue);
	
	
	
}
void printnum3(){
	
	//hblue=initdate(hand,hblue);
	HRGN rgn = CreateRectRgn(290,565,860,630);
	setcliprgn(rgn);
	clearcliprgn();
	int x,y=582;
	for(int i=0;i<6;i++){
		x=70*i+340;
		settextcolor(RED);
		setlinecolor(RED);
		styleprint(x,y,hand[i]);
	}
	settextcolor(BLUE);
	setlinecolor(BLUE);
	
	styleprint(x+70,y,hblue);
	
	
	
}

void input() 
{	
	
	char str1[20];
	for(int i=0;i<6;){
		InputBox(str1, 20, "请输入红球","红球",NULL,200,0,1);
		sscanf(str1, "%d", &hand[i]);
		printf("%d \n",hand[i]);
	
		if(hand[i]>0&&hand[i]<34){
			
			printf("满足条件:%d\n",hand[i]);
			printnum3();
			i++;
		}
		else
			InputBox(str1, 20, "请重新输入红球号","红球",NULL,200,0,1);
		
	}
//	InputBox(str1, 20, "请输入篮球号","篮球",NULL,200,0,1);
//	sscanf(str1, "%d", &hblue);
//	
//	if(hblue>0&&hblue<=16){
//		printf("满足条件:%d\n",hblue);
//		
//	}
//	else
//		InputBox(str1, 20, "请重新输入篮球号","篮球",NULL,200,0,1);
//		
	do{
		InputBox(str1, 20, "请输入篮球号","篮球",NULL,200,0,1);
		sscanf(str1, "%d", &hblue);
	}while(!(hblue>0&&hblue<=16));
	

}

void rgb(){
	ExMessage msg;
	
		while(1){
	
		
		if (peekmessage(&msg,EM_MOUSE)){
			
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if(msg.x>=300&&msg.x<=300+120&&msg.y>=650&&msg.y<=650+40){
					printf("坐标:%d,%d\n",msg.x,msg.y);
					printnum2();
					iswin(result,rblue,jixuan,jblue);
				}
				if(msg.x>=450&&msg.x<=450+120&&msg.y>=650&&msg.y<=650+40){
					input();
					printnum3();
					iswin(result,rblue,hand,hblue);
					flushmessage();
					
				}
				if(msg.x>=600&&msg.x<=600+120&&msg.y>=650&&msg.y<=650+40){
					printnum1();
					flushmessage();	
				}
				break;
		
				case WM_RBUTTONDOWN:
						printf("坐标:%d,%d\n",msg.x,msg.y);
				break;	
			
			
			
			
			}   
		
			
			
		}
		}
	
}

int main(){
	srand((unsigned int)time(NULL));
	system("mode con cols=50 lines=20");
	gui();

	button(300,650,120,40,"自动选球");
	button(450,650,120,40,"手动选球");
	button(600,650,120,40,"开奖");
	
	
	//printnum2();
	//printnum3();
	//input();
	
	
	rgb();

	

	getchar();
	return 0;
}

