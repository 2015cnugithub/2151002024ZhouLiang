package com.cnu.model;
/**
* @author ���� 
* @version ����ʱ�䣺2015��11��20�� ����2:10:24
* ��˵��
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
