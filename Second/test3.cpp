#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*为CGood类定义小于运算符（"<")和不小于运算符(">=")两个运算符重载函数，
CGoods类对象大小的比较是根据其商品价格(price)的值的大小来实现的*/
class CGoods{
	private:
		double price;
	public:
		CGoods(double price);
		double getPrice();
		friend bool operator<(const CGoods &g,const CGoods &c);//如果g<c则返回true，否则false 
		friend bool operator>=(const CGoods &g,const CGoods &c);//如果g>=c则返回true，否则false 
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
	
	cout<<"apple价格:"<<apple.getPrice()<<endl;
	cout<<"banana价格"<<banana.getPrice()<<endl;
	if( apple<banana)
	  cout<<"bannana比apple大"<<endl; 
    else
      cout<<"bannana不比apple大"<<endl; 
      
	if( apple>=banana)
	  cout<<"apple大于等于bannana"<<endl; 
	else 
	   cout<<"apple比bannana小"<<endl;
	
	   
	return 0;
}
