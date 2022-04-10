package com.shekhar.user;

public interface UserDAO {
	void create(User u);
	User read(int id);
}
