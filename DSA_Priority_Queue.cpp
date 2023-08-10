#include<iostream>
#include <algorithm>

using namespace std;

const int Max_bed = 10;
const int Max_icu = 3;

struct Patient{
	
    int ID;
    string name;
    int age;
    string diagnosis;
    string treatment;
		
};

class ICU{
	
	Patient patients[Max_icu][Max_bed];
	int UB[Max_icu];
	int LB[Max_icu];
	
	
public:	
	ICU(){
		
		for(int i=0; i<Max_icu; i++){
			
			UB[i] = -1;
			LB[i] = -1;
		}
	}
	
	
	//Adding Patients in ICU
	
	void enqeue(Patient& patient, int icu_num){
		
		if((UB[icu_num-1] == Max_bed-1 && LB[icu_num-1]== 0) || (UB[icu_num-1]+1) == LB[icu_num-1] ){
			
			 cout << "ICU-" << icu_num << " is full. Patient cannot be added." << endl;
            return;
			
		}
		
		else {
			
		
	 if(UB[icu_num-1] == -1 && LB[icu_num-1] == -1 ){
			
			UB[icu_num-1]++;
			LB[icu_num-1]++;
			
			patients[icu_num-1][UB[icu_num-1]] = patient;
			
			cout<<endl<<"Patient added to "<<icu_num<<" ICU";
			return;
		}
		else if(UB[icu_num-1] == Max_bed-1 ){
			
			UB[icu_num-1]=0;
			patients[icu_num-1][UB[icu_num-1]]=patient;
			cout<<endl<<"Patient added to "<<icu_num<<" ICU";
			return;
		}
		
		UB[icu_num-1]++;
		patients[icu_num-1][UB[icu_num-1]] = patient;
		cout<<endl<<"Patient added to "<<icu_num<<" ICU";
		return;
	}}

	//removing a patient from ICU
	
	void dequeue() {
    for (int i = 0; i < Max_icu; i++) {
        if (LB[i] == -1) {
            cout << endl << "ICU " << i + 1 << " is empty";
          
        } 
        
       
		else if (LB[i] == UB[i]) {
            Patient patient = patients[i][LB[i]];
            LB[i] = UB[i] = -1;
            cout << endl << "Patient removed from ICU: " << i + 1;
            cout << endl << "....................................Removed Patient info ................................." << endl;
            cout << "ID: " << patient.ID << ", ";
            cout << "Name: " << patient.name << ", ";
            cout << "Age: " << patient.age << ", ";
            cout << "Diagnosis: " << patient.diagnosis << ", ";
            cout << "Treatment: " << patient.treatment << endl;
            return;
        } 
		
		else {
			
		
            Patient patient = patients[i][LB[i]];
            LB[i]++;
            cout << endl << "Patient removed from ICU: " << i + 1;
            cout << endl << "....................................Removed Patient info ................................." << endl;
            cout << "ID: " << patient.ID << ", ";
            cout << "Name: " << patient.name << ", ";
            cout << "Age: " << patient.age << ", ";
            cout << "Diagnosis: " << patient.diagnosis << ", ";
            cout << "Treatment: " << patient.treatment << endl;

                  if(LB[i]>Max_icu-1){
                             	LB[i]=0;
		                     }
		
            return;
        }
    }
}



//Search a Patient by name and id

void search(int id, string name){



    for (int i = 0; i < Max_icu; i++) {
        if (LB[i] == -1 && UB[i] == -1) {
            cout << endl << "ICU " << i + 1 << " is empty";
        } 
		
		else {
          
            if (LB[i] <= UB[i]) {
                for (int j = LB[i]; j <= UB[i]; j++) {
                    Patient patient = patients[i][j];
                   if(patient.ID==id && patient.name==name){
                   	cout<<endl<<"Patient found at ICU: "<<i+1;
                   	return;
				   }
                }
            } 
			else {
                for (int j = LB[i]; j < Max_bed; j++) {
                     Patient patient = patients[i][j];
                   if(patient.ID==id && patient.name==name){
                   	cout<<endl<<"Patient found at ICU: "<<i+1;
                   	return;
				   }
                }
                for (int j = 0; j <= UB[i]; j++) {
                    Patient patient = patients[i][j];
                   if(patient.ID==id && patient.name==name){
                   	cout<<endl<<"Patient found at ICU: "<<i+1;
                   	return;
				   }
                }
            }
        }
        
      

	}

  cout<<endl<<"Patient: "<<name<<" with id: "<<id<<" not found";
	return;
	
	
}


void display(){

    for (int i = 0; i < Max_icu; i++) {
        if (LB[i] == -1 && UB[i] == -1) {
            cout << endl << "ICU " << i + 1 << " is empty";
        } 
		
		else {
            cout << endl << "Patients in ICU: " << i + 1 << " are: " << endl;

            if (LB[i] <= UB[i]) {
                for (int j = LB[i]; j <= UB[i]; j++) {
                    Patient patient = patients[i][j];
                    cout << "ID: " << patient.ID << ", ";
                    cout << "Name: " << patient.name << ", ";
                    cout << "Age: " << patient.age << ", ";
                    cout << "Diagnosis: " << patient.diagnosis << ", ";
                    cout << "Treatment: " << patient.treatment << endl;
                }
            } 
			else {
                for (int j = LB[i]; j < Max_bed; j++) {
                    Patient patient = patients[i][j];
                    cout << "ID: " << patient.ID << ", ";
                    cout << "Name: " << patient.name << ", ";
                    cout << "Age: " << patient.age << ", ";
                    cout << "Diagnosis: " << patient.diagnosis << ", ";
                    cout << "Treatment: " << patient.treatment << endl;
                }
                for (int j = 0; j <= UB[i]; j++) {
                    Patient patient = patients[i][j];
                    cout << "ID: " << patient.ID << ", ";
                    cout << "Name: " << patient.name << ", ";
                    cout << "Age: " << patient.age << ", ";
                    cout << "Diagnosis: " << patient.diagnosis << ", ";
                    cout << "Treatment: " << patient.treatment << endl;
                }
            }
        }
    }
}
};

int main(){
	
	
	 ICU icu;
	 Patient patient;
	int choice, num, id;
	string name;
	
		cout<<endl<<"...................You have 3 ICUs in a Hospital.............................";
		cout<<endl<<endl<<"         Enter the patients with most critical situation in ICU-1";
		cout<<endl<<"         Enter the patient with some critical condition in ICU-2";
		cout<<endl<<"         Enter the patients with less critical condition in ICU-3";
		cout<<endl<<endl;
		
	do{
		
	
		cout<<endl<<"..................................What do you want to perform...........................................";
		cout<<endl<<endl;
		cout<<" 1)  Press 1 to Insert a patient in ICU";
		cout<<endl<<" 2)  Press 2 to remove a patient from ICU";
		cout<<endl<<" 3)  Press 3 to search a patient in ICU";
		cout<<endl<<" 4)  Press 4 to view the patients in ICUs";
		cout<<endl<<" 5)  Press 5 to exit";
		cout<<endl<<endl;
			cout<<"..................................Enter your choice..........................................."<<endl;
		
		cin>>choice;	
		
		
		switch(choice){
			case 1:{
				
				cout<<endl<<".........................Enter the data of patient............................";
				cout<<endl<<"Enter Id: ";
				cin>>patient.ID;
				cout<<endl<<"Enter Name: ";
				cin>>patient.name;
				cout<<endl<<"Enter age: ";
				cin>>patient.age;
				cout<<endl<<"Enter diagnose: ";
				cin>>patient.diagnosis;
				cout<<"Enter treatment: ";
				cin>>patient.treatment;
				
			cout<<endl<<"Enter the ICU where you want to insert patient according to his/her condition: ";
			cin>>num;
			
			icu.enqeue(patient, num);	
				
				
				break;
			}
			
		case 2:{
			
			cout<<endl<<".........................Patient will be removed according to highest priority.........................."<<endl;
			icu.dequeue();
			
			break;
		}
		
		case 3:{
			
			
			cout<<endl<<"Enter name of patient you want to search: ";
			cin>>name;
			cout<<endl<<"Enter ID of that patient: ";
			cin>>id;
			
			icu.search(id, name);
			
		
			break;
		}
		
		case 4:{
			
			icu.display();
			
			break;
		}
		default:
		{
			cout<<endl<<"..........Thank You☺.........";
			break;
			}	
		}
	}while(choice!=5);
	
	
	
	return 0;
}