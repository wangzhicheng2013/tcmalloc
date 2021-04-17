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
    std::string str100('a', SIZE100);
    std::string str500('a', SIZE500);
    std::string str800('a', SIZE800);
    std::string str1000('a', SIZE1000);
    std::string str1600('a', SIZE1600);

    long sum = 0;
    time_elapse te;
    te.start();
    test_tcmalloc(str100);
    std::cout << "100 byes:" << te.end() << "s" << std::endl;

    te.start();
    test_tcmalloc(str500);
    std::cout << "500 byes:" << te.end() << "s" << std::endl;

    te.start();
    test_tcmalloc(str800);
    std::cout << "800 byes:" << te.end() << "s" << std::endl;

    te.start();
    test_tcmalloc(str1000);
    std::cout << "1000 byes:" << te.end() << "s" << std::endl;

    te.start();
    test_tcmalloc(str1600);
    std::cout << "1600 byes:" << te.end() << "s" << std::endl;

    return 0;
}