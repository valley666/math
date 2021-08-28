#pragma once

/*
 * 随机数生成设备
 * 用来返回一个min()到max()之间的一个数字,常用来作为生成随机数的种子
 * */

void example_random_device();

//标准把随机数抽象成随机数引擎和分布两部分.引擎用来产生随机数,分布产生特定分布的随机数(比如平均分布,正太分布等).

/*
 * 随机数引擎random number engine
 * */
void example_random_engine();

/*
 * 随机数分布 random number distributions
 * */
//随机数均匀分布
void example_uniform_random_distribution();

//随时数正太分布
void example_normal_random_distribution();
