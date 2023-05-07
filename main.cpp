//
// Created by Елизавета Кравченкова on 05.05.2023.
//
#include <iostream>
#include <math.h>

int G_1(int n,int k);
int G_0(int n,int k);
int G_2(int n,int k){
    if (k==1){
        return (n+1)/3;
    }
    return G_0(n,k-1)*((n+1)/3)+G_1(n,k-1)*((n+2)/3)+G_2(n,k-1)*((n)/3);
}
int G_1(int n,int k){
    if (k==1){
        return (n+2)/3;
    }
    return G_0(n,k-1)*((n+2)/3)+G_1(n,k-1)*((n)/3)+G_2(n,k-1)*((n+1)/3);
}
int G_0(int n,int k){
    if (k==1){
        return n/3;
    }
    return G_0(n,k-1)*((n)/3)+G_1(n,k-1)*((n+1)/3)+G_2(n,k-1)*((n+2)/3);
}

int main(int argc, char **argv) {
    if (argc<3){
        std::cerr<<"Недостаточно данных. Введите n и k";
        exit(1);
    }
    int n,k;
    n= std::stoi(argv[1]);
    k= std::stoi(argv[2]);

    std::cout<<G_0(n,k)+pow(n,k-1)- G_1(n,k-1);
}


