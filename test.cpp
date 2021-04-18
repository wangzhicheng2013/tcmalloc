#include <stdio.h>
#include <string.h>
#include <iostream>
#include "time_elapse.hpp"
int SIZE100 = 100;
int SIZE500 = 500;
int SIZE800 = 800;
int SIZE1000 = 1000;
int SIZE1600 = 1600;

void test_tcmalloc(const std::string &str) {
    int test_loop = 10000000;    // 循环一亿次
    for (int i = 0;i < test_loop;i++) {
        char *p = new char[str.size()];
        memcpy(p, str.c_str(), str.size());
        delete []p;
    }
}
int main() {
    std::string str100(SIZE100, 'a');
    std::string str500(SIZE500, 'a');
    std::string str800(SIZE800, 'a');
    std::string str1000(SIZE1000, 'a');
    std::string str1600(SIZE1600, 'a');

    const int loop = 6;
    double avg = 0;
    time_elapse te;
    for (int i = 0;i < loop;i++) {
        te.start();
        test_tcmalloc(str100);
        avg += te.end();
    }
    std::cout << "100 byes:" << avg / loop << "s" << std::endl;
    
    avg = 0;
    for (int i = 0;i < loop;i++) {
        te.start();
        test_tcmalloc(str500);
        avg += te.end();
    }
    std::cout << "500 byes:" << avg / loop << "s" << std::endl;

    avg = 0;
    for (int i = 0;i < loop;i++) {
        te.start();
        test_tcmalloc(str800);
        avg += te.end();
    }
    std::cout << "800 byes:" << avg / loop << "s" << std::endl;

    avg = 0;
    for (int i = 0;i < loop;i++) {
        te.start();
        test_tcmalloc(str1000);
        avg += te.end();
    }
    std::cout << "1000 byes:" << avg / loop << "s" << std::endl;

    avg = 0;
    for (int i = 0;i < loop;i++) {
        te.start();
        test_tcmalloc(str1600);
        avg += te.end();
    }
    std::cout << "1600 byes:" << avg / loop << "s" << std::endl;

    return 0;
}