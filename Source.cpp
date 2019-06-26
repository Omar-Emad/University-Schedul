# include <iostream>
# include <string>
# include <math.h>

using namespace std;

class date 
{
	int month, year , day ;

//=========== function to set day month year in the class =====================================================

public: 
	void set_date(string date1 )                   //set_date(string date)
	{
	    int c=0;
		int z=0;
		for(int i=0;i<=date1.length();i++)
		{
			char letter=date1[i];
		    if(letter=='/'&&c==0)
			{
				day=atof(date1.substr(z,i-z).c_str());
		        c++;
			    z=i+1;
			}
			else if(letter=='/'&&c==1)
			{
				month=atof(date1.substr(z,i-z).c_str());
			    c++;
			    z=i+1;
			}
			else if(i==date1.length())
			{
				year=atof(date1.substr(z,i-z).c_str());
			}
		}
	}


//============ function to clac. the greater date =================================================================

	string is_greater(int n,string date1[100])
	{
		date mydate[100];
		for(int i=0;i<n;i++)
		{
			mydate[i].set_date(date1[i]);
		}
		date great=mydate[0];
		for(int j=1;j<n;j++)
		{
			if(mydate[j].year>great.year)
			{
				great=mydate[j];
			}
			else if(mydate[j].month>great.month&&mydate[j].year==great.year)
			{
				great=mydate[j];
			}
			else if(mydate[j].day>great.day&&mydate[j].month==great.month&&mydate[j].year==great.year)
			{
				great=mydate[j];
			}
		}
		string x=to_string(great.day)+"/"+to_string(great.month)+"/"+to_string(great.year);
		return x;
	}

//================================================================================================================
	string is_lesser(int n,string date1[100])
	{
		date mydate[100];
		for(int i=0;i<n;i++)
		{
			mydate[i].set_date(date1[i]);
		}
		date less=mydate[0];
		for(int j=1;j<n;j++)
		{
			if(mydate[j].year<less.year)
			{
				less=mydate[j];
			}
			else if(mydate[j].month<less.month&&mydate[j].year==less.year)
			{
				less=mydate[j];
			}
			else if(mydate[j].day<less.day&&mydate[j].month==less.month&&mydate[j].year==less.year)
			{
				less=mydate[j];
			}
		}
		string x=to_string(less.day)+"/"+to_string(less.month)+"/"+to_string(less.year);
		return x;
	}
//===========================================================================================================================
	int period_indays (string str1, string str2)
	{
		cout<<str1<<str2;
		int days=0;
		date date1;
		date date2;
		date1.set_date(str1);
		date2.set_date(str2);
		if(date1.month==date2.month)
		{
		days=days+date2.day-date1.day+2;
		}
		else
		{
		switch(date1.month)
		{
		case(1) : days=days+31-date1.day+1;
			      break;
		case(2) : if((date1.year % 4 == 0 && date1.year % 100 != 0) || ( date1.year % 400 == 0))
					  days=days+29-date1.day+1;
				  else days=days+28-date1.day+1;
				  break;
		case(3) : days=days+31-date1.day+1;
			      break;
		case(4) : days=days+30-date1.day+1;
			      break;
		case(5) : days=days+31-date1.day+1;
			      break;
		case(6) : days=days+30-date1.day+1;
			      break;
		case(7) : days=days+31-date1.day+1;
			      break;
		case(8) : days=days+31-date1.day+1;
			      break;
		case(9) : days=days+30-date1.day+1;
			      break;
		case(10) : days=days+31-date1.day+1;
			      break;
		case(11) : days=days+30-date1.day+1;
			      break;

		}
		days=days+date2.day;
		}
		return days;
	}
};

//============= function number of halls ================================================================================
int number_halls (int n, string str[100])
{
	string x[100];
	int m=1;
	x[0]=str[0];
	for (int i=1;i<n;i++)
	{
		int flag=0;
		for(int j=0;j<m;j++)
		{
			if(str [i]== x [j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			x[m]=str[i];
			m++;
		}
	}
	return m;
}
//============ function max student id =====================================================================
int max_id(int n ,string str[100])        //max_id(number of students , students code array )
{
	int max_id=atof(str[0].c_str());
	for(int i=1;i<n;i++)
	{
		if(atof(str[i].c_str())>max_id)
		{
			max_id=atof(str[i].c_str());
		}
	}
	return max_id;
}
//============== function min student id =========================================================================
int min_id(int n ,string str[100])        //min_id(number of students , students code array )
{
	int min_id=atof(str[0].c_str());
	for(int i=1;i<n;i++)
	{
		if(atof(str[i].c_str())<min_id)
		{
			min_id=atof(str[i].c_str());
		}
	}
	return min_id;
}
//============== only Student Dropped IDs ============================================================================
int is_dropped (int n,string str[100], int x) //students_id_dropped(number of students,student code array,student code)
{                                              // this fun will return the id if it is dropped and it will return 0 if the id isnt dropped 
	int flag=0;
	//for(int i=min_id(n,str);i<max_id(n,str);i++)
	for(int i=0;i<n;i++)
	{
		//for(j=0;j<n;j++)
		if(x==atof(str[i].c_str()))
			flag=1;
	}
	if (flag==0)
		return x;
	return 0;
}
//=============== function =================================================================

int main ()
{
//=============input from the user================================================================================
	string osaksad;
	getline (cin,osaksad);
	string coursesexames=osaksad.substr(14,osaksad.length()-15);
	string sadasdsad;
	getline (cin,sadasdsad);
	string students=sadasdsad.substr(10,sadasdsad.length()-11);
//=============creat courses arraies===============================================================================
	int x=0,number_courses=0;
	string courses_code [100];
	string courses_name [100];
	string exames_date [100];
	string exames_location [100];
	for(int i=0;i<=coursesexames.length();i++)
	{
		char semicolon=coursesexames[i];
		if(semicolon==';'||i==coursesexames.length())
		{
			string single_course=coursesexames.substr(x,i-x);
	    	int c=1,y=0;
			for(int j=0;j<=single_course.length();j++)
			{
				char comma=single_course[j];
				if(comma==','||j==single_course.length())
				{
					switch(c)
					{
					case 1:
						{ 
							courses_code[number_courses]=single_course.substr(y,j-y);
							c++;
							y=j+1;
							break ;
						}
					case 2: 
						{
							courses_name[number_courses]=single_course.substr(y,j-y);
							c++;
							y=j+1;
							break;
						}
					case 3: 
						{
							exames_date[number_courses]=single_course.substr(y,j-y);
							c++;
							y=j+1;
							break ;
						}
					case 4:
						{
							exames_location[number_courses]=single_course.substr(y,i-y);
							break;
						}
					 }
			     }
			}
			number_courses++;
			x=i+1;
	    }
		   /*else if(i==coursesexames_length)
		        {   
				  /* string single_course=coursesexames.substr(x,coursesexames_length);
				   int single_course_length=single_course.length();
				   int c=1;
				   for(int j=0;j<single_course_length;j++)
				      {
						  char comma=single_course[j];
						  if(comma=',')
						  {
							  switch(c)
							        {
							            case 1: { 
											        courses_code[z]=single_course.substr(y,j-y);
													c++;
													y=j+1;
													break ;
												}
										case 2: {
											        courses_name[z]=single_course.substr(y,j-y);
													c++;
													y=j+1;
													break;
												}
										case 3: {
											        exames_date[z]=single_course.substr(y,j-y);
													y=j+1;
													exames_location[z]=single_course.substr(y,single_course_length);
													break;
												}
							         }
							  z++;
						   }
				      }
		        }*/
	     }

//=============creat students arraies===========================================================================

	int z=0,number_students=0;
	string students_code [100];
	string students_name [100];
	string students_courses [100];
	for(int i=0;i<=students.length();i++)
	{
		char semicolon=students[i];
		if(semicolon==';'||i==students.length())
		{
			string single_student=students.substr(z,i-z);
	    	int c=1,y=0;
			for(int j=0;j<=single_student.length();j++)
			{
				char comma=single_student[j];
				if(comma==','||j==single_student.length())
				{
					switch(c)
					{
					case 1:
						{ 
							students_code[number_students]=single_student.substr(y,j-y);
							c++;
							y=j+1;
							break ;
						}
					case 2: 
						{
							students_name[number_students]=single_student.substr(y,j-y);
							c++;
							y=j+2;
							break;
						}
					case 3:
						{
							students_courses[number_students]=single_student.substr(y,i-y-1);
							break;
						}
					 }
			     }
			}
			number_students++;
			z=i+1;
	    }
	}
//================= the options ===========================================================================================
	string user_input;
	while(1)
	{
		cin>>user_input;
//=============== quit option ===========================================================================================
		if(user_input=="Quit")
		{
			cout<<"Thanks!\n";
			break;
		}

//=============== number of halls =========================================================================================
		
		else if(user_input=="Number_Halls")
			cout<<number_halls(number_courses,exames_location)<<"\n";

//============= number of students =========================================================================================== 
		
		else if(user_input=="Number_Students")
			cout<<number_students<<"\n";

//============= number of courses =======================================================================================
		
		else if(user_input=="Number_Courses")
			cout<<number_courses<<"\n";

//============== max student id ==============================================================================================
		
		else if(user_input=="Student_ID_Max")
			cout<<max_id(number_students,students_code)<<"\n";

//============== min student id =========================================================================================
	
		else if(user_input=="Student_ID_Min")
			cout<<min_id(number_students,students_code)<<"\n";

//============= Students_Dropped_IDs =========================================================================================
		
		else if(user_input=="Students_Dropped_IDs")
		{
			//string code;
			for(int i=min_id(number_students,students_code);i<max_id(number_students,students_code);i++)
			{
				//cout<<i;
				//code=students_code[i];
				//student_dropped=is_dropped(number_students,students_code,code);
				if(is_dropped(number_students,students_code,i)!=0)
					cout<<is_dropped(number_students,students_code,i)<<"\n";
			}
		}

//============== Exams start date ==============================================================================================

		if(user_input=="Exams_Start_Date")
		{
			date dsf;
            cout<<dsf.is_lesser(number_courses,exames_date)<<endl;
		}

//============== Exams Start Date ===============================================================================================

		if(user_input=="Exams_End_Date")
		{
			date asd;
			cout<<asd.is_greater(number_courses,exames_date)<<endl;
		}

//============== Exames piriod in days =========================================================================================
		if(user_input=="Exams_Period_InDays")
		{
			date sish;
			cout<<sish.period_indays(sish.is_lesser(number_courses,exames_date),sish.is_greater(number_courses,exames_date))<<endl;
		}
	}
	
	
	

				   


	return 0;

	}										     
	                                               										










