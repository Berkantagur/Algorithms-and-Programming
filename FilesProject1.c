#include <stdio.h>
#include <stdlib.h>
#define MAX_CLIENT 100

struct clientData{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;
};

void initializeFile() {
    FILE *fPtr = NULL;

    if ((fPtr = fopen("database.dat", "wb")) == NULL) {
        printf("File could not be opened.\n");
    } else {
        struct clientData client = {0, "", "", 0.0};
        for (int i = 0; i < MAX_CLIENT; i++) {
            fwrite(&client, sizeof(struct clientData), 1, fPtr);
        }

        fclose(fPtr);
    }
}

void addClient() {
    FILE *fPtr = fopen("database.dat", "rb+");
    if (fPtr == NULL) {
        printf("File could not be opened.\n");
    } else {
        struct clientData client = {0, "", "", 0.0};
        int account;
        printf("Enter new account number (1 to 100, 0 to end input): ");
        scanf("%d", &account);

        if (account < 1 || account > 100) {
            printf("Invalid account number.\n");
            fclose(fPtr);
            return;
        }

        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
        fread(&client, sizeof(struct clientData), 1, fPtr);

        if (client.account != 0) {
            printf("Account #%d already contains information.\n", client.account);
        } else {
            printf("Enter lastname, firstname, balance: ");
            scanf("%s%s%lf", client.lastName, client.firstName, &client.balance);

            client.account = account;

            fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
            fwrite(&client, sizeof(struct clientData), 1, fPtr);
        }

        fclose(fPtr);
    }
}

void updateClient() {
    FILE *fPtr = fopen("database.dat", "rb+");
    if (fPtr == NULL) {
        printf("File could not be opened.\n");
    } else {
        struct clientData client = {0, "", "", 0.0};
        int account;
        printf("Enter account to update (1 to 100): ");
        scanf("%d", &account);

        if (account < 1 || account > 100) {
            printf("Invalid account number.\n");
            fclose(fPtr);
            return;
        }

        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
        fread(&client, sizeof(struct clientData), 1, fPtr);

        if (client.account == 0) {
            printf("Account #%d has no information.\n", account);
        } else {
            printf("%-6d%-16s%-11s%10.2f\n\n", client.account, client.lastName, client.firstName, client.balance);
            printf("Enter new lastname, new firstname, new balance: ");
            scanf("%s%s%lf", client.lastName, client.firstName, &client.balance);

            fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
            fwrite(&client, sizeof(struct clientData), 1, fPtr);
        }

        fclose(fPtr);
    }
}


void deleteClient() {
    FILE *fPtr = fopen("database.dat", "rb+");
    if (fPtr == NULL) {
        printf("File could not be opened.\n");
    } else {
        struct clientData client = {0, "", "", 0.0};
        struct clientData blankClient = {0, "", "", 0.0};
        int account;
        printf("Enter account to delete (1 to 100): ");
        scanf("%d", &account);

        if (account < 1 || account > 100) {
            printf("Invalid account number.\n");
            fclose(fPtr);
            return;
        }

        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
        fread(&client, sizeof(struct clientData), 1, fPtr);

        if (client.account == 0) {
            printf("Account #%d is already empty.\n", account);
        } else {
            fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
            fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
        }

        fclose(fPtr);
    }
}

void displayClient() {
    FILE *fPtr = fopen("database.dat", "rb");
    if (fPtr == NULL) {
        printf("File could not be opened.\n");
    } else {
        struct clientData client = {0, "", "", 0.0};
        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

        while (fread(&client, sizeof(struct clientData), 1, fPtr)) {
            if (client.account != 0) {
                printf("%-6d%-16s%-11s%10.2f\n", client.account, client.lastName, client.firstName, client.balance);
            }
        }

        fclose(fPtr);
    }
}

int main() {
    int choice;

    initializeFile();

    do {
        printf("\nEnter your choice:\n"
               "1 - Add a new account\n"
               "2 - Update an account\n"
               "3 - Delete an account\n"
               "4 - Display all accounts\n"
               "5 - End program\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                updateClient();
                break;
            case 3:
                deleteClient();
                break;
            case 4:
                displayClient();
                break;
        }
    } while (choice != 5);

    return 0;
}