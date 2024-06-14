#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
	char fName[20];
	char lName[20];
}studName;

typedef struct{
	int month;
	int year;
}bday;

typedef struct{
	studName name;
	bday birthday;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[20];
	int studcount;
}classRecord;

void insertFirst(classRecord *CR, studentInfo stud){
	  int a;
	  for(a = CR->studcount;  a > 0; a--){
	  	CR->studList[a] = CR->studList[a-1];
	  }	
	  CR->studList[a] = stud;
	  CR->studcount++;
}

void insertLast(classRecord *CR, studentInfo stud){
	if(CR->studcount < 20){
		CR->studList[CR->studcount++] = stud;
	}
}

void insertAt(classRecord *CR, int pos, studentInfo stud){
	int a;
	for(a = CR->studcount; a > 0 && a < pos; a--){
		CR->studList[a] = CR->studList[a-1]; 
	}
	CR->studList[a] = stud;
	CR->studcount++;

}

void insertSorted(classRecord *CR, studentInfo stud){
	int a;
	for(a=CR->studcount - 1; a >= 0 && CR->studList[a].age > stud.age; a--){
		CR->studList[a+1] = CR->studList[a];
	}
	CR->studList[a+1] = stud;
	CR->studcount++;
}

void deleteRear(classRecord *CR){
	if(CR->studcount > 0){
		CR->studcount--;
	}
}

void deleteFront(classRecord *CR){
	int a;
	for(a = CR->studcount; a < 0; a++){
		CR->studList[a] = CR->studList[a+1];
	}
	CR->studcount--;
}

void display(classRecord CR){
	int a;
	printf("\n---START OF ARRAY---\n");
	for(a=0; a < CR.studcount; a++){
		printf("       \n");
		printf("ID Number: [%d]\n", CR.studList[a].idNum);
		printf("Student First Name: [%s]\n", CR.studList[a].name.fName);
		printf("Student Last Name: [%s]\n", CR.studList[a].name.lName);
		printf("Month: [%d]\n", CR.studList[a].birthday.month);
		printf("Year: [%d]\n", CR.studList[a].birthday.year);
		printf("Age: [%d]\n", CR.studList[a].age);
		printf("       \n");
	}
	printf("\n");
	printf("\n%1s---END OF ARRAY---\n\n" ," ");
}



int main(){
	classRecord CR;
	studentInfo stud;
	int times, i;
	printf("Input how many student records: ");
	scanf("%d", &times);
	


	for(i=0; i<times; i++){
	printf("Input Id Number:");
	scanf("%d", &CR.studList[times].idNum);
	stud.idNum = CR.studList[times].idNum;
	
	printf("Input Student First Name:");
	scanf("%s", &CR.studList[times].name.fName);
	strcpy(stud.name.fName, CR.studList[times].name.fName);
	
	printf("Input Student Last Name:");
	scanf("%s", &CR.studList[times].name.lName);
	strcpy(stud.name.lName, CR.studList[times].name.lName);
	
	printf("Birth Month (Int):");
	scanf("%d", &CR.studList[times].birthday.month);
	stud.birthday.month = CR.studList[times].birthday.month;
	
	printf("Birth Year (Int):");
	scanf("%d", &CR.studList[times].birthday.year);
	stud.birthday.year = CR.studList[times].birthday.year;
	
	printf("Input Age:");
	scanf("%d", &CR.studList[times].age);
	stud.age = CR.studList[times].age;

	
	
	printf("record inserted!\n");
	system("pause");
	

	}


	for(i=0; i<times; i++){
	int choice;
  	printf("Choose insertion method:\n1. Insert at beginning\n2. Insert at end\n3. Insert sorted by age\n");
    scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                insertFirst(&CR, CR.studList[times]);
                printf("Record #: %d", i); 
				display(CR);
                break;
            case 2:
                insertLast(&CR, CR.studList[times]);
                printf("Record #: %d", i); 
				display(CR);
                break;
            case 3:
                insertSorted(&CR, CR.studList[times]);
                printf("Record #: %d", i); 
				display(CR);
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }
		
		
	}
	
	int a, pos = 0;
	
	printf("-------------------------INSERTING AT POSITION--------------------\n");
	printf("Inserting at index: ");
	scanf("%d", &pos);
	
	for(a=0; a<=pos; a++){
	printf("Input Id Number:");
	scanf("%d", &CR.studList[pos].idNum);
	stud.idNum = CR.studList[pos].idNum;
	
	printf("Input Student First Name:");
	scanf("%s", &CR.studList[pos].name.fName);
	strcpy(stud.name.fName, CR.studList[pos].name.fName);
	
	printf("Input Student Last Name:");
	scanf("%s", &CR.studList[pos].name.lName);
	strcpy(stud.name.lName, CR.studList[pos].name.lName);
	
	printf("Birth Month (Int):");
	scanf("%d", &CR.studList[pos].birthday.month);
	stud.birthday.month = CR.studList[pos].birthday.month;
	
	printf("Birth Year (Int):");
	scanf("%d", &CR.studList[pos].birthday.year);
	stud.birthday.year = CR.studList[pos].birthday.year;
	
	printf("Input Age:");
	scanf("%d", &CR.studList[pos].age);
	stud.age = CR.studList[pos].age;
	
	
	
	printf("record inserted!\n");
	insertAt(&CR, pos, stud);
	display(CR);
	


	}
	
	
	


	
}




