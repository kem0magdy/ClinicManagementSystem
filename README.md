# Clinic Management System
A clinic managment system created by me Starts in : 25/12/2020 , Finshied in : 28/12/2020 <br /><br />
Descreption:<br />

Write a C code for clinic management system. At the beginning of the system it asks
the user to choose between admin mode and user mode.<br />

# In admin mode
The system asks for password, the default password is 1234. The system allows 3
trails for the password entry, if the entered password was incorrect for 3 consecutive
times, the system shall close. After login in the admin mode, the system shall provide <br />

the following features:<br />

1. Add new patient record:<br />

To add a new patient, the user shall admin shall enter these basic
information: name, age, gender and ID. The ID shall be unique for the user, if
the entered ID is already exists, the system shall reject the entry.<br />

2. Edit patient record:<br />

By entering patient ID the system shall checks if the ID exists, the system
shall allow the user to edit the patient information. If not, the system shall
display incorrect ID message.<br />

3. Reserve a slot with the doctor:<br />
By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to
3:30pm, 4pm to 4:30pm and 4:30pm to 5pm. Upon opening of this window,
the system shall display the available slots. The admin shall enter the patient
ID and the desired slot. The reserved slot shall not appear again in the next
patient reservation.<br />

4. Cancel reservation:<br />
The admin can cancel a reservation by entering the patient ID. This
reservation shall be shown again in the available slots window.<br />

#In the user mode
There is no password. The system allows the following features:<br />

1. View patient record.<br />

By entering the patient ID, the system shall show the basic information for the
patient.<br />

2. View today’s reservations.<br />

In this view, the system shall print all reservations with the patient ID attached
to each reservation slot.<br />



