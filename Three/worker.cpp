#include <iostream>
using namespace std;
/* 
设计一个抽象基类Worker，并从该基类中派生出计时工人类HourlyWorker和计薪工
人类SalariedWorker。每名工人都具有姓名name、年龄age、性别sex和小时工资
额pay_per_hour等属性；周薪计算成员函数void Compute_pay(double hours)，
（其中参数hours为每周的实际工作时数）和用于显示工人的基本信息的标准输出运
算符友元函数ostream& operator<<(ostream& out, Worker& worker)。
工人的薪金等级以小时工资额划分：
计时工人的薪金等级分为10、20和40 US$/hour三个等级；
计薪工人的薪金等级，分为30和50 US$/hour两个等级。
不同类别和等级工人的周薪计算方法不同，计时工人周薪的计算方法是：
如果每周的工作时数（hours）在40以内，则周薪 = 小时工资额 × 实际工作时数；
如果每周的工作时数（hours）超过40，则周薪 = 小时工资额 × 40 + 1.5 × 小时
工资额 ×（实际工作时数 – 40）。
而计薪工周薪的计算方法是：
如果每周的实际工作时数不少于35小时，则按40小时计周薪（允许有半个工作日的
事/病假），超出40小时部分不计薪，即周薪 = 小时工资额 × 40；
如果每周的实际工作时数少于35小时（不含35小时），则周薪 = 小时工资额  实
际工作时数 + 0.5 × 小时工资额 × (35 - 实际工作时数)。
 */

class Worker{
	protected:
		string name;
		int age;
		string sex;
		int pay_per_hour;
	public:
		virtual void Compute_pay(double hours)const= 0; 
	    void Name();
	    void setName(string name);
	    void setAge(int age);
	    void setSex(string sex);
	    void setPay(int pay);
		friend ostream& operator<<(ostream& out,Worker& worker);
};
ostream& operator<<(ostream& out,Worker& worker){
	out<<"\t name:"<<worker.name<<"   age:"<<worker.age<<"   sex:"<<worker.sex<<"   pay_per_hour:"<<worker.pay_per_hour<<endl;
	//out<<"name:"<<worker.name; 
	return out;
}
void Worker::Name(){
	cout<<this->name;
}
void Worker::setName(string name){
	this->name=name;
}
void Worker::setSex(string sex){
	this->sex=sex;
}
void Worker::setAge(int  age){
	this->age=age;
}
void Worker::setPay(int pay){
	this->pay_per_hour=pay;
}
class HourlyWorker:public Worker{
	public:
		virtual void Compute_pay(double hours)const ; 
};
/*计时工人周薪的计算方法是：
如果每周的工作时数（hours）在40以内，则周薪 = 小时工资额 × 实际工作时数；
如果每周的工作时数（hours）超过40，则周薪 = 小时工资额 × 40 + 1.5 × 小时
工资额 ×（实际工作时数 – 40）。*/
void HourlyWorker::Compute_pay(double hours) const{
	double money=0;
	if(hours<=40){
	  money=this->pay_per_hour *hours;
	} else{
		money = this->pay_per_hour *40 +1.5*this->pay_per_hour*(hours-40);
	} 
	cout<<"周薪："<<money<<endl;
	
}

class SalariedWorker:public Worker{
	public:
		virtual void Compute_pay(double hours) const; 
		
};
/*
计薪工周薪的计算方法是：
如果每周的实际工作时数不少于35小时，则按40小时计周薪（允许有半个工作日的
事/病假），超出40小时部分不计薪，即周薪 = 小时工资额 × 40；
如果每周的实际工作时数少于35小时（不含35小时），则周薪 = 小时工资额  实
际工作时数 + 0.5 × 小时工资额 × (35 - 实际工作时数)。
*/ 
void SalariedWorker::Compute_pay(double hours) const{
	double money=0;
	if( hours >=35) {
		money = 40 *this->pay_per_hour;
	}else{
		money = this->pay_per_hour*hours+ 0.5*this->pay_per_hour*(35-hours);
	}
	cout<<"周薪："<<money<<endl;
}
Worker* initWorker(int type);
//显示所有工人名称 
void display(Worker *worker[],int count); 
int main(int argc, char** argv) {
	int choice; 
	int hours=0;
	Worker *worker[5];
	//注册5个不同等级的工人 
	worker[0]=initWorker(1);
	worker[1]=initWorker(1);
	worker[2]=initWorker(1);
	worker[3]=initWorker(2);
	worker[4]=initWorker(2);
	
	system("cls");
	display(worker,5);
	cout<<"根据序号查看工人情况,0退出:";
	cin>>choice;
	while(choice!=0)
	{
		cout<<(&cout,*worker[choice-1]);
		cout<<"每周的实际工作时数:"; 
		cin>>hours;
		worker[choice-1]->Compute_pay(hours);
		
	
		display(worker,5);
		cout<<"根据序号查看工人情况,0退出:";
	    cin>>choice;
	}
	for(int i = 0 ;i < 5;i++) 
	{ 
	    delete(worker[i]);
    } 
	
	return 0;
}
//显示所有工人名称 
void display(Worker *worker[],int count) {
	for(int i = 0 ;i < count;i++) 
	{ 
       cout<<"\t"<<i+1<<":\t";
	   worker[i]->Name();
	   cout<<endl;
    } 
}
/*注册一个工人
type:1 计时工人  
type:2 计薪工人 
*/ 
Worker* initWorker(int type){
	string name;
	int age;
	string sex;
	int pay;
	Worker*	worker=NULL;
	if( type == 1){
		cout<<"注册一个计时工人:"<<endl;
		worker=new HourlyWorker();
	} else{
		cout<<"注册一个计薪工人:"<<endl;
		worker=new SalariedWorker();
	}
	cout<<"输入姓名:";
	cin>>name;
	worker->setName(name);
	cout<<"输入年龄:";
	cin>>age;
	worker->setAge(age);
	cout<<"输入性别:";
	cin>>sex;
	worker->setSex(sex);
	if( type == 1)
	   cout<<"输入薪金等级(10,20,40三个等级):";
	else
	   cout<<"输入薪金等级(30,50两个等级):";
	   
	cin>>pay;
	worker->setPay(pay);
	return worker;
}
