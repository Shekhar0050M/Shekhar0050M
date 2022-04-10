package com.shekhar.user;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Unit test for simple App.
 */
public class AppTest 
{
    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue()
    {
    	UserDAOImpl dao = new UserDAOImpl();
    	User u = new User();
    	u.setId(1);
    	u.setName("shekhar");
    	u.setEmail("shekhar0050m@gmail.com");
    	dao.create(u);
    	
        assertTrue( true );
        assertEquals("shekhar",u.getName());
    }
}