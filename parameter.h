#pragma once
#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>
#include <iostream>
enum class job_type
{
	unknown, full, partial, watch
};
// ���������� ������
class Vacancy {
private:
	// ����
	std::string work_name;
	job_type job;
	int salary;
public:
	// ����������� �� ���������
	Vacancy();
	// ����������� � �����������
	Vacancy(const std::string & work_name, int salary, job_type job);
	// ���������� �����������
	Vacancy(const Vacancy & p);
	// ���������� �����������
	Vacancy(Vacancy && p);
	// ���������� ������������
	Vacancy & operator = (const Vacancy & rsh);
	// ������������ ������������
	Vacancy & operator = (Vacancy && rsh);
	// ������ ��� �������� ���� salary
	int get_salary() const;
	// ������ ��� �������� ���� salary
	void set_salary(int salary);

	
	// ������ ��� job_type
	int get_job() const;
	// ������ ��� job_type
	void set_job(job_type job);


	// ������ ��� �������� ���� work_name
	const std::string & get_work_name() const;
	// ������ ��� �������� ���� work_name � ����������� �������
	void set_work_name(const std::string & work_name);
	// ������ ��� �������� ���� work_name � rsalary �������
	void set_work_name(std::string && work_name);
	// ������� ���������
	int compare(const Vacancy & to) const;
	// ��������� ��������� � ���� ������������� �������
	bool operator < (const Vacancy & rsh) const;
	bool operator > (const Vacancy & rsh) const;
	bool operator <= (const Vacancy & rsh) const;
	bool operator >= (const Vacancy & rsh) const;
	bool operator == (const Vacancy & rsh) const;
	bool operator != (const Vacancy & rsh) const;
	// ����������
	~Vacancy();
	// �������� ������ ��� ������������� �������
	friend std::ostream & operator << (std::ostream & out, const Vacancy & p);
};
#endif