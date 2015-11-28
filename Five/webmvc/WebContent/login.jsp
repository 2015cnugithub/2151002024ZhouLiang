<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<base href="<%=basePath%>">   
<title>标题</title> 
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>
	<body>
	<span style="color: red;">${error }</span>
	<form action="login" method="post">
		 用户名：<input type="text" name="username" value="${username }">
		 密码：    <input type="password" name="password" value="${password }">
		       <input type="submit" value="登录">
	</form>
	</body>
</html>