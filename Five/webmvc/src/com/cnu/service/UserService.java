package com.cnu.service;

import com.cnu.dao.UserDao;
import com.cnu.model.User;

/**
* @author ���� 
* @version ����ʱ�䣺2015��11��20�� ����2:57:46
* ��˵��
*/
public class UserService {
	
	/**
	 * У��������û���
	 * @param username
	 * @param password
	 * @return ��ȷ����true
	 */
	public boolean validate(String username,String password){
		String namereg="\\w{3,10}";//ƥ����ĸ�����ֻ��»��߻���
		String passreg="\\S{3,10}";//ƥ�����ⲻ�ǿհ׷����ַ�
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
	 * ��¼
	 * @param username
	 * @param password
	 * @return ���ص�¼�û�
	 */
	public User login(String username,String password){
		UserDao dao = new UserDao();
		return dao.find(username, password);
		
	}
}
