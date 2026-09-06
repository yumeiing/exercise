#include <thread>
#include <vector>
#include <mutex>
#include <iostream>
#include <cassert>

/* "std::cout" if not safe to thread
 * if you have c++23
 * you can use <print>
 * !: remeber change cmake file.
 */
#include <print>

std::vector<int> a(10000,0);
int n,num = 0;

void setup();
void add1();

int main()
{
    setup();
    //std::cout<<"setup over\n";
    std::println("setup over");
    add1();
}

void setup()
{
    //std::cout<<"请输入数字：";
    std::print("请输入数字：");
    std::cin>>n;
    while(n>a.size() || n<0)
    {
        //std::cout<<"请重新输入(1~10000)：";
        std::print("请重新输入(1~10000)：");
        std::cin>>n;
    }
}

void add1()
{
    if(num >= n) return ;

    std::thread tmp(add1);

    std::mutex m;
    auto id_class = std::this_thread::get_id();
    if(m.try_lock())
    {
        //std::cout<<id_class<<":get lock\n";
        std::println("{}:get lock",id_class);
        ++num;
        //std::cout<<"num:"<<id_class<<std::endl;
        std::println("num:{}",num);
        m.unlock();
        //std::cout<<id_class<<":unlock\n";
        std::println("{}:unlock",id_class);
    }
    else
    {
        //std::cout<<id_class<<":try_lock failed\n";
        std::println("{}:try_lock failed",id_class);
    }


    assert(tmp.joinable());
    tmp.join();
}
