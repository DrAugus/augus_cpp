//
// Created by AUGUS on 2021/12/27.
//

#include <memory>
#include <iostream>

// 3.
// ��д����B����������C���ֱ���������Ķ���������麯�������麯�����������������ʱ�б𲢴�ӡ����������������ƣ�
//     ��1�� �����ָ��ָ��������
//     ��2�� �������ָ��ָ�����������
//     ��3�������ָ��ָ�����������

struct BasicB;
using basic_sptr = std::shared_ptr<BasicB>;

struct BasicB {
    BasicB() = default;
    ~BasicB() = default;
    virtual void fucku() { std::cout << "fuck\n"; }
    void fuck2() { std::cout << "fuck2b\n"; }
    static basic_sptr instance();
};

struct SonC;
using son_sptr = std::shared_ptr<SonC>;

struct SonC : public BasicB {
    SonC() = default;
    ~SonC() = default;
    void fucku() override { std::cout << "fuck again\n"; }
    void fuck2() { std::cout << "fuck2c\n"; }
    static son_sptr instance();
};

basic_sptr BasicB::instance() {
    static basic_sptr b_sptr = nullptr;
    if (b_sptr == nullptr) {
        b_sptr = std::make_shared<BasicB>();
    }
    return b_sptr;
}

son_sptr SonC::instance() {
    static son_sptr c_sptr = nullptr;
    if (c_sptr == nullptr) {
        c_sptr = std::make_shared<SonC>();
    }
    return c_sptr;
}
