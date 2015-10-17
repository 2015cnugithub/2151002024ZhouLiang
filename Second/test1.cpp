#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*定义一个商品类CGood，其中包含商品号(long no),商品名（char *P_name),商品价格（double price)山歌数据成员，
以及相应的构造函数、拷贝函数、析构函数、打印数据成员函数。*/

class CGood{
	private:
		long no;
		char *p_name;
		double price;
	public:
		CGood(long no,char *p_name,double price);
		CGood(CGood &c);
		~CGood(); 
		void print();
		 
}; 
CGood::CGood(long no,char *p_name,double price){
	this->no = no;
	this->p_name=p_name;
	this->price = price;
}
CGood::~CGood(){ 
	cout<<"释放资源"<<endl;
}
void CGood::print(){
	cout<<"no:"<<no<<"\t name:"<<p_name<<"\t price:"<<price<<endl; 
}
CGood::CGood(CGood &c){
	no = c.no;
	p_name=c.p_name;
	price = c.price;
}
int main(int argc, char** argv) {
	CGood good(101,"xiaoming12",32.5);
	CGood copygood=good;
	
	cout<<"good:\t";
	good.print();
	cout<<"copygood:\t";
	copygood.print();
	
	return 0;
}

