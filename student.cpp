#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Student {
  public:
    Student(string full_name, int id, const vector<double>& marks) :
  		_full_name(full_name),
  		_id(id),
  		_marks(marks)
    {}
  
  string get_name() const {
    return _full_name;
  }
  
  int get_id() const {
    return _id;
  }
  
  vector<double> get_marks() const {
    return _marks;
  }
  
  double get_average() const {
    return accumulate(_marks.cbegin(), _marks.cend(), 0) / _marks.size();
  }
  
  private:
    string _full_name;
    int _id;
    vector<double> _marks;
};

class StudentDB {
private:
	vector<Student> _students_list;
  
	void print_student(const Student& s) {
		cout << "Name: "      << s.get_name() << "\n"
      	 << "ID: "        << s.get_id()   << "\n"
		     << "Marks Avg: " << s.get_average() << endl  << endl;
	};

public:
	StudentDB() {};
	typedef vector<Student>::iterator student_it;

	void add_student(string name, int id, vector<double> marks) {
		_students_list.push_back(Student(name, id, marks));
	}
  
	student_it find_student(string name) {
    auto s = _students_list.begin();
		for (; s != _students_list.end(); ++s) {
			if(s->get_name() == name)
				return s;
		}
		return s;
	}
  
	student_it find_student_id(int id) {
    auto s = _students_list.begin();
		for (; s != _students_list.end(); ++s) {
			if(s->get_id() == id)
				return s;
		}
		return s;
	}


	void remove_student(string name) {
		auto s = find_student(name);
		if(s != _students_list.cend())
			_students_list.erase(s);
	}

	void remove_student(int id) {
		auto s = find_student_id(id);
		if(s > _students_list.end())
			_students_list.erase(s);
	}

	void display_student(string name) {
		auto s = find_student(name);
		if(s != _students_list.end())
			print_student(*s);
		else
			cout << "Student not found!" << endl;
	}

	void display_student(int id) {
		auto s = find_student_id(id);
		if(s != _students_list.end())
			print_student(*s);
		else
			cout << "Student not found!" << endl;
	}
};

int main()
{
	StudentDB db;

	db.add_student("Ahmed", 101, vector<double>{95, 86, 96, 75});
	db.display_student(101);
	db.display_student("Ahmed");
	db.remove_student("Ahmed");
	db.display_student("Ahmed");

	return 0;
}

