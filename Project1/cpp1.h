#pragma once
//保证头文件只被编译一次
//Ensure the include compiled once
#ifndef CPP1_h
#define CPP1_h
//防止头文件被多次引入 用#ifndef和#endef（在下面),CP5_ex7_11_h是固定格式，一般为头文件的大写的名字
//Ensure the safe.It's the format(using #ifndef and #endef).
#include<string>
#include<iostream>

struct Sales_data {
	Sales_data() = default;
	//声明了构造函数系统就不再自动生成默认构造函数了，加上这个语句可以提供系统生成的默认构造函数
	Sales_data(const std::string& s): bookNo(s){}
	Sales_data(const std::string& s, unsigned n, double p) :bookNo(s), units_sold(n),4
		revenue(n*p) {}
	//构造函数
	Sales_data(std::istream& is);
	//IO类不能被拷贝，只能通过引用来传递他们，读写操作会改变流的内容，所以不用const，
	std::string isbn() const { return bookNo; };
	//声明isbn函数：作用只是返回bookNo，const是声明this是指向常量的指针
	Sales_data& combine(const Sales_data&);
	//声明combine函数

	std::string bookNo;
	unsigned units_sold = 0;;

	double revenue = 0.0;
};
std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

std::ostream&print(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(std::istream& is) {
	read(is, *this);
}
//保存用户输入到类里面的数据

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
	//返回的是相加后的数据，this隐式地指向该数据
}

#endif