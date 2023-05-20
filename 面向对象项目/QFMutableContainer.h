#pragma once
#pragma once

//Ϊ���ܹ����ɸ����������͵�Ԫ�أ�������ඨ���ģ��
template< typename E>
//�����ֻ��Ϊ�˸�����汾������������汾�������ṩͳһ�Ľӿڣ������ֱ�����ɽӿ���
class QFMutableContainer
{
public:
	//��ĩβ���һ��Ԫ��
	virtual void add(E ele) = 0;
	//��ָ���±����һ��Ԫ��
	virtual void add(int index, E ele) = 0;
	//�����±�ɾ��Ԫ��
	virtual E remove(int index) = 0;
	//����Ԫ�ؽ���ɾ��
	virtual bool removeElement(E ele) = 0;
	//�������
	virtual void clear() = 0;
	//�����±��޸�Ԫ��
	virtual E set(int index, E ele) = 0;
	//�����±��ȡԪ��
	virtual E get(int index) = 0;
	//����
	virtual void sort() = 0;
	//����Ԫ�س��ֵ��±�
	virtual int index(E ele) = 0;
	//������Ԫ��ƴ�ӳ��ַ���
	virtual string str() = 0;
	//����������Ԫ�ص�����
	virtual int length() = 0;


	virtual ~QFMutableContainer()
	{

	}

};