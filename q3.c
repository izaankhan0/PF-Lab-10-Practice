#include <stdio.h>
#include <string.h>

struct Book{
	char title[50];
	char author[50];
	char ISBN[20];
	int publicationYear;
	int isAvailable;
	
};

void addBook(struct Book Library[], int *bookPointer) {
	
    printf("Enter Title: ");
    scanf(" %[^\n]", Library[*bookPointer].title);
    printf("Enter Author: ");
    scanf(" %[^\n]", Library[*bookPointer].author);
    printf("Enter ISBN: ");
    scanf("%s", Library[*bookPointer].ISBN);
    printf("Enter Publication Year: ");
    scanf("%d", &Library[*bookPointer].publicationYear);
    Library[*bookPointer].isAvailable = 1;

    (*bookPointer)++;
    printf("Book added successfully!\n");
}

int findBookTitle(struct Book Library[], char title[50], int bookCount){
	for(int i = 0; i < bookCount; i++){
		if (strcmp(title,Library[i].title) == 0){
			Library[i].isAvailable = 0;
			printf("Book found in space %d\n", bookCount);
			return 0;
		}
	}
	printf("Book not found");
	return 0;
}
int findBookAuthor(struct Book Library[], char author[50], int bookCount){
	for(int i = 0; i < bookCount; i++){
		if (strcmp(author,Library[i].author) == 0){
			Library[i].isAvailable = 0;
			printf("Book found in space %d\n", bookCount);
			return 0;
		}
	}
	printf("Book not found");
	return 0;
}

int main() {
    struct Book Library[100];
    int bookCount = 0;

    addBook(Library, &bookCount);
    
    char title[20] = "izaan";
	findBookTitle(Library, title, bookCount);
	
    char author[20] = "izaan";
	findBookAuthor(Library, author, bookCount);

    return 0;
}