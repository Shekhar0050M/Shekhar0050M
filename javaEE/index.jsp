<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%!
int x=10;
int y=40;
public int sum(){
	return x+y;
}
%>
<%
int z=sum();
out.print("sum is "+z);
%>
<%=10+20%>
</body>
</html>