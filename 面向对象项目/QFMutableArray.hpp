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
	//���˼�룺
	//����һ�������飬�������ԭ�����鳤��+1��ԭ������Ԫ�����ο����������飬�ѱ�����Ҫ���Ԫ�ط������������һλ
	//����޸�arrayָ��ָ��������

	//1������������
	E* temp = new E[len + 1];
	//2��������Ԫ�ؿ�������������
	for (int i = 0; i < len; i++)
	{
		temp[i] = array[i];
	}
	//3��Ԫ�ط������������һλ
	temp[len] = ele;
	//4���޸�Ԫ������
	len++;
	//5���޸�ָ��ָ��
	delete array;
	array = temp;
}

template<typename E>
inline void QFMutableArray<E>::add(int index, E ele)
{
	//���˼�룺
	//����һ�������飬�������ԭ�����鳤��+1��ԭ������Ԫ�����ο����������飬����������Ҫע���±�
	//����޸�arrayָ��ָ��������
	//1������������
	E* temp = new E[len + 1];
	//2��������Ԫ�ؿ������������У�����ָ���±���Ҫ����
	for (int j = 0, i = 0;j < len+1; j++)
	{
		if (j==index)
		{
			continue;
		}
		temp[j] = array[i++];
	}	
	//3��Ԫ�ط���ָ���±�λ
	temp[index] = ele;
	//4���޸�Ԫ������
	len++;
	//5���޸�ָ��ָ��
	delete array;
	array = temp;
}

template<typename E>
inline E QFMutableArray<E>::remove(int index)
{
	//1�����ݱ�ɾ����Ԫ��
	E ele = array[index];
	//2������һ�������飬����Ϊԭ����len-1
	E* temp = new E[len - 1];
	//3����������������
	for (int i = 0,j=0; i < len; i++)
	{
		if (i==index)
		{
			continue;
		}
		temp[j++] = array[i];
	}
	//4���޸�Ԫ������
	len--;
	//5���޸�ָ��ָ��
	delete array;
	array = temp;

	return ele;
}

template<typename E>
inline bool QFMutableArray<E>::removeElement(E ele)
{
	//˼·�����ҵ�Ԫ���±꣬�����±�ɾ��
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

	//��ԭ���������ÿ�
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
	//����һ��ostringstream��������ƴ��Ԫ��
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
