#if 0
��ĿĿ�꣺ʵ�ֶ�̬�ɱ������
1�����Ԫ�أ�ĩβ��ӣ�ָ���±���ӣ�
2��ɾ��Ԫ�أ������±�ɾ��������Ԫ��ɾ������գ�
3���޸ģ������±��޸ģ�
4����ȡ�������±��ȡ��
5��Ԫ������
6��Ԫ���±����
7����������Ԫ��ƴ��Ϊ�ַ�������

������
��ʹ�������汾�Ŀɱ�����������棬˫�����
�ӿ��෽ʽ���
#endif // 0

void arrayTest() {
#if 0
	QFMutableArray<int>* mutableArray = new QFMutableArray<int>;

	//test
	for (int i = 0; i < 10; i++)
	{
		mutableArray->add(i);
	}
	cout << mutableArray->str() << endl;

	//test
	mutableArray->add(3, 100);
	cout << mutableArray->str() << endl;

	//test
	cout << mutableArray->remove(3) << endl;
	cout << mutableArray->str() << endl;

	//test
	cout << mutableArray->index(7) << endl;

	////test
	//cout << mutableArray->removeElement(1) << endl;
	//cout << mutableArray->str() << endl;

	//test
	cout << mutableArray->set(1, 123) << endl;
	cout << mutableArray->str() << endl;

	//test
	/*int len = mutableArray->length();
	for (int i = 0; i < len; i++)
	{
		cout<<mutableArray->get(i) <<",";
	}*/

	mutableArray->sort();
	cout << mutableArray->str() << endl;

#endif // 0
}


#include<iostream>
using namespace std;
#include "QFMutableArray.hpp"
#include "QFMutableList.hpp"


int main() {

	QFMutableList<int>* list = new QFMutableList<int>();
	
	for (int i = 0; i < 10; i++)
	{
		list->add(i);
	}
	list->add(4, 100);


	/*cout << list->removeElement(1) << endl;
	cout << list->str() << endl;*/

	/*list->clear();
	cout << list->str() << endl;*/

	list->set(3, 300);
	/*cout << list->str() << endl;
	cout << list->get(3) << endl;*/

	list->sort();
	cout << list->str() << endl;

	return EXIT_SUCCESS;
}