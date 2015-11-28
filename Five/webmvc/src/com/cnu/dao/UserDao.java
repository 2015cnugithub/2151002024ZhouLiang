package com.cnu.dao;

import com.cnu.model.User;

/**
* @author 周亮 
* @version 创建时间：2015年11月20日 下午3:13:24
* 类说明
*/
public class UserDao {
	
	public User find(String username,String password){
		if( username.equals("zhangsan") && password.equals("123")){
			return new User(username, password);
		}else
			return null;
	}
}
