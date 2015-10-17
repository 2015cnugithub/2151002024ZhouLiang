#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//��ʾ���ݣ���2015��1��1�����������Ƚ�
void displayDate(int data[]);
//��ȡ�����·ݵĵ�һ�������ڼ�
int getWeekOfMonth(int year,int month);
/**
* ��ӡ��������
* @param week ����µ�һ�����ڼ�
* @param days0fMonth  ����µ�����
*/
void printCalendar(int week,int days0fMonth);
 //������
void readDate(int data[]);
//a���ڵ�b��1�շݹ��ȹ��˶����죨������b��1��)
int daysToMonth(int year,int month);
 //a��b�·ݵ�����
int daysOfMonth(int year,int month);
/**
	 * ĳһ���������
	 * @param year
	 * @return
	 */
int daysOfYear(int year);

int main(int argc, char** argv) {
		int data[2];//�洢����µ�����
		int week;//�����·ݵĵ�һ�������ڼ�
		int daysOfMonth;//����µ�����
		//������
		readDate(data);
		//��ʾ����
		displayDate(data);
}

	//��ʾ���ݣ���2015��1��1�����������Ƚ�
	  void displayDate(int data[]) {
		int week=0;//�����·ݵ�һ�������ڼ�
		int days;//����µ�����
		//У�����ݵ���ȷ��
		if( data[0]>0 && 12>=data[1] && data[1]>=1 ){
			//��ȡ�����·ݵĵ�һ�������ڼ�
			week=getWeekOfMonth(data[0],data[1]);
			//��ȡ����·ݹ�������
			days=daysOfMonth(data[0],data[1]);
			//����week��daysOfMonth��ʾ����µ�����
			printCalendar(week,days);
		}else{
			cout<<"������������!" ;
		}
	}
	//��ȡ�����·ݵĵ�һ�������ڼ�
	  int getWeekOfMonth(int year,int month){
		int overDays=0;//����2015��1��1������
		int belowDays=0;//С��2015��1��1������
		int week=0;//�����·ݵ�һ�������ڼ�
		//���ڻ����2015��1��1�յ�����
		if(year>=2015&& month>=1){ 
			for( int i = 2015;i< year;i++)
				overDays+=daysOfYear(i);
			
			overDays+=daysToMonth(year,month);
			week = (overDays%7+4);
			if(week>7)
				week=week%7;//��������·ݵĵ�һ�������ڼ�
		}else{//С��2015��1��1�յ�����
			for(int j= year;j<2015;j++){
				belowDays+=daysOfYear(j);
			}//�������
			belowDays-=daysToMonth(year,month);//��ȥ�µ�����
			week = 4-belowDays%7+7;
			if(week!=7)
				week=week%7;
		} 
		return week;
	}
	/**
	 * ��ӡ��������
	 * @param week ����µ�һ�����ڼ�
	 * @param days0fMonth  ����µ�����
	 */
	 void printCalendar(int week,int days0fMonth){
		
		cout<<"һ\t��\t��\t��\t��\t��\t��\t"<<endl;
		for( int j =1;j<week;j++)
			cout<<"\t";
		for(int i = 1;i<= days0fMonth;i++ ){
			cout<<i<<"\t";
			if( (i+week-1)%7==0 )
			  cout<<endl;
		//	cout<< ((i+week-1)%7==0)?"\n":"";
		}
	}
	//������
	 void readDate(int data[]) {
	 	cout<<"�����꣺"<<endl;
	 	cin>>data[0];
		cout<<"�����£�"<<endl;
		cin>>data[1];
	}
	//a���ڵ�b��1�շݹ��ȹ��˶����죨������b��1��)
	int daysToMonth(int year,int month){
		int allDays=0;//������
		for(int i=1;i< month;i++){
			allDays+=daysOfMonth(year,i);
		}
		return allDays;
	}
	
	//a��b�·ݵ�����
	int daysOfMonth(int year,int month){
		if( month==1 ||month ==3|| month==5 ||month ==7|| month==8 ||month ==10||month==12){
			return 31;
		}else if( month==4 ||month ==6|| month==9 ||month ==11){
			return 30;
		}else if( year%4 ==0 && year %100!=0 ||( year%100==0 && year%400==0)){//���� 4�������ܱ�100���� �����ܱ�100��400ͬʱ����
			return 29;
		}else
		   return 28;
	}
	/**
	 * ĳһ���������
	 * @param year
	 * @return
	 */
	int daysOfYear(int year){
	  if( year%4 ==0 && year %100!=0 ||( year%100==0 && year%400==0))//����
		  return 366;
	  else
		  return 365;
	}


