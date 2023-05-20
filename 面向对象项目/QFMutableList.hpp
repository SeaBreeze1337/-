#include "QFLinknode.hpp"
#include "QFMutableContainer.h"
#include <iostream>
#include <sstream>
using namespace std;


template<typename E>
class QFMutableList:public QFMutableContainer<E>
{
private:

	QFLinknode<E>* first;
	QFLinknode<E>* last;
	int len;

	//通过下标获取指定的节点
	QFLinknode<E>* getNode(int index);

public:
	QFMutableList();
	~QFMutableList()override;
	
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


};

template<typename E>
inline QFLinknode<E>* QFMutableList<E>::getNode(int index)
{
	QFLinknode<E>* p = first;
	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}
	return p;
}

template<typename E>
inline QFMutableList<E>::QFMutableList()
{
	first = nullptr;
	last = nullptr;
	len = 0;
}

template<typename E>
inline QFMutableList<E>::~QFMutableList()
{
	//销毁链表时，释放每一个结点
	clear();
}

template<typename E>
inline void QFMutableList<E>::add(E ele)
{
	//创建一个新节点
	QFLinknode<E>* node = new QFLinknode<E>(ele);

	//判断元素的数量
	if (len==0)
	{
		//说明链表没有元素，首节点和未结点都是nullptr
		this->first = node;
		this->last = node;
		
	}
	else
	{
		//说明链表是有元素的，将node节点添加last节点之后
		this->last->next = node;
		node->pre = this->last; 
		this->last = node;
	}
	//更新元素数量
	len++;

}

template<typename E>
inline void QFMutableList<E>::add(int index, E ele)
{
	//1、创建节点
	QFLinknode<E>* node = new QFLinknode<E>(ele);

	//2、分不同情况
	if (index==0)
	{
		//头插
		node->next = first;
		first->pre = node;
		first = node;
		len++;
	}
	else if (index==len)
	{
		//尾插
		node->pre = last;
		last->next = node;
		last = node;
		len++;
	}
	else
	{
		//通过下标找到需要被插入节点
		QFLinknode<E>* target = getNode(index);
		target->pre->next = node;
		node->pre = target ->pre;
		node->next = target;
		target->pre = node;
		len++;
	}
}

template<typename E>
inline E QFMutableList<E>::remove(int index)
{
	E temp;

	if (len==1)
	{
		temp = first->ele;
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		if (index==0)
		{
			//删除头节点
			temp = first->ele;
			first = first->next;
			delete first->pre;
			first->pre = nullptr;
		}
		else if (len==index-1)
		{
			//删除尾节点
			temp = last->ele;
			last = last->pre;
			delete last->next;
			last->next = nullptr;
		}
		else
		{
			//中间结点
			QFLinknode<E>* node = getNode(index);
			temp = node->ele;

			node->pre->next = node->next;
			node->next->pre = node->pre;
			delete node;
		}
	}
	len--;
	return temp;
}

template<typename E>
inline bool QFMutableList<E>::removeElement(E ele)
{
	int i = index(ele);
	if (i==-1)
	{
		return false;
	}
	remove(i);
	return true;
}

template<typename E>
inline void QFMutableList<E>::clear()
{
	if (first != nullptr)
	{
		QFLinknode<E>* p1 = first;
		QFLinknode<E>* p2 = p1->next;
		while (p2 != nullptr)
		{
			delete p1;
			p1 = p2;
			p2 = p2->next;
		}
		delete p1;

		first = nullptr;
		last = nullptr;
		len = 0;
	}
}

template<typename E>
inline E QFMutableList<E>::set(int index, E ele)
{
	//通过下标获取结点
	QFLinknode<E>* node = getNode(index);
	//备份原来数据
	E temp = node->ele;
	//修改数据
	node->ele = ele;
	return temp;
}

template<typename E>
inline E QFMutableList<E>::get(int index)
{
	QFLinknode<E>* node = getNode(index);
	return node->ele;
}

template<typename E>
inline void QFMutableList<E>::sort()
{
	for (int i = 0; i < len-1; i++)
	{
		QFLinknode<E>* node = first;
		for (int j = 0; j < len - 1-i; j++)
		{
			if (node->ele>node->next->ele) {
				E temp = node->ele;
				node->ele = node->next->ele;
				node->next->ele = temp;
			}
			node = node->next;
		}
	}
}

template<typename E>
inline int QFMutableList<E>::index(E ele)
{
	QFLinknode<E>* node = first;
	for (int i = 0; i < len; i++)
	{
		if (ele==node->ele) {
			return i;
		}
		node = node->next;
	}
	return -1;
}

template<typename E>
inline string QFMutableList<E>::str()
{
	if (len==0)
	{
		return "[]";
	}
	ostringstream oss;
	oss << "[";
	QFLinknode<E>* node = first;
	for (int i = 0; i < len-1; i++)
	{
		oss << node->ele << ", ";
		node = node->next;
	}
	oss << node->ele << "]";
	return oss.str();
}

template<typename E>
inline int QFMutableList<E>::length()
{
	return len;
}
