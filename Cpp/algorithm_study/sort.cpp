/**
 * 排序算法
 */
#include <iostream>
#include <gtest/gtest.h>
using namespace std;


/**
 * 打印数组
 */
void showArray(int a[], int len) {
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}



/**
 * 快速排序（递归结构）
 * 三 while(i_front < i_back)
 */
void QuickSort(int* a, int len) {
    int t;
    int i_center;   // 中轴元素下标
    int i_front, i_back;

    if (a == NULL)
        return;
    if (len <= 1)
        return;

    i_center = 0;
    i_front = 0;
    i_back = len - 1;
    while (i_front < i_back) {
        // 从后往前找比中轴元素小的元素
        while (i_front < i_back) {
            // 找到后就和中轴元素交换
            if(a[i_center] > a[i_back]) {
                t = a[i_center];
                a[i_center] = a[i_back];
                a[i_back] = t;
                i_center = i_back;
                break;
            }
            i_back--;
        }

        // 从前往后找比中轴元素大的元素
        while (i_front < i_back) {
            if(a[i_center] < a[i_front]) {
                t = a[i_center];
                a[i_center] = a[i_front];
                a[i_front] = t;
                i_center = i_front;
                break;
            }
            i_front++;
        }
    }
    QuickSort(a, i_center+1);   // 对数组左边进行快速基排序
    QuickSort(a + i_center + 1, len - (i_center+1));    // 对数组右边进行快速基排序
}

/**
 * 冒泡排序
 */
void BubbleSort(int* a, int len) {
    int i, j, t;

    // 外层 for 循环表示进行多少次冒泡基排序
    for (i = 0; i < len-1; i++) {
        // 冒泡基排序
        // j 代表要进行比较的元素下标
        for (j = 0; j < len-i-1; j++) {
            if (a[j] > a[j+1]) {
               t = a[j];
               a[j] = a[j+1];
               a[j+1] = t;
            }
        }
    }
}

/**
 * 归并排序（递归形式）
 */
void MergeSort(int a[], int len) {
    if (a == NULL || len <= 1)
        return;

    printf("before:len=%d\n", len);
    showArray(a, len);

    // 如果数组只有两个数，判断大小进行交换
    if (len == 2) {
        if (a[0] > a[1]) {
            int t = a[0];
            a[0] = a[1];
            a[1] = t;
        }
    }

    // 分
    int mid = len / 2;
    MergeSort(a, mid);  // 对左半边数组进行归并基排序
    MergeSort(a+mid, len-mid);  // 对右半边数组进行归并基排序

    // 合并两个有序的数组
    int i, j, k;
    int b[len];
    i = 0, j = mid, k = 0;
    while (k < len) {
        // 两个排序好的子数组挨个比较
        if (i < mid && j < len) {
            if(a[i] < a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
            continue;
        }
        // 左半边子数组还有剩余未被合并的
        if (i < mid) {
            b[k++] = a[i++];
            continue;
        }
        // 右半边子数组还有剩余未被合并的
        if (j < len) {
            b[k++] = a[j++];
        }
    }
    memcpy(a, b, sizeof(int)*len);
    printf("after:len=%d\n", len);
    showArray(a, len);
}

/**
 * 归并排序，迭代形式
 */
void mergeSort_1(int a[], int len) {
    if (a == NULL || len <= 1)
        return;

    printf("before:len=%d\n", len);
    showArray(a, len);

    // 如果数组只有两个数，判断大小进行交换
    if (len == 2) {
        if (a[0] > a[1]) {
            int t = a[0];
            a[0] = a[1];
            a[1] = t;
        }
        return;
    }

    // TODO
    int b[len];
    int i, j, k, subLen;
    k = 0;
    subLen = 1;
    while (subLen < len) {
        i = 0;
        k = 0;
        while(i + subLen < len) {
            j = i + subLen;

            i = j + subLen;
        }
        subLen *= 2;
    }
}

/**
 * 测试冒泡排序
 */
TEST(testcase0, test_BubbleSort) {
    int data_1[10] = {1,2,3,4,5,6,7,8,9,0};
    int data_2[10] = {1,0,3,4,5,6,7,8,9,2};
    int data_3[10] = {1,2,3,4,7,6,5,8,9,0};
    int data_4[10] = {0,9,8,7,6,5,4,3,2,1};
    int expect[10] = {0,1,2,3,4,5,6,7,8,9};

    BubbleSort(data_1, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_1, expect, 10 * sizeof(int)), 0);

    BubbleSort(data_2, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_2, expect, 10 * sizeof(int)), 0);

    BubbleSort(data_3, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_3, expect, 10 * sizeof(int)), 0);

    BubbleSort(data_4, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_4, expect, 10 * sizeof(int)), 0);
}


/**
 * 测试快速排序
 */
TEST(testcase0, test_QuickSort) {
    int data_1[10] = {1,2,3,4,5,6,7,8,9,0};
    int data_2[10] = {1,0,3,4,5,6,7,8,9,2};
    int data_3[10] = {1,2,3,4,7,6,5,8,9,0};
    int data_4[10] = {0,9,8,7,6,5,4,3,2,1};
    int expect[10] = {0,1,2,3,4,5,6,7,8,9};

    QuickSort(data_1, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_1, expect, 10 * sizeof(int)), 0);

    QuickSort(data_2, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_2, expect, 10 * sizeof(int)), 0);

    QuickSort(data_3, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_3, expect, 10 * sizeof(int)), 0);

    QuickSort(data_4, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_4, expect, 10 * sizeof(int)), 0);
}

/**
 * 测试归并排序
 */
TEST(testcase0, test_MergeSort) {
    int data_1[10] = {1,2,3,4,5,6,7,8,9,0};
    int data_2[10] = {1,0,3,4,5,6,7,8,9,2};
    int data_3[10] = {1,2,3,4,7,6,5,8,9,0};
    int data_4[10] = {0,9,8,7,6,5,4,3,2,1};
    int expect[10] = {0,1,2,3,4,5,6,7,8,9};

    MergeSort(data_1, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_1, expect, 10 * sizeof(int)), 0);

    MergeSort(data_2, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_2, expect, 10 * sizeof(int)), 0);

    MergeSort(data_3, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_3, expect, 10 * sizeof(int)), 0);

    MergeSort(data_4, 10);
    // memcmp 按字节进行比较，全部字节相等则返回 0
    EXPECT_EQ(memcmp(data_4, expect, 10 * sizeof(int)), 0);

}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}