#pragma once
#pragma once

//为了能够容纳各种数据类型的元素，将这个类定义成模板
template< typename E>
//这个类只是为了给数组版本的容器和链表版本的容器提供统一的接口，这个类直接做成接口类
class QFMutableContainer
{
public:
	//在末尾添加一个元素
	virtual void add(E ele) = 0;
	//在指定下标插入一个元素
	virtual void add(int index, E ele) = 0;
	//按照下标删除元素
	virtual E remove(int index) = 0;
	//按照元素进行删除
	virtual bool removeElement(E ele) = 0;
	//清空容器
	virtual void clear() = 0;
	//按照下标修改元素
	virtual E set(int index, E ele) = 0;
	//按照下标获取元素
	virtual E get(int index) = 0;
	//排序
	virtual void sort() = 0;
	//查找元素出现的下标
	virtual int index(E ele) = 0;
	//将容器元素拼接成字符串
	virtual string str() = 0;
	//返回容器中元素的数量
	virtual int length() = 0;


	virtual ~QFMutableContainer()
	{

	}

};