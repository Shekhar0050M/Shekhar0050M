package com.shekhar.user;

import java.util.HashMap;

import java.util.Map;

public class UserDAOImpl implements UserDAO {

	Map<Integer,User> users = new HashMap<>();
	@Override
	public void create(User u) {
		// TODO Auto-generated method stub
		users.put(u.getId(),u);
	}

	@Override
	public User read(int id) {
		// TODO Auto-generated method stub
		return users.get(id);
	}
}