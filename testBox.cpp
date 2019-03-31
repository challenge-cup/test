
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
 
using namespace cv;
using namespace std;

#define WinDow "程序窗口"

void Drawrectangle(cv::Mat &img, cv::Rect box);//矩形绘制函数
void OnMouseAction(int event,int x,int y,int flags,void *ustc);  //鼠标回调事件函数
int static times; //记录几次图片
int x,y;
bool touchFlag;
Rect y_rectangle;
RNG rng(12345);

int main(int argc,char*argv[])
{
    times=0;
    y_rectangle = Rect(-1, -1, 0, 0);
	Mat image=imread(argv[1]);
	imshow("image",image);
	setMouseCallback("image",OnMouseAction);
    cout<<"rectangle"<<y_rectangle<<endl;
    cv::waitKey(0);
    return 1;
}
void OnMouseAction(int event,int x,int y,int flags,void *ustc)
{	
	if(event==CV_EVENT_LBUTTONDOWN)
	{
        times++;//
		cout<<"触发左键按下事件"<<"x:"<<x<<"y:"<<y<<"flags: "<<flags<<" t"<<times<<endl;
        y_rectangle = Rect(x, y, 0, 0);
        y_rectangle.x = x;
        y_rectangle.y = y;
	}
	else if(event==CV_EVENT_LBUTTONUP)
	{
		cout<<"触发左键抬起事件"<<"x:"<<x<<"y:"<<y<<"flags: "<<flags<<" t"<<times<<endl;
        y_rectangle.height = y - y_rectangle.y;
        y_rectangle.width = x - y_rectangle.x;
        cout<<"rectangle"<<y_rectangle<<endl;
	}

}
