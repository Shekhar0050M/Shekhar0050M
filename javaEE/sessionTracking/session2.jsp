<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<form action="purchase.jsp" method="post">
<select name="jeans">
<option>Levis</option>
<option>Wrangler</option>
<option>Zara</option>
<option>Advin</option>
</select>
<input type="hidden" value="<%=request.getParameter("watch") %>" name="watch">
<input type="hidden" value="<%=request.getParameter("cloth") %>" name="cloth">
<input type="submit" value="next">
</form> 
</body>
</html>