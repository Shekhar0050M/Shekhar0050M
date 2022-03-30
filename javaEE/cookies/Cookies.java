/*
 * Cookie file size limit id 4 kb.
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Cookies
 */
@WebServlet("/Cookies")
public class Cookies extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Cookies() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter pw = response.getWriter();
		//getCookies will return an array of cookies.
		Cookie[] ckr = request.getCookies();
		//ck to store the value of detail of current session
		Cookie ck=null;
		//sdf to declare the format ** new date format api **
		SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss");
		//dt to store the value od time in given format
		String dt =sdf.format(new Date());
		if(ckr!=null) {
			for(Cookie c :ckr) {
				if(c.getName().equals("lastvisit")){
					pw.println("Your last visit was at: " + c.getValue());
					c.setValue(dt);
					ck=c;
				}
			}
		}
		else {
			pw.println("This is your first visit.");
			ck= new Cookie("lastvisit",dt);
		}
		//Expire time by default is in seconds.
		ck.setMaxAge(10);
		//adding of cookie details in browser and we have to store it the values will be further obtained explicitly. 
		response.addCookie(ck);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
