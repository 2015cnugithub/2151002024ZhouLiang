#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//显示数据，跟2015年1月1日星期四作比较
void displayDate(int data[]);
//获取输入月份的第一天是星期几
int getWeekOfMonth(int year,int month);
/**
* 打印本月日历
* @param week 这个月第一天星期几
* @param days0fMonth  这个月的天数
*/
void printCalendar(int week,int days0fMonth);
 //读数据
void readDate(int data[]);
//a年内到b月1日份共度过了多少天（不包含b月1日)
int daysToMonth(int year,int month);
 //a年b月份的天数
int daysOfMonth(int year,int month);
/**
	 * 某一年的总天数
	 * @param year
	 * @return
	 */
int daysOfYear(int year);

int main(int argc, char** argv) {
		int data[2];//存储年和月的数组
		int week;//输入月份的第一天是星期几
		int daysOfMonth;//这个月的天数
		//读数据
		readDate(data);
		//显示数据
		displayDate(data);
}

	//显示数据，跟2015年1月1日星期四作比较
	  void displayDate(int data[]) {
		int week=0;//输入月份第一个月星期几
		int days;//这个月的天数
		//校验数据的正确性
		if( data[0]>0 && 12>=data[1] && data[1]>=1 ){
			//获取输入月份的第一天是星期几
			week=getWeekOfMonth(data[0],data[1]);
			//获取这个月份共多少天
			days=daysOfMonth(data[0],data[1]);
			//根据week和daysOfMonth显示这个月的日历
			printCalendar(week,days);
		}else{
			cout<<"输入数据有误!" ;
		}
	}
	//获取输入月份的第一天是星期几
	  int getWeekOfMonth(int year,int month){
		int overDays=0;//大于2015年1月1的天数
		int belowDays=0;//小于2015年1月1的天数
		int week=0;//输入月份第一个月星期几
		//大于或等于2015年1月1日的日期
		if(year>=2015&& month>=1){ 
			for( int i = 2015;i< year;i++)
				overDays+=daysOfYear(i);
			
			overDays+=daysToMonth(year,month);
			week = (overDays%7+4);
			if(week>7)
				week=week%7;//算出给出月份的第一天是星期几
		}else{//小于2015年1月1日的日期
			for(int j= year;j<2015;j++){
				belowDays+=daysOfYear(j);
			}//年的天数
			belowDays-=daysToMonth(year,month);//减去月的天数
			week = 4-belowDays%7+7;
			if(week!=7)
				week=week%7;
		} 
		return week;
	}
	/**
	 * 打印本月日历
	 * @param week 这个月第一天星期几
	 * @param days0fMonth  这个月的天数
	 */
	 void printCalendar(int week,int days0fMonth){
		
		cout<<"一\t二\t三\t四\t五\t六\t日\t"<<endl;
		for( int j =1;j<week;j++)
			cout<<"\t";
		for(int i = 1;i<= days0fMonth;i++ ){
			cout<<i<<"\t";
			if( (i+week-1)%7==0 )
			  cout<<endl;
		//	cout<< ((i+week-1)%7==0)?"\n":"";
		}
	}
	//读数据
	 void readDate(int data[]) {
	 	cout<<"输入年："<<endl;
	 	cin>>data[0];
		cout<<"输入月："<<endl;
		cin>>data[1];
	}
	//a年内到b月1日份共度过了多少天（不包含b月1日)
	int daysToMonth(int year,int month){
		int allDays=0;//总天数
		for(int i=1;i< month;i++){
			allDays+=daysOfMonth(year,i);
		}
		return allDays;
	}
	
	//a年b月份的天数
	int daysOfMonth(int year,int month){
		if( month==1 ||month ==3|| month==5 ||month ==7|| month==8 ||month ==10||month==12){
			return 31;
		}else if( month==4 ||month ==6|| month==9 ||month ==11){
			return 30;
		}else if( year%4 ==0 && year %100!=0 ||( year%100==0 && year%400==0)){//闰年 4整除不能被100整除 或者能被100和400同时整除
			return 29;
		}else
		   return 28;
	}
	/**
	 * 某一年的总天数
	 * @param year
	 * @return
	 */
	int daysOfYear(int year){
	  if( year%4 ==0 && year %100!=0 ||( year%100==0 && year%400==0))//闰年
		  return 366;
	  else
		  return 365;
	}


