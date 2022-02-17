#include "parameter.h"
using namespace std;
// Реализации конструкторов
Vacancy::Vacancy()
	: work_name("")
	, salary(0) {
}
Vacancy::Vacancy(const std::string & work_name, int salary, job_type job)
	: work_name(work_name)
	, job(job)
	, salary(salary) {
}
Vacancy::Vacancy(const Vacancy & p)
	: work_name(p.work_name)
	, job(p.job)
	, salary(p.salary) {
}
Vacancy::Vacancy(Vacancy && p)
	: work_name(move(p.work_name))
	, job(move(p.job))
	, salary(move(p.salary)) {
}
// Копирующее присваивание
Vacancy & Vacancy::operator = (const Vacancy & rsh) {
	this->work_name = rsh.work_name;
	this->job = rsh.job;
	this->salary = rsh.salary;
	return *this;
}
// Перемещающее присваивание
Vacancy & Vacancy::operator = (Vacancy && rsh) {
	this->work_name = move(rsh.work_name);
	this->job = move(rsh.job);
	this->salary = move(rsh.salary);
	return *this;
}
// Реализация геттеров и сеттеры

int Vacancy::get_job() const {
	return static_cast<int>(job);
}
void Vacancy::set_job(job_type job) {
	this-> job = job;
}

int Vacancy::get_salary() const {
	return salary;
}
void Vacancy::set_salary(int salary) {
	this->salary = salary;
}
const string & Vacancy::get_work_name() const {
	return work_name;
}
void Vacancy::set_work_name(const string & work_name) {
	this->work_name = work_name;
}
void Vacancy::set_work_name(string && work_name) {
	this->work_name = move(work_name);
}
// Экранирование строки
static string json_string(const string & s) {
	string json_s;
	json_s.append("\"");
	for (char c : s) {
		switch (c) {
		case '\n':
			json_s.append("\\n");
			break;
		case '\v':
			json_s.append("\\n");
			break;
		case '\0':
			json_s.append("\\0");
			break;
		case '\t':
			json_s.append("\\t");
			break;
		case '\r':
			json_s.append("\\r");
			break;
		case '"':
			json_s.append("\\\"");
			break;
		default:
			json_s.push_back(c);
		};
	}
	json_s.append("\"");
	return json_s;
}
//массив для вывода типа работы в формате string 
string types[4] = { "unknown", "full", "partial", "watch" };
// Дружественная функция имеет доступ непосредственно к полям
std::ostream & operator << (ostream & out, const Vacancy & p) {
	return out << "{ \"work_name\": " << json_string(p.work_name)
		<< ", \"salary\": " << p.salary<<" \"job_type\": "<< types[static_cast<int>(p.job)]<< " }";
}
// Функция сравнения
int Vacancy::compare(const Vacancy & to) const {
	int cmp;
	cmp = work_name.compare(to.work_name);
	if (cmp != 0) {
		return cmp;
	}
	cmp = salary - to.salary;
	return cmp;
}
// Операторы сравнения
bool Vacancy::operator < (const Vacancy & rsh) const {
	return compare(rsh) < 0;
}
bool Vacancy::operator > (const Vacancy & rsh) const {
	return compare(rsh) > 0;
}
bool Vacancy::operator <= (const Vacancy & rsh) const {
	return compare(rsh) <= 0;
}
bool Vacancy::operator >= (const Vacancy & rsh) const {
	return compare(rsh) >= 0;
}
bool Vacancy::operator == (const Vacancy & rsh) const {
	return compare(rsh) == 0;
}
bool Vacancy::operator != (const Vacancy & rsh) const {
	return compare(rsh) != 0;
}
// Деструктор
Vacancy::~Vacancy() {
}

void main()
{	
	Vacancy human1("cook", 15000, job_type::full);
	Vacancy human2("programmer", 10000, job_type::partial);
	cout << human1 << endl;
	cout << human2 << endl;
	human1.set_work_name("teacher");
	human1.set_salary(10000);
	human1.set_job(job_type::unknown);
	human2.set_work_name("courier");
	human2.set_salary(20000);
	human2.set_job(job_type::watch);
	Vacancy human3(human2);
	cout << human1 << endl << human2 << endl << human3 << endl;
	cout << human1.compare(human2);
}