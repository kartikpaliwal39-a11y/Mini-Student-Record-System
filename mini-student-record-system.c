#include <stdio.h>
#include <string.h>
struct Student 
{
int id;
char name[50];
float marks;
};
struct Student students[200]; 
int count = 0;
int i;                
FILE*fp;
void saveToFile() 
{
fp=fopen("Student.txt", "a"); // Open in append mode (overwrites file)//
if (fp == NULL) 
{
printf("Error opening file!\n");
}    
else
{
fprintf(fp, "%d %s %f\n", students[i].id, students[i].name, students[i].marks);
fclose(fp);
printf("Record saved to student.txt successfully\n");
}
}
void loadFromFile() 
{
fp= fopen("Student.txt", "a"); // Open in append mode//
count = 0;
while (fscanf(fp,"%d %s %f", &students[count].id, students[count].name, &students[count].marks) !=EOF);
{
count++;
}
fclose(fp);
}
void addStudent() 
{
if (count >= 100) 
{
printf("Memory full! Cannot add more students.\n");
return;
}
printf("\nEnter ID: ");
scanf("%d", &students[count].id);
printf("Enter Name (one word): ");
scanf("%s", students[count].name);
printf("Enter Marks: ");
scanf("%f", &students[count].marks);
count++;      
saveToFile(); 
}
void displayRecords() 
{
if (count == 0) 
{
printf("\nNo records found!\n");
return;
}
printf("\n--- All Student Records ---\n");
printf("ID\tName\t\tMarks\n");
for (int i = 0; i < count; i++) 
{
printf("%d\t%s\t\t%f\n", students[i].id, students[i].name, students[i].marks);
}
}
void searchStudent() 
{
int searchId, found = 0;
printf("\nEnter ID to search: ");
scanf("%d", &searchId);
for (int i = 0; i < count; i++) 
{
if (students[i].id == searchId) 
{
printf("Found: ID: %d, Name: %s, Marks: %f\n", students[i].id, students[i].name, students[i].marks);
found = 1;
break;
}
}
if (!found) 
{
printf("Student with ID %d not found.\n", searchId);
}
}
void deleteStudent() 
{
int deleteId, found = 0;
printf("\nEnter ID to delete: ");
scanf("%d", &deleteId);
for (int i = 0; i < count; i++) 
{
if (students[i].id == deleteId)
{
for (int j = i; j < count - 1; j++) 
{
students[j] = students[j + 1];
}
count--; 
found = 1;
printf("Student deleted successfully.\n");
saveToFile(); 
break;
}
}
if (!found) 
{
printf("Student with ID %d not found.\n", deleteId);
}
}
int main()
{
loadFromFile(); 
int choice;
while (1) 
{
printf("\n=== Mini Student Record System ===\n");
printf("1. Add Student\n");
printf("2. Display All Records\n");
printf("3. Search Student\n");
printf("4. Delete Student\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) 
{
case 1: addStudent();
break;
case 2: displayRecords(); 
case 3: searchStudent(); 
break;
case 4: deleteStudent(); 
break;
case 5: 
printf("Exiting Data is safe in %s\n", fp);
return 0;
default: printf("Invalid choice! Try again \n");
}
}
return 0;
}
