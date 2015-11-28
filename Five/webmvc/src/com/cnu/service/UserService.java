package com.cnu.service;

import com.cnu.dao.UserDao;
import com.cnu.model.User;

/**
* @author 周亮 
* @version 创建时间：2015年11月20日 下午2:57:46
* 类说明
*/
public class UserService {
	
	/**
	 * 校验密码和用户名
	 * @param username
	 * @param password
	 * @return 正确返回true
	 */
	public boolean validate(String username,String password){
		String namereg="\\w{3,10}";//匹配字母或数字或下划线或汉字
		String passreg="\\S{3,10}";//匹配任意不是空白符的字符
		if( null==username || null==password){
			return false;
		}
		System.out.println(username.matches(namereg)+":"+password.matches(passreg));
		if( username.matches(namereg) && password.matches(passreg)){
			return true;
		}
		return false;
	}
	/**
	 * 登录
	 * @param username
	 * @param password
	 * @return 返回登录用户
	 */
	public User login(String username,String password){
		UserDao dao = new UserDao();
		return dao.find(username, password);
		
	}
}
