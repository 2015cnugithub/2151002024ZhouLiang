#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*����һ����Ʒ��CGood�����а�����Ʒ��(long no),��Ʒ����char *P_name),��Ʒ�۸�double price)ɽ�����ݳ�Ա��
�Լ���Ӧ�Ĺ��캯��������������������������ӡ���ݳ�Ա������*/

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
	cout<<"�ͷ���Դ"<<endl;
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

