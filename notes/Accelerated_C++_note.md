# Accelerated C++

记录一些代码练习过程中遗忘的和通过搜索明确的知识

## 之前

### 错误

- \<algorithm\> 常量不能被赋值
const vector不能排序变换位置

- cannot seek value-initialized vector iterator
未初始化向量不能直接用迭代器迭代

- 函数缺少参数
函数默认参数只能放在函数声明处或者定义处，能放在声明处就放在声明处

## 第7章

- list迭代器不能通过加int前进，只能通过++递增
- list迭代器不包含[]操作符
- erase返回删除后的下一个迭代器
- 空容器的begin等于end

## 第8章练习

- `*iter++ != (*iter)++`
- swap可用*iter为参数
- 能进行算术运算的迭代器只有**随机访问迭代器**（vector、string、deque），要求容器元素存储在连续内存空间内
- `static_cast<double>()`：更加安全的类型转换

## 第9章

- **`explicit`**:显式声明构造函数防止隐式转换
- **`[[nodiscard]]`**:C++17引入，表明返回值不应舍弃，否则编译器warning
- `std::sort`:x\<y ->升序
- template可用T代指函数

## 第10章

- 在一个类的函数后面加上const表明这个函数不能改变类的成员变量
- 空字符串的bool类型为`True`
- `abort() has been called`：中止被调用
  1.非法指针访问和内存泄漏
  2.设置的指针范围跟你运行的不对
  3.指针访问内存越界出现问题。
  4.因为不支持中文。
  5.内存不够分配
  6.多线程访问资源出的问题。
  7.检查exe和dll是否混用的不同版本的crt
- `sizeof(vector)`与vector大小无关
- 函数返回局部对象的操作
  1. 调用拷贝构造函数复制产生临时对象(如直接返回临时对象则无本步)
  2. 局部对象析构
  3. 调用拷贝构造函数复制临时对象到主函数对象（如存在）
  4. 临时对象析构
- 在C++中，只有被声明为const的成员函数(函数名后加const)才能被一个const类对象调用

## 第12章

- `std::string`结尾不一定为空字符

## 第13章

- `override` ：C++11特性，用于帮助判断派生类对virtual函数重载的正确性
- delete空指针无害，非空指针delete两次则访问出错
