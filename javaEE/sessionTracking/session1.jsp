<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<form action="session2.jsp" method="post">
<select name="cloth">
<option>Jockey</option>
<option>Levis</option>
<option>Varmooda</option>
<option>Lee Cooper</option>
</select>
<input type="hidden" value="<%=request.getParameter("watch") %>" name="watch">
<input type="submit" value="next">
</form> 
</body>
</html>