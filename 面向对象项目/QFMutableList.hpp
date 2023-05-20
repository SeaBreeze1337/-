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

	//ͨ���±��ȡָ���Ľڵ�
	QFLinknode<E>* getNode(int index);

public:
	QFMutableList();
	~QFMutableList()override;
	
	//��ĩβ���һ��Ԫ��
	 void add(E ele) override;
	//��ָ���±����һ��Ԫ��
	 void add(int index, E ele) override;
	//�����±�ɾ��Ԫ��
	 E remove(int index) override;
	//����Ԫ�ؽ���ɾ��
	 bool removeElement(E ele) override;
	//�������
	 void clear() override;
	//�����±��޸�Ԫ��
	 E set(int index, E ele) override;
	//�����±��ȡԪ��
	 E get(int index) override;
	//����
	 void sort() override;
	//����Ԫ�س��ֵ��±�
	 int index(E ele) override;
	//������Ԫ��ƴ�ӳ��ַ���
	 string str() override;
	//����������Ԫ�ص�����
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
	//��������ʱ���ͷ�ÿһ�����
	clear();
}

template<typename E>
inline void QFMutableList<E>::add(E ele)
{
	//����һ���½ڵ�
	QFLinknode<E>* node = new QFLinknode<E>(ele);

	//�ж�Ԫ�ص�����
	if (len==0)
	{
		//˵������û��Ԫ�أ��׽ڵ��δ��㶼��nullptr
		this->first = node;
		this->last = node;
		
	}
	else
	{
		//˵����������Ԫ�صģ���node�ڵ����last�ڵ�֮��
		this->last->next = node;
		node->pre = this->last; 
		this->last = node;
	}
	//����Ԫ������
	len++;

}

template<typename E>
inline void QFMutableList<E>::add(int index, E ele)
{
	//1�������ڵ�
	QFLinknode<E>* node = new QFLinknode<E>(ele);

	//2���ֲ�ͬ���
	if (index==0)
	{
		//ͷ��
		node->next = first;
		first->pre = node;
		first = node;
		len++;
	}
	else if (index==len)
	{
		//β��
		node->pre = last;
		last->next = node;
		last = node;
		len++;
	}
	else
	{
		//ͨ���±��ҵ���Ҫ������ڵ�
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
			//ɾ��ͷ�ڵ�
			temp = first->ele;
			first = first->next;
			delete first->pre;
			first->pre = nullptr;
		}
		else if (len==index-1)
		{
			//ɾ��β�ڵ�
			temp = last->ele;
			last = last->pre;
			delete last->next;
			last->next = nullptr;
		}
		else
		{
			//�м���
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
	//ͨ���±��ȡ���
	QFLinknode<E>* node = getNode(index);
	//����ԭ������
	E temp = node->ele;
	//�޸�����
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
