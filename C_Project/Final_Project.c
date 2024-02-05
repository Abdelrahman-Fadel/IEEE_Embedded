/*
 ======================================================================================================================
 Program     : Doctor clinic
 Author      : Abdelrahman Fadel, Osama Saber, Yousif Elbagory, Mohamed Adel
 Created on	 : January 31, 2024
 Description : IEEE C project
 ======================================================================================================================
 */

#include <stdio.h>
#define max_patients 50

int id , cost;
struct patient {
	int _ID , age;
	char first_name[50];
	char last_name[50];
	char gender[15];
	char blood_type[5];
	char contact_number[12];
};
struct patient arr[max_patients];
void choose() {
	printf("Please choose one of this operations :\n");
	printf("1 -> Add new patient\n");
	printf("2 -> Print data of patient\n");
	printf("3 -> Delete patient data\n");
	printf("4 -> Update patient data\n");
	printf("5 -> Exit\n");
	}


int check_id (int id) {
	if (arr[id-1]._ID==0) return 0;
	else return 1;
}

void booking(int id){
	int static booking_number , e_hour=4 , e_minute=0 , examination_day=3 , e_month=2, c_hour=4 , c_minute=0 , consultation_day=4 , c_month=2 ;
	printf("for Examination enter -> 1 for consultation enter -> 2 : ");
	scanf("%d" , &booking_number);
	if (booking_number==1){
		printf("Your ID is : %d, please don't forget it!\n",arr[id-1]._ID);
		if (arr[id-1].age<=12) { 
			printf("Cost is : 200$\n");
			cost+=200;
		}
		else { 
			printf("Cost is : 300$\n");
			cost+=300;
		}
		printf("You should go to clinic at %d:%d pm, %d/%d/2023\n" , e_hour , e_minute , examination_day , e_month);
		
		if (e_minute==40) { e_minute=0 ; e_hour++; } else e_minute+=20;
		if (e_hour==7) {examination_day+=2 ; e_hour=4 ; } 
		
	}
	else {
		printf("Your ID is : %d, please don't forget it!\n",arr[id-1]._ID);
		printf("Cost is : 150$\n");
		cost+=150;
		printf("You should go to clinic at %d:%d pm, %d/%d/2023\n" , c_hour , c_minute , consultation_day , c_month);
		
		if (c_minute==45) { c_minute=0 ; c_hour++; } else c_minute+=15;
		if (c_hour==7) { consultation_day+=2 ; c_hour=4 ; }

	}
}

// 1
void add() {
	id++;
	arr[id-1]._ID=id;
	printf("Enter your first name : "); 
	scanf("%s", &arr[id-1].first_name);
	printf("Enter your last name : "); 
	scanf("%s", &arr[id-1].last_name);
	printf("Enter your age : "); 
	scanf("%d", &arr[id-1].age);
	printf("Enter your gender : "); 
	scanf("%s", &arr[id-1].gender);
	printf("Enter your blood type : "); 
	scanf("%s", &arr[id-1].blood_type);
	printf("Enter your contact number : "); 
	scanf("%s", &arr[id-1].contact_number);
	booking(arr[id-1]._ID);
}

// 2
void print_data(int id) {
	if ( check_id(id) ) {
		printf("ID : %d\n" , arr[id-1]._ID);
		printf("Name : %s %s\n" , arr[id-1].first_name , arr[id-1].last_name);
		printf("Age : %d\n" , arr[id-1].age);
		printf("Gender : %s\n" , arr[id-1].gender);
		printf("Blood type : %s\n" , arr[id-1].blood_type);
		printf("Contact number : %s\n" , arr[id-1].contact_number);
	}
	else {
		printf("Wrong ID\n");
	}
}

// 3
void delete(int id) {
	if ( check_id(id) ) {
		arr[id-1]._ID=0;
		printf("Successfully deleted\n");
	}
	else {
		printf("Wrong ID\n");
	}
}

// 4
void update(int id) {
	if ( check_id(id) ) {
		printf("Enter your updated age : "); scanf("%d",&arr[id-1].age);
		printf("Enter your updated contact number : "); scanf("%s",&arr[id-1].contact_number);
		booking(arr[id-1]._ID);
	}
	else {
		printf("Wrong ID\n");
	}
}


int main () {
	int input_id , choice_number;
	while (1){
		printf("\n");
		choose();
		scanf("%d",&choice_number);
		if (choice_number==1) add(); 
		if (choice_number==2) { printf("Please enter the ID : "); scanf("%d", &input_id); print_data(input_id); }
		if (choice_number==3) { printf("Please enter the ID : "); scanf("%d", &input_id); delete(input_id); }
		if (choice_number==4) { printf("Please enter the ID : "); scanf("%d", &input_id); update(input_id); }
		if (choice_number==5){
		printf("Number of patients is : %d\n", id);
		printf("Total cost is : %d" , cost); 
		return 0;
		}
	printf("_______________________________________________\n");
	}
}

