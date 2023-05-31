#pragma once
#include "Function.h"

//.....��������.....

//....����������
void StudentsReading(Students* (&s), int& n, string filename) {
	ifstream reading(filename);

	if (reading) {
		Initials	initials;
		University	university;
		Date		date;
		Personal	personal;
		Subjects	subjects;
		Grades		grades;

		reading >> n;

		s = new Students[n]; //.... ������� ����

		for (int i = 0; i < n; i++) {
			reading >> initials.Lastname >> initials.Name;
			reading >> initials.Gender;

			reading >> date.BirthYear >> date.Age;

			reading >> university.Faculty;
			reading >> university.Kafedra;
			reading >> university.Group;
			reading >> university.Course;

			reading >> personal.HasChildren;
			reading >> personal.HasScholarship >> personal.ScholarshipAmount;

			reading >> subjects.Subject1 >> subjects.Grade1_1 >> subjects.Grade1_2;
			reading >> subjects.Subject2 >> subjects.Grade2_1 >> subjects.Grade2_2;
			reading >> subjects.Subject3 >> subjects.Grade3_1 >> subjects.Grade3_2;
			reading >> subjects.Subject4 >> subjects.Grade4_1 >> subjects.Grade4_2;
			reading >> subjects.Subject5 >> subjects.Grade5_1 >> subjects.Grade5_2;

			reading >> grades.ExamGrade1 >> grades.ExamGrade2 >> grades.ExamGrade3 >> grades.ExamGrade4 >> grades.ExamGrade5 >> grades.ExamGrade6 >> grades.ExamGrade7 >> grades.ExamGrade8;

			reading >> grades.DuplomTheme;

			//....������ ��� ��� 
			s[i].StudentsEntry(initials, university, date, personal, subjects, grades);
		}

		cout << "��� �������� ������ ������" << endl;
	}
	else
		cout << "������� ������� �������� �����" << endl;

	reading.close();

}
//....����
void StudentsPrint(Students* s, int n) {
	for (int i = 0; i < n; i++) {
		cout << " ������� �" << i + 1 << endl;

		s[i].Print();
		cout << "--------------------------------- \n";
		cout << "\n";
	}
}
//....����������
void SaveStudents(Students* s, int n, string filename) {
	ofstream record(filename);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
			record << s[i].GetInitials().Gender << endl;

			record << s[i].GetDate().BirthYear << " " << s[i].GetDate().Age << endl;

			record << s[i].GetUniversity().Faculty << endl;
			record << s[i].GetUniversity().Kafedra << endl;
			record << s[i].GetUniversity().Group << endl;
			record << s[i].GetUniversity().Course << endl;

			record << s[i].GetPersonal().HasChildren << endl;
			record << s[i].GetPersonal().HasScholarship << " " << s[i].GetPersonal().ScholarshipAmount << endl;

			record << s[i].GetSubjects().Subject1 << " " << s[i].GetSubjects().Grade1_1 << " " << s[i].GetSubjects().Grade1_2 << endl;
			record << s[i].GetSubjects().Subject2 << " " << s[i].GetSubjects().Grade2_1 << " " << s[i].GetSubjects().Grade2_2 << endl;
			record << s[i].GetSubjects().Subject3 << " " << s[i].GetSubjects().Grade3_1 << " " << s[i].GetSubjects().Grade3_2 << endl;
			record << s[i].GetSubjects().Subject4 << " " << s[i].GetSubjects().Grade4_1 << " " << s[i].GetSubjects().Grade4_2 << endl;
			record << s[i].GetSubjects().Subject5 << " " << s[i].GetSubjects().Grade5_1 << " " << s[i].GetSubjects().Grade5_2 << endl;

			record << s[i].GetGrades().ExamGrade1 << " " << s[i].GetGrades().ExamGrade2 << " " << s[i].GetGrades().ExamGrade3 << " " << s[i].GetGrades().ExamGrade4 << " " << s[i].GetGrades().ExamGrade5 << " " << s[i].GetGrades().ExamGrade6 << " " << s[i].GetGrades().ExamGrade7 << " " << s[i].GetGrades().ExamGrade8 << endl;

			record << s[i].GetGrades().DuplomTheme << endl;


			if (i < n - 1)
				record << endl;
		}
	}
	else
		cout << " ������� �������� ����� " << endl;

	cout << " ��� ���������� � ���� " << filename << endl;

	record.close();
}
//....���� �������� ���������� ����
void printStudentsByGroup(Students* (&s), int n, string faculty, string group) {

	cout << "�������� �� ��������� " << faculty << " ,�� ����������� � ����: " << group << endl;
	cout << "--------------------------------- \n";
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Faculty == faculty && s[i].GetUniversity().Group == group) {
			cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
			cout << "--------------------------------- \n";
			count++;
		}
	}
	cout << "�-��� ��������: " << count << endl;
}
//....���� �������� �����
void printStudentsByCourse(Students* (&s), int n, string faculty, int  course) {

	cout << "�������� �� ��������� " << faculty << " ,�� ������� �� " << course << " ���� " << endl;
	cout << "--------------------------------- \n";
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Faculty == faculty && s[i].GetUniversity().Course == course) {
			cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
			cout << "�����:" << s[i].GetUniversity().Group << endl;
			cout << "--------------------------------- \n";
			count++;
		}
	}
	cout << "� - ��� ��������: " << count << endl;
}
//....���� �������� �� �������� �� ���������� �������
void printStudentsByGrades(Students* (&s), int n, string group, string subject, int semester, int  grade) {

	int count = 0;
	cout << "C������� ����� " << group << ", �� ����� " << subject << " � " << semester << " �������, � �������:  " << grade << endl;
	cout << "--------------------------------- \n";
	for (int i = 0; i < n; i++) {
		if (semester == 1) {
			if  (s[i].GetUniversity().Group == group && ((s[i].GetSubjects().Subject1 == subject && s[i].GetSubjects().Grade1_1 == grade) ||
				(s[i].GetSubjects().Subject2 == subject && s[i].GetSubjects().Grade2_1 == grade) ||
				(s[i].GetSubjects().Subject3 == subject && s[i].GetSubjects().Grade3_1 == grade) ||
				(s[i].GetSubjects().Subject4 == subject && s[i].GetSubjects().Grade4_1 == grade) ||
				(s[i].GetSubjects().Subject5 == subject && s[i].GetSubjects().Grade5_1 == grade)))
			{
				cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
				cout << "--------------------------------- \n";
				count++;
			}
		}
		else if (semester == 2) {
			if  (s[i].GetUniversity().Group == group && ((s[i].GetSubjects().Subject1 == subject && s[i].GetSubjects().Grade1_2 == grade) ||
				(s[i].GetSubjects().Subject2 == subject && s[i].GetSubjects().Grade2_2 == grade) ||
				(s[i].GetSubjects().Subject3 == subject && s[i].GetSubjects().Grade3_2 == grade) ||
				(s[i].GetSubjects().Subject4 == subject && s[i].GetSubjects().Grade4_2 == grade) ||
				(s[i].GetSubjects().Subject5 == subject && s[i].GetSubjects().Grade5_2 == grade)))
			{
				cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
				cout << "--------------------------------- \n";
				count++;
			}
		}
	}
	cout << "�-��� ��������: " << count << endl;
}
//....���� �������� ����� �� ������� �� ��������� ����
void printStudentsExamsByGroup(Students* (&s), int n, string faculty,  string group, int exam, int examgrade ) {

	int count = 0;

	cout << "��������, �� ����� ���� �  " << exam << " � ������� " << examgrade << endl;
	cout << "�� ���������:  " << faculty << " � ����: " << group << endl;
	cout << "--------------------------------- \n";
	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Faculty == faculty && s[i].GetUniversity().Group == group) {
			int grade = 0;
			switch (exam) {
			case 1:
				grade = s[i].GetGrades().ExamGrade1;
				break;
			case 2:
				grade = s[i].GetGrades().ExamGrade2;
				break;
			case 3:
				grade = s[i].GetGrades().ExamGrade3;
				break;
			case 4:
				grade = s[i].GetGrades().ExamGrade4;
				break;
			case 5:
				grade = s[i].GetGrades().ExamGrade5;
				break;
			case 6:
				grade = s[i].GetGrades().ExamGrade6;
				break;
			case 7:
				grade = s[i].GetGrades().ExamGrade7;
				break;
			case 8:
				grade = s[i].GetGrades().ExamGrade8;
				break;

			default:
				cout << "������� ����� ���" << endl;
				return;
			}
			if (grade >= 90 && examgrade == 5 ||
				grade >= 75 && grade <= 89 && examgrade == 4 ||
				grade >= 60 && grade <= 74 && examgrade == 3 ||
				grade >= 40 && grade <= 59 && examgrade == 2 ||
				grade >= 0 && grade <= 39 && examgrade == 1) {
				cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << ", ������: " << grade << endl;
				count++;
			}
		}
	}
	cout << "�-��� ��������: " << count << endl;
}
//....���� �������� ����� �� ������� �� ��������� ����
void printStudentsExamsByCourse(Students* (&s), int n, string faculty, int  course, int exam, int examgrade ) {

	int count = 0;

	cout << "��������, �� ����� ���� �  " << exam << " � ������� " << examgrade << endl;
	cout << "�� ���������:  " << faculty << " ,�� ������� ��  " << course << "  ����" << endl;
	cout << "--------------------------------- \n";
	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Faculty == faculty && s[i].GetUniversity().Course == course) {
			int grade = 0;
			switch (exam) {
			case 1:
				grade = s[i].GetGrades().ExamGrade1;
				break;
			case 2:
				grade = s[i].GetGrades().ExamGrade2;
				break;
			case 3:
				grade = s[i].GetGrades().ExamGrade3;
				break;
			case 4:
				grade = s[i].GetGrades().ExamGrade4;
				break;
			case 5:
				grade = s[i].GetGrades().ExamGrade5;
				break;
			case 6:
				grade = s[i].GetGrades().ExamGrade6;
				break;
			case 7:
				grade = s[i].GetGrades().ExamGrade7;
				break;
			case 8:
				grade = s[i].GetGrades().ExamGrade8;
				break;

			default:
				cout << "������� ����� ���" << endl;
				return;
			}
			if (grade >= 90 && examgrade == 5 ||
				grade >= 75 && grade <= 89 && examgrade == 4 ||
				grade >= 60 && grade <= 74 && examgrade == 3 ||
				grade >= 40 && grade <= 59 && examgrade == 2 ||
				grade >= 0 && grade <= 39 && examgrade == 1) {
				cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << ", ������: " << grade << endl;
				count++;
			}
		}
	}
	cout << "�-��� ��������: " << count << endl;
}
//....���� �������� �����, �� ����� ������� � ��������� � ������ �������
void PrintStudentsByTeacher(Students* s, Teachers* t, int n, int k, string group, string teacherlastname, string teachername, string subject, int semester) {
	cout << "�������� ����� " << group << ", �� ����� " << subject << " � " << semester << " �������, � ������ �������" << endl;
	cout << "��������: " << teacherlastname << " " << teachername << endl;
	cout << "---------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Group == group) {
			int student_grade = 0;
			if (semester == 1) {
				if (s[i].GetSubjects().Subject1 == subject) {
					student_grade = s[i].GetSubjects().Grade1_1;
				}
				else if (s[i].GetSubjects().Subject2 == subject) {
					student_grade = s[i].GetSubjects().Grade2_1;
				}
				else if (s[i].GetSubjects().Subject3 == subject) {
					student_grade = s[i].GetSubjects().Grade3_1;
				}
				else if (s[i].GetSubjects().Subject4 == subject) {
					student_grade = s[i].GetSubjects().Grade4_1;
				}
				else if (s[i].GetSubjects().Subject5 == subject) {
					student_grade = s[i].GetSubjects().Grade5_1;
				}
			}
			else if (semester == 2) {
				if (s[i].GetSubjects().Subject1 == subject) {
					student_grade = s[i].GetSubjects().Grade1_2;
				}
				else if (s[i].GetSubjects().Subject2 == subject) {
					student_grade = s[i].GetSubjects().Grade2_2;
				}
				else if (s[i].GetSubjects().Subject3 == subject) {
					student_grade = s[i].GetSubjects().Grade3_2;
				}
				else if (s[i].GetSubjects().Subject4 == subject) {
					student_grade = s[i].GetSubjects().Grade4_2;
				}
				else if (s[i].GetSubjects().Subject5 == subject) {
					student_grade = s[i].GetSubjects().Grade5_2;
				}
			}

			for (int j = 0; j < k; j++) {
				if ((t[j].GetTeacherUniversity().TeachingGroup_sem1 == group && semester == 1) ||
					(t[j].GetTeacherUniversity().TeachingGroup_sem2 == group && semester == 2)) {
					if (t[j].GetTeachersInitials().Lastname == teacherlastname &&
						t[j].GetTeachersInitials().Name == teachername &&
						t[j].GetTeacherUniversity().Subject == subject ) {
						cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
						cout << "������: " << student_grade << endl;
						cout << "---------------------------------" << endl;
						break;  // ��������� ��������, ���� �������� ����������
					}
				}
			}
		}
	}
}
//....���� ��������, �� �������� �������� ������ �� ������� ������ (����'������ 4 ����)
void printStudentDuplomThemeByKafedra(Students* s, int n, string kafedra) {

	cout << " ��������, �� ����� �������� ������ �� ������: " << kafedra << endl;
	cout << "--------------------------------- \n";
	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Kafedra == kafedra && s[i].GetUniversity().Course == 4) {
			cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
			cout << " ���� ��������: " << s[i].GetGrades().DuplomTheme << endl;
			cout << "--------------------------------- \n";
			
		}
	}
}
//....���� ��������, �� �������� �������� ������ � ��������� ��������� (����'������ 4 ���� �������� �� �������� ����. ������.)
void printStudentDuplomThemeByTeacher(Students* s, Teachers* t, int n, int k, string teacherlastname, string teachername) {

	cout << "��������, �� ����� �������� ������ �: " << teacherlastname << " " << teachername << endl;
	cout << "--------------------------------- \n";
	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Course == 4) {
			bool found_teacher = false;
			for (int j = 0; j < k; j++) {
				if (t[j].GetTeachersInitials().Lastname == teacherlastname && t[j].GetTeachersInitials().Name == teachername && t[j].GetTeacherUniversity().KerivnukDuplom == 1 && t[j].GetTeacherUniversity().Kafedra == s[i].GetUniversity().Kafedra) {
					found_teacher = true;
					break;
				}
			}
			if (found_teacher) {
				cout << s[i].GetInitials().Lastname << " " << s[i].GetInitials().Name << endl;
				cout << "���� ��������: " << s[i].GetGrades().DuplomTheme << endl;
				cout << "--------------------------------- \n";
			}
		}
	}
}

//.....���������

//....����������
void TeachersReading(Teachers* (&t), int& k, string teacherfilename) {

	ifstream reading(teacherfilename);

	if (reading) {

		Initials			teacherinitials;
		Date				teacherdate;
		TeacherUniversity	teacherUniversity;
		TeacherPersonal		teacherPersonal;

		reading >> k;

		t = new Teachers[k]; //.... ������� ����

		for (int i = 0; i < k; i++) {

			reading >> teacherinitials.Lastname >> teacherinitials.Name;
			reading >> teacherinitials.Gender;

			reading >> teacherdate.BirthYear >> teacherdate.Age;

			reading >> teacherUniversity.TeachingType;
			reading >> teacherUniversity.Faculty;
			reading >> teacherUniversity.Kafedra;
			reading >> teacherUniversity.KandidTheme;
			reading >> teacherUniversity.DoctorTheme;
			reading >> teacherUniversity.Subject;

			reading >> teacherUniversity.SubjectType1 >> teacherUniversity.SubjectHours1_1 >> teacherUniversity.SubjectHours1_2;
			reading >> teacherUniversity.SubjectType2 >> teacherUniversity.SubjectHours2_1 >> teacherUniversity.SubjectHours2_2;

			reading >> teacherUniversity.TeachingGroup_sem1 >> teacherUniversity.TeachingGroup_sem2;
			reading >> teacherUniversity.CourseGroup_sem1 >> teacherUniversity.CourseGroup_sem2;

			reading >> teacherUniversity.IsAspirant;
			reading >> teacherUniversity.HasKandid;
			reading >> teacherUniversity.HasDoctor;
			reading >> teacherUniversity.KerivnukDuplom;

			reading >> teacherPersonal.HasChildren >> teacherPersonal.ChildrenAmount;

			reading >> teacherPersonal.Salary;

			//....������ ��� ��� 
			t[i].TeachersEntry(teacherinitials, teacherdate, teacherUniversity, teacherPersonal);
		}

		cout << "��� ���������� ������ ������" << endl;
	}
	else
		cout << "������� ������� �������� �����" << endl;

	reading.close();
}
//....����
void TeachersPrint(Teachers* t, int k) {
	for (int i = 0; i < k; i++) {
		cout << "�������� �" << i + 1 << endl;

		t[i].Print();
		cout << "--------------------------------- \n";
	}
}
//....����������
void SaveTeachers(Teachers* t, int k, string teacherfilename) {
	ofstream record(teacherfilename);

	if (record) {
		record << k << endl;

		for (int i = 0; i < k; i++) {
			record << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			record << t[i].GetTeachersInitials().Gender << endl;

			record << t[i].GetTeachersDate().BirthYear << " " << t[i].GetTeachersDate().Age << endl;

			record << t[i].GetTeacherUniversity().TeachingType << endl;
			record << t[i].GetTeacherUniversity().Faculty << endl;
			record << t[i].GetTeacherUniversity().Kafedra << endl;
			record << t[i].GetTeacherUniversity().KandidTheme << endl;
			record << t[i].GetTeacherUniversity().DoctorTheme << endl;
			record << t[i].GetTeacherUniversity().Subject << endl;

			record << t[i].GetTeacherUniversity().SubjectType1 << t[i].GetTeacherUniversity().SubjectHours1_1 << t[i].GetTeacherUniversity().SubjectHours1_2 << endl;
			record << t[i].GetTeacherUniversity().SubjectType2 << t[i].GetTeacherUniversity().SubjectHours2_1 << t[i].GetTeacherUniversity().SubjectHours1_2 << endl;

			record << t[i].GetTeacherUniversity().TeachingGroup_sem1 << t[i].GetTeacherUniversity().TeachingGroup_sem2 << endl;
			record << t[i].GetTeacherUniversity().CourseGroup_sem1 << t[i].GetTeacherUniversity().CourseGroup_sem2 << endl;

			record << t[i].GetTeacherUniversity().IsAspirant << endl;
			record << t[i].GetTeacherUniversity().HasKandid << endl;
			record << t[i].GetTeacherUniversity().HasDoctor << endl;
			record << t[i].GetTeacherUniversity().KerivnukDuplom << endl;

			record << t[i].GetTeacherPersonal().HasChildren << " " << t[i].GetTeacherPersonal().ChildrenAmount << endl;

			record << t[i].GetTeacherPersonal().Salary << endl;

			if (i < k - 1)
				record << endl;
		}
	}
	else
		cout << "������� �������� �����" << endl;

	cout << "��� ���������� � ���� " << teacherfilename << endl;

	record.close();
}
//....���� ���������� ��������� �������
void PrintTeachersByKafedra(Teachers* t, int k, string kafedra) {
	cout << "��������� �� ������:  " << kafedra << endl;
	cout << "--------------------------------- \n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().Kafedra == kafedra) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "--------------------------------- \n";
			count++;
		}
	}
	cout << "�-��� ����������: " << count << endl;
}
//....���� ���������� ����������
void PrintTeachersByFaculty(Teachers* t, int k, string faculty) {
	cout << "��������� �� ���������:  " << faculty << endl;
	cout << "--------------------------------- \n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().Faculty == faculty) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "--------------------------------- \n";
			count++;
		}
	}
	cout << "�-��� ����������: " << count << endl;
}
//....���� ���������� �� �����
void PrintTeachersByType(Teachers* t, int k, string type) {
	cout << "��������� �������:  " << type << endl;
	cout << "--------------------------------- \n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().TeachingType == type) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "--------------------------------- \n";
			count++;
		}
	}
	cout << "�-��� ����������: " << count << endl;
}
//....���� ����������, �� ��������� ������������ ��� ���������� (����� ������� �� ���������)
void PrintTeachersByKandidAndDoctor(Teachers* t, int k, string faculty, string kafedra) {
	cout << "���������, �� ��������� ������������ ��� ���������� ���������� �� ���������:  " << faculty << " ��� �������: " << kafedra << endl;
	cout << "--------------------------------- \n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().Faculty == faculty && t[i].GetTeacherUniversity().Kafedra == kafedra) {
			if (t[i].GetTeacherUniversity().TeachingType == "������") {
				cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
				cout << " ���� ������������: " << t[i].GetTeacherUniversity().KandidTheme << endl;
				cout << "--------------------------------- \n";
				count++;
			}
			else if (t[i].GetTeacherUniversity().TeachingType == "��������") {
				cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
				cout << " ���� ������������: " << t[i].GetTeacherUniversity().KandidTheme << endl;
				cout << " ���� ����������: " << t[i].GetTeacherUniversity().DoctorTheme << endl;
				cout << "--------------------------------- \n";
				count = count + 2;
			}
		}
	}
	cout << "�-��� ����: " << count << endl;
}
//....���� ������ �� ������, �� ��������� �������
void PrintKafedraByGroup(Students* s, int n, Teachers* t, int k, string faculty, string group, int semester) {
	cout << "�������, �� ��������� ������� �� ���������: " << faculty << " � ����: " << group << " � " << semester << " �������:" << endl;
	cout << "--------------------------------- \n";
	unordered_set<string> uniqueKafedra;

	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Faculty == faculty ) {
			for (int i = 0; i < k; i++) {
				if (semester == 1 && t[i].GetTeacherUniversity().TeachingGroup_sem1 == group) {
					uniqueKafedra.insert(t[i].GetTeacherUniversity().Kafedra);
				}
				if (semester == 2 && t[i].GetTeacherUniversity().TeachingGroup_sem2 == group) {
					uniqueKafedra.insert(t[i].GetTeacherUniversity().Kafedra);
				}
			}
		}
	}

	for (const auto& kafedra : uniqueKafedra) {
		cout << kafedra << endl;
	}
}
//....���� ������ �� ������, �� ��������� �������
void PrintKafedraByCourse(Students* s, int n, Teachers* t, int k, string faculty, int course, int semester) {
	cout << "�������, �� ��������� ������� �� ���������: " << faculty << " �� " << course << " ���� � " << semester << " �������:" << endl;
	cout << "---------------------------------\n";
	unordered_set<string> uniqueKafedra;

	for (int i = 0; i < n; i++) {
		if (s[i].GetUniversity().Faculty == faculty && s[i].GetUniversity().Course == course) {
			for (int j = 0; j < k; j++) {
				if (semester == 1 && t[j].GetTeacherUniversity().TeachingGroup_sem1 == s[i].GetUniversity().Group) {
					uniqueKafedra.insert(t[j].GetTeacherUniversity().Kafedra);
				}
				if (semester == 2 && t[j].GetTeacherUniversity().TeachingGroup_sem2 == s[i].GetUniversity().Group) {
					uniqueKafedra.insert(t[j].GetTeacherUniversity().Kafedra);
				}
			}
		}
	}

	for (const auto& kafedra : uniqueKafedra) {
		cout << kafedra << endl;
	}
}
//....���������, �� ���������(���������) ���������� ������� � ����
void PrintTeachersByGroup(Students* s, int n, Teachers* t, int k, string faculty, string group, string subject) {
	cout << "������, �� ���������(���������) ���������" << subject << " �� ��������� " << faculty << " � ����: " << group << endl;
	cout << "---------------------------------\n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		if ((t[i].GetTeacherUniversity().TeachingGroup_sem1 == group || t[i].GetTeacherUniversity().TeachingGroup_sem2 == group) &&
			t[i].GetTeacherUniversity().Subject == subject) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "---------------------------------\n";
			count++;
		}
	}
	cout << "�-���: " << count << endl;
}
//....���������, �� ���������(���������) ���������� ������� �� ����
void PrintTeachersByCourse(Students* s, int n, Teachers* t, int k, string faculty, string subject, int course) {
	cout << "������, �� ���������(���������) ���������: " << subject << " �� ��������� " << faculty << " �� " << course << " ����" << endl;
	cout << "---------------------------------\n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		if ( t[i].GetTeacherUniversity().Subject == subject) {
			for (int j = 0; j < n; j++) {
				if (s[j].GetUniversity().Faculty == faculty && s[j].GetUniversity().Course == course &&
					(t[i].GetTeacherUniversity().TeachingGroup_sem1 == s[j].GetUniversity().Group ||
						t[i].GetTeacherUniversity().TeachingGroup_sem2 == s[j].GetUniversity().Group)) {
					cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
					cout << "---------------------------------\n";
					count++;
					break; // ����� � ����� for, ���� �������� ��������� ��� ��������� ��������
				}
			}
		}
	}
	cout << "�-���: " << count << endl;
}
//....���� ��������� � ����� �� ������ � ����
void PrintSubjectTypeByGroup(Students* s, int n, Teachers* t, int k, string faculty, string group, int semester) {
	cout << "���������, �� ���������(���������) ������� �� ��������� " << faculty << " � ����: " << group << " � " << semester << " �������" << endl;
	cout << "---------------------------------\n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		bool found = false;
		for (int j = 0; j < n; j++) {
			if (s[j].GetUniversity().Faculty == faculty && (t[i].GetTeacherUniversity().TeachingGroup_sem1 == group || t[i].GetTeacherUniversity().TeachingGroup_sem2 == group)) {
				if ((semester == 1 && t[i].GetTeacherUniversity().TeachingGroup_sem1 == s[j].GetUniversity().Group) ||
					(semester == 2 && t[i].GetTeacherUniversity().TeachingGroup_sem2 == s[j].GetUniversity().Group)) {
					if (!found) {
						cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
						cout << "���� ������: " << t[i].GetTeacherUniversity().SubjectType1 << " �� " << t[i].GetTeacherUniversity().SubjectType2 << endl;
						cout << "---------------------------------\n";
						found = true;
						count++;
					}
				}
			}
		}
	}
	cout << "�-���: " << count << endl;
}
//....���� ��������� � ����� �� ������ �� ����
void PrintSubjectTypeByCourse(Students* s, int n, Teachers* t, int k, string faculty, int course, int semester) {
	cout << "���������, �� ���������(���������) ������� �� ��������� " << faculty << " �� " << course << " ����  � " << semester << " �������" << endl;
	cout << "---------------------------------\n";
	int count = 0;
	for (int i = 0; i < k; i++) {
		bool found = false;
		for (int j = 0; j < n; j++) {
			if (s[j].GetUniversity().Faculty == faculty) {
				if ((semester == 1 && t[i].GetTeacherUniversity().TeachingGroup_sem1 == s[j].GetUniversity().Group) ||
					(semester == 2 && t[i].GetTeacherUniversity().TeachingGroup_sem2 == s[j].GetUniversity().Group)) {
					if (s[j].GetUniversity().Course == course) {
						if (!found) {
							cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
							cout << "���� ������: " << t[i].GetTeacherUniversity().SubjectType1 << " �� " << t[i].GetTeacherUniversity().SubjectType2 << endl;
							cout << "---------------------------------\n";
							found = true;
							count++;
						}
					}
				}
			}
		}
	}
	cout << "�-���: " << count << endl;
}
//....���� ���������� �� ������ �����
void PrintExamTeachers(Teachers* t, int k, string group, string subject, int semester) {
	cout << "���������, �� ����� ������ � ���� " << group << ", � ��������� " << subject << " � " << semester << " �������:" << endl;
	cout << "---------------------------------\n";
	int count = 0;

	for (int i = 0; i < k; i++) {
		if ( t[i].GetTeacherUniversity().Subject == subject)  {
			if (semester == 1 && t[i].GetTeacherUniversity().CourseGroup_sem1 == group) {
				cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
				cout << " ��� �������: " << t[i].GetTeacherUniversity().TeachingType << endl;
			}
			if (semester == 2 && t[i].GetTeacherUniversity().CourseGroup_sem2 == group) {
				cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
				cout << " ��� �������: " << t[i].GetTeacherUniversity().TeachingType << endl;
			}
		}
	}
}
//....���� �������� ��������� ���� �� �����������
void PrintKerivnkDuplomByFaculty(Teachers* t, int k, string faculty) {
	cout << "�������� ��������� ���� � ���������� " << faculty << ":" << endl;
	cout << "---------------------------------" << endl;

	bool found = false;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().Faculty == faculty && t[i].GetTeacherUniversity().KerivnukDuplom == 1) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "---------------------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "�� ������ ��������� ���� �������� ��������� ����" << endl;
	}
}
//....���� �������� ��������� ���� �� ��������
void PrintKerivnkDuplomByKafedra(Teachers* t, int k, string kafedra) {
	cout << "�������� ��������� ���� � ������� " << kafedra << ":" << endl;
	cout << "---------------------------------" << endl;

	bool found = false;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().Kafedra == kafedra && t[i].GetTeacherUniversity().KerivnukDuplom == 1) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "---------------------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "�� ���� ������ ���� �������� ��������� ����" << endl;
	}
}
//....���� �������� ��������� �� ����� 
void PrintKerivnkDuplomByType(Teachers* t, int k, string type) {
	cout << "�������� ��������� ���� �� ����� ��������� " << type << endl;
	cout << "---------------------------------" << endl;

	bool found = false;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().TeachingType == type && t[i].GetTeacherUniversity().KerivnukDuplom == 1) {
			cout << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
			cout << "---------------------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << " ����� ��� �� �� ����������� ��� �������� ��������� ���� " << endl;
	}
}
//....���� �-��� ����� ������� 
void PrintTeachersWork(Teachers* t, int k) {
	cout << "������������ ����������:" << endl;
	cout << "----------------------" << endl;

	for (int i = 0; i < k; i++) {
		cout << "��������: " << t[i].GetTeachersInitials().Lastname << " " << t[i].GetTeachersInitials().Name << endl;
		cout << "----------------------" << endl;

		cout << "���������:" << t[i].GetTeacherUniversity().Subject << endl;
		cout << "----------------------" << endl;

		cout << "������:" << endl;
	    cout << t[i].GetTeacherUniversity().SubjectType1 << " 1 ���. " << t[i].GetTeacherUniversity().SubjectHours1_1 << " 2 ���. " << t[i].GetTeacherUniversity().SubjectHours1_2 << endl;
		cout << t[i].GetTeacherUniversity().SubjectType2 << " 1 ���. " << t[i].GetTeacherUniversity().SubjectHours2_1 << " 2 ���. " << t[i].GetTeacherUniversity().SubjectHours2_2 << endl;
		cout << "----------------------" << endl;
		cout << " \n" << endl;
	}
}
//....���� �-��� ����� �� ��������
void PrintSubjectHours(Teachers* t, int k) {

		std::map<std::string, int> subjectHours;

		for (int i = 0; i < k; i++) {
			TeacherUniversity university = t[i].GetTeacherUniversity();
			std::string subject = university.Subject;

			int practicalHours = university.SubjectHours1_1 + university.SubjectHours1_2;
			int labHours = university.SubjectHours2_1 + university.SubjectHours2_2;

			// ������ ������ �� ���������� ��������
			subjectHours[subject] += practicalHours + labHours;
		}

		// ������� ����� ����� ��� ������� ��������
		for (const auto& pair : subjectHours) {
			std::cout << "�������: " << pair.first << ", ��������� ����� �����: " << pair.second << std::endl;
		}
}
//....���� �-��� ����� ����������� ������� � ����������� �������
void PrintTeachersHoursBySemester(Teachers* t, int k, int semester, string teacherlastname, string teachername) {
	cout << "�������� ������������: " << teacherlastname  << " "<< teachername << " � " << semester << " ������� " << endl;
	cout << "----------------------" << endl;

	for (int i = 0; i < k; i++) {
		if (t[i].GetTeachersInitials().Lastname == teacherlastname && t[i].GetTeachersInitials().Name == teachername) {
			cout << "���������:" << t[i].GetTeacherUniversity().Subject << endl;
			cout << "----------------------" << endl;
			if (semester == 1) {
				cout << t[i].GetTeacherUniversity().SubjectType1 << " �-��� �����: " << t[i].GetTeacherUniversity().SubjectHours1_1 << endl;
				cout << t[i].GetTeacherUniversity().SubjectType2 << " �-��� �����: " << t[i].GetTeacherUniversity().SubjectHours2_1 << endl;
				cout << "�������� ������������: " << t[i].GetTeacherUniversity().SubjectHours1_1 + t[i].GetTeacherUniversity().SubjectHours2_1 << endl;
			}
			if (semester == 2) {
				cout << t[i].GetTeacherUniversity().SubjectType1 << " �-��� �����: " << t[i].GetTeacherUniversity().SubjectHours1_2 << endl;
				cout << t[i].GetTeacherUniversity().SubjectType2 << " �-��� �����: " << t[i].GetTeacherUniversity().SubjectHours2_2 << endl;
				cout << "�������� ������������: " << t[i].GetTeacherUniversity().SubjectHours1_2 + t[i].GetTeacherUniversity().SubjectHours2_2 << endl;
			}
		}
	}
}
//....���� �������� �-��� ����� ���������� �������
void PrintKafedraByHours(Teachers* t, int k, int semester, string kafedra) {
	cout << "�������� ������������ ���������� �������: " << kafedra << " � " << semester << " ������� " << endl;
	cout << "----------------------" << endl;

	int Total = 0;
	for (int i = 0; i < k; i++) {
		if (t[i].GetTeacherUniversity().Kafedra == kafedra) {
			if (semester == 1) {
				Total = Total + t[i].GetTeacherUniversity().SubjectHours1_1 + t[i].GetTeacherUniversity().SubjectHours2_1;
			}
			if (semester == 2) {
				Total = Total + t[i].GetTeacherUniversity().SubjectHours1_2 + t[i].GetTeacherUniversity().SubjectHours2_2;
			}
		}
	}
	cout << Total << endl;
}