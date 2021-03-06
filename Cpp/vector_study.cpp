#include <vector>
#include <iostream>
using namespace std;

void print_vector(vector<int> v) {
    for (vector<int>::iterator it=v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * 列表的创建
 */
void test_1() {
    // 容量为 10
    vector<int> v1(10);
    print_vector(v1);
    cout << endl;

    // 容量，每个元素初始值
    vector<int> v2(10, 1);
    print_vector(v2);
    cout << endl;

    // 从数组中获取值
    int a[] = {1,2,3,4,5};
    vector<int> v3(a, a+5);
    print_vector(v3);
    cout << endl;

    // 如果 first 和 last 地址相同，则新 vector 为空
    vector<int> v6(a, a);
    printf("v6:");
    print_vector(v6);
    cout << endl;

    // 类似数组的写法
    vector<int> v4{3,5,2,6,4};
    print_vector(v4);
    cout << endl;

    // 创建数组写法
    vector<int> v5 = {1,2,3,4,5};
    print_vector(v5);
    cout << endl;


}


/**
 * 插入元素，容量不足时，容量乘 2 扩大
 */
void test_2() {
    int a[10] = {4,5,6,3,1,2,9,8,7,0};

    // 容量为 10，并且全部初始化为 1
    vector<int> v1(10, 1);
    print_vector(v1);
    // 存量 vs 容量
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;

    // 末尾插入元素
    v1.push_back(5);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;

    // 插入一个数组
    v1.insert(v1.end(), a, a+10);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;

    v1.push_back(6);
    v1.push_back(7);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;
}

/**
 * 访问元素
 */
void test_3() {
    // 像数组一样访问
    int a[] = {1,2,3,4,5};
    vector<int> v1(a, a+5);
    cout << a[0] << " " << a[1] << endl;
}

/**
 * 判断 vector 相等
 */
void test_4() {
    int a1[] = {1,2,3,4,5};
    vector<int> v1(a1, a1+5);
    int a2[] = {1,2,3,4,5};
    vector<int> v2(a2, a2+5);
    vector<int> v3(a1, a1+4);

    if (v1 == v2) {
        cout << "v1 == v2" << endl;
    }
    if (v1 == v3) {
        cout << "v1 == v3" << endl;
    }
}


int main() {
    test_1();

    return 0;
}