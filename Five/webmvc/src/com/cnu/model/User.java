package com.cnu.model;
/**
* @author 周亮 
* @version 创建时间：2015年11月20日 下午2:10:24
* 类说明
*/
public class User {
	
	private String username;
	private String password;
	
	public User(String username, String password) {
		super();
		this.username = username;
		this.password = password;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	

}
