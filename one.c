#include <stdio.h>
struct LinearModel{
    double omega;
    double b;
};
struct LinearModel lm={0,0};
void fit(double x_train[],double y_train[]){
    lm.omega= (y_train[0] - y_train[1])/(x_train[0]-x_train[1]);//已知两个坐标的上的点了，omege为这两点构成一条直线的斜率 
    lm.b = y_train[0] - x_train[0]*lm.omega;// b = y-kx 即 y = kx + b ，  b为该y轴上的截距 
}

double predict(double x_test){
    double y_test;
    y_test = lm.omega*x_test+lm.b; //通过之前的操作确定的斜率和截距参数，已知x就能确定唯一的y 
    return y_test;//返回计算出来的y 
}
int main(){
    double X[2],Y[2];//定义两个数组 ，x为x轴上的数据，y轴为y上的数据 
    printf("Input x1 y1 x2 y2 : ");//提示输入 
    scanf("%lf %lf %lf %lf",&X[0],&Y[0],&X[1],&Y[1]);//输入4个数 ，即为两个坐标点 
    fit(X,Y);//执行函数fit ，计算出这两点形成直线的斜率和y轴上的截距 
    printf("Tranining result : omege = %lf,b=%lf\n\n",lm.omega,lm.b);//输出出来 
    double x,y;//定义两个参数 
    printf("Input x:");//提示输入x 
    scanf("%lf",&x);//输入x 
    y=predict(x);//执行predict函数 ,计算出来y 
    printf("Predict result : x=%.2lf平米,y%.2lf万元\n",x,y);//将预测的结果输出出来 
    return 0;

}
