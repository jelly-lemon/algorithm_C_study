/*
 * 学习 C++ 字符串的使用以及对象的创建方式
 */
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

/**
 * string 对象创建
 */
void test_1() {
    // 这是创建了一个对象吗？对，s5 就是该对象的首地址（个人理解）
    string s1; // string s1() 写法不能创建一个对象，空参数被当作函数声明，和 Java 不同
    cout << "s1:" << s1 << endl;

    string s2("Hello");
    cout << "s2:" << s2 << endl;

    // 重复次数
    string s3(4, 'K');
    cout << "s3:" << s3 << endl;

    // 取子串
    string s4("12345", 1, 3);
    cout << "s4:" << s4 << endl;

    string s6;
    s6 = "Ni hao";
    cout << "s6:" << s6 << endl;
    cout << "s6 length= " << s6.length() << endl;

    // 在堆中开启空间
    string *s7 = new string("malloc in heap");
    cout << *s7 << endl;
    cout << "the value of pointer:" << s7 << endl;
    delete s7;
}

/**
 * string 与 char 的拼接
 */
void test_2() {
    string s1;
    char s2[] = "nihao";
    char s3[] = "hello";
    char s4[] = "\0\0";
    char *s5 = (char*)malloc(sizeof(char)*10);

    s1 += s2;
    s1 += s3;
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    // \0 不会影响字符串的长度
    // size 与 length 没有任何区别
    s1 += s4;
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    // 除了 \0，其余都会计入长度
    s1 += "\r\n";
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    // 释放原数组不会影响 s1，说明是复制了过去
    memcpy(s5, "googe\0", 6);
    s1 += s5;
    free(s5);
    cout << s1 << endl;

    // 取 string 首地址
    string s6("hello");
    printf("s6=%s\n", &s6[0]);
}

/**
 * 字符串查找
 */
void test_3() {
    int n;
    string s = "hello\r\nnihao\r\n\r\n";
    // 如果找到字串，返回首字母下标
    n = s.find("\r\n\r\n");
    cout << n << endl;

    // 如果查找不到字串，返回 -1
    n = s.find("abc");
    cout << n << endl;
}

/**
 * 字符串转数字
 */
void test_4() {
    string s(" 123");   // 即使字符串前面有空格也没关系
    int n = stoi(s);
    cout << n << endl;

    try {
        string s2("abc");
        n = stoi(s2);
        cout << n << endl;
    } catch (...) {
        // 捕获到任何异常都抛出
        throw ;
    }
}

/**
 * 字符串编码
 * string, char s[10] 都是字节串
 */
void test_5() {
    // 设置控制台编码为 UTF-8，默认为 GBK
    system("chcp 65001");

    // 文件编码为 UTF-8 时，char 数字存储“你好”：\344\275\240\345\245\275
    // 文件编码为 GBK 时，char 数字存储“你好”：\304\343\272\303
    // 所以，在文件中输入的字符串，C++ 中存储的是文件编码对应的字节
    // 打印到控制台时，我猜测 C++ 应该是直接把字节串传过去了
    char s[10] = "你好";
    cout << s << endl;

    string s1("你好");
    cout << s1 << endl;
}


/**
 * 字符串替换
 */
void test_6() {
    string s = "/abc/def/a/b/c";

    //替换所有指定子串
    int pos = 0;
    while((pos = s.find('/')) != -1){
        s.replace(pos, 1, "\\");
    }

    cout << s << endl;
}

int main() {
    test_6();

    return 0;
}