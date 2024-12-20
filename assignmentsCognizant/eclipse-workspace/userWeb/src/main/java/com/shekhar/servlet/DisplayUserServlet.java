package com.shekhar.servlet;

import java.io.IOException;

import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.shekhar.user.User;
import com.shekhar.user.UserDAO;
import com.shekhar.user.UserDAOImpl;

/**
 * Servlet implementation class DisplayUserServlet
 */

public class DisplayUserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		UserDAO dao = new UserDAOImpl();
		PrintWriter pw = response.getWriter();
		User u = dao.read(Integer.parseInt(request.getParameter("id")));
		pw.print(u.getName()+" "+ u.getEmail());
	}

}
