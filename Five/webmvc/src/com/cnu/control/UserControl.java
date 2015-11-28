package com.cnu.control;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.cnu.model.User;
import com.cnu.service.UserService;

/**
 * Servlet implementation class UserControl
 *//*
@WebServlet(name="userControl" ,urlPatterns={"/login"})*/
public class UserControl extends HttpServlet {
	private static final long serialVersionUID = 1L;

	
	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		boolean flage = true;

		UserService userService = new UserService();
		//1.��ȡ��¼��Ϣ
		String username= request.getParameter("username");
		String password = request.getParameter("password");
		
		//2.У�������Ƿ���Ч
		if( !userService.validate(username, password)){
			request.setAttribute("error", "�û��������볤��Ϊ3-10�������пո�");
			flage = false;
		}else{
			
			//3.������Ϣ��ѯ���ݿ��ȡ�û�
			User user =userService.login(username, password);
			//4.�ж��Ƿ��¼�ɹ�
			if( user == null){
				//��¼ʧ��
				request.setAttribute("error", "�û���������������!");
				flage = false;
			}else{
				//��¼�ɹ�
				request.getSession().setAttribute("user", user);
			}
		}
		
		//5.���ݵ�¼���ת��
		if(flage){
			//�ɹ�������ҳ
			response.sendRedirect("main.jsp");
		}else{
			//ʧ�ܷ��ص�¼ҳ��

			request.setAttribute("username", username);
			request.setAttribute("password", password);
			request.getRequestDispatcher("/login.jsp").forward(request, response);
		}
	}
       
   

}
