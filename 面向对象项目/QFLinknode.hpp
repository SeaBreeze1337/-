

template<typename T>
class QFMutableList;

template<typename E>
class QFLinknode
{

	friend class QFMutableList<E>;

private:
	E ele;
	QFLinknode<E>* pre;
	QFLinknode<E>* next;

public:
	QFLinknode(E ele);



};

template<typename E>
inline QFLinknode<E>::QFLinknode(E ele)
{
	this->ele = ele;
	pre = nullptr;
	next = nullptr;
}
