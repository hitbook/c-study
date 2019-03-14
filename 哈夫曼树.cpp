#include<iostream>
#include<list>
using namespace std;
template<typename E>
class HuffTree {
private:
	HuffNode<E>* Root;
public:
	HuffTree(E&val, int freg)
	{
		Root = new LeafNode<E>(val, freg);
	}
	HuffTree(HuffTree<E>*l, HuffTree<E>*r)
	{
		Root = new InitNode<E>(l->root(), r->root());
	}
	HuffTree<E> * root() { return Root; }
	int weight() { return Root->weight(); }
};
template<typename E>
class LeafNode : public HuffNode<E> {
private:
	E it;
	int wgt;
public:
	LeafNode(const E& val, int freg) { it = val; wgt = freg }
	int weight() { return wgt; }
	E val() { return it; }
	bool isLeaf() { return true; }
};
template<typename E>
class InitNode : public HuffNode<E>{
private:
	HuffTree<E>* lc;
	HuffTree<E>* lr;
	int wgt;
public:
	InitNode(HuffTree<E>*l, HuffTree<E>*r) { lc = l; lr = r; }
	int weigh() { return lc->weight + lr->weight; }
	bool isLeaf() { return false; }
	HuffTree<E>* left() { return lc; }
	void setLeft(HuffTree<E>*l) { lc = l; }
	HuffTree<E>* right() { return lr; }
	void serRight(HuffTree<E>*r) { lr = r };

};
template<typename E>
class HuffNode {
public:
	virtual ~HuffNode()
	{

	}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};
template<typename E> 
HuffTree<E>* buildHuff(HUffTree<E>** TreeArray, int count) {
	heap<HuffTree<E>*, minTreeComp>* forest = new heap<HuffTree<E>*, minTreeComp>(TreeArray, count);
	HuffTree<char> *temp1, *temp2, *temp3 = NULL;
	while (forest->size() > 1) {
		temp1 = forest->removefirst();
		temp2 = forest->removefirst();
		temp3 = new HuffTree<E>(temp1, temp2);
		forest.insert(temp3);
		delete temp1;
		delete temp2;
	}
	return temp3;
}