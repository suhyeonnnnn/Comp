/*Write a menu-driven Library Management program in C.


Book ID
Book Name
Publication Date
Publisher Name
Publisher Phone Number
Author Name
Author Email Address


Add book information
Update book information
Delete book information
Search book information
Display a list of book(s) published by an author a
Display a list of book(s) published by a publisher p
Display a list of all book


Book ID should be unique.
Book ID should not be a negative number.

USE FUNCTIONS AND STRUCT
*/


#include <stdio.h>
#include <string.h>

struct Books {
	char name[60];
	int ID;
	char date[40];
	char author[60];
	char address[100];
	char publisher[60];
	char p_num[40];
};

// fucntion 1: check unique ID

// make sturuct & idx as global variable 
struct Books bk[20];


int unique(int x){
    int flag = 0;
    for (i = 0; i < idx; i++) {
        if (x == bk[i].ID) {
    	    x = 1;
        }
    }
    if (!flag && x > 0) {
    	bk[idx].ID = x;
    }

}


// function 2: get book information
int a[40], i;

void getinfo(struct Books a){
    getchar();
    printf("\nEnter Book name : ");
    gets(a.name);
    printf("\nEnter Publisher name : ");
    gets(a.publisher);
    printf("\nEnter Publisher Date : ");
    gets(a.date);
    printf("\nEnter Author name : ");
    gets(a.author);
    printf("\nEnter Author e-mail address : ");
    gets(a.address);
    printf("\nEnter Publisher Phone Number : ");
    gets(a.p_num);
    printf("\nRecord saved\n");
}

// function 3: print book information
void bookinfo(struct Books a){
    printf("\n\nName : %s", a.name);
	printf("\nID : %d", a.ID);
	printf("\nPublication date : %s", a.date);
	printf("\nAuthor name : %s", a.author);
	printf("\nAuthor E-mail Address : %s", a.address);
	printf("\nPublisher : %s", a.publisher);
	printf("\nPublisher Phone Number : %s", a.p_num);
}



int main(void) {
	int cmd, next = 1, flag, bk_id, del_id = 0, bk_up_id, bk_idx, temp, i, idx = 0;
	char name[40], author[40], publisher[40];
	struct Books bk[20];

	do {

		printf("\n\n<< Library Management Program >>\n");
		printf("1. Add Book Information\n");
		printf("2. Delete Book Information\n");
		printf("3. Update Book Information\n");
		printf("4. Search by Book Name\n");
		printf("5. Display a list of book(s) published by an author a\n");
		printf("6. Display a list of book(s) published by a publisher p\n");
		printf("7. Display list of all book\n");
		printf("8. Exit\n\n");
		scanf("%d", &cmd);

		switch (cmd) {
		case 1:
			while (1) {
				flag = 0;
				printf("\nEnter Book ID : ");
				scanf("%d", &temp);
				for (i = 0; i < idx; i++) {
					if (temp == bk[i].ID) {
						flag = 1;
					}
				}
				if (!flag && temp > 0) {
					bk[idx].ID = temp;
				}

				else if (flag == 1) {
					printf("\nThis ID already exists!\n");
					break;
				}
				else if (temp <= 0) {
					printf("\nThis ID's value is invalid\n'");
					break;
				}

				getinfo(bk[idx]);
				idx++;

				printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
				scanf("%d", &next);
				getchar();
				if (next == 0) break;
			}
			break;

		case 2:
			printf("\nEnter Book ID to delete : ");
			getchar();
			flag = 0;
			scanf("%d", &bk_id);
			for (i = 0; i < idx; i++) {
				if (bk_id == bk[i].ID) {
					del_id = i;
					flag = 1;
					break;
				}
			}
			if (flag) {
				for (i = del_id; i < idx; i++) {
					bk[i] = bk[i + 1];
				}
				idx--;
			}
			else if (!flag) {
				printf("\n This ID is not in this system.\n");
			}
			break;

		case 3:
			flag = 0;

			printf("\nEnter Book ID: ");
			scanf("%d", &temp);
			for (i = 0; i < idx; i++) {
				if (bk[i].ID == temp) {
					flag = 1;
					bookinfo(bk[i]);
					bk_idx = i;
					break;
				}
			}
			if (!flag) {
				printf("\nThis ID does not exist!\n");
			}
			else if (flag == 1) {
				flag = 0;
				printf("\nEnter Book ID to update : ");
				scanf("%d", &temp);
				for (i = 0; i < idx; i++) {
					if (bk[i].ID == temp) {
						flag = 1;
					}
				}
				if (!flag && temp > 0) {
					bk[bk_idx].ID = temp;
					getinfo(bk[bk_idx]);
				}
				else if (flag == 1) {
					printf("\nThis ID already exists!\n");
				}
				else if (temp < 0) {
					printf("\nThis ID's value is invalid\n'");
				}
			}
			break;

		case 4:

			printf("\nEnter name of book to find : ");
			getchar();
			gets(name);

			for (i = 0; i < idx; i++) {
				if (!strcmp(name, bk[i].name)) {
                    bookinfo(bk[i]);
				}
			}
			if (i == idx) {
				printf("\nThere is no book by that author's name!\n");
			}
			break;

		case 5:

			printf("\nEnter author's name of book to find : ");
			getchar();
			gets(author);

			for (i = 0; i < idx; i++) {
				if (!strcmp(author, bk[i].author)) {
					bookinfo(bk[i]);
				}
			}
			if (i == idx) {
				printf("\nThere is no book by that author's name!\n");
			}
			break;

		case 6:

			printf("\nEnter Publisher's name of book to find : ");
			getchar();
			gets(publisher);

			for (i = 0; i < idx; i++) {
				if (!strcmp(publisher, bk[i].publisher)) {
					bookinfo(bk[i]);
				}
			}

			if (i == idx) {
				printf("\nThere is no book by that author's name!\n");
			}
			break;

		case 7:
			for (i = 0; i < idx; i++) {
				bookinfo(bk[i]);
			}
			break;

		default:
			printf("Invalid choice: \n");
			break;
		}
	} while (cmd != 8);

	return 0;
}
