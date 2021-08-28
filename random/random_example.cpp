#include "random_example.h"
#include <iostream>
#include <random>
#include <map>
#include <iomanip> //for std::setprecision

using namespace std;

void example_random_device()
{
    std::random_device rd;
    //std::random_device 实现了括号操作符重载,Generates a non-deterministic uniformly-distributed random value.
    for(int n=0; n<20000; ++n)
        std::cout << rd() << std::endl;

}

void example_random_engine()
{
    //标准提供三种常用的引擎:linear_congruential_engine,mersenne_twister_engine和subtract_with_carry_engine.
    // 第一种是线性同余算法,第二种是梅森旋转算法,第三种带进位的线性同余算法.第一种是最常用的,而且速度也是非常快的; 第二种号称是最好的伪随机数生成器;第三种没用过....

    //std::mt19937是随机数引擎模块类的特化,名称由来 mt是因为这个伪随机数产生器基于Mersenne Twister算法,19937是因为产生随的机数的周期长，可达到2^19937-1。
    std::random_device rd;
    std::mt19937 mt(rd());
    for(int n = 0; n < 10; n++)
        std::cout << mt() << std::endl;

}

void example_uniform_random_distribution()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    for(int n=0; n<10; ++n)
        std::cout << dis(gen) << ' ';
}

void example_normal_random_distribution()
{
    std::random_device rd;//C++11新特性——大括号初始化 std::random_device rd{}
    std::mt19937 gen(rd());

    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<double> d(5,2);

    /*
     * std::round()是四舍五入到最近的整数
     * std::round(4.456) = 4
     * std::round(4.556) = 5
     * */
    std::map<int, int> hist;
    for(int n=0; n<10000; ++n) {
        ++hist[std::round(d(gen))];//统计每个取整的随机数出现的次数，对map容器相同键的值进行统计
    }
    /*
     * setprecision(n) 控制输出流显示浮点数的数字个数,最多输出n个数字，会有四舍五入。
     * std::fixed 如果想要固定保留几位小数，那setprecision就得与fixed合作了！！
     * setw() 函数只对紧接着的输出产生作用。
当后面紧跟着的输出字段长度小于 n 的时候，在该字段前面用空格补齐，当输出字段长度大于 n 时，全部整体输出。
     setw() 默认填充的内容为空格，可以 setfill() 配合使用设置其他字符填充。
     * */
    for(auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
        << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}


int main()
{
    //example_random_device();
    //example_random_engine();
    example_uniform_random_distribution();
    example_normal_random_distribution();

    return 0;
}

