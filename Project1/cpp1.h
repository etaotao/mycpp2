#pragma once
//��֤ͷ�ļ�ֻ������һ��
//Ensure the include compiled once
#ifndef CPP1_h
#define CPP1_h
//��ֹͷ�ļ���������� ��#ifndef��#endef��������),CP5_ex7_11_h�ǹ̶���ʽ��һ��Ϊͷ�ļ��Ĵ�д������
//Ensure the safe.It's the format(using #ifndef and #endef).
#include<string>
#include<iostream>

struct Sales_data {
	Sales_data() = default;
	//�����˹��캯��ϵͳ�Ͳ����Զ�����Ĭ�Ϲ��캯���ˣ���������������ṩϵͳ���ɵ�Ĭ�Ϲ��캯��
	Sales_data(const std::string& s): bookNo(s){}
	Sales_data(const std::string& s, unsigned n, double p) :bookNo(s), units_sold(n),4
		revenue(n*p) {}
	//���캯��
	Sales_data(std::istream& is);
	//IO�಻�ܱ�������ֻ��ͨ���������������ǣ���д������ı��������ݣ����Բ���const��
	std::string isbn() const { return bookNo; };
	//����isbn����������ֻ�Ƿ���bookNo��const������this��ָ������ָ��
	Sales_data& combine(const Sales_data&);
	//����combine����

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
//�����û����뵽�����������

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
	//���ص�����Ӻ�����ݣ�this��ʽ��ָ�������
}

#endif