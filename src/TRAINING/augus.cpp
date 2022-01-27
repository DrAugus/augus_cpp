//
// Created by AUGUS on 2021/12/16.
//

#include "augus/augus.h"
#include "gtest/gtest.h"

using namespace augus;

//�ⲻ����replace��
void augus::AugusUtils::TrimStr(std::string &s, char str) {
    std::string::size_type index = 0;
    if (!s.empty()) {
        while ((index = s.find(str, index)) != std::string::npos) {
            s.erase(index, 1);
        }
    }
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
}


/**
 * ƴ��int
 */
std::string augus::JsonCombine::GetKeyValue(const std::string &str_key, int i_value) {
    char tag[] = "\"";
    char colon[] = ":";
    char value[50] = {0};

    std::string str_res;

    str_res.append(tag);
    str_res.append(str_key);
    str_res.append(tag);

    str_res.append(colon);
    sprintf(value, "%d", i_value);
    str_res.append(value);

    return str_res;
}

/**
 * ƴ��float������3λ
 */
std::string augus::JsonCombine::GetKeyValue(const std::string &str_key, float f_value) {
    char tag[] = "\"";
    char colon[] = ":";
    char value[50] = {0};

    std::string str_res;

    str_res.append(tag);
    str_res.append(str_key);
    str_res.append(tag);

    str_res.append(colon);
    sprintf(value, "%0.3f", f_value);
    str_res.append(value);

    return str_res;
}

/**
 * ƴ��string
 */
std::string augus::JsonCombine::GetKeyValue(const std::string &str_key, const std::string &str_value) {
    char tag[] = "\"";
    char colon[] = ":";
    std::string str_res;

    str_res.append(tag);
    str_res.append(str_key);
    str_res.append(tag);

    str_res.append(colon);
    str_res.append(tag);
    str_res.append(str_value);
    str_res.append(tag);

    return str_res;
}

/**
 * ƴ��object
 */
std::string augus::JsonCombine::GetKeyValueObject(const std::string &str_key, const std::string &str_obj) {
    char tag[] = "\"";
    char colon[] = ":";
    std::string str_res;

    str_res.append(tag);
    str_res.append(str_key);
    str_res.append(tag);

    str_res.append(colon);
    str_res.append(str_obj);

    return str_res;
}

/**
 * ƴ��array
 */
std::string augus::JsonCombine::GetKeyValueArray(const std::string &str_key, const std::string &str_arr) {
    char tag[] = "\"";
    char colon[] = ":";
    std::string str_res;

    str_res.append(tag);
    str_res.append(str_key);
    str_res.append(tag);

    str_res.append(colon);
    str_res.append("[");
    str_res.append(str_arr);
    str_res.append("]");

    return str_res;
}

void augus::JsonCombine::use() {
    int value1 = 1;
    float value2 = 1.0f;
    std::string str_json_res("{");
    str_json_res.append(GetKeyValue("key1", value1));
    str_json_res.append(",");
    str_json_res.append(GetKeyValue("key2", value2));
    str_json_res.append("}");

    PrintTest(str_json_res);
}

TEST(JsonCombine, use) {
    auto JC = new augus::JsonCombine;
    JC->use();
}


//���������㷨����ֱ�ӽ����ڵ㣬ʱ�临�Ӷ�O��n^2��,�ռ临�Ӷ�O��1����
ListNode *ListSort::insertionSortList(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if (head == nullptr || head->next == nullptr)return head;
    ListNode *p = head->next, *pstart = new ListNode(0), *pend = head;
    pstart->next = head; //Ϊ�˲������㣬���һ��ͷ���
    while (p != nullptr) {
        ListNode *tmp = pstart->next, *pre = pstart;
        while (tmp != p && p->val >= tmp->val) //�ҵ�����λ��
        {
            tmp = tmp->next;
            pre = pre->next;
        }
        if (tmp == p)pend = p;
        else {
            pend->next = p->next;
            p->next = tmp;
            pre->next = p;
        }
        p = pend->next;
    }
    head = pstart->next;
    delete pstart;
    return head;
}

//ѡ�������㷨��ֻ�ǽ����ڵ��valֵ��ʱ�临�Ӷ�O��n^2��,�ռ临�Ӷ�O��1����
ListNode *ListSort::selectSortList(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //ѡ������
    if (head == nullptr || head->next == nullptr)return head;
    ListNode *pstart = new ListNode(0);
    pstart->next = head; //Ϊ�˲������㣬���һ��ͷ���
    ListNode *sortedTail = pstart;//ָ�����ź���Ĳ��ֵ�β��

    while (sortedTail->next != nullptr) {
        ListNode *minNode = sortedTail->next, *p = sortedTail->next->next;
        //Ѱ��δ���򲿷ֵ���С�ڵ�
        while (p != nullptr) {
            if (p->val < minNode->val)
                minNode = p;
            p = p->next;
        }
        std::swap(minNode->val, sortedTail->next->val);
        sortedTail = sortedTail->next;
    }

    head = pstart->next;
    delete pstart;
    return head;
}


//�鲢�����㷨��������ڵ㣬ʱ�临�Ӷ�O��nlogn��,�����ǵݹ�ջ�ռ�Ļ��ռ临�Ӷ���O��1����
//
//�����ÿ���ָ��ķ����ҵ������м�ڵ㣬Ȼ��ݹ�Ķ��������������򣬰������ź����������ϲ���һ������������鲢����Ӧ����������������ѵ�ѡ���ˣ���֤����ú��ʱ�临�Ӷȶ���nlogn�������������������й���ڸ���Ŀռ临�Ӷ�������������Ҳ��O(n)������O(1)
ListNode *ListSort::mergeSortList(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //����鲢����
    if (head == NULL || head->next == NULL)return head;
    else {
        //����ָ���ҵ��м�ڵ�
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
//                fast = sortList(head);//ǰ�������
//                slow = sortList(slow);//��������
        return merge(fast, slow);
    }

}

// merge two sorted list to one
ListNode *ListSort::merge(ListNode *head1, ListNode *head2) {
    if (head1 == NULL)return head2;
    if (head2 == NULL)return head1;
    ListNode *res, *p;
    if (head1->val < head2->val) {
        res = head1;
        head1 = head1->next;
    } else {
        res = head2;
        head2 = head2->next;
    }
    p = res;

    while (head1 != NULL && head2 != NULL) {
        if (head1->val < head2->val) {
            p->next = head1;
            head1 = head1->next;
        } else {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if (head1 != NULL)p->next = head1;
    else if (head2 != NULL)p->next = head2;
    return res;
}


//ð�������㷨��������ڵ�valֵ��ʱ�临�Ӷ�O��n^2��,�ռ临�Ӷ�O��1����
ListNode *ListSort::bubbleSortList(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //�����������
    if (head == NULL || head->next == NULL)return head;
    ListNode *p = NULL;
    bool isChange = true;
    while (p != head->next && isChange) {
        ListNode *q = head;
        isChange = false;//��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
        for (; q->next && q->next != p; q = q->next) {
            if (q->val > q->next->val) {
                std::swap(q->val, q->next->val);
                isChange = true;
            }
        }
        p = q;
    }
    return head;
}

//����ϣ��������Ϊ��������о����漰��arr[i+gap]����������gapΪϣ������ĵ�ǰ���������ֲ������ʺ�����
//
//���ڶ�����һ������������ʵ�ֶ���ѣ���Ȼ�����ö�������ʵ�֣�������ô��̫�鷳�����û��Ѷ���Ŀռ乹��������


ListSortPtr ListSort::instance() {
    static ListSortPtr ptr = nullptr;
    if (ptr == nullptr) {
        ptr = std::make_shared<ListSort>();
    }
    return ptr;
}


MathPtr Math::instance() {
    static MathPtr ptr = nullptr;
    if (ptr == nullptr) {
        ptr = std::make_shared<Math>();
    }
    return ptr;
}


TEST(Math, gcd) {
    auto p = Math::instance();
    EXPECT_EQ(p->gcd(49, 28), 7);
}

//����������ֲ�ģ����
//���ȷֲ���
// uniform_int_distribution �������ȷ�
// uniform_real_distribution ���������ȷֲ�
//ע�⣬uniform_int_distribution��������ķ�Χ���ǰ뿪��Χ[ )������[ ]������uniform_real_distributionȴ�ǰ뿪��Χ[ )��
//��Ŭ�����ͷֲ���������yes/no���ֽ��������һ��p��һ��1-p��
// bernoulli_distribution ��Ŭ���ֲ�
// binomial_distribution ����ֲ�
// geometry_distribution ���ηֲ�
// negative_biomial_distribution ������ֲ�
//Rate-based distributions:
// poisson_distribution ���ɷֲ�
// exponential_distributionָ���ֲ�
// gamma_distribution ٤��ֲ�
// weibull_distribution �������ֲ�
// extreme_value_distribution ��ֵ�ֲ�
//��̬�ֲ���أ�
// normal_distribution ��̬�ֲ�
// chi_squared_distribution�����ֲ�
// cauchy_distribution �����ֲ�
// fisher_f_distribution ��Ъ��F�ֲ�
// student_t_distribution t�ֲ�
//�ֶηֲ���أ�
// discrete_distribution��ɢ�ֲ�
// piecewise_constant_distribution�ֶγ����ֲ�
// piecewise_linear_distribution�ֶ����Էֲ�
void Math::getRand() {
    //����random_device����sd������
    std::random_device sd;
    //ʹ�����ӳ�ʼ��linear_congruential_engine����
    // Ϊ����ʹ��������������������ֲ�������������������ֲ�.
    // ע������Ҫʹ��()����������Ϊminst_rand()���ܵ���һ��ֵ������srandҲ�Ǹ���������һ��ֵ��
    std::minstd_rand linearRan(sd());
    //����01����
    std::uniform_int_distribution<int> dis1(0, 1);
    std::cout << "\nuniform_int_distribution:";
    for (int i = 0; i < 100; i++) {
        //ʹ��linear engine�����ӣ�
        // ע�����ﴫ��Ĳ���һ��ֵ����һ������:
        // ������ֲ�������Ҫ����һ�������������Ϊ��������ʵrandom_deviceҲ��һ�����棬�����sd����Ҳ�������
        std::cout << dis1(linearRan) << " ";
    }
    std::cout << "\n";
}



