package com.shekhar.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.shekhar.user.User;
import com.shekhar.user.UserDAO;
import com.shekhar.user.UserDAOImpl;

/**
 * Servlet implementation class AddUserServlet
 */
public class AddUserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		int id = Integer.parseInt(request.getParameter("id"));
		String name = request.getParameter("name");
		String email = request.getParameter("email");
		User user = new User();
		UserDAO dao = new UserDAOImpl();
		user.setId(id);
		user.setName(name);
		user.setEmail(email);
		dao.create(user);
	}

}
