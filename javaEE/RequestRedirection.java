import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class RequestRedirection
 */
@WebServlet("/RequestRedirection")
public class RequestRedirection extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public void doPost(HttpServletRequest request,HttpServletResponse response) throws IOException, ServletException{
		PrintWriter pw = response.getWriter();
		String name=request.getParameter("name");
		if(name.equals("shekhar0050m")) {
			pw.println("<html><body>Hello there</body></html>");
		}
		else {
			response.sendRedirect("https://www.google.com/search?q="+name);
		}
	}
}
