#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <unordered_set>
#include <map>


using namespace std;

struct Initials {
	//....ϲ� �� ����� 
	string	Lastname,
			Name,
			Gender;
};

struct University {
	//....��� �������� � ���������� 
	string	Faculty,
			Kafedra,
			Group;
	int		Course;
};

struct Date {
	//.... г� ���������� �� �� 
	int		BirthYear,
			Age;
};
 
struct Personal {
	//....������� ��� �������� 
	bool	HasChildren,
			HasScholarship;
	float	ScholarshipAmount;
};

struct Subjects {
	//.... 5 �������� � �������� (� ���� ��������)
	string	Subject1, 
			Subject2,
			Subject3,
			Subject4,
			Subject5;
	//.... ������ �� �������� 5 �������� �� ������� 
	//....�� 1 �� 2 �������
	int     Grade1_1, Grade1_2,
		    Grade2_1, Grade2_2,
			Grade3_1, Grade3_2,
			Grade4_1, Grade4_2,
			Grade5_1, Grade5_2;
};

struct Grades {
	//....������ �� ��� ( ����� ���� 2 ���, (2 ���� - 4 ���))	
	int		ExamGrade1,
			ExamGrade2,
			ExamGrade3,
			ExamGrade4,
			ExamGrade5,
			ExamGrade6,
			ExamGrade7,
			ExamGrade8;
	//....���� �������� ������ ( 4 ����) 
	string  DuplomTheme;
};

struct TeacherUniversity {
	string	TeachingType, //.... (��������, ��������, ������� ��������, ������, ��������)
		    Faculty,
			Kafedra, //.... �������
			KandidTheme, //....���� ������������ ������ (���� �) 
		    DoctorTheme,
			Subject, //.... �������, ���� ����
			SubjectType1,//.... 2 ���� ������ (��������:     1)�������� 2)����������  )                                   
			SubjectType2;//...................(��������:	 1)�������� 2)����������  )
	                     //...................(��. ��������: 1)�������� 2)����������  )
						 //...................(������:       1)�������  2)������       )
	                     //...................(��������:     1)������   2)������������ )
	int		SubjectHours1_1,//.... �-��� ����� ��� ����� ���� �������� 
			SubjectHours2_1,
	        SubjectHours1_2,//.... �-��� ����� ��� ����� ���� �������� 
		    SubjectHours2_2;

	string	TeachingGroup_sem1, //.... �����, ��� ������ � 1 ������� (�� ���� �������)
			TeachingGroup_sem2,//.... 2 ������� (�� ���� �������)
			CourseGroup_sem1, //.... �����, � ��� ���� ������� 
			CourseGroup_sem2;//.... 2 ������� 
			
	//....������ ���������� 
	bool	IsAspirant, //.... �� ��������� � ����������
			HasKandid, //....�� �������� ������������ 
			HasDoctor, //....�� �������� ���������� 
			KerivnukDuplom; //.... �� � ��������� �������� 

};

struct TeacherPersonal {
	//....������� ��� ��������� 
	bool	HasChildren;
	int		ChildrenAmount;
	float	Salary;
};

class Students {
	//.... ������� ������� ����� 
	private:

	Initials	initials;
	University	university;
	Date		date;
	Personal	personal;
	Subjects	subjects;
	Grades		grades;

	//....³������ ������� �����
	public:

	//....����'����� ������ �����
	Students();//���������� �� �������������. ������� ������ ��'��
	Students(Initials initials_, University university_, Date date_, Personal Personal_ ,Subjects Subjects_, Grades  Grades_);//����������� � �����������. ������� ��'��� � �����������.

	//.....�� ����'����� ������
	void Print();
	void StudentsEntry(Initials initials_, University university_, Date date_, Personal Personal_, Subjects Subjects_, Grades  Grades_);
	
	//....���� ����� � �����
	Initials	GetInitials()	{ return initials;	 };
	University	GetUniversity() { return university; };
	Date		GetDate()		{ return date;	     };
	Personal	GetPersonal()	{ return personal;   };
	Subjects	GetSubjects()	{ return subjects;   };
	Grades		GetGrades()		{ return grades;     };

	//....���������������� ���������
	Students& operator = (Students s_o);

};

class Teachers {
	//.... ������� ������� ����� 
	private:

	Initials			teacherinitials;
	Date				teacherdate;
	TeacherUniversity	teacherUniversity;
	TeacherPersonal		teacherPersonal;

	//....³������ ������� �����
	public:

	//....����'����� ������ �����
	Teachers();//���������� �� �������������. ������� ������ ��'��
	Teachers(Initials teacherinitials_, Date dteacherate_, TeacherUniversity teacherUniversity_, TeacherPersonal teacherPersonal_);//����������� � �����������. ������� ��'��� � �����������.

	//.....�� ����'����� ������
	void Print();
	void TeachersEntry(Initials initials_, Date date_, TeacherUniversity teacherUniversity_ , TeacherPersonal teacherPersonal_);

	//....���� ����� � �����
	Initials			GetTeachersInitials()		   { return teacherinitials;	};
	Date				GetTeachersDate()			   { return teacherdate;		};
	TeacherUniversity	GetTeacherUniversity()         { return teacherUniversity;  };
	TeacherPersonal		GetTeacherPersonal()           { return teacherPersonal;	};

	//....���������������� ���������
	Teachers& operator = (Teachers t_o);
};