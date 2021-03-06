/**
 * 2021/4/16 阿里笔试题 1
 *
 * 翻转数组的逆序对数量
 *
 * 题目：
 * 数组从 1~n
 * 现在不断输入翻转起始、结束位置，对该区间进行翻转
 * 所有翻转都完毕后，求逆序对的数量
 * 只要前面的数字比后面的数字大，就算逆序对
 *
 * 输入：
 * n, k (数组长度，区间数量), 以及 k 个翻转区间
 *
 * 输出：逆序对数量
 *
 * 例如：
 *
 *
 */
#include <iostream>
using namespace std;

/**
 * 翻转给定区间的数组
 *
 * @param a 数组
 * @param l 起点
 * @param r 终点
 */
void reverse(int *a, int l, int r) {
    int i, j;
    int len = (r-l+1)/2;
    int count;
    for (count = 0, i = l-1, j = r-1; count < len; count++) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
}

/**
 * 获取翻转后的数组
 *
 * @param a 数组
 * @param n 数组长度
 * @return 翻转后的数组
 */
int getReverseMapNum(int *a, int n) {
    int count = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                count++;
            }
        }
    }
    return count;
}

/**
 * 打印数组
 *
 * @param a 数组
 * @param n 数组长度
 */
void printArray(int *a, int n) {
    int i;
    for(i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/**
 * 枚举法求解
 */
void test_0() {
    int i, n, k;
    int l, r;

    // 输入
    cin >> n >> k;

    // 初始化数组
    int *a = new int[n];
    for (i = 1; i <= n; i++) {
        a[i-1] = i;
    }
    // printArray(a, n);

    // 翻转数组
    for (i = 0; i < k; i++) {
        cin >> l >> r;
        reverse(a, l, r);
    // printArray(a, n);
    }

    // 求逆序对
    int count = getReverseMapNum(a, n);

    // 输出
    cout << count << endl;
    delete[] a;
}

int main() {
    test_0();
    return 0;
}

