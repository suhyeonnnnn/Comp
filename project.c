#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Books {
	int ID;
    char name[60];
	char date[40];
    char publisher[60];
	char author[60];
}bk;

struct Author {
	char author[60];
	char address[100];
    char p_num[40];
    char emailaddress[100];
    char bio[100];
} ak;

void addAuthor();
void updateAuthor();
void delelteAuthor();
void searchAuthor();

void addBooks();
void updateBook();
void deleteBook();
void searchBook();
void displayBooks();

FILE *fp;

int main(void) {

	int cmd;

	do {

		printf("\n\n<< Book Management System >>\n");
        printf("1. Add author information\n");
		printf("2. Update author information\n");
		printf("3. Delete author information \n");
		printf("4. Search author information by Author Name\n");
		printf("5. Add Book Information\n");
        printf("6. Update Book Information\n");
		printf("7. Delete Book Information\n");
		printf("8. Search by Book Name\n");
		printf("9. Display a list of all book\n");
		printf("10. Exit\n\n");
		scanf("%d", &cmd);

		switch (cmd) {
		case 1:
			addAuthor();
			break;

		case 2:
			updateAuthor();
			break;

		case 3:
			delelteAuthor();
			break;

		case 4:
			searchAuthor();
			break;

		case 5:
			addBooks();
			break;

		case 6:
			updateBook();
			break;

		case 7:
			deleteBook();
			break;

        case 8:
			searchBook();
			break;

        case 9:
			displayBooks();
			break;

		default:
			printf("Invalid Menu Number\n");
			break;

		}
	} while (cmd != 10);

	return 0;
}

void addAuthor() {

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/Author.txt", "w");
    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }
	int next = 1;

	while (1) {

		int ret = getchar();

		printf("\nEnter author Name : ");
		gets(ak.author);

		printf("\nEnter Address : ");
		gets(ak.address);

		printf("\nEnter Author Phone Number : ");
		gets(ak.p_num);

		printf("\nEnter Author Email Address : ");
		gets(ak.emailaddress);

		printf("\nEnter Author Short Biography : ");
		gets(ak.bio);

		printf("\nRecord saved\n");

        fwrite(&ak, sizeof(ak), 5, fp);
        fclose(fp);

		printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
		scanf("%d", &next);
		ret = getchar();
		if (next == 0) break;
	}
}

void updateAuthor() {
    char temp[20];
    int f = 0;

    printf("Enter Author name to update: ");
    gets(temp);

    FILE *ft;

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/Author.txt", "r");
    ft = fopen("/Users/suhyeon/Desktop/comp_ppt/temp.txt", "w");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&ak, sizeof(ak), 5, fp) == 1){
        if(strcmp(temp, ak.author) == 0){
            f=1;
        }else{
            fwrite(&ak, sizeof(ak), 5, ft);
        }
    }

    if(f==1){
        printf("\nEnter author Name : ");
		gets(ak.author);

		printf("\nEnter Address : ");
		gets(ak.address);

		printf("\nEnter Author Phone Number : ");
		gets(ak.p_num);

		printf("\nEnter Author Email Address : ");
		gets(ak.emailaddress);

		printf("\nEnter Author Short Biography : ");
		gets(ak.bio);

		printf("\nRecord saved\n");

        fwrite(&ak, sizeof(ak), 5, ft);

    }
    else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("Author.txt");
    rename("temp.txt", "Author.txt");

}

void deleteAuthor() {
    char temp[20];
    int f = 0;

    printf("Enter Author name to remove: ");
    gets(temp);

    FILE *ft;

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/Author.txt", "r");
    ft = fopen("/Users/suhyeon/Desktop/comp_ppt/temp.txt", "w");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&ak, sizeof(ak), 5, fp) == 1){
        if(strcmp(temp, ak.author) == 0){
            f=1;
        }else{
            fwrite(&ak, sizeof(ak), 5, ft);
        }
    }

    if(f==1){
        printf("\n\nDeleted Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("Author.txt");
    rename("temp.txt", "Author.txt");

}

void searchAuthor() {

	char temp[20];

    printf("\nEnter Author name : ");
    gets(temp);

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/Author.txt", "r");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&ak, sizeof(ak), 5, fp) == 1){
        if(strcmp(temp, ak.author) == 0){
            printf("%s, %s, %s, %s, %s\n", ak.author, ak.address, ak.emailaddress, ak.p_num, ak.bio);
        }
            else{
        printf("\nName does not exist.\n");
        }
    }
    fclose(fp);
}

void addBooks() {

	int next = 1, temp, flag = 0;

	while (1) {

        int f = 0;
        fp = fopen("/Users/suhyeon/Desktop/comp_ppt/books.txt", "w");
        if (fp == NULL)
        {
            printf("Error!\n");
            return;
        }
        printf("Enter book id: ");
        scanf("%d", &temp);

        while(fread(&bk, sizeof(bk), 4, fp) == 1){
            if(temp == bk.ID){
                f=1;
            }
        }

		if (!f && temp > 0) {
			bk.ID = temp;
		}
		else if (f == 1) {
			printf("\nID already exists\n");
			break;
		}
		else if (temp < 0) {
			printf("\nID is invalid\n");
			break;
		}

		int ret = getchar();

		printf("\nEnter Book Name : ");
		gets(bk.name);

		printf("\nEnter Publication Date : ");
		gets(bk.date);

		printf("\nEnter Publisher Name : ");
		gets(bk.publisher);

		printf("\nEnter Author Name : ");
		gets(bk.author);

        fwrite(&bk, sizeof(bk), 4, fp);
        fclose(fp);
        
		printf("\nRecord saved\n");
		printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
		scanf("%d", &next);
		ret = getchar();
		if (next == 0) break;
	}
}

void updateBook() {

    int temp, f=0;
    printf("\nEnter Book ID to delete : ");
    scanf("%d", &temp);

    FILE *ft;

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/books.txt", "r");
    ft = fopen("/Users/suhyeon/Desktop/comp_ppt/temp.txt", "w");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&bk, sizeof(bk), 4, fp) == 1){
        if(temp == bk.ID){
            f=1;
        }
        else{
            fwrite(&bk, sizeof(bk), 4, ft);
        }
    }

    if(f==1){
        int ret = getchar();

		printf("\nEnter Book Name : ");
		gets(bk.name);

		printf("\nEnter Publication Date : ");
		gets(bk.date);

		printf("\nEnter Publisher Name : ");
		gets(bk.publisher);

		printf("\nEnter Author Name : ");
		gets(bk.author);

        fwrite(&bk, sizeof(bk), 4, ft);
    }
    else{
        printf("\nID does not exist.\n");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

	
}

void deleteBook() {

    int temp, f=0;
    printf("\nEnter Book ID to delete : ");
    scanf("%d", &temp);

    FILE *ft;

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/books.txt", "r");
    ft = fopen("/Users/suhyeon/Desktop/comp_ppt/temp.txt", "w");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&bk, sizeof(bk), 4, fp) == 1){
        if(temp == bk.ID){
            f=1;
        }
        else{
            fwrite(&bk, sizeof(bk), 4, ft);
        }
    }

    if(f==1){
        printf("\n\nDeleted Successfully.");
    }
    else{
        printf("\nID does not exist.\n");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

}

void searchBook() {

    char temp[20];

    printf("\nEnter book name : ");
    gets(temp);

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/books.txt", "r");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&bk, sizeof(bk), 4, fp) == 1){
        if(strcmp(temp, bk.name) == 0){
            printf("%d, %s, %s, %s %s\n", bk.ID, bk.name, bk.date, bk.publisher, bk.author);
        }
            else{
        printf("\nName does not exist.\n");
        }
    }
    fclose(fp);
}

void displayBooks() {

    fp = fopen("/Users/suhyeon/Desktop/comp_ppt/books.txt", "r");

    if (fp == NULL)
    {
        printf("Error!\n");
        return;
    }

    while(fread(&bk, sizeof(bk), 4, fp) == 1){
        printf("%d, %s, %s, %s %s\n", bk.ID, bk.name, bk.date, bk.publisher, bk.author);
    }

    fclose(fp);
}

