#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*ΪCGood�ඨ��С���������"<")�Ͳ�С�������(">=")������������غ�����
CGoods������С�ıȽ��Ǹ�������Ʒ�۸�(price)��ֵ�Ĵ�С��ʵ�ֵ�*/
class CGoods{
	private:
		double price;
	public:
		CGoods(double price);
		double getPrice();
		friend bool operator<(const CGoods &g,const CGoods &c);//���g<c�򷵻�true������false 
		friend bool operator>=(const CGoods &g,const CGoods &c);//���g>=c�򷵻�true������false 
};
CGoods::CGoods(double price){
	this->price = price;
} 
double CGoods::getPrice(){
	return price;
}
bool operator<(const CGoods &g,const CGoods &c){
	if(g.price<c.price)
	  return true;
	else 
      return false;
}
bool operator>=(const CGoods &g,const CGoods &c){
	if(g.price>=c.price)
	  return true;
	else
	  return false;
}
int main(int argc, char** argv) {
	CGoods apple(15.9);
	CGoods banana(15.9);
	
	cout<<"apple�۸�:"<<apple.getPrice()<<endl;
	cout<<"banana�۸�"<<banana.getPrice()<<endl;
	if( apple<banana)
	  cout<<"bannana��apple��"<<endl; 
    else
      cout<<"bannana����apple��"<<endl; 
      
	if( apple>=banana)
	  cout<<"apple���ڵ���bannana"<<endl; 
	else 
	   cout<<"apple��bannanaС"<<endl;
	
	   
	return 0;
}
