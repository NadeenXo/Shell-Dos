#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define SIZE 30
int main(int argc, char* argv[])
{

    if (argc > 1)
    {

        if (strcmp(argv[1], "--help") == 0)
        {
            printf("\n\nDOS Commands: a project that simulates a shell, ");
            printf("displaying a menu of DOS commands for the user to choose from and then displays the output. ");
            printf("Exiting the project is initiated by the user.\n\n");
            printf(" Linux  DOS\n\n");
            printf(" pwd   chdir\n cp    copy\n date  date\n rm    del\n ls    dir\n echo  ");
            printf("echo\n mkdir mkdir\n mv    move\n free  mem\n grep  find\n cat   type\n");

        }
    }

    else
    {
        FILE* fpa, * fpb;
        char comm[SIZE], name[SIZE], stra[SIZE], strb[SIZE], newcom[SIZE] = { '\0' };
        int op;

        printf("1-enter dos command \n2-Display Dos commands\n 0-Exit\n");
        scanf("%d", &op);
        while (op)
        {
            switch (op)
            {
            case 1:
                memset(newcom, 0, SIZE);
                puts("enter command:");
                scanf("%s", comm);
                fgets(name, SIZE, stdin);
                for (int i = 0; name[i] != '\0'; i++)
                {
                    if (name[i] == '\\')
                    {
                        name[i] = '/';
                    }
                }
                fpa = fopen("DOS.txt", "r");
                fpb = fopen("Linux.txt", "r");

                if (fpa == NULL || fpb == NULL)
                {
                    printf("cannot open one/two file(s)");
                }
                while (!feof(fpa))
                {
                    fscanf(fpa, "%s", stra);
                    fscanf(fpb, "%s", strb);

                    if (strcmp(comm, stra) == 0)
                    {
                        strcat(newcom, strb);
                        strcat(newcom, "");
                        strcat(newcom, name + '\0');
                        system(newcom);
                        break;

                    }
                }
                fclose(fpa);
                fclose(fpb);
                break;

            case 2:
                fpa = fopen("DOS.txt", "r");

                if (fpa == NULL)
                {
                    printf("cannot open this file");
                }

                while (!feof(fpa))
                {
                    memset(stra, 0, SIZE);
                    fscanf(fpa, "%s", stra);
                    printf("%s\n", stra);
                }
                fclose(fpa);
                break;
            }

            printf("\n1-enter dos command\n2-Display Dos commands\n 0-Exit\n");
            scanf("%d", &op);
        }
    }
    return 0;
}
