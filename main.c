#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
void nhapMang(int n, double a[],int index[]){
    printf("Nhap x: ");
    for(int i=0; i<n; i++){
        scanf("%d",index+i);
    }
    printf("Nhap p: ");
    int ts[n],ms[n];
    for(int i=0; i<n; i++){
        scanf("%d%d",ts+i,ms+i);
    }
    for(int i=0; i<n; i++){
        a[i]=(double)ts[i]/ms[i];
    }
}
void xuatMang(int n, double a[],int index[]){
    printf("Mang x: \n");
    for(int i=0; i<n; i++){
        printf("%5d ",index[i]);
    }
    printf("\nNhap p: \n");
    for(int i=0; i<n; i++){
        printf("%3.2lf ",a[i]);
    }
}
double timKyVong(int n, double a[],int index[]){
    double avg=0;
    for(int i=0; i<n; i++){
        avg+= a[i]*index[i];
    }
    return avg;
}
int timTrungVi(int n, double a[], int index[]){
    int vt=-1;
    double sum=0;
    while (sum<=0.5){
        sum+=a[++vt];
    }
    return index[vt-1];
}
double timEX2(int n,double a[], int index[]){
    double Dx=0;
    for(int i=0; i<n; i++){
        Dx+= a[i]*index[i]*index[i];
    }
    return Dx;
}
int timMod(int n, double a[], int index[]){
    double max=a[0];
    int vt = 0;
    for (int i=1; i<n; i++){
        if (max<a[i]) {max=a[i]; vt= i;}
    }
    return index[vt];
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    double a[n];
    int index[n];
    nhapMang(n,a,index);
    xuatMang(n,a,index);
    printf("\nKy vong = %lf\n",timKyVong(n,a,index));
    printf("E(X^2) = %lf\n",timEX2(n,a,index));
    printf("Phuong sai = %lf\n",timEX2(n,a,index)-timKyVong(n,a,index)*timKyVong(n,a,index));
    printf("Trung vi = %d\n",timTrungVi(n,a,index));
    printf("Mod = %d\n",timMod(n,a,index));
    return 0;
}
