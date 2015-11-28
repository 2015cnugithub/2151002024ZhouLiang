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
		//1.获取登录信息
		String username= request.getParameter("username");
		String password = request.getParameter("password");
		
		//2.校验数据是否有效
		if( !userService.validate(username, password)){
			request.setAttribute("error", "用户名或密码长度为3-10，不能有空格！");
			flage = false;
		}else{
			
			//3.根据信息查询数据库获取用户
			User user =userService.login(username, password);
			//4.判断是否登录成功
			if( user == null){
				//登录失败
				request.setAttribute("error", "用户名或者密码有误!");
				flage = false;
			}else{
				//登录成功
				request.getSession().setAttribute("user", user);
			}
		}
		
		//5.根据登录结果转发
		if(flage){
			//成功进入主页
			response.sendRedirect("main.jsp");
		}else{
			//失败返回登录页面

			request.setAttribute("username", username);
			request.setAttribute("password", password);
			request.getRequestDispatcher("/login.jsp").forward(request, response);
		}
	}
       
   

}
