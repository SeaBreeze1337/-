#if 0
项目目标：实现动态可变的数组
1、添加元素（末尾添加，指定下标添加）
2、删除元素（按照下标删除，按照元素删除、清空）
3、修改（按照下标修改）
4、获取（按照下标获取）
5、元素排序
6、元素下标查找
7、将容器中元素拼接为字符串返回

分析：
将使用两个版本的可变容器：数组版，双链表版
接口类方式完成
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