#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*2.����һ����Ʒ��CGood�����а�����Ʒ��(long no),��Ʒ����char *P_name),��Ʒ�۸�double price)����Ʒ������int count)��Ʒ���ݳ�Ա��
�Լ���Ӧ�Ĺ��캯��������������������������ӡ���ݳ�Ա������getCount��Ա������ȡcount��ֵ����Ԫ����getName��ȡ��Ʒ����p_name��*/
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

	cout<<"�ͷ���Դ"<<endl;//
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
	char *name="���"; 
	CGood good(102,name,12.6,50);
	cout<<"��Ʒ��Ϣ:"<<endl;
	good.print();
	cout<<"��Ʒ����:";
	cout<<good.getCount()<<endl;
	cout<<"��Ʒ����:";
	cout<<getName(good)<<endl;
	
	return 0;
}
