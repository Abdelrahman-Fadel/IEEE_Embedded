# IEEE_Embedded_Committe
## C project: *Clinic System* 

### Short description: 
This system allows you to add<br>
<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExd3BlNWk2anlsa2I5dzM5aXczbGpiZnY1d3d3OGFrdGlweno4cXowMCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/qgQUggAC3Pfv687qPC/giphy.gif" alt="Programming" width="300" height="180" style="float: right" align="right"/>
a new patient,print his data,<br>
delete his data and update it.<br>
After adding a new patient, it<br>
will show patient's id, cost and<br>
time he should go to clinic.<br>
If you choose the fifth choice<br>
(Exit program), it will show the total<br>
number of patients and total money they paid.


___
### Here is a sample of code of some functions:
* **Check id:**
```c
// it will return 1 if id is correct
int check_id (int id) {
	if (arr[id-1]._ID==0) return 0;
	else return 1;
```
* **Update data:**
```c
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
```
___
### Languages and Tools:
<p align="left"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> </p>
