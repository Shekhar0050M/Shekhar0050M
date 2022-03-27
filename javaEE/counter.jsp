<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.Random"% errorPage="file.html">
    <%@ include file="form.html"%>
<!-- ! Means declared once and does not change when page is refreshed , = means to print , <%%> means will change on each refresh command , errorPage se error ka request file.html mein chale jayega-->
<%!
int x=1;
%>
<%
//Random r = new Random();
String clr=request.getParameter("clr");
if(clr==null){
	clr="red";
}
%>
<body bgcolor='<%=clr%>'>
<%= "you are a visitor" + (x++) %>
</body>
</html>