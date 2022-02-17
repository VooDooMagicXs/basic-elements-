#pragma once
#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>
#include <iostream>
enum class job_type
{
	unknown, full, partial, watch
};
// Объявления класса
class Vacancy {
private:
	// Поля
	std::string work_name;
	job_type job;
	int salary;
public:
	// Конструктор по умолчанию
	Vacancy();
	// Конструктор с параметрами
	Vacancy(const std::string & work_name, int salary, job_type job);
	// Копирующий конструктор
	Vacancy(const Vacancy & p);
	// Копирующий конструктор
	Vacancy(Vacancy && p);
	// Копирующее присваивание
	Vacancy & operator = (const Vacancy & rsh);
	// Перемещающее присваивание
	Vacancy & operator = (Vacancy && rsh);
	// Геттер для простого поля salary
	int get_salary() const;
	// Сеттер для простого поля salary
	void set_salary(int salary);

	
	// Геттер для job_type
	int get_job() const;
	// Сеттер для job_type
	void set_job(job_type job);


	// Геттер для сложного поля work_name
	const std::string & get_work_name() const;
	// Сеттер для сложного поля work_name с константной ссылкой
	void set_work_name(const std::string & work_name);
	// Сеттер для сложного поля work_name с rsalary ссылкой
	void set_work_name(std::string && work_name);
	// Функция сравнения
	int compare(const Vacancy & to) const;
	// Операторы сравнения в виде дружественных функций
	bool operator < (const Vacancy & rsh) const;
	bool operator > (const Vacancy & rsh) const;
	bool operator <= (const Vacancy & rsh) const;
	bool operator >= (const Vacancy & rsh) const;
	bool operator == (const Vacancy & rsh) const;
	bool operator != (const Vacancy & rsh) const;
	// Деструктор
	~Vacancy();
	// Оператор вывода для дружественной функции
	friend std::ostream & operator << (std::ostream & out, const Vacancy & p);
};
#endif