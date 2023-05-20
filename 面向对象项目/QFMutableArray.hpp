#pragma once
#include <iostream>
#include <sstream>
#include "QFMutableContainer.h"
using namespace std;


template<typename E>
class QFMutableArray :public QFMutableContainer<E>
{
private:
	E* array;
	int len;
public:

	QFMutableArray();

	//在末尾添加一个元素
	void add(E ele) override;
	//在指定下标插入一个元素
	void add(int index, E ele) override;
	//按照下标删除元素
	E remove(int index) override;
	//按照元素进行删除
	bool removeElement(E ele) override;
	//清空容器
	void clear() override;
	//按照下标修改元素
	E set(int index, E ele) override;
	//按照下标获取元素
	E get(int index) override;
	//排序
	void sort() override;
	//查找元素出现的下标
	int index(E ele) override;
	//将容器元素拼接成字符串
	string str() override;
	//返回容器中元素的数量
	 int length() override;
	~QFMutableArray() override;

};

template<typename E>
inline QFMutableArray<E>::QFMutableArray()
{
	array = new E[0];
	len = 0;
}

template<typename E>
inline void QFMutableArray<E>::add(E ele)
{
	//添加思想：
	//创建一个新数组，新数组比原来数组长度+1，原来数组元素依次拷贝到新数组，把本次需要添加元素放入新数组最后一位
	//最后修改array指针指向新数组

	//1、创建新数组
	E* temp = new E[len + 1];
	//2、将数组元素拷贝到新数组中
	for (int i = 0; i < len; i++)
	{
		temp[i] = array[i];
	}
	//3、元素放入新数组最后一位
	temp[len] = ele;
	//4、修改元素数量
	len++;
	//5、修改指针指向
	delete array;
	array = temp;
}

template<typename E>
inline void QFMutableArray<E>::add(int index, E ele)
{
	//添加思想：
	//创建一个新数组，新数组比原来数组长度+1，原来数组元素依次拷贝到新数组，拷贝过程需要注意下标
	//最后修改array指针指向新数组
	//1、创建新数组
	E* temp = new E[len + 1];
	//2、将数组元素拷贝到新数组中，遇到指定下标需要跳过
	for (int j = 0, i = 0;j < len+1; j++)
	{
		if (j==index)
		{
			continue;
		}
		temp[j] = array[i++];
	}	
	//3、元素放入指定下标位
	temp[index] = ele;
	//4、修改元素数量
	len++;
	//5、修改指针指向
	delete array;
	array = temp;
}

template<typename E>
inline E QFMutableArray<E>::remove(int index)
{
	//1、备份被删除的元素
	E ele = array[index];
	//2、创建一个新数组，长度为原来的len-1
	E* temp = new E[len - 1];
	//3、拷贝到新数组中
	for (int i = 0,j=0; i < len; i++)
	{
		if (i==index)
		{
			continue;
		}
		temp[j++] = array[i];
	}
	//4、修改元素数量
	len--;
	//5、修改指针指向
	delete array;
	array = temp;

	return ele;
}

template<typename E>
inline bool QFMutableArray<E>::removeElement(E ele)
{
	//思路：先找到元素下标，按照下标删除
	int i = index(ele);
	if (i == -1)
	{
		return false;
	}
	remove(i);
	return true;
}

template<typename E>
inline void QFMutableArray<E>::clear()
{

	//将原来的数组置空
	delete array;
	array = new E[0];
	len = 0;
}

template<typename E>
inline E QFMutableArray<E>::set(int index, E ele)
{
	E temp = array[index];
	array[index] = ele;
	return temp;
}

template<typename E>
inline E QFMutableArray<E>::get(int index)
{
	return array[index];
}

template<typename E>
inline void QFMutableArray<E>::sort()
{
	for (int i = 0; i < len-1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < len; j++)
		{
			if (array[minIndex]>array[j]) {
				minIndex = j;
			}
		}
		if (minIndex!=i)
		{
			E temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

template<typename E>
inline int QFMutableArray<E>::index(E ele)
{
	for (int i = 0; i < len; i++)
	{
		if (ele==array[i]) {
			return i;
		}
	}
	return -1;
}

template<typename E>
inline string QFMutableArray<E>::str()
{
	if (len==0)
	{
		return "[ ]";
	}
	//创建一个ostringstream对象，用来拼接元素
	ostringstream oss;
	oss << "[";
	for (int i = 0; i < len-1; i++)
	{
		oss << array[i] << ",";
	}
	oss << array[len - 1] << "]";
	return oss.str();
}

template<typename E>
inline int QFMutableArray<E>::length()
{
	return len;
}

template<typename E>
inline QFMutableArray<E>::~QFMutableArray()
{
	if (array!=nullptr)
	{
		delete array;
		array = nullptr;
	}
}
