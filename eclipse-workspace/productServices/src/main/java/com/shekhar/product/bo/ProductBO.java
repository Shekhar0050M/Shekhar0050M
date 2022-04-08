package com.shekhar.product.bo;

import com.shekhar.product.dto.Product;

public interface ProductBO {
	
	void create(Product product);
	Product findProduct(int id);
}
