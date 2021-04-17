#include "file_utility.hpp"
static const int SIZE = 4;
static const char *file_path[SIZE] = { "./test0.bin",       // 1545KB
                                       "./test1.bin",       // 976Bytes
                                       "./test2.bin",       // 120KB
                                       "./test3.bin" };     // 496Bytes
int main() {
    int test_loop = 10;
    // no tcmalloc:3.2s tcmalloc:2.531s
    /*for (int i = 0;i < test_loop;i++) {
        std::string str;
        if (G_FILE_UTILITY.get_file_content(file_path[0], str)) {
            char *p = new char[str.size()];
            memcpy(p, str.c_str(), str.size());
            delete []p;
        }
    }*/
    test_loop = 10000;
    // no tcmalloc:1.83s tcmalloc:1.54s
    /*for (int i = 0;i < test_loop;i++) {
        std::string str;
        if (G_FILE_UTILITY.get_file_content(file_path[1], str)) {
            char *p = new char[str.size()];
            memcpy(p, str.c_str(), str.size());
            delete []p;
        }
    }*/
    /*test_loop = 100;
    // no tcmalloc:1.73s tcmalloc:1.72s
    for (int i = 0;i < test_loop;i++) {
        std::string str;
        if (G_FILE_UTILITY.get_file_content(file_path[2], str)) {
            char *p = new char[str.size()];
            memcpy(p, str.c_str(), str.size());
            delete []p;
        }
    }*/
    test_loop = 10000;
    // no tcmalloc:0.83s tcmalloc:0.86s
    for (int i = 0;i < test_loop;i++) {
        std::string str;
        if (G_FILE_UTILITY.get_file_content(file_path[3], str)) {
            char *p = new char[str.size()];
            memcpy(p, str.c_str(), str.size());
            delete []p;
        }
    }

    return 0;
}