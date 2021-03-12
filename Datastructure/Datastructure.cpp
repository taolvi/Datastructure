#include <iostream>
#include <list>
using namespace std;

template<typename T>
void printList(list<T> l)
{
    for (const auto& element : l) {
        cout << element << endl;
    }
}

template<typename T>
list<T> getUnion(list<T> l1, list<T> l2) // 求已排序元素的并集
{
    if (l1.empty() && l2.empty())
        return list<T>();
    auto iter1 = l1.cbegin();
    auto end1  = l1.cend();
    auto iter2 = l2.cbegin();
    auto end2  = l2.cend();
    list<T> result;
    while (iter1 != end1 && iter2 != end2) {
        if (*iter1 < *iter2) {
            result.push_back(*iter1);
            ++iter1;
        }
        else if (*iter2 < *iter1) {
            result.push_back(*iter2);
            ++iter2;
        }
        else {
            result.push_back(*iter1);
            ++iter1;
            ++iter2;
        }
    }
    while (iter1 != end1)
    {
        result.push_back(*iter1++);
    }
    while (iter2 != end2)
    {
        result.push_back(*iter2++);
    }
    
    return result;
}

template<typename T>
list<T> getIntersection(list<T> l1, list<T> l2) // 求已排序元素的交集
{
    if (l1.empty() && l2.empty())
        return list<T>();
    auto iter1 = l1.cbegin();
    auto end1 = l1.cend();
    auto iter2 = l2.cbegin();
    auto end2 = l2.cend();
    list<T> result;
    while (iter1 != end1 && iter2 != end2) {
        if (*iter1 < *iter2) {
            ++iter1;
        }
        else if (*iter2 < *iter1) {
            ++iter2;
        }
        else {
            result.push_back(*iter1);
            ++iter1;
            ++iter2;
        }
    }
    return result;
}

int main()
{
    list<int> l1 = { 1,4,6,9,10,23,45 };
    list<int> l2 = { 2,3,4,5,5,7,8,10,23,45,56,70 };
    auto u = getIntersection(l1, l2);
    printList(u);

    std::cout << "Hello World!\n";
}
