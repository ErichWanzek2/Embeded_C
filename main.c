#include <stdio.h>
#include <stdlib.h>
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
struct student{   /*Define the structure student to store the student information parameters*/
  int ID;
  char first_name[20];
  char last_name[20];
  float exam1;
  float exam2;
  float examfinal;
  float total_score;
};

///////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION DECLARTIONS//
//Menu Functions
void Add_Records(struct student*,int);
void View_Records(struct student*, int);                
void View_Select(struct student*);                                  
void Student_Max(struct student*,int);                                 
void Student_Min(struct student*, int);                                 
void Score_Sort(struct student*, int);                      
//Sub Functions
void calculate_total_score(struct student*, int);
void display_function(struct student*,int,int);
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/* The Add_Records function uses a for loop to run through the inputed number of 
students and input each student's information into the program*/
void Add_Records(struct student *ss, int s){
  for(int i = 0; i < s; i++){
    printf("For Student %d Enter Information: \n",i);
    printf("Enter Students ID Number:\n");
    scanf("%d", &ss[i].ID);
    printf("Enter Students First Name:\n");
    scanf("%s",ss[i].first_name);
    printf("Enter Students Last Name:\n");
    scanf("%s",ss[i].last_name);
    printf("Enter Students Score on Exam 1:\n");
    scanf("%f", &ss[i].exam1);
    printf("Enter Students Score on Exam 2:\n");
    scanf("%f", &ss[i].exam2);
    printf("Enter Students Score on Final Exam:\n");
    scanf("%f", &ss[i].examfinal); 
    
    calculate_total_score(ss, s);
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////
/* The calculate_final_score function adds ups all the exam scores for each student 
and stores the total in the final_score parameter of the struct student*/
void calculate_total_score(struct student *ss, int s){
  for(int i = 0; i < s; i++){
    ss[i].total_score = ss[i].exam1 + ss[i].exam2 + ss[i].examfinal; 
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////
/*The display_function takes in the pointer to the student structures, the integer s 
representing the number of students, and the integer select represting a select student. 
If s is set to zero the function will display the records of the select student.
If s is not equal to zero the for loop will run to display all records for all students*/
void display_function(struct student *ss, int s, int select){
  printf("First Name:  \t");
  printf("Last Name:  \t");
  printf("ID:  \t");
  printf("Exam 1:  \t");
  printf("Exam 2:  \t");
  printf("Final Exam:  \t");
  printf("Final Score:");
  printf("\n");
  if (s==0){
    printf("\n");
    printf("%s \t\t",ss[select].first_name);
    printf("%s \t\t",ss[select].last_name);
    printf("%d \t\t", ss[select].ID);
    printf("%.2f \t\t", ss[select].exam1);
    printf("%.2f \t\t", ss[select].exam2);
    printf("%.2f \t\t", ss[select].examfinal);
    printf("%.2f \t\t", ss[select].total_score);
    printf("\n");
  }
  else
    for(int i = 0; i < s; i++){
      printf("\n");
      printf("%s \t\t",ss[i].first_name);
      printf("%s \t\t",ss[i].last_name);
      printf("%d \t\t", ss[i].ID);
      printf("%.2f \t\t", ss[i].exam1);
      printf("%.2f \t\t", ss[i].exam2);
      printf("%.2f \t\t", ss[i].examfinal);
      printf("%.2f \t\t", ss[i].total_score);
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////
/*The View_Records function calls the display_function and inputs parameter s as s so
 the diaplay drivers runs the foor loop and siplays all student records.*/
void View_Records(struct student *ss, int s){
  display_function(ss,s,s);

}
//////////////////////////////////////////////////////////////////////////////////////////////

/*The View_Select function calls the display_function and inputs parameter s as 0 so the 
diaplay driver fucntion displays a selcted student records.*/
void View_Select(struct student *ss){
  printf("Enter Index of student you want to view: \n");
  int select;
  int s = 0;
  scanf("%d", &select);
  display_function(ss, s, select);

}
//////////////////////////////////////////////////////////////////////////////////////////////
/*Shows first and last name of the student who has the max total score
When this option is selected, the first and last name of the student with the highest score is displayed*/
void Student_Max(struct student *ss, int s){
  int i;
  int j;
  float m;
  for(i=0; i<s; i++){
    if(ss[i].total_score > m){
      m =ss[i].total_score;
      j=i;
    }
    else
      m = m;
      j=j;
  }
  printf("The first an last name of the student with the highest final score is:");
  printf("%s \t\t",ss[j].first_name);
  printf("%s \t\t",ss[j].last_name);
}
///////////////////////////////////////////////////////////////////////////////////////////////
/*Shows first and last name of the student who has the min total score
When this option is selected, the first and last name of the student with the lowest score is displayed*/
void Student_Min(struct student *ss, int s){
  int i;
  int j;
  float m;
  for(i=0; i<s; i++){
    if(ss[i].total_score < m){
      m =ss[i].total_score;
      j=i;
    }
    else
      m = m;
      j=j;
  }
  printf("The first an last name of the student with the Lowest final score is:");
  printf("%s \t\t",ss[j].first_name);
  printf("%s \t\t",ss[j].last_name);
}
///////////////////////////////////////////////////////////////////////////////////////////////
/*View records sorted by total score When this option is selected, records of the students 
should be displayed sorted by total score (descending order, highest to lowest)*/
void Score_Sort(struct student *ss, int s){
  int i;
  int j;

  int order[s];
  //organize the array order to store indices of students by score
  for(i=0; i<s; i++){
    for(j=i; j<s; j++){
      if(ss[j].total_score > ss[i].total_score){
        order[i] = j;
      }
      else{
        order[j] = j;
      }
    }
  }
  //display student infor in the order of integers stored in array order
  for(i=0; i<s; i++){
    display_function(ss, 0, order[i]);
  }
}
  
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
int main(void){
  int s;                
  printf("Please enter the number of students\n");  //Ask user for amount of students
  scanf("%d", &s);
  
  struct student *ss;                                        // Define a struct pointer
  ss = (struct student*)malloc(s*(sizeof(struct student)));  // Dynamicaly allocate memory
  
  int run = 1;            //Initialize run condition variable
  int select;             //Initilize Menu Selction variable

  while(run==1)           //Run program while run equals 1, termiates otherwise
  {
    printf("Enter a number to choose one of the following menu options: \n");
    printf("Warning: Only enter an integer value \n");
    printf("\t 1. Add student records\n");
    printf("\t 2. View all student Records\n");
    printf("\t 3. View a selected student's records\n");
    printf("\t 4. Show first and last name of the student Who has the max total score  \n");
    printf("\t 5. Show first and last name of the student who has the min total score \n");
    printf("\t 6. View records sorted by total score  \n");
    printf("\t 7. Quit the program  \n");   

    scanf("%d",&select);
  
    /*Check if menu number selection is in menu range, set to 8 
    otherwise to trigger an error message in the swich menu*/
    if (select<1 || select>7){
      select = 8;
    }
    //Case statements to perform the menu system //
    switch(select){
      case(1):
        printf("You have selected: \n");
        printf("\t 1. Add student records\n");
        printf("Please enter records \n");
        Add_Records(ss,s);
        break;
      case(2):
        printf("You have selected: \n");
        printf("\t 2. View all student records\n");
        View_Records(ss, s);
        break;
      case(3):
        printf("You have selected: \n");
        printf("\t 3. View a selected student's record\n");
        View_Select(ss);
        break;
      case(4):
        printf("You have selected: \n");
        printf("\t 4. Show first and last name of the student Who has the max total score  \n");
        Student_Max(ss, s);
        break;
      case(5):
        printf("You have selected:");
        printf("\t 5. Show first and last name of the student who has the min total score \n");
        Student_Min(ss,s);
        break;
      case(6):
        printf("You have selected: \n");
        printf("\t 6. View records sorted by total score  \n");
        Score_Sort(ss,s);
        break;
      case(7):
        printf("You have selected: \n");
        printf("7. Quit the program  \n");
        printf("Program has ended");
        run=0;
        break;
      case(8):
        printf("Invalid Option Selcted \n");
        printf("Please Enter an Option Number Found In The Menu \n"); 
        break;
    }
  }
  return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////