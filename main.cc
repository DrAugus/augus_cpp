#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <type_traits> // std::is_same_v

#include "gtest/gtest.h"

int hhh(int &a) {
    a++;
    printf("---a---%d", a);
    return a;
}

int jjj() {
    int a = 6;
    int answer = sizeof(hhh(a));
    auto fuc = [&](int a) { return a++; };
    printf("a##%d answer###%d", a, answer);
    return 0;
}

int global_a = 4;

int &f(int x) {
    global_a = global_a + x;
    return global_a;
}


/* max_element
 * min_element
 * assign
 * reverse
 * wstring_convert
 * */



void declare() {
    int i;
    int a[100];
    for (i = 0; i < 100; i++) {
        a[i] = i;
    }
}

void print() {
    int i;
    int a[100];
    for (i = 0; i < 100; i++) {
        printf("%d ", a[i]);
    }
}


class Solution {
public:
    static int cutBar(int n, int m) {
        int slices = 1;
        int cnt = 0;
        while (slices < n) {
            ++cnt;
            slices += std::min(slices, m);
        }
        return cnt;
    }
};

void convolution(const double *input1, const double *input2, double *output, int mm, int nn) {
    auto *xx = new double[mm + nn - 1];
    // do convolution
    for (int i = 0; i < mm + nn - 1; i++) {
        xx[i] = 0.0;
        for (int j = 0; j < mm; j++) {
            if (i - j >= 0 && i - j < nn) {
                xx[i] += input1[j] * input2[i - j];
            }
        }
    }
    // set value to the output array
    for (int i = 0; i < mm + nn - 1; i++) {
        output[i] = xx[i];
    }
    delete[] xx;
}

int frogClimb(int m, int n, int h) {
    int day = 0;
    while (h - n > 0) { // 昨天还没爬出去
        h -= m;//白天爬了m
        ++day;
        h += n;//夜里掉了n
    }
    return day;
}

std::array<int, 6> getAverage(std::array<int, 30> arr) {
    std::array<int, 6> res{0};
    int idx = 0;
    for (int i = 0; i < arr.size();) {
        for (int j = i; j < 5; ++j) {
            res[idx] += arr[j];
        }
        ++idx;
        i += 5;
    }
    return res;
}

int getAverage() {

    int arr[30];
    for (int i = 0; i < 30; ++i) {
        arr[i] = 2 * (i + 1);
        if (i % 5 == 2) {
            printf("%d ", arr[i]);
        }
    }
//    int got[6] = {2, 7, 12, 17, 22, 27};
//    for (int i = 0; i < 6; ++i) {
//        printf("%d ", arr[got[i]]);
//    }


//    int res[6] = {0};
//    int idx = 0;
//    for (int i = 0; i < 30;) {
//        for (int j = i; j < i + 5; ++j) {
//            res[idx] += arr[j];
//        }
//        res[idx] /= 5;
//        ++idx;
//        i += 5;
//    }
//
//    for (auto i : res) {
//        std::cout << res[i] << " ";
//    }
//    std::cout << "\n";

    return 0;
}


// lambda 重载 在c++17实现
constexpr auto translate = [](auto idx) {
    if constexpr (std::is_same_v<decltype(idx), int>) {
        constexpr static int table[8]{7, 6, 5, 4, 3, 2, 1, 0};
        return table[idx];
    } else if constexpr (std::is_same_v<decltype(idx), char>) {
        std::map<char, int> table{{'a', 0},
                                  {'b', 1},
                                  {'c', 2},
                                  {'d', 3},
                                  {'e', 4},
                                  {'f', 5},
                                  {'g', 6},
                                  {'h', 7}};
        return table[idx];
    }
};


int main(int argc, char *argv[]) {
    std::string Kyaneos = "Kyaneos-Kyaneos-Kyaneos-Kyaneos--";

    std::cout << Kyaneos << std::endl;


    std::string maskWord = "ss3";
    std::string maskStr(8, maskWord[0]);
    std::cout << maskWord[0] << std::endl;
    std::cout << maskStr << std::endl;

    std::wstring ssss = L"shit";
    std::string result;

    result.assign((char *) ssss.data(), ssss.size() * 2);

    std::wcout << ssss << std::endl;
    std::wcout << ssss.data() << std::endl;
    std::wcout << (char *) ssss.data() << std::endl;
    std::wcout << ssss.size() * 2 << std::endl;

    std::cout << ssss.data() << std::endl;
    std::cout << (char *) ssss.data() << std::endl;
    std::cout << ssss.size() * 2 << std::endl;

    std::cout << result << std::endl;


    std::vector<int> vec{0, 5, 2, 9, 7, 6, 1, 3, 4, 8};

    size_t compCounter = 0;
    std::sort(vec.begin(), vec.end(), [&compCounter](int a, int b) {
        ++compCounter;
        return a < b;
    });

    std::cout << "number of comparisons: " << compCounter << '\n';

    for (auto &v: vec)
        std::cout << v << ", ";


    getAverage();


    std::string s090 = "he sheef";
    std::cout << s090 << std::endl;
    s090 = s090.substr(s090.find(' '), *(s090.end()));
    std::cout << s090 << std::endl;


    std::cout << frogClimb(2, 1, 10) << std::endl;

    static std::default_random_engine randE(time(0));
    static std::uniform_int_distribution<uint64_t> randValue(0, 50);
    static const auto getValue = [&]() { return randValue(randE); };

    for (std::size_t i = 0; i != 3; ++i) {
        std::cout << getValue() << std::endl;
    }

    //以10分为一个分数段统计成绩
    std::vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }

    std::string s1 = "Hello World";
    std::cout << "s1 is \"Hello World\"" << std::endl;
    const std::string &s2 = s1;
    std::cout << "s2 is initialized by s1" << std::endl;
    std::string s3(s1);
    std::cout << "s3 is initialized by s1" << std::endl;
    // compare by '=='
    std::cout << "Compared by '==':" << std::endl;
    std::cout << "s1 and \"Hello World\": " << (s1 == "Hello World") << std::endl;
    std::cout << "s1 and s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 and s3: " << (s1 == s3) << std::endl;
    // compare by 'compare'
    std::cout << "Compared by 'compare':" << std::endl;
    std::cout << "s1 and \"Hello World\": " << !s1.compare("Hello World") << std::endl;
    std::cout << "s1 and s2: " << !s1.compare(s2) << std::endl;
    std::cout << "s1 and s3: " << !s1.compare(s3) << std::endl;



//  return Solution::cutBar(8, 2);

    declare();
    print();





//    int t = 5;
//    cout << f(t) << endl;
//    f(t) = 20;
//    cout << f(t) << endl;
//    t = f(t);
//    cout << f(t) << endl;

    jjj();


//    char a[] = "hello";
//    a[0] = 'X';
//    char *p = "world"; // 注意p 指向常量字符串
//    p[0] = 'X'; // 编译器不能发现该错误，运行时错误

//  char a[] = "hello world";
//  char *p = a;
//  cout << sizeof(a) << endl; // 12 字节
//  cout << sizeof(p) << endl; // 4 字节
//
//  printf("\n");



    return 0;
}


