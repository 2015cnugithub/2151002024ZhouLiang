package com.cnu.dao;

import com.cnu.model.User;

/**
* @author ���� 
* @version ����ʱ�䣺2015��11��20�� ����3:13:24
* ��˵��
*/
public class UserDao {
	
	public User find(String username,String password){
		if( username.equals("zhangsan") && password.equals("123")){
			return new User(username, password);
		}else
			return null;
	}
}
