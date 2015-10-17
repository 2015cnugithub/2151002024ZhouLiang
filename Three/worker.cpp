#include <iostream>
using namespace std;
/* 
���һ���������Worker�����Ӹû�������������ʱ������HourlyWorker�ͼ�н��
����SalariedWorker��ÿ�����˶���������name������age���Ա�sex��Сʱ����
��pay_per_hour�����ԣ���н�����Ա����void Compute_pay(double hours)��
�����в���hoursΪÿ�ܵ�ʵ�ʹ���ʱ������������ʾ���˵Ļ�����Ϣ�ı�׼�����
�����Ԫ����ostream& operator<<(ostream& out, Worker& worker)��
���˵�н��ȼ���Сʱ���ʶ�֣�
��ʱ���˵�н��ȼ���Ϊ10��20��40 US$/hour�����ȼ���
��н���˵�н��ȼ�����Ϊ30��50 US$/hour�����ȼ���
��ͬ���͵ȼ����˵���н���㷽����ͬ����ʱ������н�ļ��㷽���ǣ�
���ÿ�ܵĹ���ʱ����hours����40���ڣ�����н = Сʱ���ʶ� �� ʵ�ʹ���ʱ����
���ÿ�ܵĹ���ʱ����hours������40������н = Сʱ���ʶ� �� 40 + 1.5 �� Сʱ
���ʶ� ����ʵ�ʹ���ʱ�� �C 40����
����н����н�ļ��㷽���ǣ�
���ÿ�ܵ�ʵ�ʹ���ʱ��������35Сʱ����40Сʱ����н�������а�������յ�
��/���٣�������40Сʱ���ֲ���н������н = Сʱ���ʶ� �� 40��
���ÿ�ܵ�ʵ�ʹ���ʱ������35Сʱ������35Сʱ��������н = Сʱ���ʶ�  ʵ
�ʹ���ʱ�� + 0.5 �� Сʱ���ʶ� �� (35 - ʵ�ʹ���ʱ��)��
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
/*��ʱ������н�ļ��㷽���ǣ�
���ÿ�ܵĹ���ʱ����hours����40���ڣ�����н = Сʱ���ʶ� �� ʵ�ʹ���ʱ����
���ÿ�ܵĹ���ʱ����hours������40������н = Сʱ���ʶ� �� 40 + 1.5 �� Сʱ
���ʶ� ����ʵ�ʹ���ʱ�� �C 40����*/
void HourlyWorker::Compute_pay(double hours) const{
	double money=0;
	if(hours<=40){
	  money=this->pay_per_hour *hours;
	} else{
		money = this->pay_per_hour *40 +1.5*this->pay_per_hour*(hours-40);
	} 
	cout<<"��н��"<<money<<endl;
	
}

class SalariedWorker:public Worker{
	public:
		virtual void Compute_pay(double hours) const; 
		
};
/*
��н����н�ļ��㷽���ǣ�
���ÿ�ܵ�ʵ�ʹ���ʱ��������35Сʱ����40Сʱ����н�������а�������յ�
��/���٣�������40Сʱ���ֲ���н������н = Сʱ���ʶ� �� 40��
���ÿ�ܵ�ʵ�ʹ���ʱ������35Сʱ������35Сʱ��������н = Сʱ���ʶ�  ʵ
�ʹ���ʱ�� + 0.5 �� Сʱ���ʶ� �� (35 - ʵ�ʹ���ʱ��)��
*/ 
void SalariedWorker::Compute_pay(double hours) const{
	double money=0;
	if( hours >=35) {
		money = 40 *this->pay_per_hour;
	}else{
		money = this->pay_per_hour*hours+ 0.5*this->pay_per_hour*(35-hours);
	}
	cout<<"��н��"<<money<<endl;
}
Worker* initWorker(int type);
//��ʾ���й������� 
void display(Worker *worker[],int count); 
int main(int argc, char** argv) {
	int choice; 
	int hours=0;
	Worker *worker[5];
	//ע��5����ͬ�ȼ��Ĺ��� 
	worker[0]=initWorker(1);
	worker[1]=initWorker(1);
	worker[2]=initWorker(1);
	worker[3]=initWorker(2);
	worker[4]=initWorker(2);
	
	system("cls");
	display(worker,5);
	cout<<"������Ų鿴�������,0�˳�:";
	cin>>choice;
	while(choice!=0)
	{
		cout<<(&cout,*worker[choice-1]);
		cout<<"ÿ�ܵ�ʵ�ʹ���ʱ��:"; 
		cin>>hours;
		worker[choice-1]->Compute_pay(hours);
		
	
		display(worker,5);
		cout<<"������Ų鿴�������,0�˳�:";
	    cin>>choice;
	}
	for(int i = 0 ;i < 5;i++) 
	{ 
	    delete(worker[i]);
    } 
	
	return 0;
}
//��ʾ���й������� 
void display(Worker *worker[],int count) {
	for(int i = 0 ;i < count;i++) 
	{ 
       cout<<"\t"<<i+1<<":\t";
	   worker[i]->Name();
	   cout<<endl;
    } 
}
/*ע��һ������
type:1 ��ʱ����  
type:2 ��н���� 
*/ 
Worker* initWorker(int type){
	string name;
	int age;
	string sex;
	int pay;
	Worker*	worker=NULL;
	if( type == 1){
		cout<<"ע��һ����ʱ����:"<<endl;
		worker=new HourlyWorker();
	} else{
		cout<<"ע��һ����н����:"<<endl;
		worker=new SalariedWorker();
	}
	cout<<"��������:";
	cin>>name;
	worker->setName(name);
	cout<<"��������:";
	cin>>age;
	worker->setAge(age);
	cout<<"�����Ա�:";
	cin>>sex;
	worker->setSex(sex);
	if( type == 1)
	   cout<<"����н��ȼ�(10,20,40�����ȼ�):";
	else
	   cout<<"����н��ȼ�(30,50�����ȼ�):";
	   
	cin>>pay;
	worker->setPay(pay);
	return worker;
}
