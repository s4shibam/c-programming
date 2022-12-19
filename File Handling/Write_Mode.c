// File Handling
// WAP to Create or Replace a file and put some content in it. --> Write Mode (W Mode)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	char ch, fn[20];
	// x--> To store the characters of the file
	// fn[]--> To store the file name
	int n;

	printf("Enter file name: ");
	scanf("%[^\n]s", &fn);

	// Code for Write Mode Or W Mode

	fp = fopen(fn, "w"); // Opens the file in Write Mode.

	if (fp == NULL)
	{
		printf("File Not Found!!");
		// If given file name is wrong or file not available in the folder then exit the program with a remark.
		exit(0);
	}
	else
	{
		printf("Enter the content to save (\"~\" is the Escape character):\n");
		for (;;) // while(1)
		{
			scanf("%c", &ch);
			if (ch == '~') // If that particular character is entered, file will not take any input.
				break;
			else
			{
				fputc(ch, fp); // Saving the character in the file.
			}
		}
	}
	fclose(fp); // Deletes the file from Ram.

	printf("\n-----------------------\n");
	printf("File Saved Successfully!!");
	printf("\n-----------------------\n");

	// Code for Read Mode Or R Mode

	printf("\nPress 0 to Exit\nPress 1 to Show File.\n");
	scanf("%d", &n);
	printf("-----------------------\n");

	if (n == 0)
		exit(0);

	else
	{
		fp = fopen(fn, "r"); // Opening the file in the Ram under Read Mode
		if (fp == NULL)
		{
			printf("File Not Found!!");
			// If given file name is wrong or file not available in the folder then exit the program with a remark.
			exit(0);
		}
		else
		{
			while (1)
			{
				ch = fgetc(fp); // Assigning character value in "x" variable.

				if (ch == EOF) // EOF--> End of the file. / When all elements are printed.
				{
					printf("\n\n-----------------------------\n");
					printf("File Displayed Successfully!!");
					break;
				}
				else
				{
					printf("%c", ch);
					// sleep(1);
				}
			}
		}
		fclose(fp); // Deletes the file from Ram.
	}

	getch();
}
