#include <stdio.h>
struct LinearModel{
    double omega;
    double b;
};
struct LinearModel lm={0,0};
void fit(double x_train[],double y_train[]){
    lm.omega= (y_train[0] - y_train[1])/(x_train[0]-x_train[1]);//��֪����������ϵĵ��ˣ�omegeΪ�����㹹��һ��ֱ�ߵ�б�� 
    lm.b = y_train[0] - x_train[0]*lm.omega;// b = y-kx �� y = kx + b ��  bΪ��y���ϵĽؾ� 
}

double predict(double x_test){
    double y_test;
    y_test = lm.omega*x_test+lm.b; //ͨ��֮ǰ�Ĳ���ȷ����б�ʺͽؾ��������֪x����ȷ��Ψһ��y 
    return y_test;//���ؼ��������y 
}
int main(){
    double X[2],Y[2];//������������ ��xΪx���ϵ����ݣ�y��Ϊy�ϵ����� 
    printf("Input x1 y1 x2 y2 : ");//��ʾ���� 
    scanf("%lf %lf %lf %lf",&X[0],&Y[0],&X[1],&Y[1]);//����4���� ����Ϊ��������� 
    fit(X,Y);//ִ�к���fit ��������������γ�ֱ�ߵ�б�ʺ�y���ϵĽؾ� 
    printf("Tranining result : omege = %lf,b=%lf\n\n",lm.omega,lm.b);//������� 
    double x,y;//������������ 
    printf("Input x:");//��ʾ����x 
    scanf("%lf",&x);//����x 
    y=predict(x);//ִ��predict���� ,�������y 
    printf("Predict result : x=%.2lfƽ��,y%.2lf��Ԫ\n",x,y);//��Ԥ��Ľ��������� 
    return 0;

}
