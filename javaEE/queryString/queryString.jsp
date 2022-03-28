<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<!-- run query string with form tag with two buttons -->
<%
int count=0;
String ctr=request.getParameter("counter");
if(ctr!=null){
	count=Integer.parseInt(ctr);
}
out.println(count);
%>
<a href="queryString.jsp?counter=<%=count-1%>" >previous</a>
<a href="queryString.jsp?counter=<%=count+1%>" >next</a>
</body>
</html>