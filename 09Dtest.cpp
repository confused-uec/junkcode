/** 09Dtest.cpp **/

//コンパイル
//  g++ -o 09Dtest 09Dtest.cpp

//実行
//  ./09Dtest -n 3 -l 10
// -n 出力パターンの行数(default:1)
// -l 出力パターンの長さ(default:10)

#include <iostream>
#include <random>
#include <getopt.h>

int main(int argc, char **argv){
    int n=1,l=10;
    char c;
    while(c = getopt(argc,argv,"n:l:"),c!=-1){
        switch(c){
            case 'n':
                n = atoi(optarg);
                break;
            case 'l':
                l = atoi(optarg);
                break;
        }
    }

    //乱数発生器の初期化
    std::random_device seedGenerater;
    std::mt19937 engine(seedGenerater());
    /** 連続一様分布を生成 **/
    std::uniform_int_distribution<int> dist(0, 3);
    char ATGC[] = {'A','T','G','C'};

    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            std::cout << ATGC[dist(engine)];
        }
        std::cout << std::endl;
    }
    return 0;
}