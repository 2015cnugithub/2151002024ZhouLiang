#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*2.定义一个商品类CGood，其中包含商品号(long no),商品名（char *P_name),商品价格（double price)，商品总数（int count)商品数据成员，
以及相应的构造函数、拷贝函数、析构函数、打印数据成员函数、getCount成员函数获取count的值，友元函数getName获取商品名称p_name。*/
class CGood{
	private:
		long no;
		char *p_name;
		double price;
		int count; 
	public:
		CGood(long no,char *p_name,double price,int count);
		CGood(CGood &c);
		~CGood(); 
		void print();
		int getCount();
		friend char* getName(CGood &good);
}; 
CGood::CGood(long no,char *p_name,double price,int count){
	this->no = no;
	this->p_name=p_name;
	this->price = price;
	this->count = count;
}
CGood::~CGood(){ 

	cout<<"释放资源"<<endl;//
	//	delete p_name;
}
void CGood::print(){
	cout<<"no:"<<no<<"\t name:"<<p_name<<"\t price:"<<price<<"\t count:"<<count<<endl; 
}
CGood::CGood(CGood &c){
	no = c.no;
	p_name=c.p_name;
	price = c.price;
}
int CGood::getCount(){
	return this->count;
}
char *getName(CGood &good){
	return good.p_name;
} 
int main(int argc, char** argv) {
	char *name="面包"; 
	CGood good(102,name,12.6,50);
	cout<<"商品信息:"<<endl;
	good.print();
	cout<<"商品总数:";
	cout<<good.getCount()<<endl;
	cout<<"商品名称:";
	cout<<getName(good)<<endl;
	
	return 0;
}
